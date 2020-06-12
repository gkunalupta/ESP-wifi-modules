
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>
void UART_Init0();
char UART_RxChar0();
void UART_TxChar0(uint16_t data);//unsigned short(0-65535)
void printString0( char *myString);
char rxstring0();
void uart_num0(uint16_t num);
void bit0(uint16_t val);//unsigned short (0-65535)
void decimel0(uint16_t val);
void UART_Init1();
int UART_RxChar1();
char UART_at1(char *str);
void UART_TxChar1(uint8_t data);
void printString1( char *myString);
void printint1(uint16_t myint[]);
char rxstring1();
void uart_num1(uint16_t num);
void bit1(uint16_t val);//unsigned short (0-65535)
void decimel1(uint16_t val);
void UART_Init3();
char UART_RxChar3();
char UART_at3(char *str);
void UART_TxChar3(char data);
void printString3( char *myString);
void printint3(int myint[]);
char rxstring3();
void uart_num3(uint16_t num);
void bit3(uint16_t val);//unsigned short (0-65535)
void decimel3(uint16_t val);
int i=0;
char myValue;
void UART_Init0()
{
	UBRR0L = 103;
	UCSR0B = (1<<TXEN0)|(1<<RXEN0)|(1<<RXCIE0);
	UCSR0C = (1<<UCSZ00)|(1<<UCSZ01);
	//UCSR0A=(1<<U2X0);
}

void UART_TxChar0(uint16_t data)
{
	while((UCSR0A & (1<<UDRE0))==0);
	UDR0 = data;
	
}


char UART_RxChar0()
{   //unsigned char status, resh, resl;
	//status = UCSR0A;
	char pop;
// 	printString0("value of uscra before \n ");
// 	bit0(UCSR0A);
// 	printString0("\n");
	while(!(UCSR0A & (1<<RXC0)));
//     printString0(" \nvalue of ucsra after \n");
// 	bit0(UCSR0A);

// 	printString0("\n");
// 	UDR0=pop;
// 	    printString0("\n");
	return UDR0;
}

//stores the incoming string to buff
char rxstring0(char *buff)
{  int i=0;
	char myValue;
    do 
 {
	// printString0("do \n");

		myValue = UART_RxChar0();
		
// 		    printString0(" \nvalue of ucsra after rec \n");
// 		    bit0(UCSR0A);
//			printString0("\n");
//			printString0(" \nvalue of ucsrb after rec \n");
// 			bit0(UCSR0B);
//			printString0("\n");			
		if(myValue!='>')
     {
		buff[i]=myValue;
		UART_TxChar0(myValue);
		i++;
     }    else
		{
			 buff[i]='\0';
		break;
		}
// 	printString0("5\n");
// 	printString0("value of uscra on \n ");
// 	bit0(UCSR0A);
}while( !(UCSR0A & (1<<RXC0)));

	return myValue;
}

void printString0(char *myString)      /////to print any string
{

	while (*myString)
	{
		UART_TxChar0(*myString++);
	}
}


void uart_num0(uint16_t num)
{
	unsigned char H=0,T=0,O=0;
	H=num/100;
	T=(num - (H*100))/10;
	O=(num - (H*100) - (T*10));
	
	UART_TxChar0(H+48);
	UART_TxChar0(T+48);
	UART_TxChar0(O+48);
	UART_TxChar0(num);
}

void bit0(uint16_t val)
{
	int8_t ptr;
	for(ptr=7;ptr>=0;ptr--)
	{
		if ((val & (1<<ptr))==0)
		{
			UART_TxChar0('0');
		}
		else
		{
			UART_TxChar0('1');
		}
	}
}
// Transmit an unsigned 16 bit value as up to five decimal characters
void decimel0(uint16_t val)
 {
	unsigned char buf[5];
	int8_t ptr;
	for(ptr=0;ptr<5;++ptr) {
		buf[ptr] = (val % 10) + '0';
		val /= 10;
	}
	for(ptr=4;ptr>0;--ptr) {
		if (buf[ptr] != '0') break;
	}
	for(;ptr>=0;--ptr) {
		UART_TxChar0(buf[ptr]);
	}
}

void UART_Init1()  // baudrate =115200
{  //9600-103
	//115200-8
	UBRR1L = 8;
	UCSR1B = (1<<TXEN1)|(1<<RXEN1);
	UCSR1C = (1<<UCSZ10)|(1<<UCSZ11);
		//UCSR1A=(1<<U2X1);
}

void UART_TxChar1(uint8_t data)
{
	while((UCSR1A & (1<<UDRE1))==0);
	UDR1 = data;
	
}


int UART_RxChar1()
{   //unsigned char status, resh, resl;
	//status = UCSR1A;

 	printString0(" UCSR1A value before receiving data   \n");
   bit0(UCSR1A);
  	printString0(" \n");

	while( !(UCSR1A & (1<<RXC1)));
 
   printString0(" UCSR1A value after receiving data  \n");
      bit0(UCSR1A);
 printString0("\n");
	return UDR1;
}

char UART_at1(char *str)
{   
/*	while ((UCSR1A & (1<<RXC1)))
{  	    
			myValue=UDR1;
			str[i]==myValue;
			//UART_TxChar0(myValue);
			i++;
}
*/		
  //char x=2;
	int i=0;
	char value;
	printString0("jk");
	   printString0(" UCSR1A value before receiving data  \n");
	   bit0(UCSR1A);
	   printString0("\n");
	while ((UCSR1A & (1<<RXC1)))
	{
		if((UCSR1A & (1<<DOR1))==0)
		{
			
			   printString0(" UCSR1A value before reading data  \n");
			   bit0(UCSR1A);
			   printString0("\n");
			value=UDR1;
			   printString0(" UCSR1A value after reading data  \n");
			   bit0(UCSR1A);
			   printString0("\n");
			str[i]=value;
			UART_TxChar0(value);
			i++;
		}
		else
		{
			while((UCSR1A & (1<<DOR1)))
			{
				i++;
				NULL==UDR1;
				value=UDR1;
				str[i]=value;
				//UART_TxChar0(value);

			}

		}
		
		   printString0(" UCSR1A value after receiving data  \n");
		   bit0(UCSR1A);
		   printString0("\n");
	}
	return i;
}




void uart_atsir(char* str)
{
	
	char x=0;
	int i=0;
	char value,dvalue;
	//bit3(UCSR1A);
	printString0("jh\n");
	printString0("value of uscra before \n ");
	bit0(UCSR1A);
	while ((UCSR1A & (1<<RXC1)))
	{   x++;
		printString0("kl;\n");
		bit0(UCSR1A);
		if((UCSR1A & (1<<RXC1)))

		{
			value=UDR1;
			str[i]=value;
			value= '\0';
			UDR1=NULL;
			printString0(" Value of USCRA1 on \n ");
			bit0(UCSR1A);
			UART_TxChar0(str[i]);
			i++;
		}
		else
		{
			printString0("testing \n");
			printString0(str);
		    UART_TxChar0(i);
		}
	}
	
}
//stores the incoming string in buff[]
char rxstring1(char *buff)
{  
	do
	{
            //	printString0("1\n");	
// 			printString0("value of uscra before \n ");
// 			bit0(UCSR1A);
		myValue = UART_RxChar1();
// 		printString0("  \n2\n");
// 			printString0("value of uscra after \n ");
// 			bit0(UCSR1A);
		if(myValue!='O')
		{  // printString0("3 \n");
			
			buff[i]=myValue;
			UART_TxChar0(myValue);
			i++;
		
		}    else
		{ 
		//	printString0("4\n");
			buff[i]='\0';
			break;
		}
		
// 		printString0("5\n");
// 			printString0("value of uscra on \n ");
// 			bit0(UCSR1A);
	}
		
	while( !(UCSR1A & (1<<RXC1)));
	//printString0("6\n");
    
	return myValue;
}
void printString1(  char *myString)      /////to print any string
{
	char i = 0;
	while (myString[i])
	{
		UART_TxChar1(myString[i]);
		i++;
	}
}
void printint1(uint16_t myint[])
{
	
		uint16_t i = 0;
		while (myint[i])
		{
			UART_TxChar1(myint[i]);
			i++;
		}
	
}

void uart_num1(unsigned char num)
{
	unsigned char H=0,T=0,O=0;
	H=num/100;
	T=(num - (H*100))/10;
	O=(num - (H*100) - (T*10));
	
	UART_TxChar1(H+48);
	UART_TxChar1(T+48);
	UART_TxChar1(O+48);
	UART_TxChar1(num);
}

void bit1(uint16_t val)
{
	int8_t ptr;
	for(ptr=7;ptr>=0;ptr--)
	{
		if ((val & (1<<ptr))==0)
		{
			UART_TxChar1('0');
		}
		else
		{
			UART_TxChar1('1');
		}
	}
}
void decimel1(uint16_t val) {
	unsigned char buf[5];
	int8_t ptr;
	for(ptr=0;ptr<5;++ptr) {
		buf[ptr] = (val % 10) + '0';
		val /= 10;
	}
	for(ptr=4;ptr>0;--ptr) {
		if (buf[ptr] != '0') break;
	}
	for(;ptr>=0;--ptr) {
		UART_TxChar1(buf[ptr]);
	}
}
void UART_Init3()
{
	UBRR3L = 103;
	UCSR3B = (1<<TXEN3)|(1<<RXEN3);
	UCSR3C = (1<<UCSZ30)|(1<<UCSZ31);
}

void UART_TxChar3(char  data)
{
	while((UCSR3A & (1<<UDRE3))==0);
	UDR3 = data;
	
}


char UART_RxChar3()
{   

	while( !(UCSR3A & (1<<RXC3)));

	return UDR3;
}



char UART_at3(char *str)
{   int x=0;
	int i=0;
	bit3(UCSR3A);
	printString3("\n");
	while( (UCSR3A & (1<<RXC3)))
	{   str[i]=UDR3;
		bit3(UCSR3A);
		printString3("\n");
		x++;
	}
	return x;
}





//stores the incoming string in buff[]
void rxstring3(char *buff)
{  int i=0;
	char myValue;
	do
	{
		//printString3("1\n");
		myValue = UART_RxChar0();
		if(myValue!='>')
		{
			//printString3("2\n");
			buff[i]=myValue;
			 UART_TxChar3(myValue);
			i++;
		}    else
		{
			//printString3("3\n");
			buff[i]='k';
			break;
		}
		//printString3("4\n");
	}while( !(UCSR0A & (1<<RXC0)));
//printString3("5\n");
}

void printint3(int myint[])
{
	
	uint16_t i = 0;
	while (myint[i])
	{
		UART_TxChar3(myint[i]);
		i++;
	}
	
}


void printString3(char *myString)      /////to print any string
{

	while (*myString)
	{
		UART_TxChar3(*myString++);
	}
}


void uart_num3(uint16_t num)
{
	unsigned char H=0,T=0,O=0;
	H=num/100;
	T=(num - (H*100))/10;
	O=(num - (H*100) - (T*10));
	
	UART_TxChar3(H+48);
	UART_TxChar3(T+48);
	UART_TxChar3(O+48);
	UART_TxChar3(num);
}

void bit3(uint16_t val)
{
	int8_t ptr;
	for(ptr=7;ptr>=0;ptr--)
	{
		if ((val & (1<<ptr))==0)
		{
			UART_TxChar3('0');
		}
		else
		{
			UART_TxChar3('1');
		}
	}
}
// Transmit an unsigned 16 bit value as up to five decimal characters
void decimel3(uint16_t val)
{
	unsigned char buf[5];
	int8_t ptr;
	for(ptr=0;ptr<5;++ptr) {
		buf[ptr] = (val % 10) + '0';
		val /= 10;
	}
	for(ptr=4;ptr>0;--ptr) {
		if (buf[ptr] != '0') break;
	}
	for(;ptr>=0;--ptr) {
		UART_TxChar3(buf[ptr]);
	}
}
