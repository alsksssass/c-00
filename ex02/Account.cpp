#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;        // 전체 예금 횟수
int Account::_totalNbWithdrawals = 0; 
Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_nbAccounts  += 1;
	_totalAmount += initial_deposit;     // 생성된 계좌 수 
	_accountIndex = _nbAccounts -1;                  // 계좌 인덱스
    _amount += initial_deposit;                        // 계좌 잔액
    _nbDeposits = 0;
    _nbWithdrawals = 0;
	std::cout << "index:"  << _accountIndex;
	std::cout << ";amount:" << checkAmount() << ";created" << std::endl;
	//index:0;amount:42;created
}

int Account::getTotalAmount(void){
	return _totalAmount;
}

int Account::getNbDeposits(void){
	return _totalNbDeposits;	
}
int Account::getNbWithdrawals(void){
	return _totalNbWithdrawals;
}
void Account::displayAccountsInfos(void){
	_displayTimestamp();
	std::cout << "accounts:"  << _nbAccounts;
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
	//accounts:8;total:21524;deposits:8;withdrawals:0}
}
void Account::makeDeposit(int deposit){
	_displayTimestamp();
	std::cout <<"index:" << this->_accountIndex;
	std::cout <<";p_amount:" << checkAmount();
	this->_amount +=deposit;
	std::cout <<";deposit:" << deposit;
	std::cout <<";amount:" << checkAmount();
	this->_totalAmount += deposit;
	this->_nbDeposits += 1;
	_totalNbDeposits +=1;
	std::cout <<";nb_deposits:" << this->_nbDeposits << std:: endl;
	//index:1;p_amount:54;deposit:765;amount:819;nb_deposits:1
}
bool Account::makeWithdrawal(int withdrawal){
	_displayTimestamp();
	std::cout <<"index:" << this->_accountIndex;
	std::cout <<";p_amount:" << checkAmount();
	if(this->_amount < withdrawal)
	{
		std::cout <<";withdrawal:refused" << std::endl;
		return false;
	}
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals += 1;
	std::cout <<";withdrawal:" << withdrawal;
	this->_amount -= withdrawal;
	_totalNbWithdrawals += 1;
	std::cout <<";amount:" << checkAmount();
	std::cout <<";nb_withdrawals:" << this->_nbWithdrawals << std:: endl;
	return true;
	//index:4;p_amount:1321;withdrawal:76;amount:1245;nb_withdrawals:1
}
int Account::checkAmount() const{
	return this->_amount;
}
void Account::displayStatus() const{
	_displayTimestamp();
	std::cout <<"index:" << this->_accountIndex;
	std::cout <<";amount:" << checkAmount();
	std::cout <<";deposits:" << this->_nbDeposits;
	std::cout <<";withdrawals:" << this->_nbWithdrawals << std:: endl;
	//index:4;amount:1234;deposits:0;withdrawals:0
};         // 계좌 상태를 출력하는 함수
void Account::_displayTimestamp(void){
	time_t now = time(0);
	struct tm *time = localtime(&now);
    char buffer[80];

    strftime(buffer, 80, "[%Y%m%d-%H%M%S] ", time);

    // 현재 시간을 문자열로 변환하여 출력
    std::cout << buffer ;
}
Account::~Account(){
	_displayTimestamp();
	std::cout <<"index:" << this->_accountIndex;
	std::cout <<";amount:" << checkAmount() << ";closed" <<std::endl;
	//index:0;amount:47;closed
}