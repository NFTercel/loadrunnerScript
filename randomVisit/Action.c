Action(){
int randomnumber;
int i=0;
int j=0;
int flag=1;
while(flag==1){
	randomnumber=rand()%3+1;
	lr_output_message("�����������%d",randomnumber);
	lr_output_message("������:i=%d,j=%d",i,j);
	if( (i==10) && (j==10) ){
		flag=0;
		return 0;
	}
	switch(randomnumber){
		case 1:
		{
			if(i<10){
			Action1();
			i=i+1;
			lr_output_message("Action1()����˵�%d��",i);
			break;
		}
		}
		case 2:
			Action2();
			break;
		case 3:{
			if(j<10){
				Action3();
				j=j+1;
				lr_output_message("Action3()����˵�%d��",j);
				break;
			}
		}
	}
}
return 0;
}
