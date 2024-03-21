#pragma once
#include "fio.h"
#include "email.h"
#include "job.h"
#include "messenger.h"
#include "phone.h"
#include "social.h"

typedef struct Contact
{
    int id;
    FIO fio;
    Job job;
    Phone phone[5];
    Email email[5];
    Social socials[5];
    Messenger messengers[5];
}Contact;

void add(Contact *contact);
void change(Contact *contact);
void remove(Contact *contact);