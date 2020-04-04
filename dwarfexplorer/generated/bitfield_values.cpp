#include <array>
#include <cstdint>
#include <DataDefs.h>
#include <Core.h>
#include <Console.h>
#include <Export.h>
#include <PluginManager.h>
#include <RemoteServer.h>
#include <RemoteClient.h>
#include <VersionInfo.h>
#include "df_all.h"
#include "DF_Types.h"
#include "node.h"


using namespace rdf;


std::array<std::array<std::string, 3>, 32> null_bitfield = {
        {{"0", "@#", ""},
        {"1", "", ""},
        {"2", "", ""},
        {"3", "", ""},
        {"4", "", ""},
        {"5", "", ""},
        {"6", "", ""},
        {"7", "7", ""},
        {"8", "8", ""},
        {"9", "9", ""},
        {"10", "10", ""},
        {"11", "11", ""},
        {"12", "12", ""},
        {"13", "13", ""},
        {"14", "14", ""},
        {"15", "15", ""},
        {"16", "16", ""},
        {"17", "17", ""},
        {"18", "18", ""},
        {"19", "19", ""},
        {"20", "20", ""},
        {"21", "21", ""},
        {"22", "22", ""},
        {"23", "23", ""},
        {"24", "24", ""},
        {"25", "25", ""},
        {"26", "26", ""},
        {"27", "27", ""},
        {"28", "28", ""},
        {"29", "29", ""},
        {"30", "30", ""},
        {"31", "", ""}}
    };

std::array<std::array<std::string, 3>, 32> announcement_flags_values = {{
	{"0", "DO_MEGA", "BOX"},
	{"1", "PAUSE", "P"},
	{"2", "RECENTER", "R"},
	{"3", "A_DISPLAY", "A_D"},
	{"4", "D_DISPLAY", "D_D"},
	{"5", "UNIT_COMBAT_REPORT", "UCR"},
	{"6", "UNIT_COMBAT_REPORT_ALL_ACTIVE", "UCR_A"},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> poetic_form_feature_values = {{
	{"0", "InternalRhyme", ""},
	{"1", "EndRhymesDontMatch", ""},
	{"2", "Alliteration", ""},
	{"3", "Onomatopoeia", ""},
	{"4", "antanaclasis", ""},
	{"5", "DifferentReadings", ""},
	{"6", "ReadBackwards", ""},
	{"7", "ReadOrthogonally", ""},
	{"8", "Emerge", ""},
	{"9", "Assonance", ""},
	{"10", "Consonance", ""},
	{"11", "Elision", ""},
	{"12", "Epenthesis", ""},
	{"13", "Synchysis", ""},
	{"14", "Allegory", ""},
	{"15", "Ambiguity", ""},
	{"16", "Symbolism", ""},
	{"17", "Metaphor", ""},
	{"18", "Simile", ""},
	{"19", "Metonymy", ""},
	{"20", "VividImagery", ""},
	{"21", "Juxtaposision", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> musical_form_feature_values = {{
	{"0", "GlideFromNoteToNote", ""},
	{"1", "UseGraceNotes", ""},
	{"2", "UseMordents", ""},
	{"3", "MakeTrills", ""},
	{"4", "PlayRapidRuns", ""},
	{"5", "LocallyImprovise", ""},
	{"6", "SpreadSyllablesOverManyNotes", ""},
	{"7", "MatchNotesAndSyllables", ""},
	{"8", "Syncopate", ""},
	{"9", "AddFills", ""},
	{"10", "AlternateTensionAndRepose", ""},
	{"11", "ModulateFrequently", ""},
	{"12", "PlayArpeggios", ""},
	{"13", "PlayStaccato", ""},
	{"14", "PlayLegato", ""},
	{"15", "FreelyAdjustBeats", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> musical_form_interval__T_flags_values = {{
	{"0", "rising", "otherwise falling"},
	{"1", "flattened", ""},
	{"2", "sharpened", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> building_flags_values = {{
	{"0", "exists", "actually built, not just ordered"},
	{"1", "site_blocked", "items on ground on site"},
	{"2", "room_collision", "major intersection with another room?"},
	{"3", "", ""},
	{"4", "justice", ""},
	{"5", "almost_deleted", "when requesting delete while in_update"},
	{"6", "in_update", ""},
	{"7", "from_worldgen", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> door_flags_values = {{
	{"0", "forbidden", ""},
	{"1", "internal", ""},
	{"2", "taken_by_invaders", ""},
	{"3", "used_by_intruder", ""},
	{"4", "closed", ""},
	{"5", "operated_by_mechanisms", ""},
	{"6", "pet_passable", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> gate_flags_values = {{
	{"0", "closed", ""},
	{"1", "closing", ""},
	{"2", "opening", ""},
	{"3", "collapsing", "?; bridge"},
	{"4", "has_support", "bridge"},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> hospital_supplies__T_supplies_needed_values = {{
	{"0", "splints", ""},
	{"1", "thread", ""},
	{"2", "cloth", ""},
	{"3", "crutches", ""},
	{"4", "plaster", ""},
	{"5", "buckets", ""},
	{"6", "soap", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> hive_flags_values = {{
	{"0", "do_install", ""},
	{"1", "do_gather", ""},
	{"2", "ready_split", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> pressure_plate_info__T_flags_values = {{
	{"0", "units", ""},
	{"1", "water", ""},
	{"2", "magma", ""},
	{"3", "citizens", ""},
	{"4", "resets", ""},
	{"5", "track", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> gait_info__T_flags_values = {{
	{"0", "layers_slow", ""},
	{"1", "strength", ""},
	{"2", "agility", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> creature_interaction_target_flags_values = {{
	{"0", "LINE_OF_SIGHT", ""},
	{"1", "TOUCHABLE", ""},
	{"2", "DISTURBER_ONLY", ""},
	{"3", "SELF_ALLOWED", ""},
	{"4", "SELF_ONLY", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> descriptor_shape__T_gems_use_values = {{
	{"0", "noun", ""},
	{"1", "adj", ""},
	{"2", "adj_noun", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> entity_activity_statistics__T_found_misc_values = {{
	{"0", "deep_special", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> entity_animal_raw__T_flags_values = {{
	{"0", "ALWAYS_PRESENT", ""},
	{"1", "NEVER_MOUNT", ""},
	{"2", "ALWAYS_MOUNT", ""},
	{"3", "NEVER_WAGON_PULLER", ""},
	{"4", "ALWAYS_WAGON_PULLER", ""},
	{"5", "NEVER_SIEGE", ""},
	{"6", "ALWAYS_SIEGE", ""},
	{"7", "NEVER_PET", ""},
	{"8", "ALWAYS_PET", ""},
	{"9", "NEVER_PACK_ANIMAL", ""},
	{"10", "ALWAYS_PACK_ANIMAL", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> history_event_reclaim_sitest__T_flags2_values = {{
	{"0", "unretire", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> history_event_site_diedst__T_flags2_values = {{
	{"0", "abandoned", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> history_event_site_retiredst__T_flags2_values = {{
	{"0", "first_time", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> history_event_war_site_tribute_forcedst__T_tribute_flags_values = {{
	{"0", "bled_dry", "tribute was demanded, but not received"},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> history_event_hist_figure_woundedst__T_flags2_values = {{
	{"0", "torture", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> history_event_entity_lawst__T_add_flags_values = {{
	{"0", "harsh", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> history_event_entity_lawst__T_remove_flags_values = {{
	{"0", "harsh", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> history_event_artifact_copiedst__T_flags2_values = {{
	{"0", "from_original", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> history_event_modified_buildingst__T_modification_values = {{
	{"0", "dungeon", ""},
	{"1", "fortifications", ""},
	{"2", "courtyard", ""},
	{"3", "feast_hall", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> history_event_hf_convictedst__T_punishment_flags_values = {{
	{"0", "beaten", ""},
	{"1", "exiled", ""},
	{"2", "death_sentence", "sentenced to death"},
	{"3", "no_prison_available", "would have been imprisoned but for lack of accommodations"},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> history_event_hf_convictedst__T_plot_flags_values = {{
	{"0", "wrongful", "wrongful conviction"},
	{"1", "plot_surveillance", "due to ongoing surveillance as the plot unfolded"},
	{"2", "target_surveillance", "due to ongoing surveillance on the target"},
	{"3", "implicated_others", "implicated others during interrogation"},
	{"4", "co_conspirator_surveillance", "due to ongoing surveillance on a coconspirator"},
	{"5", "go_between", "convicted as go-between"},
	{"6", "revealed_nothing", "revealed nothing during interrogation"},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> history_event_hf_interrogatedst__T_interrogation_flags_values = {{
	{"0", "recognized", ""},
	{"1", "refused_to_reveal", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> interaction_source_regionst__T_region_flags_values = {{
	{"0", "NORMAL_ALLOWED", ""},
	{"1", "EVIL_ALLOWED", ""},
	{"2", "GOOD_ALLOWED", ""},
	{"3", "SAVAGE_ALLOWED", ""},
	{"4", "EVIL_ONLY", ""},
	{"5", "GOOD_ONLY", ""},
	{"6", "SAVAGE_ONLY", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> interaction_target_info__T_restrictions_values = {{
	{"0", "CANNOT_TARGET_IF_ALREADY_AFFECTED", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> weapon_attack__T_flags_values = {{
	{"0", "independent_multiattack", ""},
	{"1", "bad_multiattack", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> instrument_piece__T_flags_values = {{
	{"0", "always_singular", ""},
	{"1", "always_plural", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> engraving_flags_values = {{
	{"0", "floor", ""},
	{"1", "west", ""},
	{"2", "east", ""},
	{"3", "north", ""},
	{"4", "south", ""},
	{"5", "hidden", ""},
	{"6", "northwest", ""},
	{"7", "northeast", ""},
	{"8", "southwest", ""},
	{"9", "southeast", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> item_flags_values = {{
	{"0", "on_ground", "Item on ground"},
	{"1", "in_job", "Item currently being used in a job"},
	{"2", "hostile", "Item owned by hostile"},
	{"3", "in_inventory", "Item in a creature, workshop or container inventory"},
	{"4", "removed", "completely invisible and with no position"},
	{"5", "in_building", "Part of a building (including mechanisms, bodies in coffins)"},
	{"6", "container", "Set on anything that contains or contained items?"},
	{"7", "dead_dwarf", "Dwarfs dead body or body part"},
	{"8", "rotten", "Rotten food"},
	{"9", "spider_web", "Thread in spider web"},
	{"10", "construction", "Material used in construction"},
	{"11", "encased", "Item encased in ice or obsidian"},
	{"12", "unk12", "unknown, unseen"},
	{"13", "murder", "Implies murder - used in fell moods"},
	{"14", "foreign", "Item is imported"},
	{"15", "trader", "Item ownwed by trader"},
	{"16", "owned", "Item is owned by a dwarf"},
	{"17", "garbage_collect", "Marked for deallocation by DF it seems"},
	{"18", "artifact", "Artifact"},
	{"19", "forbid", "Forbidden item"},
	{"20", "already_uncategorized", "unknown, unseen"},
	{"21", "dump", "Designated for dumping"},
	{"22", "on_fire", "Indicates if item is on fire, Will Set Item On Fire if Set!"},
	{"23", "melt", "Designated for melting, if applicable"},
	{"24", "hidden", "Hidden item"},
	{"25", "in_chest", "Stored in chest/part of well?"},
	{"26", "use_recorded", "transient in unit.used_items update"},
	{"27", "artifact_mood", "created by mood/named existing item"},
	{"28", "temps_computed", "melting/boiling/ignite/etc. points"},
	{"29", "weight_computed", ""},
	{"30", "unk30", "unknown, unseen"},
	{"31", "from_worldgen", "created by underground critters?"}
}};

std::array<std::array<std::string, 3>, 32> item_flags2_values = {{
	{"0", "has_rider", "vehicle with a rider"},
	{"1", "unk1", ""},
	{"2", "grown", ""},
	{"3", "unk_book", "possibly book/written-content-related"},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> body_part_status_values = {{
	{"0", "on_fire", ""},
	{"1", "missing", ""},
	{"2", "organ_loss", "cyan"},
	{"3", "organ_damage", "yellow"},
	{"4", "muscle_loss", "red"},
	{"5", "muscle_damage", "yellow"},
	{"6", "bone_loss", "red"},
	{"7", "bone_damage", "yellow"},
	{"8", "skin_damage", "brown"},
	{"9", "motor_nerve_severed", ""},
	{"10", "sensory_nerve_severed", ""},
	{"11", "spilled_guts", ""},
	{"12", "has_splint", ""},
	{"13", "has_bandage", ""},
	{"14", "has_plaster_cast", ""},
	{"15", "grime", ""},
	{"16", "severed_or_jammed", "seen e.g. on ribs smashed by blunt attack, but quickly disappeared"},
	{"17", "under_shell", ""},
	{"18", "is_shell", ""},
	{"19", "unk19", "on zombified head"},
	{"20", "unk20", "on zombified head"},
	{"21", "gelded", "set on GELDABLE body parts after a unit has been gelded"},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> body_layer_status_values = {{
	{"0", "gone", ""},
	{"1", "leaking", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> item_matstate_values = {{
	{"0", "no_auto_clean", "isAutoClean returns false"},
	{"1", "pressed", ""},
	{"2", "paste", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> job_material_category_values = {{
	{"0", "plant", ""},
	{"1", "wood", "wood log"},
	{"2", "cloth", ""},
	{"3", "silk", ""},
	{"4", "leather", ""},
	{"5", "bone", ""},
	{"6", "shell", ""},
	{"7", "wood2", "wood material"},
	{"8", "soap", ""},
	{"9", "tooth", ""},
	{"10", "horn", ""},
	{"11", "pearl", ""},
	{"12", "yarn", ""},
	{"13", "strand", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> dfhack_material_category_values = {{
	{"0", "", ""},
	{"1", "plant", ""},
	{"2", "wood", ""},
	{"3", "cloth", ""},
	{"4", "silk", ""},
	{"5", "leather", ""},
	{"6", "bone", ""},
	{"7", "shell", ""},
	{"8", "wood2", ""},
	{"9", "soap", ""},
	{"10", "tooth", ""},
	{"11", "horn", ""},
	{"12", "pearl", ""},
	{"13", "yarn", ""},
	{"14", "strand", ""},
	{"15", "metal", ""},
	{"16", "stone", ""},
	{"17", "sand", ""},
	{"18", "glass", ""},
	{"19", "clay", ""},
	{"20", "milk", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> job_flags_values = {{
	{"0", "repeat", ""},
	{"1", "suspend", ""},
	{"2", "working", "not for food, or store in sp"},
	{"3", "fetching", "Actually going out to bring; corresponds to items->is_fetching"},
	{"4", "special", "Sleep/Drink/Eat/Clean; cannot be aborted via the ui"},
	{"5", "bringing", ""},
	{"6", "item_lost", "set when a Hauled item is removed; causes cancel"},
	{"7", "noise", "on the sleep job causes thoughts"},
	{"8", "by_manager", ""},
	{"9", "store_item", ""},
	{"10", "quality", "set by improvement code"},
	{"11", "specific_dropoff", "for some jobs, blocks auto-restockpiling of the hauled item"},
	{"12", "", ""},
	{"13", "on_break", "job displayed as On Break"},
	{"14", "", ""},
	{"15", "do_now", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> job_item_flags1_values = {{
	{"0", "improvable", "vtable[155]:eax,-1,-1"},
	{"1", "butcherable", "(call 0074c6d0)"},
	{"2", "millable", "vtable[79]"},
	{"3", "allow_buryable", "ALLOW items with flag 'dead_dwarf'"},
	{"4", "unrotten", "check for item flag 'rotten'"},
	{"5", "undisturbed", "check for item flag 'spider_web'"},
	{"6", "collected", "check for item flag 'spider_web'"},
	{"7", "sharpenable", "vtable[25]"},
	{"8", "murdered", "check for item flag"},
	{"9", "distillable", "vtable[105],1"},
	{"10", "empty", "(call 00753a40)"},
	{"11", "processable", "vtable[80]"},
	{"12", "bag", "vtable[131]"},
	{"13", "cookable", "(call 00753fe0)"},
	{"14", "extract_bearing_plant", "vtable[164]"},
	{"15", "extract_bearing_fish", "vtable[181]"},
	{"16", "extract_bearing_vermin", "vtable[182]"},
	{"17", "processable_to_vial", "vtable[81]"},
	{"18", "processable_to_bag", "vtable[82]"},
	{"19", "processable_to_barrel", "vtable[83]"},
	{"20", "solid", "vtable[74]"},
	{"21", "tameable_vermin", "vtable[104]"},
	{"22", "nearby", ""},
	{"23", "sand_bearing", "vtable[108]"},
	{"24", "glass", "check for material flag IS_GLASS"},
	{"25", "milk", "(call 00753d30 - check if material has CHEESE_MAT?)"},
	{"26", "milkable", "vtable[107],1,1"},
	{"27", "finished_goods", ""},
	{"28", "ammo", ""},
	{"29", "furniture", ""},
	{"30", "not_bin", ""},
	{"31", "lye_bearing", ""}
}};

std::array<std::array<std::string, 3>, 32> job_item_flags2_values = {{
	{"0", "dye", "vtable[106]"},
	{"1", "dyeable", "vtable[159]"},
	{"2", "dyed", "vtable[161]"},
	{"3", "sewn_imageless", "vtable[162]"},
	{"4", "glass_making", "vtable[26]"},
	{"5", "screw", "vtable[46]"},
	{"6", "building_material", "vtable[47]"},
	{"7", "fire_safe", "vtable[48],1"},
	{"8", "magma_safe", "vtable[48],2"},
	{"9", "deep_material", "check for inorganic material flag DEEP"},
	{"10", "melt_designated", "check for item flag 'melt'"},
	{"11", "non_economic", "(call 0076be60)"},
	{"12", "allow_melt_dump", "item can be designated for melting or dumping"},
	{"13", "allow_artifact", "item can be artifact"},
	{"14", "plant", "check if material is a PLANT_MAT"},
	{"15", "silk", "check for material flag SILK"},
	{"16", "leather", "check for material flag LEATHER"},
	{"17", "bone", "check for material flag BONE"},
	{"18", "shell", "check for material flag SHELL"},
	{"19", "totemable", "vtable[158]"},
	{"20", "horn", "check for material flag HORN"},
	{"21", "pearl", "check for material flag PEARL"},
	{"22", "plaster_containing", "vtable[17]"},
	{"23", "", ""},
	{"24", "soap", "check for material flag SOAP"},
	{"25", "body_part", "itemtype CORPSE or CORPSEPIECE"},
	{"26", "ivory_tooth", "check for material flag TOOTH"},
	{"27", "lye_milk_free", "(call 00759110)"},
	{"28", "blunt", "vtable[157]"},
	{"29", "unengraved", "vtable[214]"},
	{"30", "hair_wool", "??? (pretty sure this is [ANY_STRAND_TISSUE])"},
	{"31", "yarn", "check for material flag YARN"}
}};

std::array<std::array<std::string, 3>, 32> job_item_flags3_values = {{
	{"0", "unimproved", "vtable[176]"},
	{"1", "any_raw_material", "itemtype BAR, BOULDER, POWDER_MISC, or GLOB"},
	{"2", "non_absorbent", "vtable[215]"},
	{"3", "non_pressed", "vtable[91]"},
	{"4", "allow_liquid_powder", ""},
	{"5", "any_craft", "FIGURINE, AMULET, SCEPTER, CROWN, RING, EARRING, BRACLET"},
	{"6", "hard", "check for material flag ITEMS_HARD"},
	{"7", "food_storage", "vtable[15]"},
	{"8", "metal", ""},
	{"9", "sand", ""},
	{"10", "", ""},
	{"11", "written_on", ""},
	{"12", "edged", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> manager_order_status_values = {{
	{"0", "validated", ""},
	{"1", "active", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> training_assignment__T_flags_values = {{
	{"0", "any_trainer", ""},
	{"1", "any_unassigned_trainer", ""},
	{"2", "train_war", ""},
	{"3", "train_hunt", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> knowledge_scholar_flags_0_values = {{
	{"0", "philosophy_logic_formal_reasoning", ""},
	{"1", "philosophy_logic_deductive_reasoning", ""},
	{"2", "philosophy_logic_syllogistic_logic", ""},
	{"3", "philosophy_logic_hypothetical_syllogisms", ""},
	{"4", "philosophy_logic_propositional_logic", ""},
	{"5", "philosophy_logic_dialectic_reasoning", ""},
	{"6", "philosophy_logic_analogical_inference", ""},
	{"7", "philosophy_ethics_applied_medical", ""},
	{"8", "philosophy_ethics_individual_value", ""},
	{"9", "philosophy_ethics_state_consequentialism", ""},
	{"10", "philosophy_epistemology_truth", ""},
	{"11", "philosophy_epistemology_perception", ""},
	{"12", "philosophy_epistemology_justification", ""},
	{"13", "philosophy_epistemology_belief", ""},
	{"14", "philosophy_metaphysics_existence", ""},
	{"15", "philosophy_metaphysics_time", ""},
	{"16", "philosophy_metaphysics_mind_body", ""},
	{"17", "philosophy_metaphysics_objects_and_properties", ""},
	{"18", "philosophy_metaphysics_wholes_and_parts", ""},
	{"19", "philosophy_metaphysics_events", ""},
	{"20", "philosophy_metaphysics_processes", ""},
	{"21", "philosophy_metaphysics_causation", ""},
	{"22", "philosophy_ethics_applied_military", ""},
	{"23", "philosophy_ethics_applied_interpersonal_conduct", ""},
	{"24", "philosophy_specialized_law", ""},
	{"25", "philosophy_specialized_education", ""},
	{"26", "philosophy_specialized_language_grammar", ""},
	{"27", "philosophy_specialized_language_etymology", ""},
	{"28", "philosophy_specialized_politics_diplomacy", ""},
	{"29", "philosophy_specialized_politics_government_forms", ""},
	{"30", "philosophy_specialized_politics_economic_policy", ""},
	{"31", "philosophy_specialized_politics_social_welfare", ""}
}};

std::array<std::array<std::string, 3>, 32> knowledge_scholar_flags_1_values = {{
	{"0", "philosophy_logic_inductive_reasoning", ""},
	{"1", "philosophy_logic_direct_inference", ""},
	{"2", "philosophy_aesthetics_nature_of_beauty", ""},
	{"3", "philosophy_aesthetics_value_of_art", ""},
	{"4", "philosophy_specialized_language_dictionary", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> knowledge_scholar_flags_2_values = {{
	{"0", "mathematics_method_proof_by_contradiction", ""},
	{"1", "mathematics_notation_zero", ""},
	{"2", "mathematics_notation_negative_numbers", ""},
	{"3", "mathematics_notation_large_numbers", ""},
	{"4", "mathematics_notation_positional", ""},
	{"5", "mathematics_geometry_basic_objects", ""},
	{"6", "mathematics_method_exhaustion", ""},
	{"7", "mathematics_geometry_similar_and_congruent_triangles", ""},
	{"8", "mathematics_geometry_geometric_mean_theorem", ""},
	{"9", "mathematics_geometry_isosceles_base_angles_equal", ""},
	{"10", "mathematics_geometry_inscribed_triangle_on_diameter_is_right", ""},
	{"11", "mathematics_geometry_pythagorean_theorem", ""},
	{"12", "mathematics_geometry_pythagorean_triples_small", ""},
	{"13", "mathematics_geometry_pythagorean_triples_3_digit", ""},
	{"14", "mathematics_geometry_pythagorean_triples_4_digit", ""},
	{"15", "mathematics_geometry_existence_of_incommensurable_ratios", ""},
	{"16", "mathematics_method_axiomatic_reasoning", ""},
	{"17", "mathematics_numbers_unique_prime_factorization", ""},
	{"18", "mathematics_numbers_algorithm_for_computing_gcd", ""},
	{"19", "mathematics_geometry_volume_of_pyramid", ""},
	{"20", "mathematics_geometry_volume_of_cone", ""},
	{"21", "mathematics_geometry_volume_of_sphere", ""},
	{"22", "mathematics_geometry_pi_to_4_digits", ""},
	{"23", "mathematics_numbers_division_algorithm", ""},
	{"24", "mathematics_geometry_table_of_chord_values", ""},
	{"25", "mathematics_geometry_area_of_triangle_from_side_lengths", ""},
	{"26", "mathematics_geometry_area_of_circle", ""},
	{"27", "mathematics_geometry_pi_to_6_digits", ""},
	{"28", "mathematics_geometry_definitions_and_basic_properties_of_conic_sections", ""},
	{"29", "mathematics_numbers_chinese_remainder_algorithm", ""},
	{"30", "mathematics_geometry_area_enclosed_by_line_and_parabola", ""},
	{"31", "mathematics_numbers_sieve_algorithm_for_primes", ""}
}};

std::array<std::array<std::string, 3>, 32> knowledge_scholar_flags_3_values = {{
	{"0", "mathematics_numbers_root_2_to_5_digits", ""},
	{"1", "mathematics_numbers_infinite_primes", ""},
	{"2", "mathematics_numbers_root_2_irrational", ""},
	{"3", "mathematics_geometry_surface_area_of_sphere", ""},
	{"4", "mathematics_algebra_finite_summation_formulas", ""},
	{"5", "mathematics_algebra_solving_linear_systems", ""},
	{"6", "mathematics_algebra_balancing_and_completion", ""},
	{"7", "mathematics_algebra_quadratic_by_completing_square", ""},
	{"8", "mathematics_algebra_quadratic_formula", ""},
	{"9", "mathematics_notation_syncopated_algebra", ""},
	{"10", "mathematics_geometry_law_of_sines", ""},
	{"11", "mathematics_geometry_angle_sum_difference_trig_identities", ""},
	{"12", "mathematics_algebra_pascals_triangle", ""},
	{"13", "mathematics_algebra_solving_higher_order_polynomials", ""},
	{"14", "mathematics_notation_early_symbols_for_operations", ""},
	{"15", "mathematics_algebra_divergence_of_harmonic_series", ""},
	{"16", "mathematics_geometry_properties_of_chords", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> knowledge_scholar_flags_4_values = {{
	{"0", "history_sourcing_basic_reliability", ""},
	{"1", "history_sourcing_role_of_systemic_bias", ""},
	{"2", "history_sourcing_role_of_state_bias_and_propaganda", ""},
	{"3", "history_sourcing_personal_interviews", ""},
	{"4", "history_theory_historical_causation", ""},
	{"5", "history_theory_historical_cycles", ""},
	{"6", "history_theory_social_cohesion", ""},
	{"7", "history_theory_social_conflict", ""},
	{"8", "history_form_biography", ""},
	{"9", "history_form_comparative_biography", ""},
	{"10", "history_form_biographical_dictionaries", ""},
	{"11", "history_form_autobiographical_adventure", ""},
	{"12", "history_form_genealogy", ""},
	{"13", "history_form_encyclopedia", ""},
	{"14", "history_form_cultural_history", ""},
	{"15", "history_form_cultural_comparison", ""},
	{"16", "history_sourcing_role_of_cultural_differences", ""},
	{"17", "history_form_alternate_history", ""},
	{"18", "history_sourcing_basic_archaeology", ""},
	{"19", "history_form_treatise_on_tech_evolution", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> knowledge_scholar_flags_5_values = {{
	{"0", "astronomy_phases_of_the_moon", ""},
	{"1", "astronomy_summer_winter_moon", ""},
	{"2", "astronomy_path_of_the_moon", ""},
	{"3", "astronomy_tides_and_the_moon", ""},
	{"4", "astronomy_height_of_tides_vs_moon_and_sun", ""},
	{"5", "astronomy_summer_winter_sun", ""},
	{"6", "astronomy_relationship_between_lunar_solar_year", ""},
	{"7", "astronomy_daylight_variation_with_solar_year", ""},
	{"8", "astronomy_geocentric_model", ""},
	{"9", "astronomy_heliocentric_model", ""},
	{"10", "astronomy_dates_of_lunar_and_solar_eclipses", ""},
	{"11", "astronomy_star_charts", ""},
	{"12", "astronomy_star_catalogues_100", ""},
	{"13", "astronomy_star_catalogues_1000", ""},
	{"14", "astronomy_star_color_classification", ""},
	{"15", "astronomy_star_magnitude_classification", ""},
	{"16", "astronomy_shape_of_the_world", ""},
	{"17", "astronomy_precession_of_equinoxes", ""},
	{"18", "astronomy_method_empirical_observation", ""},
	{"19", "astronomy_method_path_models", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> knowledge_scholar_flags_6_values = {{
	{"0", "naturalist_method_dissection", ""},
	{"1", "naturalist_observation_anatomy", ""},
	{"2", "naturalist_theory_comparative_anatomy", ""},
	{"3", "naturalist_theory_classification_by_physical_features", ""},
	{"4", "naturalist_observation_migration_patterns", ""},
	{"5", "naturalist_observation_reproductive_behavior", ""},
	{"6", "naturalist_observation_foraging_behavior_and_diet", ""},
	{"7", "naturalist_theory_food_chain", ""},
	{"8", "naturalist_observation_social_behavior", ""},
	{"9", "naturalist_observation_diseases", ""},
	{"10", "naturalist_theory_climactic_adaptation", ""},
	{"11", "naturalist_observation_embriological_development", ""},
	{"12", "naturalist_theory_struggle_for_existence", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> knowledge_scholar_flags_7_values = {{
	{"0", "chemistry_classification_combustibles", ""},
	{"1", "chemistry_classification_ores", ""},
	{"2", "chemistry_metallurgy_alloys", ""},
	{"3", "chemistry_classification_scratch_test", ""},
	{"4", "chemistry_classification_elemental_theory", ""},
	{"5", "chemistry_chemicals_adhesives", ""},
	{"6", "chemistry_laboratory_blast_furnace", ""},
	{"7", "chemistry_laboratory_alembic", ""},
	{"8", "chemistry_laboratory_theory_of_liquid_liquid_extraction", ""},
	{"9", "chemistry_laboratory_theory_of_distillation", ""},
	{"10", "chemistry_laboratory_theory_of_evaporation", ""},
	{"11", "chemistry_classification_alkali_and_acids", ""},
	{"12", "chemistry_laboratory_systematic_experiments", ""},
	{"13", "chemistry_laboratory_glass_flask", ""},
	{"14", "chemistry_laboratory_glass_beaker", ""},
	{"15", "chemistry_laboratory_glass_vial", ""},
	{"16", "chemistry_laboratory_glass_funnel", ""},
	{"17", "chemistry_laboratory_crucible", ""},
	{"18", "chemistry_chemicals_nitric_acid", ""},
	{"19", "chemistry_chemicals_sulfuric_acid", ""},
	{"20", "chemistry_chemicals_aqua_regia", ""},
	{"21", "chemistry_laboratory_glass_ampoule", ""},
	{"22", "chemistry_laboratory_glass_retort", ""},
	{"23", "chemistry_laboratory_lab_ovens", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> knowledge_scholar_flags_8_values = {{
	{"0", "geography_surveying_basic", ""},
	{"1", "geography_surveying_staff", ""},
	{"2", "geography_cartography_basic", ""},
	{"3", "geography_surveying_triangulation", ""},
	{"4", "geography_surveying_cartographical", ""},
	{"5", "geography_surveying_land", ""},
	{"6", "geography_surveying_military", ""},
	{"7", "geography_surveying_engineering", ""},
	{"8", "geography_cartography_geological", ""},
	{"9", "geography_cartography_grid_system", ""},
	{"10", "geography_cartography_distance_scale", ""},
	{"11", "geography_cartography_height_measurements", ""},
	{"12", "geography_method_economic_data_collection", ""},
	{"13", "geography_cartography_economic", ""},
	{"14", "geography_form_atlas", ""},
	{"15", "geography_theory_delta_formation", ""},
	{"16", "geography_theory_wind_patterns", ""},
	{"17", "geography_theory_origin_of_rainfall_from_evap_condense", ""},
	{"18", "geography_theory_water_cycle", ""},
	{"19", "geography_theory_latitude_climate_zones", ""},
	{"20", "geography_cartography_accurate_maps", ""},
	{"21", "geography_cartography_map_projections", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> knowledge_scholar_flags_9_values = {{
	{"0", "medicine_theory_disease_and_fouled_water", ""},
	{"1", "medicine_method_physical_examination", ""},
	{"2", "medicine_method_autopsy", ""},
	{"3", "medicine_theory_prognosis", ""},
	{"4", "medicine_tool_herbal_remedies", ""},
	{"5", "medicine_tool_animal_remedies", ""},
	{"6", "medicine_tool_mineral_remedies", ""},
	{"7", "medicine_tool_bandages", ""},
	{"8", "medicine_theory_disease_classification", ""},
	{"9", "medicine_theory_toxicology", ""},
	{"10", "medicine_theory_acute_and_chronic_conditions", ""},
	{"11", "medicine_theory_endemic_disease", ""},
	{"12", "medicine_theory_epidemic_disease", ""},
	{"13", "medicine_theory_exacerbation", ""},
	{"14", "medicine_theory_paroxysm", ""},
	{"15", "medicine_theory_relapse", ""},
	{"16", "medicine_theory_convalescence", ""},
	{"17", "medicine_method_treatment_of_traumatic_injuries", ""},
	{"18", "medicine_method_fracture_treatment", ""},
	{"19", "medicine_theory_fracture_classification", ""},
	{"20", "medicine_tool_traction_bench", ""},
	{"21", "medicine_method_fracture_immobilization", ""},
	{"22", "medicine_tool_orthopedic_cast", ""},
	{"23", "medicine_method_surgery_excision", ""},
	{"24", "medicine_method_surgery_incision", ""},
	{"25", "medicine_method_hernia_surgery", ""},
	{"26", "medicine_method_tracheotomy_surgery", ""},
	{"27", "medicine_method_lithotomy_surgery", ""},
	{"28", "medicine_method_surgery_scraping", ""},
	{"29", "medicine_method_surgery_draining", ""},
	{"30", "medicine_method_surgery_probing", ""},
	{"31", "medicine_method_surgery_suturing", ""}
}};

std::array<std::array<std::string, 3>, 32> knowledge_scholar_flags_10_values = {{
	{"0", "medicine_method_surgery_ligature", ""},
	{"1", "medicine_theory_surgical_models", ""},
	{"2", "medicine_tool_mud_bags_as_surgical_models", ""},
	{"3", "medicine_tool_plants_as_surgical_models", ""},
	{"4", "medicine_tool_animals_as_surgical_models", ""},
	{"5", "medicine_theory_specialized_surgical_instruments", ""},
	{"6", "medicine_tool_forceps", ""},
	{"7", "medicine_tool_scalpel", ""},
	{"8", "medicine_tool_surgical_scissors", ""},
	{"9", "medicine_tool_surgical_needles", ""},
	{"10", "medicine_method_cataract_surgery", ""},
	{"11", "medicine_method_cauterization", ""},
	{"12", "medicine_method_anesthesia", ""},
	{"13", "medicine_theory_pulmonary_medicine", ""},
	{"14", "medicine_theory_anatomical_studies", ""},
	{"15", "medicine_theory_classification_of_bodily_fluids", ""},
	{"16", "medicine_theory_eye_anatomy", ""},
	{"17", "medicine_theory_motor_vs_sensory_nerves", ""},
	{"18", "medicine_theory_nervous_system_function", ""},
	{"19", "medicine_theory_reaction_time", ""},
	{"20", "medicine_theory_blood_vessels", ""},
	{"21", "medicine_theory_pulmonary_circulation", ""},
	{"22", "medicine_theory_comparative_anatomy", ""},
	{"23", "medicine_theory_the_voice", ""},
	{"24", "medicine_theory_classification_of_muscles", ""},
	{"25", "medicine_theory_classification_of_mental_illnesses", ""},
	{"26", "medicine_theory_treatment_of_mental_illnesses", ""},
	{"27", "medicine_tool_dedicated_hospitals", ""},
	{"28", "medicine_method_professional_hospital_staff", ""},
	{"29", "medicine_method_specialized_wards", ""},
	{"30", "medicine_method_hospital_lab", ""},
	{"31", "medicine_method_medical_school", ""}
}};

std::array<std::array<std::string, 3>, 32> knowledge_scholar_flags_11_values = {{
	{"0", "medicine_method_asylum_for_mentally_ill", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> knowledge_scholar_flags_12_values = {{
	{"0", "engineering_horology_shadow_clock", ""},
	{"1", "engineering_horology_water_clock", ""},
	{"2", "engineering_horology_conical_water_clock", ""},
	{"3", "engineering_horology_water_clock_reservoir", ""},
	{"4", "engineering_horology_astrarium", ""},
	{"5", "engineering_horology_hourglass", ""},
	{"6", "engineering_horology_mechanical_clock", ""},
	{"7", "engineering_machine_theory_of_pulley", ""},
	{"8", "engineering_machine_pulley", ""},
	{"9", "engineering_machine_theory_of_screw", ""},
	{"10", "engineering_machine_screw", ""},
	{"11", "engineering_machine_theory_of_wheel_and_axle", ""},
	{"12", "engineering_machine_windlass", ""},
	{"13", "engineering_machine_theory_of_wedge", ""},
	{"14", "engineering_machine_theory_of_lever", ""},
	{"15", "engineering_machine_lever", ""},
	{"16", "engineering_machine_straight_beam_balance", ""},
	{"17", "engineering_machine_theory_of_gears", ""},
	{"18", "engineering_machine_warded_lock", ""},
	{"19", "engineering_machine_tumbler_lock", ""},
	{"20", "engineering_machine_padlock", ""},
	{"21", "engineering_machine_camshaft", ""},
	{"22", "engineering_machine_crankshaft", ""},
	{"23", "engineering_machine_water_powered_sawmill", ""},
	{"24", "engineering_machine_chariot_odometer", ""},
	{"25", "engineering_machine_chain_drive", ""},
	{"26", "engineering_machine_mechanical_compass", ""},
	{"27", "engineering_machine_differential_gear", ""},
	{"28", "engineering_machine_combination_lock", ""},
	{"29", "engineering_machine_verge_escapement", ""},
	{"30", "engineering_machine_balance_wheel", ""},
	{"31", "engineering_fluid_theory_of_siphon", ""}
}};

std::array<std::array<std::string, 3>, 32> knowledge_scholar_flags_13_values = {{
	{"0", "engineering_fluid_valves", ""},
	{"1", "engineering_fluid_force_pump", ""},
	{"2", "engineering_optics_crystal_lens", ""},
	{"3", "engineering_optics_water_filled_spheres", ""},
	{"4", "engineering_optics_glass_lens", ""},
	{"5", "engineering_optics_camera_obscura", ""},
	{"6", "engineering_optics_parabolic_mirror", ""},
	{"7", "engineering_optics_theory_of_color", ""},
	{"8", "engineering_optics_theory_of_rainbows", ""},
	{"9", "engineering_optics_law_of_refraction", ""},
	{"10", "engineering_design_models_and_templates", ""},
	{"11", "engineering_construction_wood_lamination", ""},
	{"12", "engineering_astronomy_dioptra", ""},
	{"13", "engineering_astronomy_astrolabe", ""},
	{"14", "engineering_astronomy_armillary_sphere", ""},
	{"15", "engineering_astronomy_spherical_astrolabe", ""},
	{"16", "engineering_astronomy_mural_instrument", ""},
	{"17", "engineering_astronomy_orrery", ""},
	{"18", "engineering_machine_water_powered_trip_hammer", ""},
	{"19", "engineering_machine_double_acting_piston_bellows", ""},
	{"20", "engineering_fluid_archimedes_principle", ""},
	{"21", "engineering_optics_atmospheric_refraction", ""},
	{"22", "engineering_optics_cause_of_twilight", ""},
	{"23", "engineering_optics_height_of_atmosphere", ""},
	{"24", "engineering_machine_piston", ""},
	{"25", "engineering_machine_crank", ""},
	{"26", "engineering_machine_bellows", ""},
	{"27", "engineering_machine_water_powered_piston_bellows", ""},
	{"28", "engineering_machine_water_wheel", ""},
	{"29", "engineering_machine_trip_hammer", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> language_word_flags_values = {{
	{"0", "front_compound_noun_sing", ""},
	{"1", "front_compound_noun_plur", ""},
	{"2", "front_compound_adj", ""},
	{"3", "front_compound_prefix", ""},
	{"4", "rear_compound_noun_sing", ""},
	{"5", "rear_compound_noun_plur", ""},
	{"6", "rear_compound_adj", ""},
	{"7", "the_noun_sing", ""},
	{"8", "the_noun_plur", ""},
	{"9", "the_compound_noun_sing", ""},
	{"10", "the_compound_noun_plur", ""},
	{"11", "the_compound_adj", ""},
	{"12", "the_compound_prefix", ""},
	{"13", "of_noun_sing", ""},
	{"14", "of_noun_plur", ""},
	{"15", "standard_verb", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> invasion_info__T_flags_values = {{
	{"0", "active", ""},
	{"1", "siege", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "parley", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> machine_info__T_flags_values = {{
	{"0", "frozen", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> machine_conn_modes_values = {{
	{"0", "up", ""},
	{"1", "down", ""},
	{"2", "right", ""},
	{"3", "left", ""},
	{"4", "z_up", ""},
	{"5", "z_down", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> tile_designation_values = {{
	{"0", "flow_size", "liquid amount"},
	{"1", "pile", "stockpile?"},
	{"2", "dig", ""},
	{"3", "smooth", ""},
	{"4", "hidden", ""},
	{"5", "geolayer_index", ""},
	{"6", "light", ""},
	{"7", "subterranean", ""},
	{"8", "outside", ""},
	{"9", "biome", ""},
	{"10", "liquid_type", ""},
	{"11", "water_table", "aquifer"},
	{"12", "rained", ""},
	{"13", "traffic", ""},
	{"14", "flow_forbid", ""},
	{"15", "liquid_static", ""},
	{"16", "feature_local", ""},
	{"17", "feature_global", ""},
	{"18", "water_stagnant", ""},
	{"19", "water_salt", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> tile_occupancy_values = {{
	{"0", "building", ""},
	{"1", "unit", "standing"},
	{"2", "unit_grounded", "prone"},
	{"3", "item", ""},
	{"4", "edge_flow_in", "if set on an edge tile, water or magma will flow in"},
	{"5", "moss", ""},
	{"6", "arrow_color", ""},
	{"7", "arrow_variant", ""},
	{"8", "unk13_noncitizen_unit", "when noncitizen moves in, something happens and it is cleared"},
	{"9", "monster_lair", "A monster lair. Items placed wont be moved."},
	{"10", "no_grow", "seems to be set on terrain tiles where grass growth is impossible"},
	{"11", "unk16", ""},
	{"12", "unk17", ""},
	{"13", "carve_track_north", ""},
	{"14", "carve_track_south", ""},
	{"15", "carve_track_east", ""},
	{"16", "carve_track_west", ""},
	{"17", "unk22", ""},
	{"18", "unk23", ""},
	{"19", "dig_marked", ""},
	{"20", "dig_auto", ""},
	{"21", "heavy_aquifer", "Light/Heavy aquifer flag"},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> block_flags_values = {{
	{"0", "designated", "for jobs etc"},
	{"1", "update_temperature", ""},
	{"2", "update_liquid", ""},
	{"3", "update_liquid_twice", "Protects UpdateLiquid from being cleared the first time."},
	{"4", "repath_on_freeze", "reindex_pathfinding set and flag cleared if temperature below 10000"},
	{"5", "repath_on_melt", "reindex_pathfinding set and flag cleared if temperature above 10000"},
	{"6", "has_aquifer", "has at least one 'water_table' designation flag"},
	{"7", "check_aquifer", "has tiles that may get flooded by an adjacent aquifer"},
	{"8", "", "Seems to be surface or level above surface up to some limit (air biome?), with trees reaching higher than the limit. All have at least one tile of Outside. Cutting all trees in area did not seem to cause any change"},
	{"9", "subterranean_water", "has tiles with designation flow_size > 0, liquid_type = true, and subterranean. At embark:not checked how player actions affect this flag"},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> z_level_flags_values = {{
	{"0", "update", ""},
	{"1", "can_stop", ""},
	{"2", "update_twice", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> tile_liquid_flow_values = {{
	{"0", "temp_flow_timer", "set when water sloshes around, counts down to zero"},
	{"1", "unk_1", ""},
	{"2", "perm_flow_dir", ""},
	{"3", "unk_2", "periodically set whenever perm_flow_dir is nonzero"},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> construction_flags_values = {{
	{"0", "no_build_item", "build item is created from scratch upon removing construction, does not exist beforehand"},
	{"1", "top_of_wall", "used on the floors above constructed walls so you cannot remove them"},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> flow_reuse_pool__T_flags_values = {{
	{"0", "active", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> uniform_indiv_choice_values = {{
	{"0", "any", ""},
	{"1", "melee", ""},
	{"2", "ranged", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> squad_use_flags_values = {{
	{"0", "sleep", ""},
	{"1", "train", ""},
	{"2", "indiv_eq", ""},
	{"3", "squad_eq", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> uniform_flags_values = {{
	{"0", "replace_clothing", ""},
	{"1", "exact_matches", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> army_controller_sub4__T_unk_2_values = {{
	{"0", "not_sleeping", "set to 1 to make army wake up"},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> plant_flags_values = {{
	{"0", "watery", ""},
	{"1", "is_shrub", "If it is not a shrub, then it is a tree"},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> plant_tree_tile_values = {{
	{"0", "trunk", ""},
	{"1", "connection_east", ""},
	{"2", "connection_south", ""},
	{"3", "connection_west", ""},
	{"4", "connection_north", ""},
	{"5", "branches", ""},
	{"6", "twigs", ""},
	{"7", "blocked", "e.g. by other tree"},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> projectile_flags_values = {{
	{"0", "no_impact_destroy", ""},
	{"1", "has_hit_ground", ""},
	{"2", "bouncing", ""},
	{"3", "high_flying", ""},
	{"4", "piercing", ""},
	{"5", "to_be_deleted", ""},
	{"6", "unk6", ""},
	{"7", "unk7", ""},
	{"8", "parabolic", ""},
	{"9", "unk9", ""},
	{"10", "unk10", ""},
	{"11", "no_collide", ""},
	{"12", "safe_landing", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> reaction_reagent_flags_values = {{
	{"0", "PRESERVE_REAGENT", ""},
	{"1", "IN_CONTAINER", ""},
	{"2", "DOES_NOT_DETERMINE_PRODUCT_AMOUNT", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> general_ref_entity_popst__T_flags_values = {{
	{"0", "animated_corpse", ""},
	{"1", "ghostly", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> general_ref_creaturest__T_flags_values = {{
	{"0", "animated_corpse", ""},
	{"1", "ghostly", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> general_ref_unit_itemownerst__T_flags_values = {{
	{"0", "litter", "apparetly set after 1000 ticks, then confiscated in 1000 more ticks"},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> entity_site_link_flags_values = {{
	{"0", "residence", "site is residence"},
	{"1", "capital", "site is capital"},
	{"2", "fortress", "used at least by those castles which arent currently in"},
	{"3", "local_market", "for villages to think about their market town"},
	{"4", "trade_partner", "for markets to think about other markets"},
	{"5", "monument", "for a civ to know its tomb sites"},
	{"6", "primary_criminal_gang", ""},
	{"7", "criminal_gang", ""},
	{"8", "invasion_marked", "marked for invasion"},
	{"9", "land_for_holding", "all regular sites get this if civ has nobles, whether they have a noble or not (reclaim and capital (can be?) excluded, as can 'slow repopulation' by civ group)"},
	{"10", "central_holding_land", "only dwarf fortresses get this for now"},
	{"11", "land_holder_residence", "the regular sites where a baron etc. actually lives"},
	{"12", "invasion_push_out", "pushed out by invasion"},
	{"13", "reclaim", "marked for reclaim"},
	{"14", "occupation_failed", "failed to hold hostile occupation"},
	{"15", "base_of_operation", "set for some Religions, Criminals, and Merchant Companies. The function is largely a guess. Persecution, founding seen, as well as no mentioning of a relation at all in exported legends"},
	{"16", "holy_city", "for the holy city of a religion"},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> entity_site_link_status_flags_values = {{
	{"0", "failure_1", ""},
	{"1", "failure_2", ""},
	{"2", "unk_4", ""},
	{"3", "unk_8", ""},
	{"4", "unk_16", ""},
	{"5", "unk_32", ""},
	{"6", "unk_64", ""},
	{"7", "unk_128", ""},
	{"8", "unk_256", ""},
	{"9", "unk_512", ""},
	{"10", "unk_1024", ""},
	{"11", "unk_2048", ""},
	{"12", "unk_4096", ""},
	{"13", "unk_8192", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> stockpile_group_set_values = {{
	{"0", "animals", ""},
	{"1", "food", ""},
	{"2", "furniture", ""},
	{"3", "corpses", ""},
	{"4", "refuse", ""},
	{"5", "stone", ""},
	{"6", "ammo", ""},
	{"7", "coins", ""},
	{"8", "bars_blocks", ""},
	{"9", "gems", ""},
	{"10", "finished_goods", ""},
	{"11", "leather", ""},
	{"12", "cloth", ""},
	{"13", "wood", ""},
	{"14", "weapons", ""},
	{"15", "armor", ""},
	{"16", "sheet", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> route_stockpile_link__T_mode_values = {{
	{"0", "take", ""},
	{"1", "give", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> creature_interaction_effect_flags_values = {{
	{"0", "SIZE_DELAYS", ""},
	{"1", "SIZE_DILUTES", ""},
	{"2", "VASCULAR_ONLY", ""},
	{"3", "MUSCULAR_ONLY", ""},
	{"4", "RESISTABLE", ""},
	{"5", "LOCALIZED", ""},
	{"6", "MOON_PHASE", ""},
	{"7", "COUNTER_TRIGGER", ""},
	{"8", "ABRUPT_START", ""},
	{"9", "ABRUPT_END", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> cie_add_tag_mask1_values = {{
	{"0", "EXTRAVISION", ""},
	{"1", "OPPOSED_TO_LIFE", ""},
	{"2", "NOT_LIVING", ""},
	{"3", "NOEXERT", ""},
	{"4", "NOPAIN", ""},
	{"5", "NOBREATHE", ""},
	{"6", "HAS_BLOOD", ""},
	{"7", "NOSTUN", ""},
	{"8", "NONAUSEA", ""},
	{"9", "NO_DIZZINESS", ""},
	{"10", "NO_FEVERS", ""},
	{"11", "TRANCES", ""},
	{"12", "NOEMOTION", ""},
	{"13", "LIKES_FIGHTING", ""},
	{"14", "PARALYZEIMMUNE", ""},
	{"15", "NOFEAR", ""},
	{"16", "NO_EAT", ""},
	{"17", "NO_DRINK", ""},
	{"18", "NO_SLEEP", ""},
	{"19", "MISCHIEVOUS", ""},
	{"20", "NO_PHYS_ATT_GAIN", ""},
	{"21", "NO_PHYS_ATT_RUST", ""},
	{"22", "NOTHOUGHT", ""},
	{"23", "NO_THOUGHT_CENTER_FOR_MOVEMENT", ""},
	{"24", "CAN_SPEAK", ""},
	{"25", "CAN_LEARN", ""},
	{"26", "UTTERANCES", ""},
	{"27", "CRAZED", ""},
	{"28", "BLOODSUCKER", ""},
	{"29", "NO_CONNECTIONS_FOR_MOVEMENT", ""},
	{"30", "SUPERNATURAL", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> cie_add_tag_mask2_values = {{
	{"0", "NO_AGING", ""},
	{"1", "MORTAL", ""},
	{"2", "STERILE", ""},
	{"3", "FIT_FOR_ANIMATION", ""},
	{"4", "FIT_FOR_RESURRECTION", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> syndrome_flags_values = {{
	{"0", "SYN_INJECTED", ""},
	{"1", "SYN_CONTACT", ""},
	{"2", "SYN_INHALED", ""},
	{"3", "", ""},
	{"4", "SYN_INGESTED", ""},
	{"5", "SYN_NO_HOSPITAL", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> unit_flags1_values = {{
	{"0", "move_state", "Can the dwarf move or are they waiting for their movement timer"},
	{"1", "inactive", "Set for dead units and incoming/leaving critters that are alive but off-map"},
	{"2", "has_mood", "Currently in mood"},
	{"3", "had_mood", "Had a mood already"},
	{"4", "marauder", "wide class of invader/inside creature attackers"},
	{"5", "drowning", "Is currently drowning"},
	{"6", "merchant", "An active merchant"},
	{"7", "forest", "used for units no longer linked to merchant/diplomacy, they just try to leave mostly"},
	{"8", "left", "left the map"},
	{"9", "rider", "Is riding an another creature"},
	{"10", "incoming", ""},
	{"11", "diplomat", ""},
	{"12", "zombie", ""},
	{"13", "skeleton", ""},
	{"14", "can_swap", "Can swap tiles during movement (prevents multiple swaps)"},
	{"15", "on_ground", "The creature is laying on the floor, can be conscious"},
	{"16", "projectile", "Launched into the air? Funny."},
	{"17", "active_invader", "Active invader (for organized ones)"},
	{"18", "hidden_in_ambush", ""},
	{"19", "invader_origin", "Invader origin (could be inactive and fleeing)"},
	{"20", "coward", "Will flee if invasion turns around"},
	{"21", "hidden_ambusher", "Active marauder/invader moving inward?"},
	{"22", "invades", "Marauder resident/invader moving in all the way"},
	{"23", "check_flows", "Check against flows next time you get a chance"},
	{"24", "ridden", ""},
	{"25", "caged", ""},
	{"26", "tame", ""},
	{"27", "chained", ""},
	{"28", "royal_guard", ""},
	{"29", "fortress_guard", ""},
	{"30", "suppress_wield", ""},
	{"31", "important_historical_figure", "Is an important historical figure"}
}};

std::array<std::array<std::string, 3>, 32> unit_flags2_values = {{
	{"0", "swimming", ""},
	{"1", "sparring", "works, but not set for sparring military dwarves(?) (since 0.40.01?)"},
	{"2", "no_notify", "Do not notify about level gains (for embark etc)"},
	{"3", "unused", ""},
	{"4", "calculated_nerves", ""},
	{"5", "calculated_bodyparts", ""},
	{"6", "important_historical_figure", "Is important historical figure (slight variation)"},
	{"7", "killed", "Has been killed by kill function (slightly different from dead, not necessarily violent death)"},
	{"8", "cleanup_1", "Must be forgotten by forget function (just cleanup)"},
	{"9", "cleanup_2", "Must be deleted (cleanup)"},
	{"10", "cleanup_3", "Recently forgotten (cleanup)"},
	{"11", "for_trade", "Offered for trade"},
	{"12", "trade_resolved", ""},
	{"13", "has_breaks", ""},
	{"14", "gutted", ""},
	{"15", "circulatory_spray", ""},
	{"16", "locked_in_for_trading", "Locked in for trading (it's a projectile on the other set of flags, might be what the flying was)"},
	{"17", "slaughter", "marked for slaughter"},
	{"18", "underworld", "Underworld creature"},
	{"19", "resident", "Current resident"},
	{"20", "cleanup_4", "Marked for special cleanup as unused load from unit block on disk"},
	{"21", "calculated_insulation", "Insulation from clothing calculated"},
	{"22", "visitor_uninvited", "Uninvited guest"},
	{"23", "visitor", ""},
	{"24", "calculated_inventory", "Inventory order calculated"},
	{"25", "vision_good", "Vision -- have good part"},
	{"26", "vision_damaged", "Vision -- have damaged part"},
	{"27", "vision_missing", "Vision -- have missing part"},
	{"28", "breathing_good", "Breathing -- have good part"},
	{"29", "breathing_problem", "Breathing -- having a problem"},
	{"30", "roaming_wilderness_population_source", ""},
	{"31", "roaming_wilderness_population_source_not_a_map_feature", ""}
}};

std::array<std::array<std::string, 3>, 32> unit_flags3_values = {{
	{"0", "body_part_relsize_computed", ""},
	{"1", "size_modifier_computed", ""},
	{"2", "stuck_weapon_computed", "cleared if removing StuckIn item to recompute wound flags."},
	{"3", "compute_health", "causes the health structure to be created or updated"},
	{"4", "announce_titan", "Announces creature like an FB or titan."},
	{"5", "unk5", ""},
	{"6", "on_crutch", ""},
	{"7", "weight_computed", ""},
	{"8", "body_temp_in_range", "Is set to 1 every tick for non-dead creatures."},
	{"9", "wait_until_reveal", "Blocks all kind of things until tile is revealed."},
	{"10", "scuttle", ""},
	{"11", "unk11", ""},
	{"12", "ghostly", ""},
	{"13", "unk13", ""},
	{"14", "unk14", ""},
	{"15", "unk15", "dropped when znew >= zold"},
	{"16", "unk16", "something to do with werewolves?"},
	{"17", "no_meandering", "for active_invaders"},
	{"18", "floundering", ""},
	{"19", "exit_vehicle1", "trapavoid"},
	{"20", "exit_vehicle2", "trapavoid"},
	{"21", "dangerous_terrain", ""},
	{"22", "adv_yield", ""},
	{"23", "vision_cone_set", ""},
	{"24", "unk24", ""},
	{"25", "emotionally_overloaded", ""},
	{"26", "unk26", ""},
	{"27", "available_for_adoption", ""},
	{"28", "gelded", ""},
	{"29", "marked_for_gelding", ""},
	{"30", "injury_thought", ""},
	{"31", "unk31", ""}
}};

std::array<std::array<std::string, 3>, 32> unit_flags4_values = {{
	{"0", "unk0", ""},
	{"1", "unk1", ""},
	{"2", "unk2", ""},
	{"3", "unk3", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> wound_damage_flags1_values = {{
	{"0", "cut", ""},
	{"1", "smashed", ""},
	{"2", "scar_cut", "straight scar"},
	{"3", "scar_smashed", "huge dent"},
	{"4", "tendon_bruised", ""},
	{"5", "tendon_strained", ""},
	{"6", "tendon_torn", ""},
	{"7", "ligament_bruised", ""},
	{"8", "ligament_sprained", ""},
	{"9", "ligament_torn", ""},
	{"10", "motor_nerve_severed", ""},
	{"11", "sensory_nerve_severed", ""},
	{"12", "edged_damage", ""},
	{"13", "smashed_apart", "?"},
	{"14", "major_artery", ""},
	{"15", "guts_spilled", ""},
	{"16", "edged_shake1", ""},
	{"17", "scar_edged_shake1", "jagged scar"},
	{"18", "edged_shake2", ""},
	{"19", "broken", ""},
	{"20", "scar_broken", "huge dent"},
	{"21", "gouged", ""},
	{"22", "blunt_shake1", ""},
	{"23", "scar_blunt_shake1", "jagged scar"},
	{"24", "blunt_shake2", ""},
	{"25", "joint_bend1", ""},
	{"26", "scar_joint_bend1", "jagged scar"},
	{"27", "joint_bend2", ""},
	{"28", "compound_fracture", ""},
	{"29", "diagnosed", ""},
	{"30", "artery", ""},
	{"31", "overlapping_fracture", ""}
}};

std::array<std::array<std::string, 3>, 32> wound_damage_flags2_values = {{
	{"0", "needs_setting", ""},
	{"1", "entire_surface", ""},
	{"2", "gelded", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> unit_health_flags_values = {{
	{"0", "rq_diagnosis", ""},
	{"1", "needs_recovery", "needs diagnosis but cannot walk"},
	{"2", "needs_healthcare", "???; set when rq_diagnosis is, and not blocked by having a diagnosis"},
	{"3", "rq_immobilize", ""},
	{"4", "rq_dressing", ""},
	{"5", "rq_cleaning", ""},
	{"6", "rq_surgery", ""},
	{"7", "rq_suture", ""},
	{"8", "rq_setting", ""},
	{"9", "rq_traction", ""},
	{"10", "rq_crutch", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> unit_bp_health_flags_values = {{
	{"0", "rq_immobilize", ""},
	{"1", "rq_dressing", ""},
	{"2", "rq_cleaning", ""},
	{"3", "rq_surgery", ""},
	{"4", "rq_suture", ""},
	{"5", "rq_setting", ""},
	{"6", "rq_traction", ""},
	{"7", "inoperable_rot", ""},
	{"8", "needs_bandage", "used to remove once not needed"},
	{"9", "needs_cast", "used to remove once not needed"},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> orientation_flags_values = {{
	{"0", "indeterminate", "only seen on adventurers"},
	{"1", "romance_male", ""},
	{"2", "marry_male", ""},
	{"3", "romance_female", ""},
	{"4", "marry_female", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> unit_action_data_move__T_flags_values = {{
	{"0", "charge", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> vermin_flags_values = {{
	{"0", "", ""},
	{"1", "is_colony", "A vermin colony. For example an anthill or bee hive."},
	{"2", "", ""},
	{"3", "is_roaming_colony", "colony building vermin away from colony"},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> kitchen_pref_flag_values = {{
	{"0", "Cook", ""},
	{"1", "Brew", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> health_view_bits1_values = {{
	{"0", "bleeding_heavy", ""},
	{"1", "bleeding", ""},
	{"2", "pale", ""},
	{"3", "blood_loss_severe", ""},
	{"4", "faint", ""},
	{"5", "blood_loss", ""},
	{"6", "paralyzed", ""},
	{"7", "paralyzed_partially", ""},
	{"8", "sluggish", ""},
	{"9", "numb_completely", ""},
	{"10", "numb_partially", ""},
	{"11", "numb_slightly", ""},
	{"12", "fever_serious", ""},
	{"13", "fever_moderate", ""},
	{"14", "fever_slight", ""},
	{"15", "pain_extreme", ""},
	{"16", "pain_moderate", ""},
	{"17", "pain_slight", ""},
	{"18", "exhausted", ""},
	{"19", "overexerted", ""},
	{"20", "tired", ""},
	{"21", "stunned", ""},
	{"22", "dizzy", ""},
	{"23", "drowning", ""},
	{"24", "winded", ""},
	{"25", "nauseous", ""},
	{"26", "drowsy_very", ""},
	{"27", "drowsy", ""},
	{"28", "dehydrated", ""},
	{"29", "thirsty", ""},
	{"30", "starving", ""},
	{"31", "hungry", ""}
}};

std::array<std::array<std::string, 3>, 32> health_view_bits2_values = {{
	{"0", "breathe_cant", ""},
	{"1", "breathe_trouble", ""},
	{"2", "vision_lost", ""},
	{"3", "vision_impaired", ""},
	{"4", "vision_impaired2", ""},
	{"5", "stand_cant", ""},
	{"6", "stand_impaired", ""},
	{"7", "grasp_cant", ""},
	{"8", "grasp_impaired", ""},
	{"9", "fly_cant", ""},
	{"10", "fly_impaired", ""},
	{"11", "motor_nerve", ""},
	{"12", "sensory_nerve", ""},
	{"13", "spilled", ""},
	{"14", "artery_major", ""},
	{"15", "artery", ""},
	{"16", "tendon_torn", ""},
	{"17", "tendon_strain", ""},
	{"18", "tendon_bruise", ""},
	{"19", "ligament_torn", ""},
	{"20", "ligament_sprain", ""},
	{"21", "ligament_bruise", ""},
	{"22", "fracture_compound", ""},
	{"23", "fracture_overlap", ""},
	{"24", "need_setting", ""},
	{"25", "tissue_broken", ""},
	{"26", "tissue_part_broken", ""},
	{"27", "damage_heavy", ""},
	{"28", "damage_moderate", ""},
	{"29", "damage_light", ""},
	{"30", "pain_extreme", ""},
	{"31", "pain_moderate", ""}
}};

std::array<std::array<std::string, 3>, 32> health_view_bits3_values = {{
	{"0", "pain_minor", ""},
	{"1", "swell_extreme", ""},
	{"2", "swell_medium", ""},
	{"3", "swell_minor", ""},
	{"4", "infection", ""},
	{"5", "rq_diagnosis", ""},
	{"6", "rq_crutch", ""},
	{"7", "inoperable_rot", ""},
	{"8", "rq_cleaning", ""},
	{"9", "rq_surgery", ""},
	{"10", "rq_suture", ""},
	{"11", "rq_setting", ""},
	{"12", "rq_dressing", ""},
	{"13", "rq_traction", ""},
	{"14", "rq_immobilize", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> tower_shape_values = {{
	{"0", "round", ""},
	{"1", "hollow", "no internal floors or fortifications"},
	{"2", "keep", "fill with rooms at the bottom"},
	{"3", "goblin", "ignore set heights and generate automatically"},
	{"4", "unk10", "set on goblin towers. doesnt seem to do anything"},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> report__T_flags_values = {{
	{"0", "continuation", "When split into multiple lines, set on all but the first"},
	{"1", "unconscious", "units.active[0]"},
	{"2", "announcement", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> poetic_form_part__T_flags_values = {{
	{"0", "size_in_lines", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> musical_form_instruments__T_substitutions_values = {{
	{"0", "singer", ""},
	{"1", "speaker", ""},
	{"2", "chanter", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> building_civzonest__T_zone_flags_values = {{
	{"0", "water_source", ""},
	{"1", "garbage_dump", ""},
	{"2", "sand", ""},
	{"3", "active", ""},
	{"4", "fishing", ""},
	{"5", "pit_pond", ""},
	{"6", "meeting_area", ""},
	{"7", "hospital", ""},
	{"8", "pen_pasture", ""},
	{"9", "clay", ""},
	{"10", "animal_training", ""},
	{"11", "gather", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> building_civzonest__T_pit_flags_values = {{
	{"0", "is_pond", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> building_civzonest__T_gather_flags_values = {{
	{"0", "pick_trees", ""},
	{"1", "pick_shrubs", ""},
	{"2", "gather_fallen", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> building_design__T_flags_values = {{
	{"0", "rough", "rough gabbro road"},
	{"1", "built", ""},
	{"2", "designed", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> building_bedst__T_bed_flags_values = {{
	{"0", "barracks", ""},
	{"1", "dormitory", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> building_cagest__T_cage_flags_values = {{
	{"0", "triggered", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> building_chainst__T_chain_flags_values = {{
	{"0", "triggered", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> building_coffinst__T_burial_mode_values = {{
	{"0", "allow_burial", ""},
	{"1", "no_pets", ""},
	{"2", "no_citizens", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> building_shopst__T_shop_flags_values = {{
	{"0", "for_sale", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> building_supportst__T_support_flags_values = {{
	{"0", "triggered", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> building_tablest__T_table_flags_values = {{
	{"0", "meeting_hall", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> building_tradedepotst__T_trade_flags_values = {{
	{"0", "trader_requested", ""},
	{"1", "anyone_can_trade", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> building_trapst__T_stop_flags_values = {{
	{"0", "disabled", ""},
	{"1", "disabling", ""},
	{"2", "enabling", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> building_wellst__T_well_flags_values = {{
	{"0", "lowering", ""},
	{"1", "just_raised", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> caste_attack__T_flags_values = {{
	{"0", "with", ""},
	{"1", "latch", ""},
	{"2", "main", ""},
	{"3", "edge", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> creature_interaction__T_flags_values = {{
	{"0", "CAN_BE_MUTUAL", ""},
	{"1", "VERBAL", ""},
	{"2", "FREE_ACTION", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> caste_body_info__T_flags_values = {{
	{"0", "unk0", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> caravan_state__T_flags_values = {{
	{"0", "check_cleanup", "set each time a merchant leaves the map or dies"},
	{"1", "casualty", ""},
	{"2", "hardship", ""},
	{"3", "communicate", "send data to mountainhomes"},
	{"4", "seized", ""},
	{"5", "offended", ""},
	{"6", "announce", "display merchantintro and merchantexit"},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> honors_type__T_flags_values = {{
	{"0", "granted_to_all_new_members", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> honors_type__T_required_skill_type_values = {{
	{"0", "melee_weapon", ""},
	{"1", "ranged_weapon", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> agreement__T_anon_3_values = {{
	{"0", "petition_not_accepted", "this gets unset by accepting a petition"},
	{"1", "convicted_accepted", "convicted for PositionCorruption/accepted for Location"},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> history_event_artifact_createdst__T_flags2_values = {{
	{"0", "name_only", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> history_event_hist_figure_revivedst__T_flags2_values = {{
	{"0", "again", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> history_event_tactical_situationst__T_tactics_flags_values = {{
	{"0", "start", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> interaction_effect__T_flags_values = {{
	{"0", "IMMEDIATE", "IE_IMMEDIATE"},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> interaction_source_secretst__T_learn_flags_values = {{
	{"0", "SUPERNATURAL_LEARNING_POSSIBLE", ""},
	{"1", "MUNDANE_RESEARCH_POSSIBLE", ""},
	{"2", "MUNDANE_RECORDING_POSSIBLE", ""},
	{"3", "MUNDANE_TEACHING_POSSIBLE", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> interaction_target_materialst__T_restrictions_values = {{
	{"0", "CONTEXT_MATERIAL", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> itemimprovement_coveredst__T_cover_flags_values = {{
	{"0", "glazed", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> spatter_common__T_base_flags_values = {{
	{"0", "evaporates", "does not contaminate tile when washed away"},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> spatter__T_flags_values = {{
	{"0", "water_soluble", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> item_body_component__T_corpse_flags_values = {{
	{"0", "unbutchered", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "bone", ""},
	{"5", "shell", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "skull", ""},
	{"13", "separated_part", "?"},
	{"14", "hair_wool", ""},
	{"15", "yarn", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> poetic_form__T_flags_values = {{
	{"0", "tone_patterns", ""},
	{"1", "produces_individual_poems", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> musical_form__T_flags_values = {{
	{"0", "produces_individual_songs", ""},
	{"1", "repeats_as_necessary", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> historical_entity__T_flags_values = {{
	{"0", "neighbor", "Changes as you move on embark screen. Includes kobolds, cave civs, and necros (which are SiteGovernments)"},
	{"1", "player_civ", "Changes as you change your civ on embark screen"},
	{"2", "unk2", ""},
	{"3", "unk3", ""},
	{"4", "unreliable_lost_last_site", "When set, no sites remain. Doesn't say much about remaining sites when not set"},
	{"5", "worshipping", ""},
	{"6", "unk6", "Set for a significant number of entities"},
	{"7", "unk7", ""},
	{"8", "player_government", "Appears when embarking (and having unpaused)"},
	{"9", "unk9", ""},
	{"10", "unspecific_race", "Can be set for SiteGovernment, always set for Guild and PerformanceTroupe. Never set for NomadicGroup even when race=-1"},
	{"11", "unk11", "Set for a significant number of entities. Includes the full [6] set, plus some"},
	{"12", "unk12", "Set for all but unnamed civs, kobold entities, vault governments, and cave civ building race Outcasts"},
	{"13", "unk13", "Set for a significant number of entities"},
	{"14", "unk14", "Set for a significant number of entities"},
	{"15", "unk15", "Set for a limited set of entities"},
	{"16", "unk16", "Set for a limited set of entities. All seem to be dwarven, but definitely not complete set"},
	{"17", "unk17", "Set for a limited set of entities"},
	{"18", "unk18", "Set for a limited set of entities"},
	{"19", "unk19", "Set for a limited set of entities"},
	{"20", "unk20", "Set for a limited set of entities"},
	{"21", "unk21", ""},
	{"22", "unk22", "All are religions, but not the full set"},
	{"23", "unk23", ""},
	{"24", "unk24", "Set for a significant number of entities"},
	{"25", "military_unit_property", "Probably some property only those have. All present in the selection, though"},
	{"26", "unk26", "Set for a significant number of entities"},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> item_petst__T_pet_flags_values = {{
	{"0", "available_for_adoption", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> entity_raw__T_scholar_values = {{
	{"0", "PHILOSOPHER", ""},
	{"1", "MATHEMATICIAN", ""},
	{"2", "HISTORIAN", ""},
	{"3", "ASTRONOMER", ""},
	{"4", "NATURALIST", ""},
	{"5", "CHEMIST", ""},
	{"6", "GEOGRAPHER", ""},
	{"7", "DOCTOR", ""},
	{"8", "ENGINEER", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> machine__T_flags_values = {{
	{"0", "active", ""},
	{"1", "frozen", "?"},
	{"2", "unfreeze", "?"},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> building_gear_assemblyst__T_gear_flags_values = {{
	{"0", "disengaged", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> block_square_event_mineralst__T_flags_values = {{
	{"0", "discovered", ""},
	{"1", "cluster", ""},
	{"2", "vein", ""},
	{"3", "cluster_small", ""},
	{"4", "cluster_one", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> dipscript_popup__T_flags_values = {{
	{"0", "close_screen", ""},
	{"1", "new_screen", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> meeting_diplomat_info__T_flags_values = {{
	{"0", "dynamic_load", "destroy dipscript_info in destructor"},
	{"1", "failure", ""},
	{"2", "success", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> activity_info__T_flags_values = {{
	{"0", "next_step", ""},
	{"1", "checked_building", ""},
	{"2", "add_delay", ""},
	{"3", "topic_discussed", ""},
	{"4", "meeting_done", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> room_rent_info__T_flags_values = {{
	{"0", "eviction_underway", ""},
	{"1", "move_underway", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> activity_event__T_flags_values = {{
	{"0", "dismissed", "to be removed from squad_position, anyway"},
	{"1", "squad", "for all in training session, but not ind.drill"},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> activity_event_conversationst__T_flags2_values = {{
	{"0", "", ""},
	{"1", "shouting", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> activity_event_copy_written_contentst__T_flagsmaybe_values = {{
	{"0", "unk0", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> squad_ammo_spec__T_flags_values = {{
	{"0", "use_combat", ""},
	{"1", "use_training", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> plant_growth__T_locations_values = {{
	{"0", "twigs", ""},
	{"1", "light_branches", ""},
	{"2", "heavy_branches", ""},
	{"3", "trunk", ""},
	{"4", "roots", ""},
	{"5", "cap", ""},
	{"6", "sapling", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> plant_growth__T_behavior_values = {{
	{"0", "drops_off", ""},
	{"1", "no_cloud", ""},
	{"2", "has_seed", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> plant__T_damage_flags_values = {{
	{"0", "is_burning", ""},
	{"1", "is_drowning", ""},
	{"2", "is_dead", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> stop_depart_condition__T_flags_values = {{
	{"0", "at_most", ""},
	{"1", "desired", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> unit_ghost_info__T_flags_values = {{
	{"0", "announced", ""},
	{"1", "was_at_rest", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> unit_syndrome__T_symptoms__T_flags_values = {{
	{"0", "disabled", "if PROB roll fails, or all symptoms expire"},
	{"1", "active", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> unit_syndrome__T_flags_values = {{
	{"0", "is_sick", "causes health.flags.needs_healthcare"},
	{"1", "is_sick_low", "less sick? fever: 5-19 low, 20-* full"},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> unit_wound__T_flags_values = {{
	{"0", "severed_part", ""},
	{"1", "mortal_wound", ""},
	{"2", "stuck_weapon", ""},
	{"3", "diagnosed", ""},
	{"4", "sutured", ""},
	{"5", "infection", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> unit_personality__T_emotions__T_flags_values = {{
	{"0", "unk0", ""},
	{"1", "unk1", ""},
	{"2", "unk2", ""},
	{"3", "unk3", ""},
	{"4", "remembered_longterm", ""},
	{"5", "remembered_shortterm", ""},
	{"6", "remembered_reflected_on", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> unit_personality__T_flags_values = {{
	{"0", "", ""},
	{"1", "has_unmet_needs", "focus_level is below -999 for at least one need"},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> historical_figure_info__T_known_info__T_knowledge__T_knowledge_goal_values = {{
	{"0", "unk0", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> historical_figure_info__T_books__T_flags_values = {{
	{"0", "", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> unit_action_data_attack__T_flags_values = {{
	{"0", "", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "quick", ""},
	{"6", "heavy", ""},
	{"7", "wild", ""},
	{"8", "precise", ""},
	{"9", "charge", ""},
	{"10", "", "multi-attack"},
	{"11", "", ""},
	{"12", "lightly_tap", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "spar_report", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> mission__T_details__T_raid__T_raid_flags_values = {{
	{"0", "Unknown1", ""},
	{"1", "OneTimeTribute", ""},
	{"2", "OngoingTribute", ""},
	{"3", "FreeCaptives", ""},
	{"4", "ReleaseOtherPrisoners", ""},
	{"5", "TakeImportantTreasures", ""},
	{"6", "LootOtherItems", ""},
	{"7", "StealLivestock", ""},
	{"8", "Unknown256", ""},
	{"9", "DemandSurrender", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> ui__T_equipment__T_update_values = {{
	{"0", "weapon", ""},
	{"1", "armor", ""},
	{"2", "shoes", ""},
	{"3", "shield", ""},
	{"4", "helm", ""},
	{"5", "gloves", ""},
	{"6", "ammo", ""},
	{"7", "pants", ""},
	{"8", "backpack", ""},
	{"9", "quiver", ""},
	{"10", "flask", ""},
	{"11", "", ""},
	{"12", "buildings", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> ui__T_unk23c8_flags_values = {{
	{"0", "", ""},
	{"1", "recheck_aid_requests", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> viewscreen_textviewerst__T_formatted_text__T_flags_values = {{
	{"0", "hyperlink", ""},
	{"1", "no_newline", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> viewscreen_workquota_conditionst__T_traits__T_flags_values = {{
	{"0", "", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> item_eggst__T_egg_flags_values = {{
	{"0", "fertile", "allows the incubation_counter to be checked/incremented"},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> unit__T_military__T_pickup_flags_values = {{
	{"0", "update", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> local_population__T_flags_values = {{
	{"0", "discovered", ""},
	{"1", "extinct", "guessed, based on 23a"},
	{"2", "already_removed", "no longer in world.populations"},
	{"3", "unk3", "prevents it from showing up, related to world.unk_59dc4 (now area_grasses?)"},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> region_map_entry__T_clouds_values = {{
	{"0", "front", ""},
	{"1", "cumulus", ""},
	{"2", "cirrus", ""},
	{"3", "stratus", ""},
	{"4", "fog", ""},
	{"5", "countdown", "A counter for stratus clouds that randomly decreases by 1 or 0 each timer weather is checked there. it does various stratus/fog effects based on the humidity/breezes/etc."},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> region_map_entry__T_wind_values = {{
	{"0", "north_1", ""},
	{"1", "south_1", ""},
	{"2", "east_1", ""},
	{"3", "west_1", ""},
	{"4", "north_2", ""},
	{"5", "south_2", ""},
	{"6", "east_2", ""},
	{"7", "west_2", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> incident__T_flags_values = {{
	{"0", "announced_missing", ""},
	{"1", "discovered", ""},
	{"2", "unk2", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> crime__T_flags_values = {{
	{"0", "sentenced", ""},
	{"1", "discovered", ""},
	{"2", "needs_trial", "i.e. the player chooses whom to convict"},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> job_handler__T_postings__T_flags_values = {{
	{"0", "dead", ""},
	{"1", "", ""},
	{"2", "", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> world__T_status__T_slots__T_flags_values = {{
	{"0", "behind", ""},
	{"1", "side", ""},
	{"2", "by", ""},
	{"3", "item", ""},
	{"4", "tap", ""},
	{"5", "sever", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32> world__T_status__T_flags_values = {{
	{"0", "combat", ""},
	{"1", "hunting", ""},
	{"2", "sparring", ""},
	{"3", "", ""},
	{"4", "", ""},
	{"5", "", ""},
	{"6", "", ""},
	{"7", "", ""},
	{"8", "", ""},
	{"9", "", ""},
	{"10", "", ""},
	{"11", "", ""},
	{"12", "", ""},
	{"13", "", ""},
	{"14", "", ""},
	{"15", "", ""},
	{"16", "", ""},
	{"17", "", ""},
	{"18", "", ""},
	{"19", "", ""},
	{"20", "", ""},
	{"21", "", ""},
	{"22", "", ""},
	{"23", "", ""},
	{"24", "", ""},
	{"25", "", ""},
	{"26", "", ""},
	{"27", "", ""},
	{"28", "", ""},
	{"29", "", ""},
	{"30", "", ""},
	{"31", "", ""}
}};

std::array<std::array<std::string, 3>, 32>& get_bitfield_bits(DF_Type p_df_type)
{
	switch(p_df_type)
	{
		case DF_Type::announcement_flags: return announcement_flags_values;
		case DF_Type::poetic_form_feature: return poetic_form_feature_values;
		case DF_Type::musical_form_feature: return musical_form_feature_values;
		case DF_Type::musical_form_interval__T_flags: return musical_form_interval__T_flags_values;
		case DF_Type::building_flags: return building_flags_values;
		case DF_Type::door_flags: return door_flags_values;
		case DF_Type::gate_flags: return gate_flags_values;
		case DF_Type::hospital_supplies__T_supplies_needed: return hospital_supplies__T_supplies_needed_values;
		case DF_Type::hive_flags: return hive_flags_values;
		case DF_Type::pressure_plate_info__T_flags: return pressure_plate_info__T_flags_values;
		case DF_Type::gait_info__T_flags: return gait_info__T_flags_values;
		case DF_Type::creature_interaction_target_flags: return creature_interaction_target_flags_values;
		case DF_Type::descriptor_shape__T_gems_use: return descriptor_shape__T_gems_use_values;
		case DF_Type::entity_activity_statistics__T_found_misc: return entity_activity_statistics__T_found_misc_values;
		case DF_Type::entity_animal_raw__T_flags: return entity_animal_raw__T_flags_values;
		case DF_Type::history_event_reclaim_sitest__T_flags2: return history_event_reclaim_sitest__T_flags2_values;
		case DF_Type::history_event_site_diedst__T_flags2: return history_event_site_diedst__T_flags2_values;
		case DF_Type::history_event_site_retiredst__T_flags2: return history_event_site_retiredst__T_flags2_values;
		case DF_Type::history_event_war_site_tribute_forcedst__T_tribute_flags: return history_event_war_site_tribute_forcedst__T_tribute_flags_values;
		case DF_Type::history_event_hist_figure_woundedst__T_flags2: return history_event_hist_figure_woundedst__T_flags2_values;
		case DF_Type::history_event_entity_lawst__T_add_flags: return history_event_entity_lawst__T_add_flags_values;
		case DF_Type::history_event_entity_lawst__T_remove_flags: return history_event_entity_lawst__T_remove_flags_values;
		case DF_Type::history_event_artifact_copiedst__T_flags2: return history_event_artifact_copiedst__T_flags2_values;
		case DF_Type::history_event_modified_buildingst__T_modification: return history_event_modified_buildingst__T_modification_values;
		case DF_Type::history_event_hf_convictedst__T_punishment_flags: return history_event_hf_convictedst__T_punishment_flags_values;
		case DF_Type::history_event_hf_convictedst__T_plot_flags: return history_event_hf_convictedst__T_plot_flags_values;
		case DF_Type::history_event_hf_interrogatedst__T_interrogation_flags: return history_event_hf_interrogatedst__T_interrogation_flags_values;
		case DF_Type::interaction_source_regionst__T_region_flags: return interaction_source_regionst__T_region_flags_values;
		case DF_Type::interaction_target_info__T_restrictions: return interaction_target_info__T_restrictions_values;
		case DF_Type::weapon_attack__T_flags: return weapon_attack__T_flags_values;
		case DF_Type::instrument_piece__T_flags: return instrument_piece__T_flags_values;
		case DF_Type::engraving_flags: return engraving_flags_values;
		case DF_Type::item_flags: return item_flags_values;
		case DF_Type::item_flags2: return item_flags2_values;
		case DF_Type::body_part_status: return body_part_status_values;
		case DF_Type::body_layer_status: return body_layer_status_values;
		case DF_Type::item_matstate: return item_matstate_values;
		case DF_Type::job_material_category: return job_material_category_values;
		case DF_Type::dfhack_material_category: return dfhack_material_category_values;
		case DF_Type::job_flags: return job_flags_values;
		case DF_Type::job_item_flags1: return job_item_flags1_values;
		case DF_Type::job_item_flags2: return job_item_flags2_values;
		case DF_Type::job_item_flags3: return job_item_flags3_values;
		case DF_Type::manager_order_status: return manager_order_status_values;
		case DF_Type::training_assignment__T_flags: return training_assignment__T_flags_values;
		case DF_Type::knowledge_scholar_flags_0: return knowledge_scholar_flags_0_values;
		case DF_Type::knowledge_scholar_flags_1: return knowledge_scholar_flags_1_values;
		case DF_Type::knowledge_scholar_flags_2: return knowledge_scholar_flags_2_values;
		case DF_Type::knowledge_scholar_flags_3: return knowledge_scholar_flags_3_values;
		case DF_Type::knowledge_scholar_flags_4: return knowledge_scholar_flags_4_values;
		case DF_Type::knowledge_scholar_flags_5: return knowledge_scholar_flags_5_values;
		case DF_Type::knowledge_scholar_flags_6: return knowledge_scholar_flags_6_values;
		case DF_Type::knowledge_scholar_flags_7: return knowledge_scholar_flags_7_values;
		case DF_Type::knowledge_scholar_flags_8: return knowledge_scholar_flags_8_values;
		case DF_Type::knowledge_scholar_flags_9: return knowledge_scholar_flags_9_values;
		case DF_Type::knowledge_scholar_flags_10: return knowledge_scholar_flags_10_values;
		case DF_Type::knowledge_scholar_flags_11: return knowledge_scholar_flags_11_values;
		case DF_Type::knowledge_scholar_flags_12: return knowledge_scholar_flags_12_values;
		case DF_Type::knowledge_scholar_flags_13: return knowledge_scholar_flags_13_values;
		case DF_Type::language_word_flags: return language_word_flags_values;
		case DF_Type::invasion_info__T_flags: return invasion_info__T_flags_values;
		case DF_Type::machine_info__T_flags: return machine_info__T_flags_values;
		case DF_Type::machine_conn_modes: return machine_conn_modes_values;
		case DF_Type::tile_designation: return tile_designation_values;
		case DF_Type::tile_occupancy: return tile_occupancy_values;
		case DF_Type::block_flags: return block_flags_values;
		case DF_Type::z_level_flags: return z_level_flags_values;
		case DF_Type::tile_liquid_flow: return tile_liquid_flow_values;
		case DF_Type::construction_flags: return construction_flags_values;
		case DF_Type::flow_reuse_pool__T_flags: return flow_reuse_pool__T_flags_values;
		case DF_Type::uniform_indiv_choice: return uniform_indiv_choice_values;
		case DF_Type::squad_use_flags: return squad_use_flags_values;
		case DF_Type::uniform_flags: return uniform_flags_values;
		case DF_Type::army_controller_sub4__T_unk_2: return army_controller_sub4__T_unk_2_values;
		case DF_Type::plant_flags: return plant_flags_values;
		case DF_Type::plant_tree_tile: return plant_tree_tile_values;
		case DF_Type::projectile_flags: return projectile_flags_values;
		case DF_Type::reaction_reagent_flags: return reaction_reagent_flags_values;
		case DF_Type::general_ref_entity_popst__T_flags: return general_ref_entity_popst__T_flags_values;
		case DF_Type::general_ref_creaturest__T_flags: return general_ref_creaturest__T_flags_values;
		case DF_Type::general_ref_unit_itemownerst__T_flags: return general_ref_unit_itemownerst__T_flags_values;
		case DF_Type::entity_site_link_flags: return entity_site_link_flags_values;
		case DF_Type::entity_site_link_status_flags: return entity_site_link_status_flags_values;
		case DF_Type::stockpile_group_set: return stockpile_group_set_values;
		case DF_Type::route_stockpile_link__T_mode: return route_stockpile_link__T_mode_values;
		case DF_Type::creature_interaction_effect_flags: return creature_interaction_effect_flags_values;
		case DF_Type::cie_add_tag_mask1: return cie_add_tag_mask1_values;
		case DF_Type::cie_add_tag_mask2: return cie_add_tag_mask2_values;
		case DF_Type::syndrome_flags: return syndrome_flags_values;
		case DF_Type::unit_flags1: return unit_flags1_values;
		case DF_Type::unit_flags2: return unit_flags2_values;
		case DF_Type::unit_flags3: return unit_flags3_values;
		case DF_Type::unit_flags4: return unit_flags4_values;
		case DF_Type::wound_damage_flags1: return wound_damage_flags1_values;
		case DF_Type::wound_damage_flags2: return wound_damage_flags2_values;
		case DF_Type::unit_health_flags: return unit_health_flags_values;
		case DF_Type::unit_bp_health_flags: return unit_bp_health_flags_values;
		case DF_Type::orientation_flags: return orientation_flags_values;
		case DF_Type::unit_action_data_move__T_flags: return unit_action_data_move__T_flags_values;
		case DF_Type::vermin_flags: return vermin_flags_values;
		case DF_Type::kitchen_pref_flag: return kitchen_pref_flag_values;
		case DF_Type::health_view_bits1: return health_view_bits1_values;
		case DF_Type::health_view_bits2: return health_view_bits2_values;
		case DF_Type::health_view_bits3: return health_view_bits3_values;
		case DF_Type::tower_shape: return tower_shape_values;
		case DF_Type::report__T_flags: return report__T_flags_values;
		case DF_Type::poetic_form_part__T_flags: return poetic_form_part__T_flags_values;
		case DF_Type::musical_form_instruments__T_substitutions: return musical_form_instruments__T_substitutions_values;
		case DF_Type::building_civzonest__T_zone_flags: return building_civzonest__T_zone_flags_values;
		case DF_Type::building_civzonest__T_pit_flags: return building_civzonest__T_pit_flags_values;
		case DF_Type::building_civzonest__T_gather_flags: return building_civzonest__T_gather_flags_values;
		case DF_Type::building_design__T_flags: return building_design__T_flags_values;
		case DF_Type::building_bedst__T_bed_flags: return building_bedst__T_bed_flags_values;
		case DF_Type::building_cagest__T_cage_flags: return building_cagest__T_cage_flags_values;
		case DF_Type::building_chainst__T_chain_flags: return building_chainst__T_chain_flags_values;
		case DF_Type::building_coffinst__T_burial_mode: return building_coffinst__T_burial_mode_values;
		case DF_Type::building_shopst__T_shop_flags: return building_shopst__T_shop_flags_values;
		case DF_Type::building_supportst__T_support_flags: return building_supportst__T_support_flags_values;
		case DF_Type::building_tablest__T_table_flags: return building_tablest__T_table_flags_values;
		case DF_Type::building_tradedepotst__T_trade_flags: return building_tradedepotst__T_trade_flags_values;
		case DF_Type::building_trapst__T_stop_flags: return building_trapst__T_stop_flags_values;
		case DF_Type::building_wellst__T_well_flags: return building_wellst__T_well_flags_values;
		case DF_Type::caste_attack__T_flags: return caste_attack__T_flags_values;
		case DF_Type::creature_interaction__T_flags: return creature_interaction__T_flags_values;
		case DF_Type::caste_body_info__T_flags: return caste_body_info__T_flags_values;
		case DF_Type::caravan_state__T_flags: return caravan_state__T_flags_values;
		case DF_Type::honors_type__T_flags: return honors_type__T_flags_values;
		case DF_Type::honors_type__T_required_skill_type: return honors_type__T_required_skill_type_values;
		case DF_Type::agreement__T_anon_3: return agreement__T_anon_3_values;
		case DF_Type::history_event_artifact_createdst__T_flags2: return history_event_artifact_createdst__T_flags2_values;
		case DF_Type::history_event_hist_figure_revivedst__T_flags2: return history_event_hist_figure_revivedst__T_flags2_values;
		case DF_Type::history_event_tactical_situationst__T_tactics_flags: return history_event_tactical_situationst__T_tactics_flags_values;
		case DF_Type::interaction_effect__T_flags: return interaction_effect__T_flags_values;
		case DF_Type::interaction_source_secretst__T_learn_flags: return interaction_source_secretst__T_learn_flags_values;
		case DF_Type::interaction_target_materialst__T_restrictions: return interaction_target_materialst__T_restrictions_values;
		case DF_Type::itemimprovement_coveredst__T_cover_flags: return itemimprovement_coveredst__T_cover_flags_values;
		case DF_Type::spatter_common__T_base_flags: return spatter_common__T_base_flags_values;
		case DF_Type::spatter__T_flags: return spatter__T_flags_values;
		case DF_Type::item_body_component__T_corpse_flags: return item_body_component__T_corpse_flags_values;
		case DF_Type::poetic_form__T_flags: return poetic_form__T_flags_values;
		case DF_Type::musical_form__T_flags: return musical_form__T_flags_values;
		case DF_Type::historical_entity__T_flags: return historical_entity__T_flags_values;
		case DF_Type::item_petst__T_pet_flags: return item_petst__T_pet_flags_values;
		case DF_Type::entity_raw__T_scholar: return entity_raw__T_scholar_values;
		case DF_Type::machine__T_flags: return machine__T_flags_values;
		case DF_Type::building_gear_assemblyst__T_gear_flags: return building_gear_assemblyst__T_gear_flags_values;
		case DF_Type::block_square_event_mineralst__T_flags: return block_square_event_mineralst__T_flags_values;
		case DF_Type::dipscript_popup__T_flags: return dipscript_popup__T_flags_values;
		case DF_Type::meeting_diplomat_info__T_flags: return meeting_diplomat_info__T_flags_values;
		case DF_Type::activity_info__T_flags: return activity_info__T_flags_values;
		case DF_Type::room_rent_info__T_flags: return room_rent_info__T_flags_values;
		case DF_Type::activity_event__T_flags: return activity_event__T_flags_values;
		case DF_Type::activity_event_conversationst__T_flags2: return activity_event_conversationst__T_flags2_values;
		case DF_Type::activity_event_copy_written_contentst__T_flagsmaybe: return activity_event_copy_written_contentst__T_flagsmaybe_values;
		case DF_Type::squad_ammo_spec__T_flags: return squad_ammo_spec__T_flags_values;
		case DF_Type::plant_growth__T_locations: return plant_growth__T_locations_values;
		case DF_Type::plant_growth__T_behavior: return plant_growth__T_behavior_values;
		case DF_Type::plant__T_damage_flags: return plant__T_damage_flags_values;
		case DF_Type::stop_depart_condition__T_flags: return stop_depart_condition__T_flags_values;
		case DF_Type::unit_ghost_info__T_flags: return unit_ghost_info__T_flags_values;
		case DF_Type::unit_syndrome__T_symptoms__T_flags: return unit_syndrome__T_symptoms__T_flags_values;
		case DF_Type::unit_syndrome__T_flags: return unit_syndrome__T_flags_values;
		case DF_Type::unit_wound__T_flags: return unit_wound__T_flags_values;
		case DF_Type::unit_personality__T_emotions__T_flags: return unit_personality__T_emotions__T_flags_values;
		case DF_Type::unit_personality__T_flags: return unit_personality__T_flags_values;
		case DF_Type::historical_figure_info__T_known_info__T_knowledge__T_knowledge_goal: return historical_figure_info__T_known_info__T_knowledge__T_knowledge_goal_values;
		case DF_Type::historical_figure_info__T_books__T_flags: return historical_figure_info__T_books__T_flags_values;
		case DF_Type::unit_action_data_attack__T_flags: return unit_action_data_attack__T_flags_values;
		case DF_Type::mission__T_details__T_raid__T_raid_flags: return mission__T_details__T_raid__T_raid_flags_values;
		case DF_Type::ui__T_equipment__T_update: return ui__T_equipment__T_update_values;
		case DF_Type::ui__T_unk23c8_flags: return ui__T_unk23c8_flags_values;
		case DF_Type::viewscreen_textviewerst__T_formatted_text__T_flags: return viewscreen_textviewerst__T_formatted_text__T_flags_values;
		case DF_Type::viewscreen_workquota_conditionst__T_traits__T_flags: return viewscreen_workquota_conditionst__T_traits__T_flags_values;
		case DF_Type::item_eggst__T_egg_flags: return item_eggst__T_egg_flags_values;
		case DF_Type::unit__T_military__T_pickup_flags: return unit__T_military__T_pickup_flags_values;
		case DF_Type::local_population__T_flags: return local_population__T_flags_values;
		case DF_Type::region_map_entry__T_clouds: return region_map_entry__T_clouds_values;
		case DF_Type::region_map_entry__T_wind: return region_map_entry__T_wind_values;
		case DF_Type::incident__T_flags: return incident__T_flags_values;
		case DF_Type::crime__T_flags: return crime__T_flags_values;
		case DF_Type::job_handler__T_postings__T_flags: return job_handler__T_postings__T_flags_values;
		case DF_Type::world__T_status__T_slots__T_flags: return world__T_status__T_slots__T_flags_values;
		case DF_Type::world__T_status__T_flags: return world__T_status__T_flags_values;
		default: break;
	}
	return null_bitfield;
}

