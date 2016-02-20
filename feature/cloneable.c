//Cracked by Roath
// cloneable.c 
// by xuy

// this function clone a copy of itself or "clone_ob" if defined, added by xuy
object clone()
{
	string clone;
	seteuid(getuid());
	
	if (!stringp(clone = this_object()->query("clone_ob"))) 
		clone = base_name(this_object());
	return new(clone);
}
