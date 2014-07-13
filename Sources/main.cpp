/*
#include "mbed.h"

DigitalOut myled(LED1);

int main() {
    while(1) {
        myled = 1;
        wait(0.2);
        myled = 0;
        wait(0.2);
    }
}


#include "mbed.h"
#include "rtos.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);

void led2_thread(void const *args) {
    while (true) {
        led2 = !led2;
        Thread::wait(1000);
    }
}

int main() {
    Thread thread(led2_thread);

    while (true) {
        led1 = !led1;
        Thread::wait(250);
    }
}

*/

#include "mbed.h"
#include "EthernetInterface.h"
const char* SERVER_ADDRESS = "10.0.0.77";
const int SERVER_PORT = 1337;
const bool CHECK_RESPONSE = true;

int main()
{
    EthernetInterface eth; // declare interface
    eth.init(); // initialize interface to use DHCP
    eth.connect(); // connect interface
    printf("\n\rIP Address aquired: %s\n\r", eth.getIPAddress()); // display IP address
    TCPSocketConnection client; // set up a client socket
    client.set_blocking(false,100); // limit client to a 10ms wait for response
    if(!client.connect(SERVER_ADDRESS, SERVER_PORT)) // connect to server
    {
        printf ("Connected to Server\n\r");
        char message[] = "GET / HTTP/1.1\r\nHost: 10.0.0.77:1337\r\n\r\n";
        char response[256];
        int bytes_sent;
        int bytes_received;
        int loop;
        for (loop=0;loop<100;loop++)
        {
            // send data
            bytes_sent = client.send_all(message, strlen(message));
            printf("Sent: %d '%s' (Bytes: %d)\n\r",loop,message,bytes_sent);
            // check for received data
            if(CHECK_RESPONSE)
            {
                bytes_received = client.receive(response, 256);
                if (bytes_received!=-1)
                {
                    response[bytes_received] = '\0';
                    printf("Received: '%s' (Bytes: %d)\n\r",response, bytes_received);
                }
            }
        }
    }
    else
    {
        printf("Unable to connect to server\n\r");
    }
    printf("Finished\n");
}
