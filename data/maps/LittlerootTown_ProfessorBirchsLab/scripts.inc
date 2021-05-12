LittlerootTown_ProfessorBirchsLab_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfessorBirchsLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LittlerootTown_ProfessorBirchsLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ROUTE105_STATE, 0, LittlerootTown_ProfessorBirchsLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

LittlerootTown_ProfessorBirchsLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	lockall
	setvar VAR_ROUTE106_STATE, 0
	setobjectxy 1, 3, 4
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_CYNDAQUIL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_TOTODILE
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_CHIKORITA
	applymovement EVENT_OBJ_ID_PLAYER, MapScript_PlayerMove
	waitmovement EVENT_OBJ_ID_PLAYER
	applymovement 1, Common_Movement_ExclamationMark
	playse SE_PIN
	delay 64
	turnobject 1, DIR_EAST
	msgbox LittlerootTown_ProfessorBirchsLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0
	closemessage
	applymovement 1, MapScript_IvyMoveToTable
	delay 16
	turnobject EVENT_OBJ_ID_PLAYER, DIR_WEST
	delay 26
	turnobject EVENT_OBJ_ID_PLAYER, DIR_EAST
	waitmovement 1
	msgbox LittlerootTown_ProfessorBirchsLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1
	setvar VAR_ROUTE105_STATE, 1
	setflag FLAG_UNUSED_0x022
	releaseall
	return


MapScript_PlayerMove:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MapScript_IvyMoveToTable:
	walk_up
	walk_right
	walk_right
	walk_right
	face_down
	step_end

TileScript_StarterNotChosenYet::
	lockall
	msgbox TileScript_StarterNotChosenYet_Text_0, MSGBOX_AUTOCLOSE
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkUp
	waitmovement EVENT_OBJ_ID_PLAYER
	releaseall
	return


TileScript_HopeGivesPokeBalls::
	lockall
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	switch VAR_TEMP_0
	case 4, TileScript_HopeGivesPokeBalls_3
	case 5, TileScript_HopeGivesPokeBalls_4
	case 6, TileScript_HopeGivesPokeBalls_5
TileScript_HopeGivesPokeBalls_1:
	msgbox TileScript_HopeGivesPokeBalls_Text_0
	giveitem_std ITEM_POKE_BALL, 5
	msgbox TileScript_HopeGivesPokeBalls_Text_1, MSGBOX_AUTOCLOSE
	switch VAR_TEMP_0
	case 4, TileScript_HopeGivesPokeBalls_8
	case 5, TileScript_HopeGivesPokeBalls_9
	case 6, TileScript_HopeGivesPokeBalls_10
TileScript_HopeGivesPokeBalls_6:
	setvar VAR_ROUTE105_STATE, 3
	releaseall
	return

TileScript_HopeGivesPokeBalls_3:
	applymovement 2, TileScript_HopeWalksToPlayerLeftTile
	waitmovement 2
	goto TileScript_HopeGivesPokeBalls_1

TileScript_HopeGivesPokeBalls_4:
	applymovement 2, TileScript_HopeWalksToPlayerMidTile
	waitmovement 2
	goto TileScript_HopeGivesPokeBalls_1

TileScript_HopeGivesPokeBalls_5:
	applymovement 2, TileScript_HopeWalksToPlayerRightTile
	waitmovement 2
	goto TileScript_HopeGivesPokeBalls_1

TileScript_HopeGivesPokeBalls_8:
	applymovement 2, TileScript_HopeWalksBackLeftTile
	waitmovement 2
	goto TileScript_HopeGivesPokeBalls_6

TileScript_HopeGivesPokeBalls_9:
	applymovement 2, TileScript_HopeWalksBackMidTile
	waitmovement 2
	goto TileScript_HopeGivesPokeBalls_6

TileScript_HopeGivesPokeBalls_10:
	applymovement 2, TileScript_HopeWalksBackRightTile
	waitmovement 2
	goto TileScript_HopeGivesPokeBalls_6


TileScript_HopeWalksToPlayerLeftTile:
	walk_right
	face_up
	step_end

TileScript_HopeWalksToPlayerMidTile:
	walk_right
	walk_right
	face_up
	step_end

TileScript_HopeWalksToPlayerRightTile:
	walk_right
	walk_right
	walk_right
	face_up
	step_end

TileScript_HopeWalksBackLeftTile:
	walk_left
	delay_1
	face_down
	step_end

TileScript_HopeWalksBackMidTile:
	walk_left
	walk_left
	delay_1
	face_down
	step_end

TileScript_HopeWalksBackRightTile:
	walk_left
	walk_left
	walk_left
	delay_1
	face_down
	step_end

EventScript_Hope::
	lock
	faceplayer
	msgbox TileScript_HopeGivesPokeBalls_Text_1
	release
	return


EventScript_Ivy::
	lock
	faceplayer
	goto_if_set FLAG_GS_BALL_TRACEY, EventScript_Ivy_2
	compare VAR_ROUTE105_STATE, 2
	goto_if_ge EventScript_Ivy_5
	msgbox LittlerootTown_ProfessorBirchsLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1
EventScript_Ivy_4:
	release
	return

EventScript_Ivy_2:
	goto_if_set FLAG_GS_BALL_IVY, EventScript_Ivy_9
	msgbox EventScript_Ivy_Text_1
	playfanfare MUS_ME_WAZA
	message EventScript_Ivy_Text_2
	waitmessage
	waitfanfare
	takeitem ITEM_DEVON_GOODS, 1
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	delay 7
	playse SE_PIN
	waitse
	switch VAR_FACING
	case DIR_SOUTH, EventScript_Ivy_13
	case DIR_NORTH, EventScript_Ivy_14
	case DIR_WEST, EventScript_Ivy_15
	case DIR_EAST, EventScript_Ivy_16
EventScript_Ivy_11:
	msgbox EventScript_Ivy_Text_3
	setflag FLAG_GS_BALL_IVY
	release
	return

EventScript_Ivy_5:
	msgbox EventScript_Ivy_Text_4
	goto EventScript_Ivy_4

EventScript_Ivy_9:
	msgbox EventScript_Ivy_Text_0
	release
	return

EventScript_Ivy_13:
	applymovement 1, Movement_IvyExcitedFacingNorth
	waitmovement 0
	goto EventScript_Ivy_11

EventScript_Ivy_14:
	applymovement 1, Movement_IvyExcitedFacingSouth
	waitmovement 0
	goto EventScript_Ivy_11

EventScript_Ivy_15:
	applymovement 1, Movement_IvyExcitedFacingEast
	waitmovement 0
	goto EventScript_Ivy_11

EventScript_Ivy_16:
	applymovement 1, Movement_IvyExcitedFacingWest
	waitmovement 0
	goto EventScript_Ivy_11


Movement_IvyExcitedFacingNorth:
	walk_in_place_fast_up
	walk_in_place_fastest_up
	walk_in_place_fast_up
	walk_in_place_fastest_up
	step_end

Movement_IvyExcitedFacingSouth:
	walk_in_place_fast_down
	walk_in_place_fastest_down
	walk_in_place_fast_down
	walk_in_place_fastest_down
	step_end

Movement_IvyExcitedFacingEast:
	walk_in_place_fast_right
	walk_in_place_fastest_right
	walk_in_place_fast_right
	walk_in_place_fastest_right
	step_end

Movement_IvyExcitedFacingWest:
	walk_in_place_fast_left
	walk_in_place_fastest_left
	walk_in_place_fast_left
	walk_in_place_fastest_left
	step_end

EventScript_HealingMachinePC::
	lockall
	compare VAR_ROUTE105_STATE, 2
	goto_if_ge EventScript_HealingMachinePC_1
	msgbox EventScript_HealingMachinePC_Text_1
	releaseall
	return

EventScript_HealingMachinePC_1:
	msgbox EventScript_HealingMachinePC_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne EventScript_HealingMachinePC_4
	fadescreen 1
	playfanfare MUS_ME_ASA
	release
	lock
	special HealPlayerParty
	waitfanfare
	fadescreen 0
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	releaseall
	return

EventScript_HealingMachinePC_4:
	releaseall
	return


EventScript_Cyndaquil::
	release
	compare VAR_ROUTE105_STATE, 2
	goto_if_ge EventScript_Cyndaquil_1
	applymovement 1, Movement_Ivy_FaceDown
	waitmovement 0
	showmonpic SPECIES_CYNDAQUIL, 10, 3
	playmoncry SPECIES_CYNDAQUIL, 0
	msgbox EventScript_Cyndaquil_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq EventScript_Cyndaquil_4
	bufferspeciesname 0, SPECIES_CYNDAQUIL
	setvar VAR_TEMP_1, SPECIES_CYNDAQUIL
	givemon SPECIES_CYNDAQUIL, 5, ITEM_ORAN_BERRY
	switch VAR_RESULT
	case 0, EventScript_Cyndaquil_8
	case 1, EventScript_Cyndaquil_9
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	return

EventScript_Cyndaquil_1:
	msgbox EventScript_Cyndaquil_Text_0
	releaseall
	return

EventScript_Cyndaquil_4:
	hidemonpic
	msgbox EventScript_Cyndaquil_Text_2
	releaseall
	return

EventScript_Cyndaquil_8:
	call EventScript_ReceivedJohtoStarter
	removeobject 3
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_Cyndaquil_12
EventScript_Cyndaquil_11:
	goto EventScript_ReceivedCyndaquil
	return

EventScript_Cyndaquil_9:
	call EventScript_ReceivedJohtoStarter
	removeobject 3
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_Cyndaquil_15
EventScript_Cyndaquil_14:
	call Common_EventScript_TransferredToPC
	goto EventScript_ReceivedCyndaquil
	return

EventScript_Cyndaquil_12:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto EventScript_Cyndaquil_11

EventScript_Cyndaquil_15:
	call Common_EventScript_NameReceivedBoxMon
	goto EventScript_Cyndaquil_14


EventScript_ReceivedCyndaquil::
	hidemonpic
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	switch VAR_TEMP_1
	case 3, EventScript_ReceivedCyndaquil_3
	case 4, EventScript_ReceivedCyndaquil_4
	case 5, EventScript_ReceivedCyndaquil_5
EventScript_ReceivedCyndaquil_1:
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_CYNDAQUIL
	setvar VAR_ROUTE105_STATE, 2
	goto EventScript_IvyAfterStarterChosen
	return

EventScript_ReceivedCyndaquil_3:
	delay 5
	turnobject 1, DIR_EAST
	delay 5
	turnobject EVENT_OBJ_ID_PLAYER, DIR_WEST
	goto EventScript_ReceivedCyndaquil_1

EventScript_ReceivedCyndaquil_4:
	delay 5
	turnobject 1, DIR_SOUTH
	delay 5
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	goto EventScript_ReceivedCyndaquil_1

EventScript_ReceivedCyndaquil_5:
	applymovement EVENT_OBJ_ID_PLAYER, Movement_CyndaquilPlayerFacingNorth
	delay 5
	turnobject 1, DIR_SOUTH
	waitmovement 0
	goto EventScript_ReceivedCyndaquil_1


Movement_CyndaquilPlayerFacingNorth:
	walk_left
	walk_up
	step_end

EventScript_Totodile::
	release
	compare VAR_ROUTE105_STATE, 2
	goto_if_ge EventScript_Totodile_1
	applymovement 1, Movement_Ivy_FaceDown
	waitmovement 0
	showmonpic SPECIES_TOTODILE, 10, 3
	playmoncry SPECIES_TOTODILE, 0
	msgbox EventScript_Totodile_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq EventScript_Totodile_4
	bufferspeciesname 0, SPECIES_TOTODILE
	setvar VAR_TEMP_1, SPECIES_TOTODILE
	givemon SPECIES_TOTODILE, 5, ITEM_ORAN_BERRY
	switch VAR_RESULT
	case 0, EventScript_Totodile_8
	case 1, EventScript_Totodile_9
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	return

EventScript_Totodile_1:
	msgbox EventScript_Cyndaquil_Text_0
	releaseall
	return

EventScript_Totodile_4:
	hidemonpic
	msgbox EventScript_Cyndaquil_Text_2
	releaseall
	return

EventScript_Totodile_8:
	call EventScript_ReceivedJohtoStarter
	removeobject 4
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_Totodile_12
EventScript_Totodile_11:
	goto EventScript_ReceivedTotodile
	return

EventScript_Totodile_9:
	call EventScript_ReceivedJohtoStarter
	removeobject 4
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_Totodile_15
EventScript_Totodile_14:
	call Common_EventScript_TransferredToPC
	goto EventScript_ReceivedTotodile
	return

EventScript_Totodile_12:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto EventScript_Totodile_11

EventScript_Totodile_15:
	call Common_EventScript_NameReceivedBoxMon
	goto EventScript_Totodile_14


EventScript_ReceivedTotodile::
	hidemonpic
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	switch VAR_TEMP_1
	case 3, EventScript_ReceivedTotodile_3
	case 5, EventScript_ReceivedTotodile_4
EventScript_ReceivedTotodile_1:
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_TOTODILE
	setvar VAR_ROUTE105_STATE, 2
	goto EventScript_IvyAfterStarterChosen
	return

EventScript_ReceivedTotodile_3:
	applymovement EVENT_OBJ_ID_PLAYER, Movement_TotodilePlayerFacingSouth
	delay 5
	turnobject 1, DIR_EAST
	waitmovement 0
	goto EventScript_ReceivedTotodile_1

EventScript_ReceivedTotodile_4:
	applymovement EVENT_OBJ_ID_PLAYER, Movement_TotodilePlayerFacingNorth
	delay 5
	turnobject 1, DIR_SOUTH
	waitmovement 0
	goto EventScript_ReceivedTotodile_1


Movement_TotodilePlayerFacingSouth:
	walk_left
	step_end

Movement_TotodilePlayerFacingNorth:
	walk_left
	walk_left
	walk_up
	step_end

EventScript_Chikorita::
	release
	compare VAR_ROUTE105_STATE, 2
	goto_if_ge EventScript_Chikorita_1
	applymovement 1, Movement_Ivy_FaceDown
	waitmovement 0
	showmonpic SPECIES_CHIKORITA, 10, 3
	playmoncry SPECIES_CHIKORITA, 0
	msgbox EventScript_Chikorita_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq EventScript_Chikorita_4
	bufferspeciesname 0, SPECIES_CHIKORITA
	setvar VAR_TEMP_1, SPECIES_CHIKORITA
	givemon SPECIES_CHIKORITA, 5, ITEM_ORAN_BERRY
	switch VAR_RESULT
	case 0, EventScript_Chikorita_8
	case 1, EventScript_Chikorita_9
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	return

EventScript_Chikorita_1:
	msgbox EventScript_Cyndaquil_Text_0
	releaseall
	return

EventScript_Chikorita_4:
	hidemonpic
	msgbox EventScript_Cyndaquil_Text_2
	releaseall
	return

EventScript_Chikorita_8:
	call EventScript_ReceivedJohtoStarter
	removeobject 5
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_Chikorita_12
EventScript_Chikorita_11:
	goto EventScript_ReceivedChikorita
	return

EventScript_Chikorita_9:
	call EventScript_ReceivedJohtoStarter
	removeobject 5
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_Chikorita_15
EventScript_Chikorita_14:
	call Common_EventScript_TransferredToPC
	goto EventScript_ReceivedChikorita
	return

EventScript_Chikorita_12:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto EventScript_Chikorita_11

EventScript_Chikorita_15:
	call Common_EventScript_NameReceivedBoxMon
	goto EventScript_Chikorita_14


EventScript_ReceivedChikorita::
	hidemonpic
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	switch VAR_TEMP_1
	case 3, EventScript_ReceivedChikorita_3
	case 5, EventScript_ReceivedChikorita_4
EventScript_ReceivedChikorita_1:
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_CHIKORITA
	setvar VAR_ROUTE105_STATE, 2
	goto EventScript_IvyAfterStarterChosen
	return

EventScript_ReceivedChikorita_3:
	applymovement EVENT_OBJ_ID_PLAYER, Movement_ChikoritaPlayerFacingSouth
	delay 5
	turnobject 1, DIR_EAST
	waitmovement 0
	goto EventScript_ReceivedChikorita_1

EventScript_ReceivedChikorita_4:
	applymovement EVENT_OBJ_ID_PLAYER, Movement_ChikoritaPlayerFacingNorth
	delay 5
	turnobject 1, DIR_SOUTH
	waitmovement 0
	goto EventScript_ReceivedChikorita_1


Movement_ChikoritaPlayerFacingSouth:
	walk_left
	walk_left
	step_end

Movement_ChikoritaPlayerFacingNorth:
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

EventScript_ReceivedJohtoStarter::
	msgbox EventScript_ReceivedJohtoStarter_Text_0
	playfanfare MUS_RG_FAN5
	message EventScript_ReceivedJohtoStarter_Text_1
	waitmessage
	waitfanfare
	return


EventScript_IvyAfterStarterChosen::
	msgbox EventScript_IvyAfterStarterChosen_Text_0
	delay 5
	turnobject 1, DIR_WEST
	msgbox EventScript_IvyAfterStarterChosen_Text_1
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	switch VAR_TEMP_0
	case 6, EventScript_IvyAfterStarterChosen_3
	case 7, EventScript_IvyAfterStarterChosen_4
EventScript_IvyAfterStarterChosen_1:
	msgbox EventScript_IvyAfterStarterChosen_Text_2
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_SYS_POKEDEX_GET
	playfanfare MUS_FANFA5
	message EventScript_IvyAfterStarterChosen_Text_3
	waitmessage
	waitfanfare
	msgbox EventScript_IvyAfterStarterChosen_Text_4
	releaseall
	return

EventScript_IvyAfterStarterChosen_3:
	delay 5
	turnobject 1, DIR_SOUTH
	goto EventScript_IvyAfterStarterChosen_1

EventScript_IvyAfterStarterChosen_4:
	delay 5
	turnobject 1, DIR_EAST
	goto EventScript_IvyAfterStarterChosen_1


Movement_Ivy_FaceDown:
	face_down
	step_end

EventScript_HealingMachine::
	msgbox EventScript_HealingMachine_Text_0, MSGBOX_SIGN
	return


EventScript_RegionalFormsResearchPC::
	msgbox EventScript_RegionalFormsResearchPC_Text_0, MSGBOX_SIGN
	return


EventScript_WindowSeaBreeze::
	msgbox EventScript_WindowSeaBreeze_Text_0, MSGBOX_SIGN
	return


EventScript_Bookshelves::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	switch VAR_TEMP_0
	case 0, EventScript_Bookshelves_2
	case 1, EventScript_Bookshelves_3
	case 2, EventScript_Bookshelves_4
	case 3, EventScript_Bookshelves_5
	msgbox EventScript_Bookshelves_Text_4, MSGBOX_SIGN
	return

EventScript_Bookshelves_2:
	msgbox EventScript_Bookshelves_Text_0, MSGBOX_SIGN
	return

EventScript_Bookshelves_3:
	msgbox EventScript_Bookshelves_Text_1, MSGBOX_SIGN
	return

EventScript_Bookshelves_4:
	msgbox EventScript_Bookshelves_Text_2, MSGBOX_SIGN
	return

EventScript_Bookshelves_5:
	msgbox EventScript_Bookshelves_Text_3, MSGBOX_SIGN
	return


EventScript_TrashCan::
	msgbox EventScript_TrashCan_Text_0, MSGBOX_SIGN
	return


EventScript_WindowReflection::
	msgbox EventScript_WindowReflection_Text_0, MSGBOX_SIGN
	return


LittlerootTown_ProfessorBirchsLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
	.string "PROF. IVY: {PLAYER}!\n"
	.string "There you are!\p"
	.string "Today is the day you begin your\n"
	.string "POKéMON journey.\p"
	.string "As a POKéMON PROFESSOR, I will give\n"
	.string "you a tool known as a POKéDEX.\p"
	.string "It will record data of all sorts of\n"
	.string "POKéMON you see or catch.\p"
	.string "I'd also like you to take a\n"
	.string "POKéMON that I recently caught.$"

LittlerootTown_ProfessorBirchsLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1:
	.string "I want you to raise one of the POKéMON\n"
	.string "contained in these POKé BALLS.\p"
	.string "You'll be that POKéMON's first partner,\n"
	.string "{PLAYER}! Go on. Pick one!$"

TileScript_StarterNotChosenYet_Text_0:
	.string "PROF. IVY: Wait! Where are you going?$"

TileScript_HopeGivesPokeBalls_Text_0:
	.string "{PLAYER}!\n"
	.string "Use these on your POKéDEX quest!$"

TileScript_HopeGivesPokeBalls_Text_1:
	.string "To complete the POKéDEX, you have\n"
	.string "to catch POKéMON.\p"
	.string "Throw POKé BALLS at wild POKéMON\n"
	.string "to catch them.$"

EventScript_Ivy_Text_0:
	.string "I'm counting on you, {PLAYER}.\p"
	.string "Please alert me if you find out\n"
	.string "any information about that GS BALL.$"

EventScript_Ivy_Text_1:
	.string "PROF. IVY: Oh, {PLAYER}!\n"
	.string "Good to see you.\p"
	.string "It seems my old POKéMON has grown\n"
	.string "pretty attached to you.\p"
	.string "Huh, you have something for me?$"

EventScript_Ivy_Text_2:
	.string "{PLAYER} delivered the GS BALL.$"

EventScript_Ivy_Text_3:
	.string "PROF. IVY: This is…\p"
	.string "This is a very important item.\n"
	.string "The GS BALL.\p"
	.string "I don't know what it does or\n"
	.string "who even made it.\p"
	.string "I had it sent to PROF. OAK in\n"
	.string "the KANTO region.\p"
	.string "It seems he didn't know either…\p"
	.string "Thank you for bringing it back\n"
	.string "to me safely, {PLAYER}.\p"
	.string "I will further examine it here,\n"
	.string "and update you if I discover anything.\p"
	.string "Now that you are travelling across\n"
	.string "the region, please let me know\l"
	.string "if you find any clues, too.\p"
	.string "I'm counting on you, {PLAYER}!$"

EventScript_Ivy_Text_4:
	.string "Take care, {PLAYER}.\p"
	.string "Always remember to visit home\n"
	.string "from time to time.$"

EventScript_HealingMachinePC_Text_0:
	.string "Would you like to heal your POKéMON?$"

EventScript_HealingMachinePC_Text_1:
	.string "This PC contains PROF. IVY's research!\n"
	.string "Better ask her before using it.$"

EventScript_Cyndaquil_Text_0:
	.string "It contains a POKéMON caught by\n"
	.string "PROF. IVY.$"

EventScript_Cyndaquil_Text_1:
	.string "PROF. IVY: The FIRE POKéMON\n"
	.string "CYNDAQUIL caught your eye?$"

EventScript_Cyndaquil_Text_2:
	.string "PROF. IVY: Take your time before\n"
	.string "you decide.\p"
	.string "Your partner is important.$"

EventScript_Totodile_Text_0:
	.string "PROF. IVY: The WATER POKéMON\n"
	.string "TOTODILE is your choice?$"

EventScript_Chikorita_Text_0:
	.string "PROF. IVY: So, you have decided on\n"
	.string "CHIKORITA, the GRASS POKéMON?$"

EventScript_ReceivedJohtoStarter_Text_0:
	.string "PROF. IVY: I think that's a cool\n"
	.string "POKéMON too!$"

EventScript_ReceivedJohtoStarter_Text_1:
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from PROF. IVY!$"

EventScript_IvyAfterStarterChosen_Text_0:
	.string "{PLAYER}, go to the west end of\n"
	.string "ROUTE 49 to find VALENCIA PORT.\p"
	.string "You can catch the SEAGALLOP FERRY\n"
	.string "there to head to TANGELO ISLAND.$"

EventScript_IvyAfterStarterChosen_Text_1:
	.string "If your POKéMON is hurt, you should\n"
	.string "heal it using the machine over there.\p"
	.string "Feel free to use it anytime.$"

EventScript_IvyAfterStarterChosen_Text_2:
	.string "Finally, here's the POKéDEX I mentioned\n"
	.string "earlier. It's a hi-tech encyclopedia!\p"
	.string "Go discover all kinds of POKéMON, and\n"
	.string "complete that POKéDEX!$"

EventScript_IvyAfterStarterChosen_Text_3:
	.string "{PLAYER} received the POKéDEX from\n"
	.string "PROF. IVY!$"

EventScript_IvyAfterStarterChosen_Text_4:
	.string "Take care, {PLAYER}!$"

EventScript_HealingMachine_Text_0:
	.string "There's a note…\p"
	.string "Use this machine to heal your POKéMON!\n"
	.string "Interact with the PC to operate it.$"

EventScript_RegionalFormsResearchPC_Text_0:
	.string "REGIONAL FORMS OF POKéMON\p"
	.string "…It says on the screen…$"

EventScript_WindowSeaBreeze_Text_0:
	.string "The window's open.\n"
	.string "An ocean breeze is blowing in.$"

EventScript_Bookshelves_Text_0:
	.string "{PLAYER} opened a book.\p"
	.string "Travel Tip 1: Press START to open\n"
	.string "the menu.$"

EventScript_Bookshelves_Text_1:
	.string "{PLAYER} opened a book.\p"
	.string "Travel Tip 2: Choose SAVE from the\n"
	.string "menu to save your progress!$"

EventScript_Bookshelves_Text_2:
	.string "{PLAYER} opened a book.\p"
	.string "Travel Tip 3: Open your bag and\n"
	.string "press SELECT to move items.$"

EventScript_Bookshelves_Text_3:
	.string "{PLAYER} opened a book.\p"
	.string "Travel Tip 4: Check your POKéMON's\n"
	.string "moves and press A to switch their order.$"

EventScript_Bookshelves_Text_4:
	.string "It's a book that's too hard to read.$"

EventScript_TrashCan_Text_0:
	.string "The wrapper from the snack PROF. IVY\n"
	.string "ate is in there…$"

EventScript_WindowReflection_Text_0:
	.string "My reflection!\n"
	.string "Lookin' good!$"
