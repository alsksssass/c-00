// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once                // 이 헤더 파일이 중복 포함되는 것을 방지하기 위한 pragma once 지시문
#ifndef __ACCOUNT_H__       // 헤더 파일 내용이 아래 ifndef와 #endif로 감싸여 있으므로 중복 포함 방지
#define __ACCOUNT_H__       // 헤더 파일 내용이 아래 ifndef와 #endif로 감싸여 있으므로 중복 포함 방지

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {             // Account 클래스 정의

public:
    typedef Account t;     // Account 클래스의 별칭 정의

    // 정적 멤버 함수들 선언
    
    static int getTotalAmount();         // 전체 계좌 잔액 합 반환
    static int getNbDeposits();         // 전체 예금 횟수 반환
    static int getNbWithdrawals();       // 전체 출금 횟수 반환
    static void displayAccountsInfos();  // 모든 계좌 정보 출력

    // 생성자 및 소멸자 선언
    Account(int initial_deposit);       // 초기 예금을 받는 생성자
    ~Account();                          // 소멸자

    // 멤버 함수들 선언
    void makeDeposit(int deposit);      // 예금을 처리하는 함수
    bool makeWithdrawal(int withdrawal);  // 출금을 처리하는 함수
    int checkAmount() const;            // 현재 계좌 잔액 반환
    void displayStatus() const;         // 계좌 상태를 출력하는 함수

private:
    // 정적 멤버 변수들
    static int _nbAccounts;             // 생성된 계좌 수
    static int _totalAmount;            // 전체 계좌 잔액 합
    static int _totalNbDeposits;        // 전체 예금 횟수
    static int _totalNbWithdrawals;     // 전체 출금 횟수

    // 정적 멤버 함수
    static void _displayTimestamp();    // 타임스탬프를 출력하는 정적 멤버 함수

    // 인스턴스 멤버 변수들
    int _accountIndex;                  // 계좌 인덱스
    int _amount;                        // 계좌 잔액
    int _nbDeposits;                    // 예금 횟수
    int _nbWithdrawals;                 // 출금 횟수

    // 기본 생성자는 private로 선언하여 외부에서 생성할 수 없도록 함
    Account();                          // 기본 생성자

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */              // 헤더 파일의 끝을 나타내는 endif 지시문
