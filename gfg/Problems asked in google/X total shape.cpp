// pROBLEM LINK :  https://practice.geeksforgeeks.org/problems/x-total-shapes3617/1/?company[]=Google&page=1&query=company[]Googlepage1#
//Given N * M string array arr of O's and X's. The task is to find the number of 'X' total shapes.
//'X' shape consists of one or more adjacent X's (diagonals not included).

Input:
The first line of input takes the number of test cases T. Then T test cases follow. Each of the T test cases takes 2 input lines. The first line of each test case have two integers N and M.The second line of N space separated strings follow which indicate the elements in the array.

Output:
For each testcase, in a new line print the total X shapes.

Your Task:
Complete Shape function that takes string array arr, n, m as arguments and returns the count of total X shapes.

Constraints:
1 <= T <= 100
1 <= N, M <= 50

Expected Time Complexity : O(N*M)
Expected Auxilliary Space : O(N*M)

Example:
Input:
2
4 7
OOOOXXO OXOXOOX XXXXOXO OXXXOOO
10 3
XXO OOX OXO OOO XOX XOX OXO XXO XXX OOO

Output:
4
6

Explanation:
Testcase 1: Given input is like:
OOOOXXO
OXOXOOX
XXXXOXO
OXXXOOO

So, X with same colour are adjacent to each other vertically for horizontally (diagonals not included). So, there are 4 different groups in the given matrix.

Testcase 2: Given input is like:
XXO
OOX
OXO
OOO
XOX
XOX
OXO
XXO
XXX
OOO
So, this matrix has 6 groups with is having adjacent Xs. Total number of groups is 6.

==> Approach : using dfs in grid 


bool visited[100][100];
char a[100][100];

void dfs(int i,int j,int n,int m){
    if(i<1||j<1||i>n||j>m)return;
    visited[i][j]=true;
    
    int ar1[] = {-1,0,1,0};
    int ar2[] = {0,1,0,-1};
    
    for(int k=0;k<4;k++)if(visited[i+ar1[k]][j+ar2[k]]==false&&a[i+ar1[k]][j+ar2[k]]=='X')dfs(i+ar1[k],j+ar2[k],n,m);
    return;
}

int Shape(vector<string> &arr,int n,int m) {
    
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    a[i][j]=arr[i-1][j-1];
    
    int ans =0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        if(a[i][j]=='O')continue;
        if(visited[i][j]==true)continue;
        ans++;

        dfs(i,j,n,m);
    }
    return ans;
}



