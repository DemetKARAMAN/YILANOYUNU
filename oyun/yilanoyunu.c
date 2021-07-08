#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // rand fonksiyonunu kullanmak i�in tan�mlad���m bir k�t�phane
#include <conio.h>  
  
	/*  YILAN OYUNU  */
int main(){
	char tahta[12][12],cevap;  // '.', '|' bir karakter oldugu icin char tipinde bi dizi tan�mlad�m ald�g�m cevapta bir karakter 
	int yemx,yemy; 
    time_t start,end;
		int satir,sutun; // X in baslamas� gereken sat�r ve sutunlar� tan�mlad� 
	baslangic:
	time(&start);
	srand(time(NULL));  // her defas�nda yemi farkli yerlere atmas� icin srand � kulland�mm
	yemx=rand()%9+1;    // rand fonsiyonu ile yemx ve yemy nin 1 ile 10 arasnda bir say� �retir 
	yemy=rand()%9+1;
    int deneme=3; // oyunda 3 deneme hakk�m�z bulunmaktad�r
        basla:
   	
   		satir=1;sutun=2;
       	if(deneme>0){ // deneme 0 dan buyuk oldugu surece d�nder
        	do{  
    		int i,j;	
		    printf("Yilan oyununa hosgeldiniz, hareket icin w a s d tuslarini kullaniniz...\n");
	        for(i=0;i<12;i++){  // for d�ng�s� satir say�s�n� ifade eder ve 12 defa d�ner
		        for(j=0;j<12;j++){ // 2.for d�ng�s� sutun say�s�n ifade eder ve 12 defa d�ner
			        if(i==satir && j==sutun){    // satir sayisi i ye sutun sayisi j ye e�it oldu�u zaman
				        tahta[satir][sutun]='X'; // tahta dizisinde satir ve sutun degerinin yerine X yi yaz�l�rr
				    }
			        else{
				        if(i==yemx && j==yemy){    // i sayisi yemx'e j sayisi yemy'e  e�it oldu�u zaman
					        tahta[yemx][yemy]='*'; // tahta dizisinde yemx ve yemy dizisinin yerine * yaz�l�rr
				        }
				
				        else{
			                if(i==0 || i==11){ // 0ile 11 inci sat�rlara '-' karakterini yazar�z
	                    	    tahta[i][j]='-';	
			                }
			                else if(j==0 || j==11){ // 0 ile 11inci sutunlara '|' karakterlerini yazar�z
			                    tahta[i][j]='|';	
			                }
			                else {
				                tahta[i][j]='.'; // 10x10luk k�sma ise '.' karakterrini yazar�z.
			                }
			                
				    	}
			    	} 
		    	}
		    
	       }
	       
	    for(i=0;i<12;i++){
	     	for(j=0;j<12;j++){
			    printf("%c",tahta[i][j]); // burada tahta[12][12] matrisini yazd�r�r
		    }
		    printf("\n");  // \n ile s�ra atlar�z
        }
        
		yemx=yemx;
        yemy=yemy;
          
        scanf("%s",&cevap); // X'i y�lendirmek i�in bir cevap almam�z laz�m 
        	time(&end);
        
        if(cevap=='w'){ // cevap eger w ise sat�r� 1 eksiltiyoruz ve d�ng�y� tekrar d�ng�r�yoruz
    	    satir--;
		}
		
	    if(cevap=='a'){ // cevap eger a ise sutunu  1 eksiltiyoruz ve d�ng�y� tekrar d�ng�r�yoruz
    	    sutun--; 
	    }
	    
	    if(cevap=='s'){ // cevap eger s ise sat�r� 1 art�r�yoruz ve d�ng�y� tekrar d�ng�r�yoruz
    	    satir++;
    	}
    	
	    if(cevap=='d'){ // cevap eger d ise sutunu 1 art�r�yoruz ve d�ng�y� tekrar d�ng�r�yoruz
            sutun++;
	    }
	 
	    if(satir==0 || satir==11 || sutun==0 || sutun==11){ // satir 0 veya 11 ,sutun 0 veya 11 ise bu yanl�� yerde oldugu anlam�na gelir
    	    cevap=tahta[satir][sutun];
    	    deneme--;
		    system("CLS"); // ekran� her defas�nda s�f�rlar
		   goto basla;  // d�ng�y� ba�la k�sm�na al�r
        }                     
	
	    if(satir==yemx && sutun==yemy){ // X in sat�r ve sutunu ,yemin yemx ve yemy'sine esit ise ekrana tebrikler yazar
    		printf("Tebrikler...\n");
    		scanf("%s",&cevap); // cevap ister ona g�re devam eder
    		system("CLS");  // ekran� s�f�rlar
            goto baslangic;   // kodu ba�lang�� k�sm�na al�r
    	
		}
			
	getchar(); // klavyeden al�nan harfi belle�inde tutar ve entera basmay� bekler
	    system("CLS"); //ekran� s�f�rlar
    }
  
    while (cevap!='q' && cevap!='Q' && difftime(end,start)<20); //eger while i�indeki sartlardan biri saglan�rsa kodu bitirir 
        if(cevap=='q' || cevap=='Q'){
        	int i,j;
        	printf("Yilan oyununa hosgeldiniz, hareket icin w a s d tuslarini kullaniniz...\n");
		    for(i=0;i<12;i++){
	     	    for(j=0;j<12;j++){
			    printf("%c",tahta[i][j]); // burada tahta[12][12] matrisini yazd�r�r
		    }
		    printf("\n");  // \n ile s�ra atlar�z
            }
        printf("\nKullanici q veya Q bastigi icin oyun tamamlayamadiniz ...\n");
		}
	    else{
	    	printf("Yilan oyununa hosgeldiniz, hareket icin w a s d tuslarini kullaniniz...\n");
	    	int i,j;
		    for(i=0;i<12;i++){
	     	    for(j=0;j<12;j++){
			    printf("%c",tahta[i][j]); // burada tahta[12][12] matrisini yazd�r�r
		    }
		    printf("\n");  // \n ile s�ra atlar�z
            }
        printf("Oyunu suresinde tamamlayamadiniz...\n");
		}
  
        }
		else{
	    	int i,j;
		    for(i=0;i<12;i++){
	     	    for(j=0;j<12;j++){
			    printf("%c",tahta[i][j]); // burada tahta[12][12] matrisini yazd�r�r
		    }
		    printf("\n");  // \n ile s�ra atlar�z
        }
				 	
	    printf("\nOyun basarisiz 3 hakkinizi doldurdunuz..!\n"); // deneme hakk� bittiyse ekrana oyun bitti basar�s�z yazar ve koddan c�kar
	    scanf("%s",&cevap);
	    system("CLS");
	    goto baslangic;
		}
        
return 0;
}

