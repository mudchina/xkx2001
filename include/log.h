//Cracked by Roath
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** log.h -- specifies the available log files
**
** All log files go under DIR_LOG.  They are typically written by LOG_D.
** Note that these are symbolic names for log files.  The LOG_D will
** actually coordinate their placement.
**
** 960102, Deathblade: created
*/

#ifndef LOG_H
#define LOG_H

#define LOG_AUTODOC		"autodoc"
#define LOG_BANISH		"banish"
#define LOG_BUG			"bug"
#define LOG_CHANNEL		"channel"
#define LOG_FEEDBACK		"feedback"
#define LOG_FORCE		"force"
#define LOG_FTP			"ftp"
#define LOG_HELP_MISS		"help miss"
#define LOG_I3_ERROR		"i3 error"
#define LOG_IDEA		"idea"
#define LOG_LOGIN		"login"
#define LOG_LOGIN_FAILURE	"login failure"
#define LOG_MAIL_ERROR		"mail error"
#define LOG_NEW_PLAYERS         "new players"
#define LOG_QUEST		"quest"
#define LOG_QUESTION		"question"
#define LOG_QUIT		"quit"
#define LOG_SHUTDOWN		"shutdown"
#define LOG_SNOOP		"snoop"
#define LOG_SOCKET		"socket"
#define LOG_TODO		"todo"
#define LOG_TYPO		"typo"
#define LOG_WALL		"wall"

/* these are logged to directly */
#define LOG_FILE_CATCH		"/log/catch"
#define LOG_FILE_RUNTIME	"/log/runtime"
#define LOG_FILE_ERROR		"/log/log"

#endif /* LOG_H */
