/* Parallel back substitutuin */
/* for this we need a square matrix and a column matrix 
 * the A is the squre matrix and B is the column matrix */
#define n 10
float A[n+1][n+1]; /*lower triangular matrix*/
float B[n+1], x[n+1]; /*two arrays */
float stream pipechan[n+2]; /* array of stream */
int i;

void initializeAB(void){
    int row, col;
    for(row = 1; row <= n; row++){
        for(col = 1; col <= n; col++){
            if (row == col){ A[row][col] = 5.0; } /* setting the diagonal to 5 */
            else if (col < row) { A[row][col] = 1.0; } /*setting the all elements below diagonal to 1*/
            else { A[row][col] = 0.0; } /* setting all elements above the diagonal to 0 since we are operating on lower triangular maxtrix */
        }
        B[row] = row; /* setting to column matrix to row value */
    }
}

void PipeProcess(const int i){
    int j;
    float sum, xvalue;

    sum = 0;
    for (j = 1; j <= i-1; j++) {
        recv(pipechan[i], xvalue);  /*reading from the stream i into xvalue*/
        send(pipechan[i+1], xvalue);/*writing to the stream i + 1 */          
        sum = sum + A[i][j] * xvalue;
    }
    x[i] = (B[i] - sum) / A[i][i];  
    send(pipechan[i+1], x[i]);
}

main(void){
    initializeAB();
    forall i = 1 to n do
        PipeProcess(i);

    /* printing the ouput array x */
    for(i=1; i<=n;i++){
        cout.precision(3);
        cout <<"x["<<i<<"  ] = "<<x[i] << endl;
    }
}
