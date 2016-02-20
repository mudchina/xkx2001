//Cracked by Roath
// command.h

#define ADM_PATH ({"/cmds/adm/", "/cmds/arch/", "/cmds/wiz/", "/cmds/imm/", "/cmds/usr/","/cmds/std/", "/cmds/skill/"})
#define ARC_PATH ({"/cmds/arch/", "/cmds/wiz/", "/cmds/imm/", "/cmds/usr/","/cmds/std/", "/cmds/skill/"})
#define WIZ_PATH ({"/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/", "/cmds/wiz/"})
#define APR_PATH ({"/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/", "/cmds/wiz/"})
#define IMM_PATH ({"/cmds/imm/", "/cmds/usr/", "/cmds/std/", "/cmds/skill/"})
#define PLR_PATH ({"/cmds/std/", "/cmds/usr/", "/cmds/skill/"})
#define UNR_PATH ({"/cmds/usr/", "/cmds/std/"})
#define NPC_PATH ({"/cmds/std/", "/cmds/skill/"})

// These are command objects that will also be called in those
// non-player objects.

#define DROP_CMD		"/cmds/std/drop"
#define GET_CMD			"/cmds/std/get"
#define GO_CMD			"/cmds/std/go"
#define KILL_CMD		"/cmds/std/kill"
#define TELL_CMD		"/cmds/std/tell"
#define UPTIME_CMD		"/cmds/usr/uptime"
#define WHO_CMD			"/cmds/usr/who"
#define MUDLIST_CMD		"/cmds/usr/mudlist"
