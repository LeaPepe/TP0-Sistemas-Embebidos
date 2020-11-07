#include "main.h"


int main(void){
	
	int nImages=0;
	char img_name[MAX_IMG_NAME];
	
	//create shapes
	Line line(20,10,40,40);
	Rect rect(40,120,40,40);
	for(int i=0; i<72; i++){ // 3 seconds, 24 fps
		// new image
		Image img(N_ROWS,N_COLS);
		
		//show
		line.plot(&img);
		rect.plot(&img);
		// update
		
		line.move(3,1);
		rect.move(1,-2);
		
		line.rotate(M_PI/8);
		rect.rotate(-M_PI/8);
		// to file
		sprintf(img_name,"./images/img%.3d.pbm",nImages); 
		img.toFile(img_name); 

		++nImages;
	}

	return 0;
}