std::string
TestClass::FindSubstring( std::string S, multiset T )
{
	if ( T.empty() || S.size() < T.size() ) return "";
	
	int N = S.size();
	
	int currentLeftIndex;
	int currentRightIndex;
	std::multiset<std::string, int> validationT;
	std::multimap<std::string, int> currentSubstring;
	
	std::multimap<int, std::string> validSubstringsOrdered;
	
	int countShortestSubstring = N;
	
	for ( int i = 0; i < N; i++ )
	{
		// Is current character part of T?
		if ( T.count( S[i] ) == 0 ) continue;
		
		// Keep track of values and location index in the current valid substring:
		currentSubstring.insert( std::pair<std::string, int>( S[i], i ) );
		
		// Do we have a full set?
		if ( validationT.size() != T.size() )
		{
			// Set incomplete:
			
			// If it's empty, set the minimum, otherwise this might the max of the first potential substring.
			if ( validationT.empty() ) currentLeftIndex = i;
			else
			{
				currentRightIndex = i;
				
				// Clean currentSubstring of the first element of the same value if the quota has been satisfied:
				if ( validationT.count( S[i] ) == T.count( S[i] ) )
				{
					// Logarithmic complexity
					currentSubstring.erase( currentSubstring.find( S[i] ) );
					
					// Update currentLeftIndex:
					currentLeftIndex = currentSubstring.begin()->second;
				}
			}
			
			// Insert this to the copy:
			if ( validationT.count( S[i] ) < T.count( S[i] ))
				validationT.insert( S[i] );
		}
		else
		{
			// Complete set:

			// Remove the first occurrence of the current value:
			// Logarithmic complexity
			currentSubstring.erase( currentSubstring.find( S[i] ) );
			
			// Update currentLeftIndex:
			currentLeftIndex = currentSubstring.begin()->second;
			
			// Update currentRightIndex:
			currentRightIndex = i;
			
			// Only keep the substrings of shorter length:
			if ( currentRightIndex - currentLeftIndex < countShortestSubstring )
			{
				countShortestSubstring = currentRightIndex - currentLeftIndex;
				validSubstringsOrdered.insert( std::pair<int, std::string>( countShortestSubstring, S.substr( currentLeftIndex, countShortestSubstring + 1 ) ) );
			}
		}
	}
	
	// Substring found only if we have a full set, otherwise there is nothing:
	if ( validationT.size() == T.size() ) return validSubstringsOrdered.begin()->second;
	else return "";
}