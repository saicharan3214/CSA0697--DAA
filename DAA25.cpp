 #include <stdio.h>
#define INF 99999999

int tsp(int graph[][10], int pos, int visited, int n, int dp[][1024]) {
    if (visited == (1 << n) - 1) {
        return graph[pos][0]; 
    }

    if (dp[pos][visited] != -1) {
        return dp[pos][visited];
    }

    int ans = INF;
    for (int city = 0; city < n; city++) {
        if ((visited & (1 << city)) == 0) {
            int newAns = graph[pos][city] + tsp(graph, city, visited | (1 << city), n, dp);
            ans = (newAns < ans) ? newAns : ans;
        }
    }
    return dp[pos][visited] = ans;
}

int main() {
    int n;
    printf("Enter number of cities: ");
    scanf("%d", &n);

    int graph[10][10];
    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int dp[10][1024];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 1024; j++) {
            dp[i][j] = -1;
        }
    }

    printf("Minimum cost: %d\n", tsp(graph, 0, 1, n, dp));
    return 0;
}

