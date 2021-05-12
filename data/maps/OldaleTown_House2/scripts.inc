OldaleTown_House2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, OldaleTown_House2_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

OldaleTown_House2_MapScripts_MAP_SCRIPT_ON_LOAD:
	return


OldaleTownHouse2Girl::
	lock
	faceplayer
	msgbox OldaleTownHouse2Girl_Text_0, MSGBOX_AUTOCLOSE
	release
	return


OldaleTownHouse2Boy::
	lock
	faceplayer
	msgbox OldaleTownHouse2Boy_Text_0, MSGBOX_AUTOCLOSE
	release
	return


OldaleTownHouse2Girl_Text_0:
	.string "There are several islands that\nhave not been explored yet.\pSome just aren't habitable, while\nothers are protected so WILD POKéMON\lcan live freely.$"

OldaleTownHouse2Boy_Text_0:
	.string "The ORANGE ARCHIPELAGO consists of\nseventeen islands in total.\pOf course, this number just accounts for\nthe more populated hub islands.$"
