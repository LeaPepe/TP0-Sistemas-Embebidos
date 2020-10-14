#include "main.h"

int main(void){
	
	int nImages=0;
	char img_name[MAX_IMG_NAME];
	
	//create shapes
	Line line(20,100,100,130);
	Rect rect(40,120,60,40);
	for(int i=0; i<50; i++){
		// new image
		Image img;
		
		//show
		line.plot(img);
		rect.plot(img);
		// update
		line.move(1,1);
		rect.move(1,-1);
		
		// Lo guardo en un archivo
		sprintf(img_name,"./images/img%.3d.pbm",nImages); 
		img.toFile(img_name); 

		++nImages;
	}

	return 0;
}