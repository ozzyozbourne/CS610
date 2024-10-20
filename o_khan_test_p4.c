#include <stdlib.h>

#define header_lines 4;
#define image_columns 120
#define image_rows 134
#define MaxGrayComponentValue 255;
#define carriage_return '\n'

int image_in[image_rows+ 1][image_columns+ 1];
int hist[MaxGrayComponentValue + 1];
int stream streamlocks[MaxGrayComponentValue + 1]; /* array of stream */

int i, j;

void read_image_header(void){
    char buffer[header_lines+1][80];
    char c;
    int m;
    for (m = 1; m <= header_lines; ++m){
        do{
            cin >> c;  
        } while (c != carriage_return);
    }
 }

void read_image_values(void){    
    for(i = 1; i <= image_rows; i++){
        for( j = 1; j <= image_columns; j++) { cin >> image_in[i][j]; }
    }
}

main(void){

    read_image_header();
    read_image_values();

    for (i = 0; i <= MaxGrayComponentValue; i++){ hist[i] = 0; }

    forall i = 1 to image_rows do { 
        int j, intensity;
        forall j = 1 to image_columns do {
            intensity = image_in[i][j];
            /* fill the stream */
            send(streamlocks[intensity], intensity); 
        }
    }


    for (i = 0; i <= MaxGrayComponentValue; i++){ 
        /* drain the stream */
        while(streamlocks[i]??){ 
            int res;
            recv(streamlocks[i], res);
            hist[i] = hist[i] + 1;
        }
    }

    for (i = 0; i <= MaxGrayComponentValue; i++){ cout << "hist ["<<i<< "] = " << hist[i] << endl; } 

}
