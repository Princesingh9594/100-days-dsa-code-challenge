#include <stdio.h>

int main() {
    int m, n;
    
    // Read rows and columns
    scanf("%d %d", &m, &n);
    
    int matrix[m][n];
    int sum = 0;
    
  
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    
    for(int i = 0; i < m && i < n; i++) {
        sum = sum + matrix[i][i];
    }
    
  
    printf("%d", sum);
    
    return 0;
}
