#pragma once

#include <stdint.h>

typedef struct 
{
    uint16_t transactionId;     // 2 byte hex number
    uint16_t flags;             // 16 bits of control flags
    /*
        bit     function
        0       Response marker
        1-4     Op code
        5       authoritative server 
        6       truncated marker
        7       recursion desired 
        8       recursion available
        9       Z: reserved
        10      answer authenticated (DNSSEC)
        11      accept non-authenticated (DNSSEC)
        12-15   Replay Code: No error (0)
    */
    uint16_t questionCount;     // 2 byte uints
    uint16_t answerCount;       // "
    uint16_t authorityCount;    // "
    uint16_t additionalCount;   // "

    // Query section
    char* dnsName;
    uint16_t queryType;         // 2 byte uint
    uint16_t queryClass;        // "

    // Answers section
    char* domainName;
    uint16_t dataType;
    uint16_t dataClass;
    uint32_t timeToLive;
    uint16_t dataLength;
    char* resourceData;

    // Authoritative nameservers
    // ...

    // Additional Records
    // ...

} DNS_QUERY;