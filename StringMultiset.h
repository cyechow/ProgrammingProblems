std::string
TestClass::FindSubstring( std::string S, multiset T )
{
	if ( T.empty() || S.size() < T.size() ) return "";
	
	int N = S.size();
	
	int iMin;
	int iMax;
	std::multiset<std::string, int> Tc;
	std::multimap<std::string, int> idxTc;
	std::list<int> idxMaxList, idxMinList, idxN;
	
	int nMinSs = N;
	std::map<int, std::string> mSs;
	
	for ( int i = 0; i < N; i++ )
	{
		// Is current character part of T?
		if ( T.count( S[i] ) == 0 ) continue;
		
		// Keep track of values and location index in the current valid substring:
		idxTc.insert( std::pair<std::string, int>( S[i], i ) );
		
		// Do we have a full set?
		if ( Tc.size() != T.size() )
		{
			// Set incomplete:
			
			// If it's empty, set the minimum, otherwise this might the max of the first potential substring.
			if ( Tc.empty() ) iMin = i;
			else
			{
				iMax = i;
				
				// Clean idxTc of the first element of the same value if the quota has been satisfied:
				if ( Tc.count( S[i] ) == T.count( S[i] ) )
				{
					// Logarithmic complexity
					idxTc.erase( idxTc.find( S[i] ) );
					
					// Update iMin:
					iMin = idxTc.begin()->second;
				}
			}
			
			// Insert this to the copy:
			Tc.insert( S[i] );
		}
		else
		{
			// Complete set:

			// Remove the first occurrence of the current value:
			// Logarithmic complexity
			idxTc.erase( idxTc.find( S[i] ) );
			
			// Update iMin:
			iMin = idxTc.begin()->second;
			
			// Update iMax:
			iMax = i;
			
			// Only keep the substrings of shorter length:
			if ( iMax - iMin < nMinSs )
			{
				nMinSs = iMax - iMin;
				nSs.insert( std::pair<int, std::string>( nMinSs, S.substr( iMin, nMinSs + 1 ) ) );
			}
		}
	}
	
	// Substring found only if we have a full set, otherwise there is nothing:
	if ( Tc.size() == T.size() ) return nSs.begin()->second;
	else return "";
}