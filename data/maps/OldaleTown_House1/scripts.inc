OldaleTown_House1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, OldaleTown_House1_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

OldaleTown_House1_MapScripts_MAP_SCRIPT_ON_LOAD:
	return


OldaleTownHouse1Girl::
	lock
	faceplayer
	msgbox OldaleTownHouse1Girl_Text_0, MSGBOX_AUTOCLOSE
	release
	return


OldaleTownHouse1Fatass::
	lock
	faceplayer
	msgbox OldaleTownHouse1Fatass_Text_0, MSGBOX_AUTOCLOSE
	release
	return


OldaleTownHouse1Girl_Text_0:
	.string "Of all the ORANGE CREW members, the\nstrongest is DRAKE, on PUMMELO ISLAND.$"

OldaleTownHouse1Fatass_Text_0:
	.string "Hm… Those are some great POKéMON\nyou have there.\pTaking on the ORANGE CREW won't be\nan easy task, though.$"
