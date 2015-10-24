execCmd(*cmd, *args, *status) {
	*argStr = "";
	foreach(*arg in *args) {
		*argStr = *argStr++execCmdArg(*arg)++" ";
	}
	*argStr = substr(*argStr, 0, strlen(*argStr) - 1);
	writeLine("serverLog", *cmd ++ " " ++ *argStr);
	*e = errorcode(msiExecCmd(*cmd, *argStr, "null", "null", "null", *status));
	#if(*e < 0) {
	#	msiGetStderrInExecCmdOut(*status, *err);
	#	writeLine("serverLog", "execCmd: *err");
	#}
	*e;
}