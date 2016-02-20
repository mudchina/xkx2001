//Cracked by Roath
// Author: Chu@xkx
// Date: 2/9/1999

/*
 * This is an object that can be used in 3 ways:
 *
 * 1. It is an item object that can be cloned by wiz.  This way it 
 *    acts as a debug tool for job_server, showing information about
 *    all job systems, and statistics
 * 2. It is a daemon of xkx that can be used as an object.  You can
 *    clone a job_server and then call the methods
 * 3. It can also be used as a file, so simply call those interface
 *    methods using job_server.c->foo() and it will automatically
 *    handle the cloning part.  (This is the recommended way to use it)
 *
 * Functionality:
 *    This object stores itself in /data/npc/job_server.o (can't find a
 *    better place and I don't want to create a new directory).  All the
 *    jobs set 2 limits: max exp and pot growth rate (per hour).  Then, 
 *    when a player starts a job, notify this server by calling start_job(),
 *    and when the job finishes, simply call the reward() method to reward
 *    the player.
 * 
 *    It also provides interface to check the configurations and shows
 *    statistics, such as average job award and a histogram of reward.
 *
 * Interface:
 *    commands (as an item): 
 * 	set_exp_limit "job_name" integer  // sets the exp limit
 * 	set_pot_limit "job_name" integer  // sets the pot limit
 * 	job_clear "job_name" 		  // removes job settings and histogram
 *      job_info "job_name"               // shows the exp/pot limit
 *      job_info                          // shows all exp/pot limits
 *      job_hist "job_name"               // shows reward histogram for a job
 *      job_stat "job_name"               // shows reward logs for a job
 *      job_start job player   		// simulate a player starting a job
 *      job_reward job player  		// simulate a reward, random rate
 *
 *    Method interfaces: See below in each method.
 *      start_job, abort_job, get_start_time, 
 * 	reward, get_job_hist
 *      set_exp_limit, set_pot_limit,
 *      get_exp_limit, get_pot_limit
 *      set_job_data, get_job_data
 * 
 *    Every Interface Method except the first 3 has a matching "func" method, 
 *    with the same prototype and _func postfix. (e.g. reward_func, 
 *    set_exp_limit_func)
 */

#include <ansi.h>

/************************** MACROS ***************************************/
#ifndef JOB_SERVER
#define JOB_SERVER "/clone/obj/job_server.c"
#endif
#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif

inherit F_SAVE;
inherit ITEM;

int do_set_exp_limit(string arg);
int do_set_pot_limit(string arg);
int do_job_info(string arg);
int do_job_hist(string arg);
int do_job_stat(string arg);
int do_job_clear(string arg);
int do_job_start(string arg);
int do_job_reward(string arg);
void print_hist_func(mixed *hist);
void set_exp_limit_func(string job_name, int limit);
void set_pot_limit_func(string job_name, int limit);
int get_exp_limit_func(string job_name);
int get_pot_limit_func(string job_name);
string reward_func(object player, string job, int exp_rate, int pot_rate);
void clear_func(string arg);
mixed get_job_data_func (string job_name, string data_name);
void set_job_data_func(string job_name, string data_name, mixed value);
mixed get_job_hist_func(string job_name);
mixed get_job_stat_func(string job_name);

/************************************************************************
 *                             Interface Methods 
 *
 * These methods are being called by file, e.g., JOB_SERVER->start_job()
 * They call the func methods which are the real implementations
 *
 ************************************************************************/
/* Start a job: player is the player object, job is the name of job
 * For examples of how to use this method, see do_job_start below
 */ 
void start_job(object player, string job) {
    if (objectp(player)) 
	player->set("job_server/"+job+"_start", time());
}


// Abort a job
void abort_job(object player, string job) {
    if (objectp(player))
	player->delete("job_server/"+job+"_start");
}

// Query job start time
int get_start_time(object player, string job) {
    if (objectp(player)) 
	return player->query("job_server/"+job+"_start");
    return 0;
}

/*
 * reward a player exp and pot.
 *
 * player  : the player object.  must be non-null object
 * job     : the name of the job.  non-null string
 * exp_rate: percentage of the exp_limit that the player should be rewarded
 * pot_rate: same as exp_rate, for potential
 *	   : exp_rate and pot_rate are expected to be numbers between 0 and
 *         : 100, but I don't check it so that you could reward some player
 *         : negative or over 100%.  But make sure you have a good reason 
 *         : to do so.
 *
 * return:  non-null string: error message
 *          0:  success
 *
 * For examples of how to use this method, see do_job_reward below
 */
string reward(object player, string job, int exp_rate, int pot_rate) {
    object js;
    string msg;

    js = new(JOB_SERVER);
    if (!objectp(js)) {
        printf("BUG: please report: job_server.c could not be cloned\n");
        return;
    }
    msg=js->reward_func(player, job, exp_rate, pot_rate); // real impl.
    destruct(js);
    return msg;
}


//set the exp limit 
void set_exp_limit(string job_name, int exp_limit) {
    object js;

    js = new(JOB_SERVER);
    if (!objectp(js)) {
        printf("BUG: please report: job_server.c could not be cloned\n");
        return;
    }
    js->set_exp_limit_func(job_name, exp_limit); // real impl.
    destruct(js);
}

//set the pot limit 
void set_pot_limit(string job_name, int pot_limit) {
    object js;

    js = new(JOB_SERVER);
    if (!objectp(js)) {
        printf("BUG: please report: job_server.c could not be cloned\n");
        return;
    }
    js->set_pot_limit_func(job_name, pot_limit); // real impl.
    destruct(js);
}

//get the exp limit 
int get_exp_limit(string job_name) {
    object js;
    int limit;

    js = new(JOB_SERVER);
    if (!objectp(js)) {
        printf("BUG: please report: job_server.c could not be cloned\n");
        return;
    }
    limit = js->get_exp_limit_func(job_name);
    destruct(js);
    return limit;
}

//get the pot limit 
int get_pot_limit(string job_name) {
    object js;
    int limit;

    js = new(JOB_SERVER);
    if (!objectp(js)) {
        printf("BUG: please report: job_server.c could not be cloned\n");
        return;
    }
    limit = js->get_pot_limit_func(job_name);
    destruct(js);
    return limit;
}

void set_job_data(string job_name, string data_name, mixed value) {
    object js;

    js = new(JOB_SERVER);
    if (!objectp(js)) {
        printf("BUG: please report: job_server.c could not be cloned\n");
        return;
    }
    js->set_job_data_func(job_name, data_name, value);
    destruct(js);
}

mixed get_job_data(string job_name, string data_name) {
    object js;
    mixed value;

    js = new(JOB_SERVER);
    if (!objectp(js)) {
        printf("BUG: please report: job_server.c could not be cloned\n");
        return;
    }
    value = js->get_job_data_func(job_name, data_name);
    destruct(js);
    return value;
}

mixed get_job_hist(string job_name) {
    object js;
    mixed value;

    js = new(JOB_SERVER);
    if (!objectp(js)) {
        printf("BUG: please report: job_server.c could not be cloned\n");
        return;
    }
    value = js->get_job_hist_func(job_name);
    destruct(js);
    return value;
}

/************************************************************************
 *                             Item Methods 
 *
 * These methods are necessary for the implementation of the job_server
 * item.
 *
 ************************************************************************/
void create()
{
    set_name("任务系统操纵器", ({"job server", "js"}));
    set_weight(0);
    if (clonep()) set_default_object(__FILE__);
    else {
	set("long", "任务系统操纵器. \n");
	set("unit", "台");
	set("material", "iron");
	set("value", 0);
    }
    seteuid(getuid());
    if (!restore()) save();
}

string query_save_file() { return NPCDATA+"job_server"; }

int init()
{
    object me = this_player();
    add_action("do_job_clear", "job_clear");
    add_action("do_job_start", "job_start");
    add_action("do_job_reward", "job_reward");
    add_action("do_job_info", "job_info");
    add_action("do_job_hist", "job_hist");
    add_action("do_job_stat", "job_stat");
    add_action("do_set_exp_limit", "set_exp_limit");
    add_action("do_set_pot_limit", "set_pot_limit");

    set("no_get", "干什么!");
    set("no_drop", "干什么!");
    set("no_steal", "干什么!");
    return 1;
}

int do_set_exp_limit(string arg)
{
    string job_name;
    int limit;

    if (!arg) {
	printf("Usage: set_exp_limit \"job name\" integer\n");
	return 1;
    }
    if (sscanf(arg, "%s %d", job_name, limit)!=2) {
	printf("Usage: set_exp_limit \"job name\" integer\n");
	return 1;
    }
    set_exp_limit_func(job_name, limit);
    log_file("job_server", 
	sprintf("%s: %s(%s) set %s exp limit to %d\n",
	    ctime(time()), this_player()->name(1), geteuid(this_player()), 
	    job_name, limit));
    printf("OK.\n");
    return 1;
}

int do_set_pot_limit(string arg)
{
    string job_name;
    int limit;

    if (!arg) {
	printf("Usage: set_pot_limit \"job name\" integer\n");
	return 1;
    }
    if (sscanf(arg, "%s %d", job_name, limit)!=2) {
	printf("Usage: set_exp_limit \"job name\" integer\n");
	return 1;
    }
    set_pot_limit_func(job_name, limit);
    log_file("job_server", 
	sprintf("%s: %s(%s) set %s pot limit to %d\n",
	    ctime(time()), this_player()->name(1), geteuid(this_player()), 
	    job_name, limit));
    printf("OK.\n");
    return 1;
}

int do_job_info(string arg)
{
    string job_name, *names;
    int i, exp_limit, pot_limit;
    mapping exp_map, pot_map;

    restore();
    if (!arg) {
	exp_map=this_object()->query("exp_limit");
	pot_map=this_object()->query("pot_limit");
	if (! exp_map) {
	    printf("No job system has been registered yet.\n");
	    return 1;
        }
	names=keys(exp_map);
  	for (i=0; i<sizeof(names); i++) {
	    printf("%s: exp_limit=%d, pot_limit=%d\n",
	        names[i], exp_map[names[i]], pot_map[names[i]]);
 	}
	return 1;
    }
    exp_limit=get_exp_limit_func(arg);
    pot_limit=get_pot_limit_func(arg);
    printf("%s: exp_limit=%d, pot_limit=%d\n", arg, exp_limit, pot_limit);
    return 1;
}

int compare_exp(mixed a, mixed b) {
    int n, x, y;
    n = a[2]; if (n < 1) return -1;
    x = a[5]*3600/n;
    n = b[2]; if (n < 1) return 1;
    y = b[5]*3600/n;

    return x-y;
}

int compare_pot(mixed a, mixed b) {
    int n, x, y;
    n = a[2]; if (n < 1) return -1;
    x = a[3]*3600/n;
    n = b[2]; if (n < 1) return 1;
    y = b[3]*3600/n;

    return x-y;
}

int compare_name(mixed a, mixed b) {
    return strcmp(a[0], b[0]);
}

int compare_number(mixed a, mixed b) {
    return a[1] - b[1];
}

int do_job_stat(string arg)
{
    mixed *info, *tmp;
    mapping stat;
    string *ids, job_name, sort_key;
    int i, j;
 
    if (!arg) return notify_fail("Usage: job_stat <job_name> [name|exp|pot]\n");
    if (sscanf(arg, "%s %s", job_name, sort_key) != 2) {
	job_name = arg;
	sort_key = "number";
    }
    restore();
    stat = get_job_stat_func(job_name);
    if (!mapp(stat)) {
	printf("no stat information for %s\n", job_name);
	return 1;
    }
    info = allocate(sizeof(stat));
    ids = keys(stat);
    for (i=0; i<sizeof(ids); i++) {
  	tmp = stat[ids[i]];
	info[i] = allocate(sizeof(tmp)+1);
	info[i][0] = ids[i];
	for (j=0; j<sizeof(tmp); j++)
	    info[i][j+1] = tmp[j];
    }
    switch (sort_key) {
    case "exp":
	info = sort_array(info, (: compare_exp :));
	break;
    case "pot":
	info = sort_array(info, (: compare_pot :));
	break;
    case "name":
	info = sort_array(info, (: compare_name :));
	break;
    case "number":
    default:
	info = sort_array(info, (: compare_number :));
	break;
    }

    printf(" User-Id #jobs exp/hour exp/job (rate) pot/hour pot/job (rate)\n");
    for (i=0; i<sizeof(info); i++) {
        if (info[i][1] <= 0 || info[i][2] <= 0) {
	    printf("%8s %5d %8d %7d %5d%% %8d %7d %5d%%\n",
		info[i][0], info[i][1],
		info[i][5], 0, info[i][6], 
		info[i][3], 0, info[i][4]);
	}else {
	    printf("%8s %5d %8d %7d %5d%% %8d %7d %5d%%\n",
		info[i][0], info[i][1],
		info[i][5]*3600/info[i][2],
		info[i][5]/info[i][1],
		info[i][6]/info[i][1],
		info[i][3]*3600/info[i][2],
		info[i][3]/info[i][1],
		info[i][4]/info[i][1]);
  	}
    }
    return 1;
}

    

int do_job_hist(string arg)
{
    mixed *hist;
    object obj=this_object();

    if (arg) {
	hist = get_job_hist_func(arg);
        if (! hist) {
	    printf("No Histogram for %s\n", arg);
        }else {
	    printf("Exp Histogram for %s:\n", arg);
	    print_hist_func(hist[0]);
	    printf("\nPot Histogram for %s:\n", arg);
	    print_hist_func(hist[1]);
 	}
    }else {
 	printf("Usage: job_hist <job name>\n");
    }
        
    return 1;
}


int do_job_clear(string arg)
{
    if (!arg) {
	return notify_fail("Usage: job_clear <job name>\n");
    }
    clear_func(arg);
    printf("all information about %s cleared.\n", arg);
    return 1;
}

/************************************************************************
 *                             Example Code
 *
 * These item methods are also example code for how to use job_server
 * as a file.  
 ************************************************************************/
int do_job_start(string arg)
{
    string job, player_name;
    object player;

    if (!arg || sscanf(arg, "%s %s", job, player_name)!=2) {
	return notify_fail("Usage: job_start job_name, player_name\n");
    }
    player=present(player_name, environment(this_player()));
    if (!objectp(player)) {
	return notify_fail("No such player: "+player_name+"\n");
    }

    // ********** this is the line you need *************** 
    JOB_SERVER->start_job(player, job);

    printf("OK, started %s for %s\n", job, player->name(1));
    return 1;
}

int do_job_reward(string arg)
{
    string msg, job, player_name;
    object player;

    if (!arg || sscanf(arg, "%s %s", job, player_name)!=2) {
	return notify_fail("Usage: job_reward job_name, player_name\n");
    }
    player=present(player_name, environment(this_player()));
    if (!objectp(player)) {
	return notify_fail("No such player: "+player_name+"\n");
    }

    // **************** this is the line you need ***************
    msg=JOB_SERVER->reward(player, job, random(100), random(100));
    // **************** but you shouldn't use random ************

    if (! msg) {
	printf("OK, rewarded %s for %s\n", job, player->name(1));
    }else {
	printf("reward error: %s\n", msg);
    }
    return 1;
}

/************************************************************************
 *                             Func Methods 
 *
 * These are the real implementations of various functionalities of
 * the job server.  Both the Item methods and the interface methods 
 * call them.
 ************************************************************************/

void set_exp_limit_func(string job_name, int limit) { 
    restore();
    this_object()->set("exp_limit/"+job_name, limit);
    save();
}

void set_pot_limit_func(string job_name, int limit) { 
    restore();
    this_object()->set("pot_limit/"+job_name, limit);
    save();
}

int get_exp_limit_func(string job_name) { 
    restore();
    return this_object()->query("exp_limit/"+job_name);
}

int get_pot_limit_func(string job_name) { 
    restore();
    return this_object()->query("pot_limit/"+job_name);
}

string reward_func(object player, string job, int exp_rate, int pot_rate)
{
    int start_time, time_now, exp_limit, pot_limit;
    int exp_reward, pot_reward, i;
    mixed *hist, *info;
    mapping stat;
    object obj=this_object();

    if (! objectp(player)) return "player object is null";
    if (! objectp(obj)) return "this object is null";
    start_time = player->query("job_server/"+job+"_start");
    player->delete("job_server/"+job+"_start");
    if (start_time <= 0) return "no start time";
    time_now = time();
    restore();
    exp_limit=obj->query("exp_limit/"+job);
    pot_limit=obj->query("pot_limit/"+job);

    // compute and apply reward
    
    exp_reward = exp_limit*exp_rate*(time_now-start_time)/360000;
    pot_reward = pot_limit*pot_rate*(time_now-start_time)/360000;
    player->add("combat_exp", exp_reward);
    player->add("potential", pot_reward);
    if (player->query("potential") > player->query("max_potential"))
	player->set("potential", player->query("max_potential"));
    
    
    // log the reward in a logfile
    log_file("job_server-"+job, 
	sprintf("%s %s(%s) used %d sec get %d(%d%%)pot, %d(%d%%)exp=%d\n",
	        ctime(time()), player->name(1), geteuid(player),
	        time_now-start_time,
		pot_reward, pot_rate,
		exp_reward, exp_rate, 
		player->query("combat_exp")));

    // update per-user statistics.  We only record a total and average here.
    // per-user histogram would take more space and doesn't seem useful anyway.
    stat = obj->query("stat/"+job);
    if (! mapp(stat)) {
        stat = ([player->query("id"): 
		({1, time_now-start_time, pot_reward, pot_rate, exp_reward, exp_rate}) ]);
  	obj->set("stat/"+job, stat);
    }else {
        info = stat[player->query("id")];
	if (! info) {
	    stat[player->query("id")] =  
		({1, time_now-start_time, pot_reward, pot_rate, exp_reward, exp_rate});
  	}else {
 	    info[0] ++;
	    info[1] += time_now-start_time;
	    info[2] += pot_reward;
 	    info[3] += pot_rate;
	    info[4] += exp_reward;
	    info[5] += exp_rate;
	}
    }
    

    // update the per-job histograms
    hist = obj->query("exp_hist/"+job);
    if (! hist) {
	hist = allocate(10);
	for (i=0; i<10; i++) hist[i] = ({0,0, 0});
	obj->set("exp_hist/"+job, hist);
    }
    if (exp_rate<0) exp_rate = 0;
    if (exp_rate>99) exp_rate = 99;
    i=exp_rate/10;
    hist[i][0]++;
    hist[i][1]+=exp_reward;
    hist[i][2]+=time_now-start_time;

    hist = obj->query("pot_hist/"+job);
    if (! hist) {
	hist = allocate(10);
	for (i=0; i<10; i++) hist[i] = ({0,0, 0});
	obj->set("pot_hist/"+job, hist);
    }
    if (pot_rate<0) pot_rate = 0;
    if (pot_rate>99) pot_rate = 99;
    i=pot_rate/10;
    hist[i][0]++;
    hist[i][1]+=pot_reward;
    hist[i][2]+=time_now-start_time;
    
    save();
    return 0;
}

void clear_func(string arg) {
    int i;
    mixed *hist;

    restore();
    log_file("job_server", 
	sprintf("%s: %s(%s) cleared job %s\n",
	    ctime(time()), this_player()->name(1), geteuid(this_player()), arg));
    // delete("exp_limit/"+arg);
    // delete("pot_limit/"+arg);
    hist = query("exp_hist/"+arg);
    if (hist)  for (i=0; i<10; i++) hist[i] = ({0, 0, 0});
    hist = query("pot_hist/"+arg);
    if (hist)  for (i=0; i<10; i++) hist[i] = ({0, 0, 0});
    // delete("job_data/"+arg);
    delete("stat/"+arg);
    save();
}

void set_job_data_func(string job_name, string data_name, mixed value) {
    restore();
    set("job_data/"+job_name+"_"+data_name, value);
    save();
}

mixed get_job_data_func(string job_name, string data_name) {
    restore();
    return query("job_data/"+job_name+"_"+data_name);
}

mixed get_job_stat_func(string job_name) {
    return query("stat/"+job_name);
}

mixed get_job_hist_func(string job_name) {
    mixed *hist;
    
    hist = allocate(2);
    restore();
    hist[0] = query("exp_hist/"+job_name);
    hist[1] = query("pot_hist/"+job_name);
    return hist;
}

void print_hist_func(mixed *hist) 
{
    int i, total_job, total_reward, total_time;

    total_job=0;
    total_reward=0;
    total_time=0;
    for (i=0; i<sizeof(hist); i++) {
 	printf("%d - %d: %d jobs, average: %d/job %d/hour\n",
		i*10, (i+1)*10-1, hist[i][0],
		(hist[i][0]>0?hist[i][1]/hist[i][0]:0),
		(hist[i][2]>0?3600*hist[i][1]/hist[i][2]:0));
	total_job += hist[i][0];
	total_reward += hist[i][1];
	total_time += hist[i][2];
    }
    printf("In Total: %d jobs, average: %d/job %d/hour \n",
	total_job, 
	(total_job>0?total_reward/total_job:0),
	(total_time>0?3600*total_reward/total_time:0));
}
