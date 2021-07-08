#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // rand fonksiyonunu kullanmak için tanýmladýðým bir kütüphane
#include <conio.h>  
  
	/*  YILAN OYUNU  */
int main(){
	char tahta[12][12],cevap;  // '.', '|' bir karakter oldugu icin char tipinde bi dizi tanýmladým aldýgým cevapta bir karakter 
	int yemx,yemy; 
    time_t start,end;
		int satir,sutun; // X in baslamasý gereken satýr ve sutunlarý tanýmladý 
	baslangic:
	time(&start);
	srand(time(NULL));  // her defasýnda yemi farkli yerlere atmasý icin srand ý kullandýmm
	yemx=rand()%9+1;    // rand fonsiyonu ile yemx ve yemy nin 1 ile 10 arasnda bir sayý üretir 
	yemy=rand()%9+1;
    int deneme=3; // oyunda 3 deneme hakkýmýz bulunmaktadýr
        basla:
   	
   		satir=1;sutun=2;
       	if(deneme>0){ // deneme 0 dan buyuk oldugu surece dönder
        	do{  
    		int i,j;	
		    printf("Yilan oyununa hosgeldiniz, hareket icin w a s d tuslarini kullaniniz...\n");
	        for(i=0;i<12;i++){  // for döngüsü satir sayýsýný ifade eder ve 12 defa döner
		        for(j=0;j<12;j++){ // 2.for döngüsü sutun sayýsýn ifade eder ve 12 defa döner
			        if(i==satir && j==sutun){    // satir sayisi i ye sutun sayisi j ye eþit olduðu zaman
				        tahta[satir][sutun]='X'; // tahta dizisinde satir ve sutun degerinin yerine X yi yazýlýrr
				    }
			        else{
				        if(i==yemx && j==yemy){    // i sayisi yemx'e j sayisi yemy'e  eþit olduðu zaman
					        tahta[yemx][yemy]='*'; // tahta dizisinde yemx ve yemy dizisinin yerine * yazýlýrr
				        }
				
				        else{
			                if(i==0 || i==11){ // 0ile 11 inci satýrlara '-' karakterini yazarýz
	                    	    tahta[i][j]='-';	
			                }
			                else if(j==0 || j==11){ // 0 ile 11inci sutunlara '|' karakterlerini yazarýz
			                    tahta[i][j]='|';	
			                }
			                else {
				                tahta[i][j]='.'; // 10x10luk kýsma ise '.' karakterrini yazarýz.
			                }
			                
				    	}
			    	} 
		    	}
		    
	       }
	       
	    for(i=0;i<12;i++){
	     	for(j=0;j<12;j++){
			    printf("%c",tahta[i][j]); // burada tahta[12][12] matrisini yazdýrýr
		    }
		    printf("\n");  // \n ile sýra atlarýz
        }
        
		yemx=yemx;
        yemy=yemy;
          
        scanf("%s",&cevap); // X'i yölendirmek için bir cevap almamýz lazým 
        	time(&end);
        
        if(cevap=='w'){ // cevap eger w ise satýrý 1 eksiltiyoruz ve döngüyü tekrar döngürüyoruz
    	    satir--;
		}
		
	    if(cevap=='a'){ // cevap eger a ise sutunu  1 eksiltiyoruz ve döngüyü tekrar döngürüyoruz
    	    sutun--; 
	    }
	    
	    if(cevap=='s'){ // cevap eger s ise satýrý 1 artýrýyoruz ve döngüyü tekrar döngürüyoruz
    	    satir++;
    	}
    	
	    if(cevap=='d'){ // cevap eger d ise sutunu 1 artýrýyoruz ve döngüyü tekrar döngürüyoruz
            sutun++;
	    }
	 
	    if(satir==0 || satir==11 || sutun==0 || sutun==11){ // satir 0 veya 11 ,sutun 0 veya 11 ise bu yanlýþ yerde oldugu anlamýna gelir
    	    cevap=tahta[satir][sutun];
    	    deneme--;
		    system("CLS"); // ekraný her defasýnda sýfýrlar
		   goto basla;  // döngüyü baþla kýsmýna alýr
        }                     
	
	    if(satir==yemx && sutun==yemy){ // X in satýr ve sutunu ,yemin yemx ve yemy'sine esit ise ekrana tebrikler yazar
    		printf("Tebrikler...\n");
    		scanf("%s",&cevap); // cevap ister ona göre devam eder
    		system("CLS");  // ekraný sýfýrlar
            goto baslangic;   // kodu baþlangýç kýsmýna alýr
    	
		}
			
	getchar(); // klavyeden alýnan harfi belleðinde tutar ve entera basmayý bekler
	    system("CLS"); //ekraný sýfýrlar
    }
  
    while (cevap!='q' && cevap!='Q' && difftime(end,start)<20); //eger while içindeki sartlardan biri saglanýrsa kodu bitirir 
        if(cevap=='q' || cevap=='Q'){
        	int i,j;
        	printf("Yilan oyununa hosgeldiniz, hareket icin w a s d tuslarini kullaniniz...\n");
		    for(i=0;i<12;i++){
	     	    for(j=0;j<12;j++){
			    printf("%c",tahta[i][j]); // burada tahta[12][12] matrisini yazdýrýr
		    }
		    printf("\n");  // \n ile sýra atlarýz
            }
        printf("\nKullanici q veya Q bastigi icin oyun tamamlayamadiniz ...\n");
		}
	    else{
	    	printf("Yilan oyununa hosgeldiniz, hareket icin w a s d tuslarini kullaniniz...\n");
	    	int i,j;
		    for(i=0;i<12;i++){
	     	    for(j=0;j<12;j++){
			    printf("%c",tahta[i][j]); // burada tahta[12][12] matrisini yazdýrýr
		    }
		    printf("\n");  // \n ile sýra atlarýz
            }
        printf("Oyunu suresinde tamamlayamadiniz...\n");
		}
  
        }
		else{
	    	int i,j;
		    for(i=0;i<12;i++){
	     	    for(j=0;j<12;j++){
			    printf("%c",tahta[i][j]); // burada tahta[12][12] matrisini yazdýrýr
		    }
		    printf("\n");  // \n ile sýra atlarýz
        }
				 	
	    printf("\nOyun basarisiz 3 hakkinizi doldurdunuz..!\n"); // deneme hakký bittiyse ekrana oyun bitti basarýsýz yazar ve koddan cýkar
	    scanf("%s",&cevap);
	    system("CLS");
	    goto baslangic;
		}
        
return 0;
}

