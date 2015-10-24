execCmd(*cmd, *args) {
	*argStr = "";
	foreach(*arg in *args) {
		*argStr = *argStr++execCmdArg(*arg)++" ";
	}
	*argStr = substr(*argStr, 0, strlen(*argStr) - 1);
	writeLine("serverLog", *cmd ++ " " ++ *argStr);
	*e = errorcode(msiExecCmd(*cmd, *argStr, "null", "null", "null", *status));
	msiGetStderrInExecCmdOut(*status, *err);
	msiGetStdoutInExecCmdOut(*status, *out);
	msiFree(*status);
	(*e, *out, *err);
}
