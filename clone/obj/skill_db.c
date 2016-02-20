//Cracked by Roath
// skill database
// author: chu@xkx
// name: skill_db.c
// date: 6/16/98

#include <ansi.h>
#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif

inherit F_SAVE;
inherit F_DBASE;

// default average: 36 hours for 100% power
#define STANDARD_INTERVAL 129600

void create()
{
    seteuid(getuid());

    if (!restore()) {
        save();
    }
}

void debug(string msg)
{
    printf("DEBUG: %s\n", msg);
}

string query_save_file()
{
    return NPCDATA+"skill_db";
}

int average(string skill_name)
{
  return query(skill_name+"/average");
}

void set_average(string skill_name, int value)
{
  set(skill_name+"/average", value);
}

int compute_rate(mapping info) {
  int freq, average, tmp, exp, rate;

  // at this point info == new_info
  freq = info["history"];
  average = info["average"];

  if (freq <= average) { // used often, drop/increase rate linearly
    // so if the average frequency is 36 hours, we will get normal
    // power, otherwise linearly increase or decrease in the range
    // of 0-100%
    rate = freq * 100 / average; // percentage, center at average/2 
  }else {	// bonus: not being used for a long time
    // sort of logrithm
    tmp = freq*100/average;
    exp = 100;
    rate = 0;

    while (tmp >= exp) {	
      rate += 100;
      exp *= 2;
    }
    rate += 100*(2*tmp-exp)/exp;
  }
  return rate;
}

/*
 * skill_name: the name of the skill or perform (e.g., piaoxue)
 * me: the performer.
 * target: the victim
 * weight: the weight of the new usage in terms of how much it affects
 *         the history.  0-100, with 0 means this usage doesn't count
 *
 * return:
 *    mapping["last_use"] the last time (time()) this perform is used
 *    mapping["history"] the historical usage frequency, including this one
 *    mapping["average"] standard average usage (a fixed number)
 *    mapping["rate"] the rate of the current usage frequency comparing with
 *       the standard one, in percentage.  The rate is computed in the following
 *       manner: 
 *            if cur_freq <= 2*average, rate is linear to cur_freq
 *            otherwise, rate is 2+log2(cuf_freq/average);
 */
mapping update_usage(string skill_name, object me, object target, int weight)
{
  mapping info, usage;
  int     freq, last_use, interval, average, tmp;
  string id;

  info = query(skill_name);

  if( wizardp(me) && (string)me->query("env/combat")=="verbose" ) {
    tell_object(me, sprintf("got from skill_db: info£º%O\n", 
			    info));
  }
  if (!mapp(info)) { // first time usage, set default values
    info = ([ "average": STANDARD_INTERVAL, "history": STANDARD_INTERVAL, 
	    "last_use":time(), "rate":100]);
    if( wizardp(me) && (string)me->query("env/combat")=="verbose" ) {
      tell_object(me, sprintf("initialized %s record\n", skill_name));
    }
  }


  if (weight<=0 || weight >100 || (!objectp(me)) || !userp(me) || wizardp(me) ) {  
    return info;
  }
  
  // now we need to update
  average = info["average"];
  if (average <= 0) {
    average = STANDARD_INTERVAL;
  }

  last_use = info["last_use"];
  freq = info["history"]; 
  interval = time() - last_use;

  info["last_use"] = time();
  if (interval > freq) {
    info["history"]=interval;
  }else{
    info["history"] = (freq*(100-weight)+interval*weight)/100;
  }

  if (objectp(me)) {
    id = me->query("id");
    usage = info["usage"];
    if (!mapp(usage)) {
      usage=([]);
      info["usage"] = usage;
    }
    tmp = usage[id];
    usage[id] = tmp+1;
    info["last_performer"] = me->query("name")+" ("+id+")";
    if (objectp(target)) {
      info["last_target"] = target->query("name")+" ("+target->query("id")+")";
    }
  }
  set(skill_name, info);
  save();

  info["rate"] = compute_rate(info);
  return info;
}

