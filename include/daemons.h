//Cracked by Roath
/*
// File		:  /include/daemons.h
// Purpose	:  Mudlib Daemon Macro defines
//		   These are included by objects and used to call or inherit
//		   the daemon rather than the explicit name for two reasons:
//		   a) The define is generally shorter and stands out.
//		   b) Helps with compatibility and changing the daemons place
*/
#ifndef __DAEMONS_H
#define __DAEMONS_H
 
#define ANNOUNCE		"/adm/daemons/announce"
#define APROPOS_D		"/adm/daemons/aproposd"
#define BANISH_D		"/adm/daemons/banish"
//#define CHANNELS_D		"/adm/daemons/channels"
#define CLEAN_D			"/adm/daemons/clean_dir"
#define CMD_D			"/adm/daemons/cmd_d"
#define DOC_D			"/adm/daemons/doc_d"
#define DOMAIN_D			"/adm/daemons/domain"
#define EMOTE_D 			"/adm/daemons/emoted"
#define EVENT 			"/adm/daemons/event"
#define FINGER_D		"/adm/daemons/finger"
#define FLOCK_D                 "/adm/daemons/flock"
#define GA_SERVER_D             "/adm/daemons/ga_server"
#define I3_D			"/adm/daemons/network/I3"
#define LANGUAGE_D		"/adm/daemons/language"
#define LOGIN_D			"/adm/daemons/logind"
#define MAILER_D		"/adm/daemons/mailbox"
//#define MAIL_SERV		"/adm/daemons/network/mail_serv"
#define MAN_D			"/adm/daemons/mand"
#define MSG_D			"/adm/daemons/news"
#define NEWS_D			"/adm/daemons/news_server"
#define NEWUSER_D		"/adm/daemons/newuserd"
#define PARTY_D			"/adm/daemons/party_d"
#define PROMOTION_D		"/adm/daemons/wizmakerd"
#define PRUNE_LOGDIR_D		"/adm/daemons/prune_logdir"
#define PURGE_D			"/adm/daemons/purge"
#define QUOTA			"/adm/daemons/quota"
#define REF_D			"/adm/daemons/ref_d"
#define SHUTDOWN_D		"/adm/daemons/shutdownd"
#define STUDENT_D		"/adm/daemons/studentd"
#define TERMINAL_D              "/adm/daemons/terminal"
#define TIME_D			"/adm/daemons/timezone"
#define USAGE_D			"/adm/daemons/usage_d"
#define USE_R_D			"/adm/daemons/use_remove"
#define VIRTUAL_D		"/adm/daemons/virtual_d"
#define WEATHER_D		"/adm/daemons/weather_d"
#define WHATIS_D		"/adm/daemons/whatisd"

#define SAVE_D 	"/std/save"
#endif //__DAEMONS_H
