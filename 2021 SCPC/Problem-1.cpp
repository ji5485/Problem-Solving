#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Answer;

void dfs(vector<int> graph[], int start, vector<int>& visited);

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);
	
	int n, tmp;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		cin >> n;
		vector<int> graph[n + 1], visited(n + 1, 0);
		
		for (int i = 0; i < n; i++) {
		    cin >> tmp;
		    int friends = i + tmp;
		    
		    if (friends >= n) continue;
		    
		    graph[i].push_back(friends);
		    graph[friends].push_back(i);
		}
		
		for (int i = 0; i < n; i++)
		    sort(graph[i].begin(), graph[i].end());
		    
		for (int i = 0; i < n; i++) {
		    if (visited[i]) continue;
		    
		    dfs(graph, i, visited);
		    Answer++;
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}

void dfs(vector<int> graph[], int start, vector<int>& visited) {
    if (visited[start]) return;
    visited[start] = 1;
    
    for (int i = 0; i < graph[start].size(); i++)
        dfs(graph, graph[start][i], visited);
        
    return;
}