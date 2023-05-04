#pragma once 

#include <iostream>
using namespace std;
class Client
{   
    private:

        char statusOfClient;
        int arrivedTime;
        int transactionTime;
    public:
        Client();
        Client(char, int , int);
        Client(const Client &_aClient);
        ~Client();
        void setArrivalTime(int );
        void setTransTime(int );
        void setStatus(char );
        char getStatus() const;
        int getTransTime() const;
        int getArrival() const;
        bool operator!=(const Client &) const;
        bool operator>(const Client &) const;
        bool operator<(const Client &) const;
        friend ostream &operator<<(ostream &output, const Client &);
};

Client::Client() : statusOfClient('D'), arrivedTime(-1), transactionTime(-1)
{}
Client::Client(const Client &_aClient)
{
    setStatus(_aClient.getStatus());
    setArrivalTime(_aClient.getArrival());
    setTransTime(_aClient.getTransTime());
}
Client::Client(char status, int arrived, int transTime)
{
    setStatus(status);
    setArrivalTime(arrived);
    setTransTime(transTime);
}
Client::~Client()
{}

inline void Client::setArrivalTime(int arrivalTime)
{
    arrivedTime = arrivalTime;
}

inline void Client::setTransTime(int transTime)
{
    transactionTime = transTime;
}

inline void Client::setStatus(char clientStatus)
{
    statusOfClient = clientStatus;
}

inline char Client::getStatus() const
{
    return statusOfClient;
}

inline int Client::getTransTime() const
{
    return transactionTime;
}

inline int Client::getArrival() const
{
    return arrivedTime;
}

inline bool Client::operator!=(const Client &_aClient) const
{
    return (statusOfClient != _aClient.getStatus()) && (arrivedTime != _aClient.getArrival()) && (transactionTime != _aClient.getTransTime());
}

inline bool Client::operator>(const Client &_aClient) const
{
    return arrivedTime > _aClient.getArrival();
}

inline bool Client::operator<(const Client &_aClient) const
{
    return arrivedTime < _aClient.getArrival();
}

ostream &operator<<(ostream &output, const Client &aClient)
{
    
    output <<  aClient.getTransTime() << endl;

    return output;
}