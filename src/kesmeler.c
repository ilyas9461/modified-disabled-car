char seri_buf[250];
const int DONANIM =100;

void get_bilgi() {
   char c;
   unsigned int8  i=0;
   while(kbhit(pc)){
      c=fgetc(pc);
      seri_buf[i]=c;
      i++;
  }  
}

/////
void dizi_sil(char *dizi){
   int i=0;
   for(i=0;i<strlen(dizi);i++) 
      if(dizi[i]!=0)dizi[i]=0;
}
int komut_al(){
   int komut_kodu=-1;
   if((seri_buf[0]=='*')){
      komut_kodu=((seri_buf[1]-48)*100+(seri_buf[2]-48)*10+(seri_buf[3]-48));
      if((seri_buf[4]=='#')){
         //fprintf(pc, "KOMUT:%u \r",komut_kodu );
         //delay_ms(200);
         return komut_kodu;
      }else return -1;
      
   }else return -1;
}   
////
#int_RDA FAST //level=1
void  RDA_isr(void) 
{
   fgets(seri_buf,pc);
   
   //dizi_sil(seri_buf);
   clear_interrupt(int_rda);
   //enable_interrupts(int_RDA);
}


