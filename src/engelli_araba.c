#include <engelli_araba.h>
#include <string.h>
#include <INPUT.C>

#USE STANDARD_IO(A)


int komut=-1;
unsigned long duty=100,value=0;
float v=0,vadc;

#include "hc_sr_04.c"
#include "komutlar.c"
#include "kesmeler.c"

void main()
{
   setup_spi( FALSE );
   setup_spi2( FALSE );
   setup_wdt(WDT_OFF);
   
   setup_timer1(TMR_INTERNAL | TMR_DIV_BY_8,0xFFFF);
   // 1:8 Prescare value, Fcy=8MHz/2=4MHz=0.25us, 1:8= 0.25*8 = 2us
   //setup_timer1(TMR_INTERNAL | TMR_DIV_BY_1);
   // 1:1 Prescare value, Fcy=8MHz/2=4MHz=0.25us,
  
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports(sAN0||sAN12||sAN11||sAN10||sAN9,VSS_VDD);//0-3.3V arasý olçüm
  //  setup_adc_ports(sAN1||sAN12||sAN11||sAN10||sAN9,VSS_VREF );//AN VDD ve VSS yok o yüzden çalýþmaz
  
   //setup_timer2(TMR_INTERNAL | TMR_DIV_BY_1,4000);//1KHz PWM
   setup_timer2(TMR_INTERNAL | TMR_DIV_BY_1,8000);//500Hz PWM
   //setup_timer2(TMR_INTERNAL | TMR_DIV_BY_1,16000);//250Hz PWM
   setup_compare(1, COMPARE_PWM | COMPARE_TIMER2);  //  sol-sað 1    PIN 2
   setup_compare(2, COMPARE_PWM | COMPARE_TIMER2);  //  ileri-geri 1 PIN 4 
   setup_compare(3, COMPARE_PWM | COMPARE_TIMER2);  //  ileri-geri 2 PIN 5
   setup_compare(4, COMPARE_PWM | COMPARE_TIMER2);  //  VCC/2        PIN 6
   setup_compare(5, COMPARE_PWM | COMPARE_TIMER2);  //  sol-sað 2    PIN 7
   //set_pwm_duty(1,3900);

   fprintf(pc, " >>-.-.-.-. --> \r" );delay_ms(200);
   fprintf(pc, " Sistem basladi... \r" );
   
   set_adc_channel(0);
   
   clear_interrupt(int_rda);
   enable_interrupts(INT_RDA);
   enable_interrupts(INTR_CN_PIN | PIN_A2);
   enable_interrupts(INTR_GLOBAL);
   
   araba_dur();
   delay_ms(500);
   while(true){
     value = read_adc();
     delay_ms(10);
     v=(3.3f/1023)*value;
     //uzaklik_olc();
     uzaklik=cni_uzaklik_olc();
     if(uzaklik<49.0) araba_dur();
     
     fprintf(pc, "->K=%d <> SEN=> V=%1.3f  U=%3.1f \r"komut ,v,uzaklik);
    // fprintf(pc, "KOMUT: %d <> SENSOR V=%1.3f \r"komut ,v);
     delay_ms(100);
     komut=komut_al();
     switch(komut){
         case ILERI:
            araba_ileri();
         break;
         case GERI:
            araba_geri();
         break;
         case DUR:
          araba_dur();
         break;
         case SAG:
            araba_saga();
         break;
         case SOL:
            araba_sola();
         break;
         case SAG_ILERI:
            araba_sag_ileri();
         break;
         case SAG_GERI:
            araba_sag_geri();
         break;
         case SOL_ILERI:
            araba_sol_ileri();
         break;
         case SOL_GERI:
            araba_sol_geri();
         break;
         case DONANIM:
            delay_ms(1000);
            fprintf(pc, "DANANIM: Baðlandý...");
         break;
         case SENSOR_OKU:
            v=(3.3f/1023)*value;
            fprintf(pc, "SENSOR V=%1.3f",v);
            delay_ms(1000);
         break;
         default:
           // araba_dur();
           //komut=-1;
            break;
      }
      
     
 }//while(1)

}//main

///////////////////////////////////////7
   //value = read_adc();
     //v=(3.3f/1023)*value;
     //fprintf(pc, "Olcum %lu: ADC deger =%lu >> V= %1.2f\r",test++,value,v);
     //fprintf(pc, "Vdc icin DUTY: %lu",Vdc_duty(2.5));
    
    // fputc(13,pc);
    // fputc(test++,pc);
      //duty+=100;
      //if(duty>3850)duty=100;
      /*
      v+=0.1;
      set_pwm_duty(1,Vdc_duty(3.52f));
      delay_ms(5000);
      set_pwm_duty(1,Vdc_duty(2.3f));
      delay_ms(5000);
      set_pwm_duty(1,Vdc_duty(1.1f));
      delay_ms(5000);*/
      //
     //
      //fprintf(pc, "test:%lu V=%1.2f\r",test++,v);
      //set_pwm_duty(1,4000-duty); 
