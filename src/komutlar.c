///
#define VCC 3.81      //Max ��k�� gerilimi zener diyot ve
#define v_ileri 3.45 //3.52  // 5V vcc degerine g�re 
#define v_geri 1.0   //1.14
#define v_stop 2.0  //2.50
#define v_sag_ileri 2.93 //3.00

//#define duty_max 4000   //1KHz i�in
#define duty_max 8000   //500Hz i�in  
//#define duty_max 16000   //250Hz i�in

const int DUR =0;
const int ILERI =1;
const int GERI =2;
const int SOL =3;
const int SAG =4;
const int SAG_ILERI =5;//�apraz komutlar
const int SAG_GERI =6;
const int SOL_ILERI =7;
const int SOL_GERI =8;

const int SENSOR_OKU =10;

long Vdc_duty(float vdc){
   return (1-(vdc/VCC))*duty_max;
}
void sol_sag_1(float vdc)//Data sheets e g�re 2 nolu pin
{
   set_pwm_duty(1,Vdc_duty(vdc));
}
void ileri_geri_1(float vdc)//Data sheets e g�re 4 nolu pin
{
   set_pwm_duty(2,Vdc_duty(vdc));
}
void ileri_geri_2(float vdc)//Data sheets e g�re 5 nolu pin
{
   set_pwm_duty(3,Vdc_duty(vdc));
}
void merkez_gerilim(float vdc)//Data sheets e g�re 6 nolu pin
{
   set_pwm_duty(4,Vdc_duty(vdc));
}
void sol_sag_2(float vdc)//Data sheets e g�re 7 nolu pin
{
   set_pwm_duty(5,Vdc_duty(vdc));
}
/////
void araba_dur(){
   merkez_gerilim(v_stop); // DS 6 nolu PIN, PIC te PIN_B8 Bacak 17  OC4
   sol_sag_1(v_stop);      // DS 2 nolu PIN, PIC te PIN_B5 Bacak 14  OC1
   sol_sag_2(v_stop);      // DS 7 nolu PIN, PIC te PIN_B9 Bacak 18  OC5
   ileri_geri_1(v_stop);   // DS 4 nolu PIN, PIC te PIN_B6 Bacak 15  OC2
   ileri_geri_2(v_stop);   // DS 5 nolu PIN, PIC te PIN_B7 Bacak 16  OC3
   //fprintf(pc,"DUR...\r");
}
void araba_ileri(){
   sol_sag_1(v_stop);   
   sol_sag_2(v_stop);
   ileri_geri_1(v_ileri);
   ileri_geri_2(v_ileri);
   //fprintf(pc,"ileri...\r");
}
void araba_geri(){
   sol_sag_1(v_stop);
   sol_sag_2(v_stop);
   ileri_geri_1(v_geri);
   ileri_geri_2(v_geri);
   //fprintf(pc,"geri...\r");

}
void araba_sola(){
   sol_sag_1(v_geri);
   sol_sag_2(v_geri);
   ileri_geri_1(v_stop);
   ileri_geri_2(v_stop);
   //fprintf(pc,"sola...\r");
}
void araba_saga(){
   sol_sag_1(v_ileri);
   sol_sag_2(v_ileri);
   ileri_geri_1(v_stop);
   ileri_geri_2(v_stop);
   //fprintf(pc,"saga...\r");
}
//////////////////////////////7
void araba_sag_ileri(){
   sol_sag_1(v_ileri);
   sol_sag_2(v_ileri);
   ileri_geri_1(v_sag_ileri);//*** v_ileri olma olas�l��� y�ksek
   ileri_geri_2(v_sag_ileri);
   //fprintf(pc,"sag ileri...\r");
}
void araba_sag_geri(){
   sol_sag_1(v_ileri);
   sol_sag_2(v_ileri);
   ileri_geri_1(v_geri);
   ileri_geri_2(v_geri);
   //fprintf(pc,"sag geri...\r");
}
void araba_sol_ileri(){
   sol_sag_1(v_geri);
   sol_sag_2(v_geri);
   ileri_geri_1(v_ileri);
   ileri_geri_2(v_ileri);
   //fprintf(pc,"sol ileri...\r");
}
void araba_sol_geri(){
   sol_sag_1(v_geri);
   sol_sag_2(v_geri);
   ileri_geri_1(v_geri);
   ileri_geri_2(v_geri);
   //fprintf(pc,"sol geri...\r");

}
/////
void komut_deneme(){
   araba_ileri(); delay_ms(5000);
   araba_dur();  delay_ms(5000);
   araba_geri();delay_ms(5000);
   araba_dur();delay_ms(5000);
   araba_sola();delay_ms(5000);
   araba_dur();delay_ms(5000);
   araba_saga();delay_ms(5000);
   araba_dur();delay_ms(5000);
   
   araba_dur();  delay_ms(5000);
   araba_sag_ileri();delay_ms(5000);
   araba_dur();  delay_ms(5000);
   araba_sag_geri();delay_ms(5000);
   araba_dur();  delay_ms(5000);
   araba_sol_ileri();delay_ms(5000);
   araba_dur();  delay_ms(5000);
   araba_sol_geri();delay_ms(5000);
}
