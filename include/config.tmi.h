//Cracked by Roath
 
//   File  :  /include/config.h
//
//   This include file controls the major macro defines for 
//   the mudlib's base systems.
 
#ifndef __CONFIG_H
#define __CONFIG_H
 
#define __TMI
#ifdef __TMI
#define NO_PKILL
#endif

//  The base distribution mudlib name.  
//  This identifies the core mudlib, not the mud.  If you hack on the lib,
//  it's still TMI-2 based.  To set your mud name, edit the driver config file.
#define MUDLIB_NAME		"TMI-2"
#define MUDLIB_VERSION_NUMBER	"1.4alpha"
#define MUDLIB_VERSION		(MUDLIB_NAME + " " + MUDLIB_VERSION_NUMBER)
 
// This is included for people who write code on different muds, and want
// to make it portable.  To see if they are on a tmi-type mud they can
// check #ifdef __tmi__, or for versions, #if __tmi__ > 1.0
#define __tmi__ 1.3

//  Directory path defines
 
#define PDATA_DIR	"/data/std/connection/"		
#define CDATA_DIR	"/data/std/user"
#define DATA_DIR	"/data"
#define CONFIG_DIR	"/adm/etc/"
#define SECURE_DIR	"/adm/"
#define HOME_DIRS	"/u/"
#define STUDENT_DIR	"/student/"
#define LOG_DIR		"/log/"
#define NEWS_DIR 	"/adm/news/"
#define TMP_DIR		"/tmp/"
#define OPEN_DIR	"/open/"
#define HELP_DIR	"/doc/help/"
#define WIZH_DIR	"/doc/wizhelp/"
#define PROPH_DIR	"/doc/properties/"
#define ARCHIVE_DIR	"/data/attic/"
#define SIMUL_EFUN_DIR	"/adm/simul_efun/"
 
//  System objects
 
#define USER_OB		"/std/user"
#define CONNECTION	"/std/connection"
#define MASTER_OB	master()
// These functions are both handled by the master object in the TMI lib
#define GROUP_OB	MASTER_OB
#define ACCESS_OB	MASTER_OB
#define SIMUL_EFUN_OB	"/adm/obj/simul_efun"
 
//  User command locations
 
#define WIZ_CMDS 	"/cmds/wiz"
#define WIZX_CMDS  "/cmds/xtra"
#define WIZF_CMDS 	"/cmds/file"
#define USER_CMDS 	"/cmds/std"
#define ADM_CMDS 	"/cmds/adm"
#define CHAN_CMDS	"/cmds/channels"
#define OBJ_CMDS 	"/cmds/object"
#define GHOST_CMDS	"/cmds/ghost"

// NEW_WIZ_PATH is used by /cmds/adm/_makewiz.c and /adm/daemons/wizmakerd.c
// You may want to change this so new wizards don't get WIZX_CMDS
#define NEW_WIZ_PATH \
  USER_CMDS + ":" + OBJ_CMDS + ":" \
  WIZX_CMDS + ":" + WIZF_CMDS + ":" + WIZ_CMDS
 
//  Important global mudlib information
 
#define THIS_MUD 	lower_case(implode(explode(mud_name(), " "), "."))
#define ADMIN_EMAIL	"paul@via.nl or tmi2@cam037103.student.utwente.bl"
 
//  The AUTO_WIZHOOD define causes all those to login as new users to be
//  granted automatic wizship, and given the PATH in the define.
 
#define AUTO_WIZHOOD
 
 
// The SAFETY_SHUTDOWN define allows an admin to type "shutdown" at
// the "Press ENTER to continue" prompt and shut the game down. This
// permits you to unwedge the MUD when something is blocking commands, but
// will be destroyed if the game is restarted.

#define SAFETY_SHUTDOWN	"yeah!"

//  Defines for TMI's student base system
 
#define MAX_STUDENT_NUM		20
#define STUDENT_TIME_PERIOD	(30 * 86400)
#define SAVE_FILES_PERIOD	(7 * 86400)
 
 
//  Mudlib definable locations
 
#define START		"/d/TMI/rooms/quad"
#define VOID		"/d/std/void"

// Note: some people may dislike the block_attack() system during combat...
// partly because it's inconsistently used (eg in 'say', but not in 'shout')
// in the mudlib, or because some players dislike this "feature".  *grin*
// If this applies to you (the sysadmin), #undef the next line
#define BLOCK_ATTACK

// You can make player killing conditional on both players having
// the "no_attack" property set to zero or nonexistent.  This is
// what we have at TMI.  To change it, undef the following:
//#define NO_PKILL

// You can have the MUD keep track of which commands are being used and
// how much time they're taking by #defining PROFILING. This will take up
// a fair bit of CPU, so don't leave this on unless you have some use for
// the information - such as trying to find out where your MUD is slowing
// down - or you have CPU to blow (and who does?  ;)
//#define PROFILING 1

// Defines for the LOG directory pruner.
#define MAX_LOG_FILE_SIZE (100 * 1024)
#define MAX_LOG_DAYS 0

// If query("cap_name") is not MASTER_ONLY, you may choose to undefine
// the symbol below to ensure proper logging.
#undef CAP_NAME_MASTER_ONLY

// This controls the MUD local time zone. Define your time zone as the
// number of half-hours to ADD to Greenwich Mean Time to get your time zone.
// For example: Greenwich Time = 0, British Standard = -2, Eastern Standard
// = -10, Central Standard = -12, Central European = +2, Australian Standard
// = +24.
#define LOCAL_TIME_ZONE 1

#endif /* __CONFIG_H */
