#include <unistd.h>
#include <sys/types.h>
//#include <stdio.h>
#include <fcntl.h>   /* File control definitions */
//#include <errno.h>   /* Error number definitions */
#include <termios.h>
#include <pthread.h>


#ifndef _RFT_COM_H_
#define _RFT_COM_H_

#include "RFT_IF_PACKET_Rev1.2.h" // RFT F/T SENSOR DATA FIELD & UART PACKET HANDLING SOURCE

/*
see termbits.h file
#define  B0	  
#define  B50	
#define  B75	
#define  B110	
#define  B134	
#define  B150	
#define  B200	
#define  B300	
#define  B600	
#define  B1200
#define  B1800
#define  B2400
#define  B4800
#define  B9600
#define  B19200
#define  B38400
#define  B57600  
#define  B115200 
#define  B230400 
#define  B460800 
#define  B500000 
#define  B576000 
#define  B921600 
#define  B1000000
#define  B1152000
#define  B1500000
#define  B2000000
#define  B2500000
#define  B3000000
#define  B3500000
#define  B4000000

#define CSIZE
#define CS5
#define CS6
#define CS7
#define CS8
#define CSTOPB
#define CREAD	
#define PARENB
#define PARODD
#define HUPCL	
#define CLOCAL
#define CBAUDEX

*/
// Flow control flags
#define FC_DTRDSR       0x01
#define FC_RTSCTS       0x02
/* REMOVE Software Flow Control
#define FC_XONXOFF      0x04
*/
#define FC_NONE         0x00

// ascii definitions
#define ASCII_BEL       0x07
#define ASCII_BS        0x08
#define ASCII_LF        0x0A
#define ASCII_CR        0x0D
#define	ASCII_XON		    0x11
#define	ASCII_XOFF		  0x13

#define RFT_UART_TX_BUFF_SIZE (1024)
#define RFT_UART_RX_BUFF_SIZE (1024*4)


#define BUFF_SIZE (1024)
	
class CRT_RFT_UART
{

public:
	CRT_RFT_UART( void );
	~CRT_RFT_UART( void );

	// EXTERNAL INTERFACE FUNCTIONS
	bool openPort( char *devName, int rate = B115200, int bByteSize = CS8 );
	bool closePort( void );
	bool isConnected( void );


	bool writeBuffer( unsigned char* lpBuffer, int bytesToWrite, int *bytesWritten );

	bool readWorker( void );         // read worker.

  
	////////////////////////////////////////////////////////////////////////////////////////////
	// FOR RFT INTERFACE
	CRT_RFT_IF_PACKET m_RFT_IF_PACKET;	// data field & uart packet handling class
	
	bool rqst_ProductName(void);		// read product name
	bool rqst_SerialNumber(void);		// read serial number
	bool rqst_Firmwareverion(void);		// read firmware version
	bool rqst_CommSpeed(void);			// read baud-rate
	bool rqst_FT_Filter_Type(void);		// read filter type
	bool rqst_FT(void);					// read force/torque (once)
	bool rqst_FT_Continuous(void);		// start force/torque continuous output 
	bool rqst_FT_Stop(void);			// stop force/torque continuous output
	bool rqst_FT_Cont_Interval(void);   // read force/torque output frq.
	bool rqst_FT_OverloadCnt(void);		// read overload count

	bool set_Comm_Speed(int comm_speed);						// set baud-rate
	bool set_FT_Filter_Type(int filter_type, int sub_type);		// set filter
	bool set_FT_Cont_Interval(int interval);					// set force/torque output frq.
	bool set_FT_Bias(int is_on);								// set bias

	int m_nCurrMode;					// current operation mode or command type
	bool m_bIsRcvd_Response_Pkt;		// receive flag for response packet of current command

	bool RFT_Data_Handler(void);		// receive packet handler

	bool rcvd_ProduectName(void);		// check function for response of read product name command
	bool rcvd_SerialNumber(void);		// check function for response of read serial number command
	bool rcvd_Firmwareversion(void);	// check function for response of read firmware version command
	bool rcvd_CommSpeed(void);			// check function for response of read baud-rate command
	bool rcvd_FT_Filter_Type(void);		// check function for response of read filter type command
	bool rcvd_FT(void);					// check function for response of read force/torque command
	bool rcvd_FT_Cont_Interval(void);	// check function for response of read force/torque output frq. command
	bool rcvd_FT_Overload_Count(void);	// check function for response of read overload count command
    
	bool rcvd_Response_Set_Comm_Speed(void);		// check function for response of set baud-rate command
	bool rcvd_Response_Set_FT_Filter_Type(void);	// check function for response of set filter type command
	bool rcvd_Response_Set_FT_Cont_Interval(void);	// check function for response of set force/torque output frq. command
  
protected:
	
	void initialize_variables(void);

	bool m_bConnected;		        // Open/Closed indicating flag
  
 	int  m_nRcvdBufferIdx;
	unsigned char m_rcvdBuff[RFT_UART_RX_BUFF_SIZE];
	unsigned char m_txBuff[RFT_UART_TX_BUFF_SIZE]; 
	
  // INTERNAL USE ONLY
	bool createComPort(char *devName );
	bool setupConnection(int dwBaudrate, int bByteSize );
	bool createDataEvent(void);

private:
	int fd; // COM port... file description

};

#endif//_RFT_COM_H_
//////////////////////////////////////////////////////////////////////////////
// END OF FILE

