#include <iostream>  
using namespace std;   
  
int main(int argc, char *argv[])  
{
	unsigned int Subchunk1Size = 0;
    FILE *p = NULL;
    
    if (argc < 2) {
    	cout<<"Usage: ./wavHeadTest Inputfile"<<endl;
    	return 0;
	}
    
    p = fopen(argv[1],"rb");
    if (p == NULL) {
    	cout<<"Open "<<argv[1]<<" error."<<endl;
    	return 0;
	}
    fseek(p,16,SEEK_SET);
    fread(&Subchunk1Size,4,1,p);
    fclose(p);
	
	if (Subchunk1Size < 16) {
		cout<<"This is not a valid wav file."<<endl;
	} else {
		switch (Subchunk1Size) {
			case 16:
				cout<<"44-byte header"<<endl;
				break;
			case 18:
				cout<<"46-byte header"<<endl;
				break;
			default:
				cout<<"Header contains extra data and is larger than 46 bytes"<<endl;
		}	
	}
	
	system("pause");
    return 0;  
}  
