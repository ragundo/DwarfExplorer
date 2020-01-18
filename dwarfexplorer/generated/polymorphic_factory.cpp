#include <DataDefs.h>
#include "DF_Types.h"
#include "df_all.h"
#include "node.h"


using namespace rdf;

DF_Type text_info_elementst_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::text_info_elementst*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "text_info_element_longst")
			return DF_Type::text_info_element_longst;
		if (l_full_name == "text_info_element_stringst")
			return DF_Type::text_info_element_stringst;
	}
	return DF_Type::None;
}

DF_Type adventure_optionst_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::adventure_optionst*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "adventure_option_eat_unit_contaminantst")
			return DF_Type::adventure_option_eat_unit_contaminantst;
		if (l_full_name == "adventure_option_eat_item_contaminantst")
			return DF_Type::adventure_option_eat_item_contaminantst;
		if (l_full_name == "adventure_option_view_contaminantst")
			return DF_Type::adventure_option_view_contaminantst;
		if (l_full_name == "adventure_environment_optionst")
			return DF_Type::adventure_environment_optionst;
		if (l_full_name == "adventure_environment_place_in_it_containerst")
			return DF_Type::adventure_environment_place_in_it_containerst;
		if (l_full_name == "adventure_environment_ingest_from_containerst")
			return DF_Type::adventure_environment_ingest_from_containerst;
		if (l_full_name == "adventure_environment_pickup_ignite_vegst")
			return DF_Type::adventure_environment_pickup_ignite_vegst;
		if (l_full_name == "adventure_environment_ingest_materialst")
			return DF_Type::adventure_environment_ingest_materialst;
		if (l_full_name == "adventure_environment_pickup_make_campfirest")
			return DF_Type::adventure_environment_pickup_make_campfirest;
		if (l_full_name == "adventure_environment_place_in_bld_containerst")
			return DF_Type::adventure_environment_place_in_bld_containerst;
		if (l_full_name == "adventure_environment_pickup_vermin_eventst")
			return DF_Type::adventure_environment_pickup_vermin_eventst;
		if (l_full_name == "adventure_environment_pickup_chop_treest")
			return DF_Type::adventure_environment_pickup_chop_treest;
		if (l_full_name == "adventure_environment_unit_suck_bloodst")
			return DF_Type::adventure_environment_unit_suck_bloodst;
	}
	return DF_Type::None;
}

DF_Type adventure_movement_optionst_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::adventure_movement_optionst*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "adventure_movement_release_hold_itemst")
			return DF_Type::adventure_movement_release_hold_itemst;
		if (l_full_name == "adventure_movement_release_hold_tilest")
			return DF_Type::adventure_movement_release_hold_tilest;
		if (l_full_name == "adventure_movement_attack_creaturest")
			return DF_Type::adventure_movement_attack_creaturest;
		if (l_full_name == "adventure_movement_hold_tilest")
			return DF_Type::adventure_movement_hold_tilest;
		if (l_full_name == "adventure_movement_movest")
			return DF_Type::adventure_movement_movest;
		if (l_full_name == "adventure_movement_climbst")
			return DF_Type::adventure_movement_climbst;
		if (l_full_name == "adventure_movement_hold_itemst")
			return DF_Type::adventure_movement_hold_itemst;
		if (l_full_name == "adventure_movement_building_interactst")
			return DF_Type::adventure_movement_building_interactst;
		if (l_full_name == "adventure_movement_item_interactst")
			return DF_Type::adventure_movement_item_interactst;
		if (l_full_name == "adventure_movement_item_interact_guidest")
			return DF_Type::adventure_movement_item_interact_guidest;
		if (l_full_name == "adventure_movement_item_interact_ridest")
			return DF_Type::adventure_movement_item_interact_ridest;
		if (l_full_name == "adventure_movement_item_interact_pushst")
			return DF_Type::adventure_movement_item_interact_pushst;
	}
	return DF_Type::None;
}

DF_Type adventure_item_interact_choicest_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::adventure_item_interact_choicest*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "adventure_item_interact_pull_outst")
			return DF_Type::adventure_item_interact_pull_outst;
		if (l_full_name == "adventure_item_interact_heat_from_tilest")
			return DF_Type::adventure_item_interact_heat_from_tilest;
		if (l_full_name == "adventure_item_interact_fill_from_containerst")
			return DF_Type::adventure_item_interact_fill_from_containerst;
		if (l_full_name == "adventure_item_interact_readst")
			return DF_Type::adventure_item_interact_readst;
		if (l_full_name == "adventure_item_interact_fill_with_materialst")
			return DF_Type::adventure_item_interact_fill_with_materialst;
		if (l_full_name == "adventure_item_interact_strugglest")
			return DF_Type::adventure_item_interact_strugglest;
		if (l_full_name == "adventure_item_interact_give_namest")
			return DF_Type::adventure_item_interact_give_namest;
	}
	return DF_Type::None;
}

DF_Type art_image_element_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::art_image_element*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "art_image_element_creaturest")
			return DF_Type::art_image_element_creaturest;
		if (l_full_name == "art_image_element_plantst")
			return DF_Type::art_image_element_plantst;
		if (l_full_name == "art_image_element_treest")
			return DF_Type::art_image_element_treest;
		if (l_full_name == "art_image_element_shapest")
			return DF_Type::art_image_element_shapest;
		if (l_full_name == "art_image_element_itemst")
			return DF_Type::art_image_element_itemst;
	}
	return DF_Type::None;
}

DF_Type art_image_property_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::art_image_property*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "art_image_property_transitive_verbst")
			return DF_Type::art_image_property_transitive_verbst;
		if (l_full_name == "art_image_property_intransitive_verbst")
			return DF_Type::art_image_property_intransitive_verbst;
	}
	return DF_Type::None;
}

DF_Type building_def_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::building_def*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "building_def_workshopst")
			return DF_Type::building_def_workshopst;
		if (l_full_name == "building_def_furnacest")
			return DF_Type::building_def_furnacest;
	}
	return DF_Type::None;
}

DF_Type building_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::building*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "building_stockpilest")
			return DF_Type::building_stockpilest;
		if (l_full_name == "building_civzonest")
			return DF_Type::building_civzonest;
		if (l_full_name == "building_actual")
			return DF_Type::building_actual;
		if (l_full_name == "building_furnacest")
			return DF_Type::building_furnacest;
		if (l_full_name == "building_workshopst")
			return DF_Type::building_workshopst;
		if (l_full_name == "building_animaltrapst")
			return DF_Type::building_animaltrapst;
		if (l_full_name == "building_archerytargetst")
			return DF_Type::building_archerytargetst;
		if (l_full_name == "building_armorstandst")
			return DF_Type::building_armorstandst;
		if (l_full_name == "building_bars_verticalst")
			return DF_Type::building_bars_verticalst;
		if (l_full_name == "building_bars_floorst")
			return DF_Type::building_bars_floorst;
		if (l_full_name == "building_bedst")
			return DF_Type::building_bedst;
		if (l_full_name == "building_bookcasest")
			return DF_Type::building_bookcasest;
		if (l_full_name == "building_boxst")
			return DF_Type::building_boxst;
		if (l_full_name == "building_bridgest")
			return DF_Type::building_bridgest;
		if (l_full_name == "building_cabinetst")
			return DF_Type::building_cabinetst;
		if (l_full_name == "building_cagest")
			return DF_Type::building_cagest;
		if (l_full_name == "building_chainst")
			return DF_Type::building_chainst;
		if (l_full_name == "building_chairst")
			return DF_Type::building_chairst;
		if (l_full_name == "building_coffinst")
			return DF_Type::building_coffinst;
		if (l_full_name == "building_constructionst")
			return DF_Type::building_constructionst;
		if (l_full_name == "building_display_furniturest")
			return DF_Type::building_display_furniturest;
		if (l_full_name == "building_doorst")
			return DF_Type::building_doorst;
		if (l_full_name == "building_farmplotst")
			return DF_Type::building_farmplotst;
		if (l_full_name == "building_floodgatest")
			return DF_Type::building_floodgatest;
		if (l_full_name == "building_grate_floorst")
			return DF_Type::building_grate_floorst;
		if (l_full_name == "building_grate_wallst")
			return DF_Type::building_grate_wallst;
		if (l_full_name == "building_hatchst")
			return DF_Type::building_hatchst;
		if (l_full_name == "building_hivest")
			return DF_Type::building_hivest;
		if (l_full_name == "building_instrumentst")
			return DF_Type::building_instrumentst;
		if (l_full_name == "building_nestst")
			return DF_Type::building_nestst;
		if (l_full_name == "building_nest_boxst")
			return DF_Type::building_nest_boxst;
		if (l_full_name == "building_roadst")
			return DF_Type::building_roadst;
		if (l_full_name == "building_road_dirtst")
			return DF_Type::building_road_dirtst;
		if (l_full_name == "building_road_pavedst")
			return DF_Type::building_road_pavedst;
		if (l_full_name == "building_shopst")
			return DF_Type::building_shopst;
		if (l_full_name == "building_siegeenginest")
			return DF_Type::building_siegeenginest;
		if (l_full_name == "building_slabst")
			return DF_Type::building_slabst;
		if (l_full_name == "building_statuest")
			return DF_Type::building_statuest;
		if (l_full_name == "building_supportst")
			return DF_Type::building_supportst;
		if (l_full_name == "building_tablest")
			return DF_Type::building_tablest;
		if (l_full_name == "building_traction_benchst")
			return DF_Type::building_traction_benchst;
		if (l_full_name == "building_tradedepotst")
			return DF_Type::building_tradedepotst;
		if (l_full_name == "building_trapst")
			return DF_Type::building_trapst;
		if (l_full_name == "building_wagonst")
			return DF_Type::building_wagonst;
		if (l_full_name == "building_weaponst")
			return DF_Type::building_weaponst;
		if (l_full_name == "building_weaponrackst")
			return DF_Type::building_weaponrackst;
		if (l_full_name == "building_wellst")
			return DF_Type::building_wellst;
		if (l_full_name == "building_windowst")
			return DF_Type::building_windowst;
		if (l_full_name == "building_window_glassst")
			return DF_Type::building_window_glassst;
		if (l_full_name == "building_window_gemst")
			return DF_Type::building_window_gemst;
		if (l_full_name == "building_axle_horizontalst")
			return DF_Type::building_axle_horizontalst;
		if (l_full_name == "building_axle_verticalst")
			return DF_Type::building_axle_verticalst;
		if (l_full_name == "building_gear_assemblyst")
			return DF_Type::building_gear_assemblyst;
		if (l_full_name == "building_windmillst")
			return DF_Type::building_windmillst;
		if (l_full_name == "building_water_wheelst")
			return DF_Type::building_water_wheelst;
		if (l_full_name == "building_screw_pumpst")
			return DF_Type::building_screw_pumpst;
		if (l_full_name == "building_rollersst")
			return DF_Type::building_rollersst;
	}
	return DF_Type::None;
}

DF_Type mental_picture_propertyst_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::mental_picture_propertyst*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "mental_picture_property_datest")
			return DF_Type::mental_picture_property_datest;
		if (l_full_name == "mental_picture_property_actionst")
			return DF_Type::mental_picture_property_actionst;
		if (l_full_name == "mental_picture_property_toolst")
			return DF_Type::mental_picture_property_toolst;
		if (l_full_name == "mental_picture_property_emotionst")
			return DF_Type::mental_picture_property_emotionst;
		if (l_full_name == "mental_picture_property_color_patternst")
			return DF_Type::mental_picture_property_color_patternst;
		if (l_full_name == "mental_picture_property_shapest")
			return DF_Type::mental_picture_property_shapest;
		if (l_full_name == "mental_picture_property_adjectivest")
			return DF_Type::mental_picture_property_adjectivest;
		if (l_full_name == "mental_picture_property_positionst")
			return DF_Type::mental_picture_property_positionst;
		if (l_full_name == "mental_picture_property_timest")
			return DF_Type::mental_picture_property_timest;
	}
	return DF_Type::None;
}

DF_Type mental_picture_elementst_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::mental_picture_elementst*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "mental_picture_element_hfst")
			return DF_Type::mental_picture_element_hfst;
		if (l_full_name == "mental_picture_element_sitest")
			return DF_Type::mental_picture_element_sitest;
		if (l_full_name == "mental_picture_element_regionst")
			return DF_Type::mental_picture_element_regionst;
	}
	return DF_Type::None;
}

DF_Type history_event_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::history_event*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "history_event_war_attacked_sitest")
			return DF_Type::history_event_war_attacked_sitest;
		if (l_full_name == "history_event_war_destroyed_sitest")
			return DF_Type::history_event_war_destroyed_sitest;
		if (l_full_name == "history_event_created_sitest")
			return DF_Type::history_event_created_sitest;
		if (l_full_name == "history_event_hist_figure_diedst")
			return DF_Type::history_event_hist_figure_diedst;
		if (l_full_name == "history_event_add_hf_entity_linkst")
			return DF_Type::history_event_add_hf_entity_linkst;
		if (l_full_name == "history_event_remove_hf_entity_linkst")
			return DF_Type::history_event_remove_hf_entity_linkst;
		if (l_full_name == "history_event_entity_expels_hfst")
			return DF_Type::history_event_entity_expels_hfst;
		if (l_full_name == "history_event_first_contactst")
			return DF_Type::history_event_first_contactst;
		if (l_full_name == "history_event_first_contact_failedst")
			return DF_Type::history_event_first_contact_failedst;
		if (l_full_name == "history_event_topicagreement_concludedst")
			return DF_Type::history_event_topicagreement_concludedst;
		if (l_full_name == "history_event_topicagreement_rejectedst")
			return DF_Type::history_event_topicagreement_rejectedst;
		if (l_full_name == "history_event_topicagreement_madest")
			return DF_Type::history_event_topicagreement_madest;
		if (l_full_name == "history_event_war_peace_acceptedst")
			return DF_Type::history_event_war_peace_acceptedst;
		if (l_full_name == "history_event_war_peace_rejectedst")
			return DF_Type::history_event_war_peace_rejectedst;
		if (l_full_name == "history_event_diplomat_lostst")
			return DF_Type::history_event_diplomat_lostst;
		if (l_full_name == "history_event_agreements_voidedst")
			return DF_Type::history_event_agreements_voidedst;
		if (l_full_name == "history_event_merchantst")
			return DF_Type::history_event_merchantst;
		if (l_full_name == "history_event_artifact_hiddenst")
			return DF_Type::history_event_artifact_hiddenst;
		if (l_full_name == "history_event_artifact_possessedst")
			return DF_Type::history_event_artifact_possessedst;
		if (l_full_name == "history_event_artifact_createdst")
			return DF_Type::history_event_artifact_createdst;
		if (l_full_name == "history_event_artifact_lostst")
			return DF_Type::history_event_artifact_lostst;
		if (l_full_name == "history_event_artifact_foundst")
			return DF_Type::history_event_artifact_foundst;
		if (l_full_name == "history_event_artifact_recoveredst")
			return DF_Type::history_event_artifact_recoveredst;
		if (l_full_name == "history_event_artifact_droppedst")
			return DF_Type::history_event_artifact_droppedst;
		if (l_full_name == "history_event_reclaim_sitest")
			return DF_Type::history_event_reclaim_sitest;
		if (l_full_name == "history_event_hf_destroyed_sitest")
			return DF_Type::history_event_hf_destroyed_sitest;
		if (l_full_name == "history_event_site_diedst")
			return DF_Type::history_event_site_diedst;
		if (l_full_name == "history_event_site_retiredst")
			return DF_Type::history_event_site_retiredst;
		if (l_full_name == "history_event_entity_createdst")
			return DF_Type::history_event_entity_createdst;
		if (l_full_name == "history_event_entity_actionst")
			return DF_Type::history_event_entity_actionst;
		if (l_full_name == "history_event_entity_incorporatedst")
			return DF_Type::history_event_entity_incorporatedst;
		if (l_full_name == "history_event_created_buildingst")
			return DF_Type::history_event_created_buildingst;
		if (l_full_name == "history_event_replaced_buildingst")
			return DF_Type::history_event_replaced_buildingst;
		if (l_full_name == "history_event_add_hf_site_linkst")
			return DF_Type::history_event_add_hf_site_linkst;
		if (l_full_name == "history_event_remove_hf_site_linkst")
			return DF_Type::history_event_remove_hf_site_linkst;
		if (l_full_name == "history_event_add_hf_hf_linkst")
			return DF_Type::history_event_add_hf_hf_linkst;
		if (l_full_name == "history_event_remove_hf_hf_linkst")
			return DF_Type::history_event_remove_hf_hf_linkst;
		if (l_full_name == "history_event_entity_razed_buildingst")
			return DF_Type::history_event_entity_razed_buildingst;
		if (l_full_name == "history_event_masterpiece_createdst")
			return DF_Type::history_event_masterpiece_createdst;
		if (l_full_name == "history_event_masterpiece_created_arch_designst")
			return DF_Type::history_event_masterpiece_created_arch_designst;
		if (l_full_name == "history_event_masterpiece_created_arch_constructst")
			return DF_Type::history_event_masterpiece_created_arch_constructst;
		if (l_full_name == "history_event_masterpiece_created_itemst")
			return DF_Type::history_event_masterpiece_created_itemst;
		if (l_full_name == "history_event_masterpiece_created_dye_itemst")
			return DF_Type::history_event_masterpiece_created_dye_itemst;
		if (l_full_name == "history_event_masterpiece_created_item_improvementst")
			return DF_Type::history_event_masterpiece_created_item_improvementst;
		if (l_full_name == "history_event_masterpiece_created_foodst")
			return DF_Type::history_event_masterpiece_created_foodst;
		if (l_full_name == "history_event_masterpiece_created_engravingst")
			return DF_Type::history_event_masterpiece_created_engravingst;
		if (l_full_name == "history_event_masterpiece_lostst")
			return DF_Type::history_event_masterpiece_lostst;
		if (l_full_name == "history_event_change_hf_statest")
			return DF_Type::history_event_change_hf_statest;
		if (l_full_name == "history_event_change_hf_jobst")
			return DF_Type::history_event_change_hf_jobst;
		if (l_full_name == "history_event_war_field_battlest")
			return DF_Type::history_event_war_field_battlest;
		if (l_full_name == "history_event_war_plundered_sitest")
			return DF_Type::history_event_war_plundered_sitest;
		if (l_full_name == "history_event_war_site_new_leaderst")
			return DF_Type::history_event_war_site_new_leaderst;
		if (l_full_name == "history_event_war_site_tribute_forcedst")
			return DF_Type::history_event_war_site_tribute_forcedst;
		if (l_full_name == "history_event_war_site_taken_overst")
			return DF_Type::history_event_war_site_taken_overst;
		if (l_full_name == "history_event_site_surrenderedst")
			return DF_Type::history_event_site_surrenderedst;
		if (l_full_name == "history_event_body_abusedst")
			return DF_Type::history_event_body_abusedst;
		if (l_full_name == "history_event_hist_figure_abductedst")
			return DF_Type::history_event_hist_figure_abductedst;
		if (l_full_name == "history_event_item_stolenst")
			return DF_Type::history_event_item_stolenst;
		if (l_full_name == "history_event_hf_razed_buildingst")
			return DF_Type::history_event_hf_razed_buildingst;
		if (l_full_name == "history_event_creature_devouredst")
			return DF_Type::history_event_creature_devouredst;
		if (l_full_name == "history_event_hist_figure_woundedst")
			return DF_Type::history_event_hist_figure_woundedst;
		if (l_full_name == "history_event_hist_figure_simple_battle_eventst")
			return DF_Type::history_event_hist_figure_simple_battle_eventst;
		if (l_full_name == "history_event_created_world_constructionst")
			return DF_Type::history_event_created_world_constructionst;
		if (l_full_name == "history_event_hist_figure_reunionst")
			return DF_Type::history_event_hist_figure_reunionst;
		if (l_full_name == "history_event_hist_figure_reach_summitst")
			return DF_Type::history_event_hist_figure_reach_summitst;
		if (l_full_name == "history_event_hist_figure_travelst")
			return DF_Type::history_event_hist_figure_travelst;
		if (l_full_name == "history_event_hist_figure_new_petst")
			return DF_Type::history_event_hist_figure_new_petst;
		if (l_full_name == "history_event_assume_identityst")
			return DF_Type::history_event_assume_identityst;
		if (l_full_name == "history_event_create_entity_positionst")
			return DF_Type::history_event_create_entity_positionst;
		if (l_full_name == "history_event_change_creature_typest")
			return DF_Type::history_event_change_creature_typest;
		if (l_full_name == "history_event_hist_figure_revivedst")
			return DF_Type::history_event_hist_figure_revivedst;
		if (l_full_name == "history_event_hf_learns_secretst")
			return DF_Type::history_event_hf_learns_secretst;
		if (l_full_name == "history_event_change_hf_body_statest")
			return DF_Type::history_event_change_hf_body_statest;
		if (l_full_name == "history_event_hf_act_on_buildingst")
			return DF_Type::history_event_hf_act_on_buildingst;
		if (l_full_name == "history_event_hf_does_interactionst")
			return DF_Type::history_event_hf_does_interactionst;
		if (l_full_name == "history_event_hf_confrontedst")
			return DF_Type::history_event_hf_confrontedst;
		if (l_full_name == "history_event_entity_lawst")
			return DF_Type::history_event_entity_lawst;
		if (l_full_name == "history_event_hf_gains_secret_goalst")
			return DF_Type::history_event_hf_gains_secret_goalst;
		if (l_full_name == "history_event_artifact_storedst")
			return DF_Type::history_event_artifact_storedst;
		if (l_full_name == "history_event_agreement_formedst")
			return DF_Type::history_event_agreement_formedst;
		if (l_full_name == "history_event_site_disputest")
			return DF_Type::history_event_site_disputest;
		if (l_full_name == "history_event_agreement_concludedst")
			return DF_Type::history_event_agreement_concludedst;
		if (l_full_name == "history_event_insurrection_startedst")
			return DF_Type::history_event_insurrection_startedst;
		if (l_full_name == "history_event_insurrection_endedst")
			return DF_Type::history_event_insurrection_endedst;
		if (l_full_name == "history_event_hf_attacked_sitest")
			return DF_Type::history_event_hf_attacked_sitest;
		if (l_full_name == "history_event_performancest")
			return DF_Type::history_event_performancest;
		if (l_full_name == "history_event_competitionst")
			return DF_Type::history_event_competitionst;
		if (l_full_name == "history_event_processionst")
			return DF_Type::history_event_processionst;
		if (l_full_name == "history_event_ceremonyst")
			return DF_Type::history_event_ceremonyst;
		if (l_full_name == "history_event_knowledge_discoveredst")
			return DF_Type::history_event_knowledge_discoveredst;
		if (l_full_name == "history_event_artifact_transformedst")
			return DF_Type::history_event_artifact_transformedst;
		if (l_full_name == "history_event_artifact_destroyedst")
			return DF_Type::history_event_artifact_destroyedst;
		if (l_full_name == "history_event_hf_relationship_deniedst")
			return DF_Type::history_event_hf_relationship_deniedst;
		if (l_full_name == "history_event_regionpop_incorporated_into_entityst")
			return DF_Type::history_event_regionpop_incorporated_into_entityst;
		if (l_full_name == "history_event_poetic_form_createdst")
			return DF_Type::history_event_poetic_form_createdst;
		if (l_full_name == "history_event_musical_form_createdst")
			return DF_Type::history_event_musical_form_createdst;
		if (l_full_name == "history_event_dance_form_createdst")
			return DF_Type::history_event_dance_form_createdst;
		if (l_full_name == "history_event_written_content_composedst")
			return DF_Type::history_event_written_content_composedst;
		if (l_full_name == "history_event_change_hf_moodst")
			return DF_Type::history_event_change_hf_moodst;
		if (l_full_name == "history_event_artifact_claim_formedst")
			return DF_Type::history_event_artifact_claim_formedst;
		if (l_full_name == "history_event_artifact_givenst")
			return DF_Type::history_event_artifact_givenst;
		if (l_full_name == "history_event_hf_act_on_artifactst")
			return DF_Type::history_event_hf_act_on_artifactst;
		if (l_full_name == "history_event_hf_recruited_unit_type_for_entityst")
			return DF_Type::history_event_hf_recruited_unit_type_for_entityst;
		if (l_full_name == "history_event_hfs_formed_reputation_relationshipst")
			return DF_Type::history_event_hfs_formed_reputation_relationshipst;
		if (l_full_name == "history_event_artifact_copiedst")
			return DF_Type::history_event_artifact_copiedst;
		if (l_full_name == "history_event_sneak_into_sitest")
			return DF_Type::history_event_sneak_into_sitest;
		if (l_full_name == "history_event_spotted_leaving_sitest")
			return DF_Type::history_event_spotted_leaving_sitest;
		if (l_full_name == "history_event_entity_searched_sitest")
			return DF_Type::history_event_entity_searched_sitest;
		if (l_full_name == "history_event_hf_freedst")
			return DF_Type::history_event_hf_freedst;
		if (l_full_name == "history_event_hist_figure_simple_actionst")
			return DF_Type::history_event_hist_figure_simple_actionst;
		if (l_full_name == "history_event_entity_rampaged_in_sitest")
			return DF_Type::history_event_entity_rampaged_in_sitest;
		if (l_full_name == "history_event_entity_fled_sitest")
			return DF_Type::history_event_entity_fled_sitest;
		if (l_full_name == "history_event_tactical_situationst")
			return DF_Type::history_event_tactical_situationst;
		if (l_full_name == "history_event_squad_vs_squadst")
			return DF_Type::history_event_squad_vs_squadst;
	}
	return DF_Type::None;
}

DF_Type history_event_collection_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::history_event_collection*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "history_event_collection_warst")
			return DF_Type::history_event_collection_warst;
		if (l_full_name == "history_event_collection_battlest")
			return DF_Type::history_event_collection_battlest;
		if (l_full_name == "history_event_collection_duelst")
			return DF_Type::history_event_collection_duelst;
		if (l_full_name == "history_event_collection_site_conqueredst")
			return DF_Type::history_event_collection_site_conqueredst;
		if (l_full_name == "history_event_collection_abductionst")
			return DF_Type::history_event_collection_abductionst;
		if (l_full_name == "history_event_collection_theftst")
			return DF_Type::history_event_collection_theftst;
		if (l_full_name == "history_event_collection_beast_attackst")
			return DF_Type::history_event_collection_beast_attackst;
		if (l_full_name == "history_event_collection_journeyst")
			return DF_Type::history_event_collection_journeyst;
		if (l_full_name == "history_event_collection_insurrectionst")
			return DF_Type::history_event_collection_insurrectionst;
		if (l_full_name == "history_event_collection_occasionst")
			return DF_Type::history_event_collection_occasionst;
		if (l_full_name == "history_event_collection_performancest")
			return DF_Type::history_event_collection_performancest;
		if (l_full_name == "history_event_collection_competitionst")
			return DF_Type::history_event_collection_competitionst;
		if (l_full_name == "history_event_collection_processionst")
			return DF_Type::history_event_collection_processionst;
		if (l_full_name == "history_event_collection_ceremonyst")
			return DF_Type::history_event_collection_ceremonyst;
		if (l_full_name == "history_event_collection_purgest")
			return DF_Type::history_event_collection_purgest;
		if (l_full_name == "history_event_collection_raidst")
			return DF_Type::history_event_collection_raidst;
	}
	return DF_Type::None;
}

DF_Type interaction_effect_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::interaction_effect*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "interaction_effect_animatest")
			return DF_Type::interaction_effect_animatest;
		if (l_full_name == "interaction_effect_add_syndromest")
			return DF_Type::interaction_effect_add_syndromest;
		if (l_full_name == "interaction_effect_resurrectst")
			return DF_Type::interaction_effect_resurrectst;
		if (l_full_name == "interaction_effect_cleanst")
			return DF_Type::interaction_effect_cleanst;
		if (l_full_name == "interaction_effect_contactst")
			return DF_Type::interaction_effect_contactst;
		if (l_full_name == "interaction_effect_material_emissionst")
			return DF_Type::interaction_effect_material_emissionst;
		if (l_full_name == "interaction_effect_hidest")
			return DF_Type::interaction_effect_hidest;
	}
	return DF_Type::None;
}

DF_Type interaction_source_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::interaction_source*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "interaction_source_regionst")
			return DF_Type::interaction_source_regionst;
		if (l_full_name == "interaction_source_secretst")
			return DF_Type::interaction_source_secretst;
		if (l_full_name == "interaction_source_disturbancest")
			return DF_Type::interaction_source_disturbancest;
		if (l_full_name == "interaction_source_deityst")
			return DF_Type::interaction_source_deityst;
		if (l_full_name == "interaction_source_attackst")
			return DF_Type::interaction_source_attackst;
		if (l_full_name == "interaction_source_ingestionst")
			return DF_Type::interaction_source_ingestionst;
		if (l_full_name == "interaction_source_creature_actionst")
			return DF_Type::interaction_source_creature_actionst;
		if (l_full_name == "interaction_source_underground_specialst")
			return DF_Type::interaction_source_underground_specialst;
	}
	return DF_Type::None;
}

DF_Type interaction_target_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::interaction_target*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "interaction_target_corpsest")
			return DF_Type::interaction_target_corpsest;
		if (l_full_name == "interaction_target_creaturest")
			return DF_Type::interaction_target_creaturest;
		if (l_full_name == "interaction_target_materialst")
			return DF_Type::interaction_target_materialst;
		if (l_full_name == "interaction_target_locationst")
			return DF_Type::interaction_target_locationst;
	}
	return DF_Type::None;
}

DF_Type itemdef_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::itemdef*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "itemdef_ammost")
			return DF_Type::itemdef_ammost;
		if (l_full_name == "itemdef_armorst")
			return DF_Type::itemdef_armorst;
		if (l_full_name == "itemdef_foodst")
			return DF_Type::itemdef_foodst;
		if (l_full_name == "itemdef_glovesst")
			return DF_Type::itemdef_glovesst;
		if (l_full_name == "itemdef_helmst")
			return DF_Type::itemdef_helmst;
		if (l_full_name == "itemdef_instrumentst")
			return DF_Type::itemdef_instrumentst;
		if (l_full_name == "itemdef_pantsst")
			return DF_Type::itemdef_pantsst;
		if (l_full_name == "itemdef_shieldst")
			return DF_Type::itemdef_shieldst;
		if (l_full_name == "itemdef_shoesst")
			return DF_Type::itemdef_shoesst;
		if (l_full_name == "itemdef_siegeammost")
			return DF_Type::itemdef_siegeammost;
		if (l_full_name == "itemdef_toolst")
			return DF_Type::itemdef_toolst;
		if (l_full_name == "itemdef_toyst")
			return DF_Type::itemdef_toyst;
		if (l_full_name == "itemdef_trapcompst")
			return DF_Type::itemdef_trapcompst;
		if (l_full_name == "itemdef_weaponst")
			return DF_Type::itemdef_weaponst;
	}
	return DF_Type::None;
}

DF_Type itemimprovement_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::itemimprovement*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "itemimprovement_art_imagest")
			return DF_Type::itemimprovement_art_imagest;
		if (l_full_name == "itemimprovement_coveredst")
			return DF_Type::itemimprovement_coveredst;
		if (l_full_name == "itemimprovement_rings_hangingst")
			return DF_Type::itemimprovement_rings_hangingst;
		if (l_full_name == "itemimprovement_bandsst")
			return DF_Type::itemimprovement_bandsst;
		if (l_full_name == "itemimprovement_spikesst")
			return DF_Type::itemimprovement_spikesst;
		if (l_full_name == "itemimprovement_itemspecificst")
			return DF_Type::itemimprovement_itemspecificst;
		if (l_full_name == "itemimprovement_threadst")
			return DF_Type::itemimprovement_threadst;
		if (l_full_name == "itemimprovement_clothst")
			return DF_Type::itemimprovement_clothst;
		if (l_full_name == "itemimprovement_sewn_imagest")
			return DF_Type::itemimprovement_sewn_imagest;
		if (l_full_name == "itemimprovement_pagesst")
			return DF_Type::itemimprovement_pagesst;
		if (l_full_name == "itemimprovement_illustrationst")
			return DF_Type::itemimprovement_illustrationst;
		if (l_full_name == "itemimprovement_instrument_piecest")
			return DF_Type::itemimprovement_instrument_piecest;
		if (l_full_name == "itemimprovement_writingst")
			return DF_Type::itemimprovement_writingst;
	}
	return DF_Type::None;
}

DF_Type spatter_common_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::spatter_common*)void_ptr;

	if (static_cast<df::spatter*>(object_ptr) != nullptr)
		return DF_Type::spatter;
	return DF_Type::None;
}

DF_Type item_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::item*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "item_actual")
			return DF_Type::item_actual;
		if (l_full_name == "item_crafted")
			return DF_Type::item_crafted;
		if (l_full_name == "item_constructed")
			return DF_Type::item_constructed;
		if (l_full_name == "item_doorst")
			return DF_Type::item_doorst;
		if (l_full_name == "item_floodgatest")
			return DF_Type::item_floodgatest;
		if (l_full_name == "item_bedst")
			return DF_Type::item_bedst;
		if (l_full_name == "item_chairst")
			return DF_Type::item_chairst;
		if (l_full_name == "item_chainst")
			return DF_Type::item_chainst;
		if (l_full_name == "item_flaskst")
			return DF_Type::item_flaskst;
		if (l_full_name == "item_gobletst")
			return DF_Type::item_gobletst;
		if (l_full_name == "item_windowst")
			return DF_Type::item_windowst;
		if (l_full_name == "item_cagest")
			return DF_Type::item_cagest;
		if (l_full_name == "item_bucketst")
			return DF_Type::item_bucketst;
		if (l_full_name == "item_animaltrapst")
			return DF_Type::item_animaltrapst;
		if (l_full_name == "item_tablest")
			return DF_Type::item_tablest;
		if (l_full_name == "item_coffinst")
			return DF_Type::item_coffinst;
		if (l_full_name == "item_boxst")
			return DF_Type::item_boxst;
		if (l_full_name == "item_armorstandst")
			return DF_Type::item_armorstandst;
		if (l_full_name == "item_weaponrackst")
			return DF_Type::item_weaponrackst;
		if (l_full_name == "item_cabinetst")
			return DF_Type::item_cabinetst;
		if (l_full_name == "item_amuletst")
			return DF_Type::item_amuletst;
		if (l_full_name == "item_scepterst")
			return DF_Type::item_scepterst;
		if (l_full_name == "item_crownst")
			return DF_Type::item_crownst;
		if (l_full_name == "item_ringst")
			return DF_Type::item_ringst;
		if (l_full_name == "item_earringst")
			return DF_Type::item_earringst;
		if (l_full_name == "item_braceletst")
			return DF_Type::item_braceletst;
		if (l_full_name == "item_anvilst")
			return DF_Type::item_anvilst;
		if (l_full_name == "item_backpackst")
			return DF_Type::item_backpackst;
		if (l_full_name == "item_quiverst")
			return DF_Type::item_quiverst;
		if (l_full_name == "item_catapultpartsst")
			return DF_Type::item_catapultpartsst;
		if (l_full_name == "item_ballistapartsst")
			return DF_Type::item_ballistapartsst;
		if (l_full_name == "item_trappartsst")
			return DF_Type::item_trappartsst;
		if (l_full_name == "item_pipe_sectionst")
			return DF_Type::item_pipe_sectionst;
		if (l_full_name == "item_hatch_coverst")
			return DF_Type::item_hatch_coverst;
		if (l_full_name == "item_gratest")
			return DF_Type::item_gratest;
		if (l_full_name == "item_quernst")
			return DF_Type::item_quernst;
		if (l_full_name == "item_millstonest")
			return DF_Type::item_millstonest;
		if (l_full_name == "item_splintst")
			return DF_Type::item_splintst;
		if (l_full_name == "item_crutchst")
			return DF_Type::item_crutchst;
		if (l_full_name == "item_traction_benchst")
			return DF_Type::item_traction_benchst;
		if (l_full_name == "item_instrumentst")
			return DF_Type::item_instrumentst;
		if (l_full_name == "item_toyst")
			return DF_Type::item_toyst;
		if (l_full_name == "item_armorst")
			return DF_Type::item_armorst;
		if (l_full_name == "item_shoesst")
			return DF_Type::item_shoesst;
		if (l_full_name == "item_shieldst")
			return DF_Type::item_shieldst;
		if (l_full_name == "item_helmst")
			return DF_Type::item_helmst;
		if (l_full_name == "item_glovesst")
			return DF_Type::item_glovesst;
		if (l_full_name == "item_pantsst")
			return DF_Type::item_pantsst;
		if (l_full_name == "item_siegeammost")
			return DF_Type::item_siegeammost;
		if (l_full_name == "item_weaponst")
			return DF_Type::item_weaponst;
		if (l_full_name == "item_ammost")
			return DF_Type::item_ammost;
		if (l_full_name == "item_trapcompst")
			return DF_Type::item_trapcompst;
		if (l_full_name == "item_toolst")
			return DF_Type::item_toolst;
		if (l_full_name == "item_barrelst")
			return DF_Type::item_barrelst;
		if (l_full_name == "item_binst")
			return DF_Type::item_binst;
		if (l_full_name == "item_gemst")
			return DF_Type::item_gemst;
		if (l_full_name == "item_statuest")
			return DF_Type::item_statuest;
		if (l_full_name == "item_figurinest")
			return DF_Type::item_figurinest;
		if (l_full_name == "item_slabst")
			return DF_Type::item_slabst;
		if (l_full_name == "item_orthopedic_castst")
			return DF_Type::item_orthopedic_castst;
		if (l_full_name == "item_coinst")
			return DF_Type::item_coinst;
		if (l_full_name == "item_totemst")
			return DF_Type::item_totemst;
		if (l_full_name == "item_clothst")
			return DF_Type::item_clothst;
		if (l_full_name == "item_bookst")
			return DF_Type::item_bookst;
		if (l_full_name == "item_sheetst")
			return DF_Type::item_sheetst;
		if (l_full_name == "item_foodst")
			return DF_Type::item_foodst;
		if (l_full_name == "item_body_component")
			return DF_Type::item_body_component;
		if (l_full_name == "item_corpsest")
			return DF_Type::item_corpsest;
		if (l_full_name == "item_corpsepiecest")
			return DF_Type::item_corpsepiecest;
		if (l_full_name == "item_critter")
			return DF_Type::item_critter;
		if (l_full_name == "item_verminst")
			return DF_Type::item_verminst;
		if (l_full_name == "item_petst")
			return DF_Type::item_petst;
		if (l_full_name == "item_liquipowder")
			return DF_Type::item_liquipowder;
		if (l_full_name == "item_liquid")
			return DF_Type::item_liquid;
		if (l_full_name == "item_drinkst")
			return DF_Type::item_drinkst;
		if (l_full_name == "item_liquid_miscst")
			return DF_Type::item_liquid_miscst;
		if (l_full_name == "item_powder")
			return DF_Type::item_powder;
		if (l_full_name == "item_powder_miscst")
			return DF_Type::item_powder_miscst;
		if (l_full_name == "item_barst")
			return DF_Type::item_barst;
		if (l_full_name == "item_smallgemst")
			return DF_Type::item_smallgemst;
		if (l_full_name == "item_blocksst")
			return DF_Type::item_blocksst;
		if (l_full_name == "item_roughst")
			return DF_Type::item_roughst;
		if (l_full_name == "item_boulderst")
			return DF_Type::item_boulderst;
		if (l_full_name == "item_woodst")
			return DF_Type::item_woodst;
		if (l_full_name == "item_branchst")
			return DF_Type::item_branchst;
		if (l_full_name == "item_rockst")
			return DF_Type::item_rockst;
		if (l_full_name == "item_seedsst")
			return DF_Type::item_seedsst;
		if (l_full_name == "item_skin_tannedst")
			return DF_Type::item_skin_tannedst;
		if (l_full_name == "item_meatst")
			return DF_Type::item_meatst;
		if (l_full_name == "item_plantst")
			return DF_Type::item_plantst;
		if (l_full_name == "item_plant_growthst")
			return DF_Type::item_plant_growthst;
		if (l_full_name == "item_cheesest")
			return DF_Type::item_cheesest;
		if (l_full_name == "item_globst")
			return DF_Type::item_globst;
		if (l_full_name == "item_remainsst")
			return DF_Type::item_remainsst;
		if (l_full_name == "item_fishst")
			return DF_Type::item_fishst;
		if (l_full_name == "item_fish_rawst")
			return DF_Type::item_fish_rawst;
		if (l_full_name == "item_threadst")
			return DF_Type::item_threadst;
		if (l_full_name == "item_eggst")
			return DF_Type::item_eggst;
		if (l_full_name == "item_ballistaarrowheadst")
			return DF_Type::item_ballistaarrowheadst;
	}
	return DF_Type::None;
}

DF_Type machine_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::machine*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "machine_standardst")
			return DF_Type::machine_standardst;
	}
	return DF_Type::None;
}

DF_Type block_square_event_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::block_square_event*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "block_square_event_mineralst")
			return DF_Type::block_square_event_mineralst;
		if (l_full_name == "block_square_event_frozen_liquidst")
			return DF_Type::block_square_event_frozen_liquidst;
		if (l_full_name == "block_square_event_world_constructionst")
			return DF_Type::block_square_event_world_constructionst;
		if (l_full_name == "block_square_event_material_spatterst")
			return DF_Type::block_square_event_material_spatterst;
		if (l_full_name == "block_square_event_grassst")
			return DF_Type::block_square_event_grassst;
		if (l_full_name == "block_square_event_spoorst")
			return DF_Type::block_square_event_spoorst;
		if (l_full_name == "block_square_event_item_spatterst")
			return DF_Type::block_square_event_item_spatterst;
		if (l_full_name == "block_square_event_designation_priorityst")
			return DF_Type::block_square_event_designation_priorityst;
	}
	return DF_Type::None;
}

DF_Type feature_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::feature*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "feature_outdoor_riverst")
			return DF_Type::feature_outdoor_riverst;
		if (l_full_name == "feature_cavest")
			return DF_Type::feature_cavest;
		if (l_full_name == "feature_pitst")
			return DF_Type::feature_pitst;
		if (l_full_name == "feature_magma_poolst")
			return DF_Type::feature_magma_poolst;
		if (l_full_name == "feature_volcanost")
			return DF_Type::feature_volcanost;
		if (l_full_name == "feature_deep_special_tubest")
			return DF_Type::feature_deep_special_tubest;
		if (l_full_name == "feature_deep_surface_portalst")
			return DF_Type::feature_deep_surface_portalst;
		if (l_full_name == "feature_subterranean_from_layerst")
			return DF_Type::feature_subterranean_from_layerst;
		if (l_full_name == "feature_magma_core_from_layerst")
			return DF_Type::feature_magma_core_from_layerst;
		if (l_full_name == "feature_underworld_from_layerst")
			return DF_Type::feature_underworld_from_layerst;
	}
	return DF_Type::None;
}

DF_Type feature_init_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::feature_init*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "feature_init_outdoor_riverst")
			return DF_Type::feature_init_outdoor_riverst;
		if (l_full_name == "feature_init_cavest")
			return DF_Type::feature_init_cavest;
		if (l_full_name == "feature_init_pitst")
			return DF_Type::feature_init_pitst;
		if (l_full_name == "feature_init_magma_poolst")
			return DF_Type::feature_init_magma_poolst;
		if (l_full_name == "feature_init_volcanost")
			return DF_Type::feature_init_volcanost;
		if (l_full_name == "feature_init_deep_special_tubest")
			return DF_Type::feature_init_deep_special_tubest;
		if (l_full_name == "feature_init_deep_surface_portalst")
			return DF_Type::feature_init_deep_surface_portalst;
		if (l_full_name == "feature_init_subterranean_from_layerst")
			return DF_Type::feature_init_subterranean_from_layerst;
		if (l_full_name == "feature_init_magma_core_from_layerst")
			return DF_Type::feature_init_magma_core_from_layerst;
		if (l_full_name == "feature_init_underworld_from_layerst")
			return DF_Type::feature_init_underworld_from_layerst;
	}
	return DF_Type::None;
}

DF_Type feature_alteration_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::feature_alteration*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "feature_alteration_new_pop_maxst")
			return DF_Type::feature_alteration_new_pop_maxst;
		if (l_full_name == "feature_alteration_new_lava_fill_zst")
			return DF_Type::feature_alteration_new_lava_fill_zst;
	}
	return DF_Type::None;
}

DF_Type world_construction_square_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::world_construction_square*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "world_construction_square_roadst")
			return DF_Type::world_construction_square_roadst;
		if (l_full_name == "world_construction_square_tunnelst")
			return DF_Type::world_construction_square_tunnelst;
		if (l_full_name == "world_construction_square_bridgest")
			return DF_Type::world_construction_square_bridgest;
		if (l_full_name == "world_construction_square_wallst")
			return DF_Type::world_construction_square_wallst;
	}
	return DF_Type::None;
}

DF_Type world_construction_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::world_construction*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "world_construction_roadst")
			return DF_Type::world_construction_roadst;
		if (l_full_name == "world_construction_tunnelst")
			return DF_Type::world_construction_tunnelst;
		if (l_full_name == "world_construction_bridgest")
			return DF_Type::world_construction_bridgest;
		if (l_full_name == "world_construction_wallst")
			return DF_Type::world_construction_wallst;
	}
	return DF_Type::None;
}

DF_Type flow_guide_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::flow_guide*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "flow_guide_trailing_flowst")
			return DF_Type::flow_guide_trailing_flowst;
		if (l_full_name == "flow_guide_item_cloudst")
			return DF_Type::flow_guide_item_cloudst;
	}
	return DF_Type::None;
}

DF_Type region_block_eventst_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::region_block_eventst*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "region_block_event_sphere_fieldst")
			return DF_Type::region_block_event_sphere_fieldst;
	}
	return DF_Type::None;
}

DF_Type material_common_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::material_common*)void_ptr;

	if (static_cast<df::material*>(object_ptr) != nullptr)
		return DF_Type::material;
	if (static_cast<df::material_template*>(object_ptr) != nullptr)
		return DF_Type::material_template;
	return DF_Type::None;
}

DF_Type script_stepst_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::script_stepst*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "script_step_setvarst")
			return DF_Type::script_step_setvarst;
		if (l_full_name == "script_step_simpleactionst")
			return DF_Type::script_step_simpleactionst;
		if (l_full_name == "script_step_conditionalst")
			return DF_Type::script_step_conditionalst;
		if (l_full_name == "script_step_textviewerst")
			return DF_Type::script_step_textviewerst;
		if (l_full_name == "script_step_diphistoryst")
			return DF_Type::script_step_diphistoryst;
		if (l_full_name == "script_step_discussst")
			return DF_Type::script_step_discussst;
		if (l_full_name == "script_step_topicdiscussionst")
			return DF_Type::script_step_topicdiscussionst;
		if (l_full_name == "script_step_constructtopiclistst")
			return DF_Type::script_step_constructtopiclistst;
		if (l_full_name == "script_step_eventst")
			return DF_Type::script_step_eventst;
		if (l_full_name == "script_step_dipeventst")
			return DF_Type::script_step_dipeventst;
		if (l_full_name == "script_step_invasionst")
			return DF_Type::script_step_invasionst;
	}
	return DF_Type::None;
}

DF_Type script_varst_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::script_varst*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "script_var_unitst")
			return DF_Type::script_var_unitst;
		if (l_full_name == "script_var_longst")
			return DF_Type::script_var_longst;
	}
	return DF_Type::None;
}

DF_Type active_script_varst_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::active_script_varst*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "active_script_var_unitst")
			return DF_Type::active_script_var_unitst;
		if (l_full_name == "active_script_var_longst")
			return DF_Type::active_script_var_longst;
	}
	return DF_Type::None;
}

DF_Type activity_event_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::activity_event*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "activity_event_training_sessionst")
			return DF_Type::activity_event_training_sessionst;
		if (l_full_name == "activity_event_combat_trainingst")
			return DF_Type::activity_event_combat_trainingst;
		if (l_full_name == "activity_event_skill_demonstrationst")
			return DF_Type::activity_event_skill_demonstrationst;
		if (l_full_name == "activity_event_individual_skill_drillst")
			return DF_Type::activity_event_individual_skill_drillst;
		if (l_full_name == "activity_event_sparringst")
			return DF_Type::activity_event_sparringst;
		if (l_full_name == "activity_event_ranged_practicest")
			return DF_Type::activity_event_ranged_practicest;
		if (l_full_name == "activity_event_harassmentst")
			return DF_Type::activity_event_harassmentst;
		if (l_full_name == "activity_event_conversationst")
			return DF_Type::activity_event_conversationst;
		if (l_full_name == "activity_event_conflictst")
			return DF_Type::activity_event_conflictst;
		if (l_full_name == "activity_event_guardst")
			return DF_Type::activity_event_guardst;
		if (l_full_name == "activity_event_reunionst")
			return DF_Type::activity_event_reunionst;
		if (l_full_name == "activity_event_prayerst")
			return DF_Type::activity_event_prayerst;
		if (l_full_name == "activity_event_socializest")
			return DF_Type::activity_event_socializest;
		if (l_full_name == "activity_event_worshipst")
			return DF_Type::activity_event_worshipst;
		if (l_full_name == "activity_event_performancest")
			return DF_Type::activity_event_performancest;
		if (l_full_name == "activity_event_researchst")
			return DF_Type::activity_event_researchst;
		if (l_full_name == "activity_event_ponder_topicst")
			return DF_Type::activity_event_ponder_topicst;
		if (l_full_name == "activity_event_discuss_topicst")
			return DF_Type::activity_event_discuss_topicst;
		if (l_full_name == "activity_event_readst")
			return DF_Type::activity_event_readst;
		if (l_full_name == "activity_event_fill_service_orderst")
			return DF_Type::activity_event_fill_service_orderst;
		if (l_full_name == "activity_event_writest")
			return DF_Type::activity_event_writest;
		if (l_full_name == "activity_event_copy_written_contentst")
			return DF_Type::activity_event_copy_written_contentst;
		if (l_full_name == "activity_event_teach_topicst")
			return DF_Type::activity_event_teach_topicst;
		if (l_full_name == "activity_event_playst")
			return DF_Type::activity_event_playst;
		if (l_full_name == "activity_event_make_believest")
			return DF_Type::activity_event_make_believest;
		if (l_full_name == "activity_event_play_with_toyst")
			return DF_Type::activity_event_play_with_toyst;
		if (l_full_name == "activity_event_encounterst")
			return DF_Type::activity_event_encounterst;
		if (l_full_name == "activity_event_store_objectst")
			return DF_Type::activity_event_store_objectst;
	}
	return DF_Type::None;
}

DF_Type squad_order_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::squad_order*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "squad_order_movest")
			return DF_Type::squad_order_movest;
		if (l_full_name == "squad_order_kill_listst")
			return DF_Type::squad_order_kill_listst;
		if (l_full_name == "squad_order_defend_burrowsst")
			return DF_Type::squad_order_defend_burrowsst;
		if (l_full_name == "squad_order_patrol_routest")
			return DF_Type::squad_order_patrol_routest;
		if (l_full_name == "squad_order_trainst")
			return DF_Type::squad_order_trainst;
		if (l_full_name == "squad_order_drive_entity_off_sitest")
			return DF_Type::squad_order_drive_entity_off_sitest;
		if (l_full_name == "squad_order_cause_trouble_for_entityst")
			return DF_Type::squad_order_cause_trouble_for_entityst;
		if (l_full_name == "squad_order_kill_hfst")
			return DF_Type::squad_order_kill_hfst;
		if (l_full_name == "squad_order_drive_armies_from_sitest")
			return DF_Type::squad_order_drive_armies_from_sitest;
		if (l_full_name == "squad_order_retrieve_artifactst")
			return DF_Type::squad_order_retrieve_artifactst;
		if (l_full_name == "squad_order_raid_sitest")
			return DF_Type::squad_order_raid_sitest;
		if (l_full_name == "squad_order_rescue_hfst")
			return DF_Type::squad_order_rescue_hfst;
	}
	return DF_Type::None;
}

DF_Type projectile_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::projectile*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "proj_itemst")
			return DF_Type::proj_itemst;
		if (l_full_name == "proj_unitst")
			return DF_Type::proj_unitst;
		if (l_full_name == "proj_magicst")
			return DF_Type::proj_magicst;
	}
	return DF_Type::None;
}

DF_Type reaction_reagent_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::reaction_reagent*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "reaction_reagent_itemst")
			return DF_Type::reaction_reagent_itemst;
	}
	return DF_Type::None;
}

DF_Type reaction_product_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::reaction_product*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "reaction_product_itemst")
			return DF_Type::reaction_product_itemst;
		if (l_full_name == "reaction_product_item_improvementst")
			return DF_Type::reaction_product_item_improvementst;
	}
	return DF_Type::None;
}

DF_Type general_ref_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::general_ref*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "general_ref_artifact")
			return DF_Type::general_ref_artifact;
		if (l_full_name == "general_ref_is_artifactst")
			return DF_Type::general_ref_is_artifactst;
		if (l_full_name == "general_ref_nemesis")
			return DF_Type::general_ref_nemesis;
		if (l_full_name == "general_ref_is_nemesisst")
			return DF_Type::general_ref_is_nemesisst;
		if (l_full_name == "general_ref_item")
			return DF_Type::general_ref_item;
		if (l_full_name == "general_ref_contains_itemst")
			return DF_Type::general_ref_contains_itemst;
		if (l_full_name == "general_ref_contained_in_itemst")
			return DF_Type::general_ref_contained_in_itemst;
		if (l_full_name == "general_ref_item_type")
			return DF_Type::general_ref_item_type;
		if (l_full_name == "general_ref_coinbatch")
			return DF_Type::general_ref_coinbatch;
		if (l_full_name == "general_ref_mapsquare")
			return DF_Type::general_ref_mapsquare;
		if (l_full_name == "general_ref_entity_art_image")
			return DF_Type::general_ref_entity_art_image;
		if (l_full_name == "general_ref_projectile")
			return DF_Type::general_ref_projectile;
		if (l_full_name == "general_ref_unit")
			return DF_Type::general_ref_unit;
		if (l_full_name == "general_ref_contains_unitst")
			return DF_Type::general_ref_contains_unitst;
		if (l_full_name == "general_ref_unit_milkeest")
			return DF_Type::general_ref_unit_milkeest;
		if (l_full_name == "general_ref_unit_traineest")
			return DF_Type::general_ref_unit_traineest;
		if (l_full_name == "general_ref_unit_itemownerst")
			return DF_Type::general_ref_unit_itemownerst;
		if (l_full_name == "general_ref_unit_tradebringerst")
			return DF_Type::general_ref_unit_tradebringerst;
		if (l_full_name == "general_ref_unit_holderst")
			return DF_Type::general_ref_unit_holderst;
		if (l_full_name == "general_ref_unit_workerst")
			return DF_Type::general_ref_unit_workerst;
		if (l_full_name == "general_ref_unit_cageest")
			return DF_Type::general_ref_unit_cageest;
		if (l_full_name == "general_ref_unit_beateest")
			return DF_Type::general_ref_unit_beateest;
		if (l_full_name == "general_ref_unit_foodreceiverst")
			return DF_Type::general_ref_unit_foodreceiverst;
		if (l_full_name == "general_ref_unit_kidnapeest")
			return DF_Type::general_ref_unit_kidnapeest;
		if (l_full_name == "general_ref_unit_patientst")
			return DF_Type::general_ref_unit_patientst;
		if (l_full_name == "general_ref_unit_infantst")
			return DF_Type::general_ref_unit_infantst;
		if (l_full_name == "general_ref_unit_slaughtereest")
			return DF_Type::general_ref_unit_slaughtereest;
		if (l_full_name == "general_ref_unit_sheareest")
			return DF_Type::general_ref_unit_sheareest;
		if (l_full_name == "general_ref_unit_suckeest")
			return DF_Type::general_ref_unit_suckeest;
		if (l_full_name == "general_ref_unit_reporteest")
			return DF_Type::general_ref_unit_reporteest;
		if (l_full_name == "general_ref_unit_riderst")
			return DF_Type::general_ref_unit_riderst;
		if (l_full_name == "general_ref_unit_climberst")
			return DF_Type::general_ref_unit_climberst;
		if (l_full_name == "general_ref_unit_geldeest")
			return DF_Type::general_ref_unit_geldeest;
		if (l_full_name == "general_ref_building")
			return DF_Type::general_ref_building;
		if (l_full_name == "general_ref_building_civzone_assignedst")
			return DF_Type::general_ref_building_civzone_assignedst;
		if (l_full_name == "general_ref_building_triggerst")
			return DF_Type::general_ref_building_triggerst;
		if (l_full_name == "general_ref_building_triggertargetst")
			return DF_Type::general_ref_building_triggertargetst;
		if (l_full_name == "general_ref_building_chainst")
			return DF_Type::general_ref_building_chainst;
		if (l_full_name == "general_ref_building_cagedst")
			return DF_Type::general_ref_building_cagedst;
		if (l_full_name == "general_ref_building_holderst")
			return DF_Type::general_ref_building_holderst;
		if (l_full_name == "general_ref_building_well_tag")
			return DF_Type::general_ref_building_well_tag;
		if (l_full_name == "general_ref_building_use_target_1st")
			return DF_Type::general_ref_building_use_target_1st;
		if (l_full_name == "general_ref_building_use_target_2st")
			return DF_Type::general_ref_building_use_target_2st;
		if (l_full_name == "general_ref_building_destinationst")
			return DF_Type::general_ref_building_destinationst;
		if (l_full_name == "general_ref_building_nest_boxst")
			return DF_Type::general_ref_building_nest_boxst;
		if (l_full_name == "general_ref_building_display_furniturest")
			return DF_Type::general_ref_building_display_furniturest;
		if (l_full_name == "general_ref_entity")
			return DF_Type::general_ref_entity;
		if (l_full_name == "general_ref_entity_stolenst")
			return DF_Type::general_ref_entity_stolenst;
		if (l_full_name == "general_ref_entity_offeredst")
			return DF_Type::general_ref_entity_offeredst;
		if (l_full_name == "general_ref_entity_itemownerst")
			return DF_Type::general_ref_entity_itemownerst;
		if (l_full_name == "general_ref_locationst")
			return DF_Type::general_ref_locationst;
		if (l_full_name == "general_ref_interactionst")
			return DF_Type::general_ref_interactionst;
		if (l_full_name == "general_ref_abstract_buildingst")
			return DF_Type::general_ref_abstract_buildingst;
		if (l_full_name == "general_ref_historical_eventst")
			return DF_Type::general_ref_historical_eventst;
		if (l_full_name == "general_ref_spherest")
			return DF_Type::general_ref_spherest;
		if (l_full_name == "general_ref_sitest")
			return DF_Type::general_ref_sitest;
		if (l_full_name == "general_ref_subregionst")
			return DF_Type::general_ref_subregionst;
		if (l_full_name == "general_ref_feature_layerst")
			return DF_Type::general_ref_feature_layerst;
		if (l_full_name == "general_ref_historical_figurest")
			return DF_Type::general_ref_historical_figurest;
		if (l_full_name == "general_ref_entity_popst")
			return DF_Type::general_ref_entity_popst;
		if (l_full_name == "general_ref_creaturest")
			return DF_Type::general_ref_creaturest;
		if (l_full_name == "general_ref_knowledge_scholar_flagst")
			return DF_Type::general_ref_knowledge_scholar_flagst;
		if (l_full_name == "general_ref_activity_eventst")
			return DF_Type::general_ref_activity_eventst;
		if (l_full_name == "general_ref_value_levelst")
			return DF_Type::general_ref_value_levelst;
		if (l_full_name == "general_ref_languagest")
			return DF_Type::general_ref_languagest;
		if (l_full_name == "general_ref_written_contentst")
			return DF_Type::general_ref_written_contentst;
		if (l_full_name == "general_ref_poetic_formst")
			return DF_Type::general_ref_poetic_formst;
		if (l_full_name == "general_ref_musical_formst")
			return DF_Type::general_ref_musical_formst;
		if (l_full_name == "general_ref_dance_formst")
			return DF_Type::general_ref_dance_formst;
	}
	return DF_Type::None;
}

DF_Type histfig_entity_link_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::histfig_entity_link*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "histfig_entity_link_memberst")
			return DF_Type::histfig_entity_link_memberst;
		if (l_full_name == "histfig_entity_link_former_memberst")
			return DF_Type::histfig_entity_link_former_memberst;
		if (l_full_name == "histfig_entity_link_mercenaryst")
			return DF_Type::histfig_entity_link_mercenaryst;
		if (l_full_name == "histfig_entity_link_former_mercenaryst")
			return DF_Type::histfig_entity_link_former_mercenaryst;
		if (l_full_name == "histfig_entity_link_slavest")
			return DF_Type::histfig_entity_link_slavest;
		if (l_full_name == "histfig_entity_link_former_slavest")
			return DF_Type::histfig_entity_link_former_slavest;
		if (l_full_name == "histfig_entity_link_prisonerst")
			return DF_Type::histfig_entity_link_prisonerst;
		if (l_full_name == "histfig_entity_link_former_prisonerst")
			return DF_Type::histfig_entity_link_former_prisonerst;
		if (l_full_name == "histfig_entity_link_enemyst")
			return DF_Type::histfig_entity_link_enemyst;
		if (l_full_name == "histfig_entity_link_criminalst")
			return DF_Type::histfig_entity_link_criminalst;
		if (l_full_name == "histfig_entity_link_positionst")
			return DF_Type::histfig_entity_link_positionst;
		if (l_full_name == "histfig_entity_link_former_positionst")
			return DF_Type::histfig_entity_link_former_positionst;
		if (l_full_name == "histfig_entity_link_position_claimst")
			return DF_Type::histfig_entity_link_position_claimst;
		if (l_full_name == "histfig_entity_link_squadst")
			return DF_Type::histfig_entity_link_squadst;
		if (l_full_name == "histfig_entity_link_former_squadst")
			return DF_Type::histfig_entity_link_former_squadst;
		if (l_full_name == "histfig_entity_link_occupationst")
			return DF_Type::histfig_entity_link_occupationst;
		if (l_full_name == "histfig_entity_link_former_occupationst")
			return DF_Type::histfig_entity_link_former_occupationst;
	}
	return DF_Type::None;
}

DF_Type histfig_site_link_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::histfig_site_link*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "histfig_site_link_seat_of_powerst")
			return DF_Type::histfig_site_link_seat_of_powerst;
		if (l_full_name == "histfig_site_link_hangoutst")
			return DF_Type::histfig_site_link_hangoutst;
		if (l_full_name == "histfig_site_link_home_site_abstract_buildingst")
			return DF_Type::histfig_site_link_home_site_abstract_buildingst;
		if (l_full_name == "histfig_site_link_home_site_realization_buildingst")
			return DF_Type::histfig_site_link_home_site_realization_buildingst;
		if (l_full_name == "histfig_site_link_lairst")
			return DF_Type::histfig_site_link_lairst;
		if (l_full_name == "histfig_site_link_home_site_realization_sulst")
			return DF_Type::histfig_site_link_home_site_realization_sulst;
		if (l_full_name == "histfig_site_link_home_site_saved_civzonest")
			return DF_Type::histfig_site_link_home_site_saved_civzonest;
		if (l_full_name == "histfig_site_link_occupationst")
			return DF_Type::histfig_site_link_occupationst;
	}
	return DF_Type::None;
}

DF_Type histfig_hf_link_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::histfig_hf_link*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "histfig_hf_link_motherst")
			return DF_Type::histfig_hf_link_motherst;
		if (l_full_name == "histfig_hf_link_fatherst")
			return DF_Type::histfig_hf_link_fatherst;
		if (l_full_name == "histfig_hf_link_spousest")
			return DF_Type::histfig_hf_link_spousest;
		if (l_full_name == "histfig_hf_link_childst")
			return DF_Type::histfig_hf_link_childst;
		if (l_full_name == "histfig_hf_link_deityst")
			return DF_Type::histfig_hf_link_deityst;
		if (l_full_name == "histfig_hf_link_loverst")
			return DF_Type::histfig_hf_link_loverst;
		if (l_full_name == "histfig_hf_link_prisonerst")
			return DF_Type::histfig_hf_link_prisonerst;
		if (l_full_name == "histfig_hf_link_imprisonerst")
			return DF_Type::histfig_hf_link_imprisonerst;
		if (l_full_name == "histfig_hf_link_masterst")
			return DF_Type::histfig_hf_link_masterst;
		if (l_full_name == "histfig_hf_link_apprenticest")
			return DF_Type::histfig_hf_link_apprenticest;
		if (l_full_name == "histfig_hf_link_companionst")
			return DF_Type::histfig_hf_link_companionst;
		if (l_full_name == "histfig_hf_link_former_apprenticest")
			return DF_Type::histfig_hf_link_former_apprenticest;
		if (l_full_name == "histfig_hf_link_former_masterst")
			return DF_Type::histfig_hf_link_former_masterst;
		if (l_full_name == "histfig_hf_link_pet_ownerst")
			return DF_Type::histfig_hf_link_pet_ownerst;
	}
	return DF_Type::None;
}

DF_Type resource_allotment_specifier_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::resource_allotment_specifier*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "resource_allotment_specifier_cropst")
			return DF_Type::resource_allotment_specifier_cropst;
		if (l_full_name == "resource_allotment_specifier_stonest")
			return DF_Type::resource_allotment_specifier_stonest;
		if (l_full_name == "resource_allotment_specifier_metalst")
			return DF_Type::resource_allotment_specifier_metalst;
		if (l_full_name == "resource_allotment_specifier_woodst")
			return DF_Type::resource_allotment_specifier_woodst;
		if (l_full_name == "resource_allotment_specifier_armor_bodyst")
			return DF_Type::resource_allotment_specifier_armor_bodyst;
		if (l_full_name == "resource_allotment_specifier_armor_pantsst")
			return DF_Type::resource_allotment_specifier_armor_pantsst;
		if (l_full_name == "resource_allotment_specifier_armor_glovesst")
			return DF_Type::resource_allotment_specifier_armor_glovesst;
		if (l_full_name == "resource_allotment_specifier_armor_bootsst")
			return DF_Type::resource_allotment_specifier_armor_bootsst;
		if (l_full_name == "resource_allotment_specifier_armor_helmst")
			return DF_Type::resource_allotment_specifier_armor_helmst;
		if (l_full_name == "resource_allotment_specifier_clothing_bodyst")
			return DF_Type::resource_allotment_specifier_clothing_bodyst;
		if (l_full_name == "resource_allotment_specifier_clothing_pantsst")
			return DF_Type::resource_allotment_specifier_clothing_pantsst;
		if (l_full_name == "resource_allotment_specifier_clothing_glovesst")
			return DF_Type::resource_allotment_specifier_clothing_glovesst;
		if (l_full_name == "resource_allotment_specifier_clothing_bootsst")
			return DF_Type::resource_allotment_specifier_clothing_bootsst;
		if (l_full_name == "resource_allotment_specifier_clothing_helmst")
			return DF_Type::resource_allotment_specifier_clothing_helmst;
		if (l_full_name == "resource_allotment_specifier_weapon_meleest")
			return DF_Type::resource_allotment_specifier_weapon_meleest;
		if (l_full_name == "resource_allotment_specifier_weapon_rangedst")
			return DF_Type::resource_allotment_specifier_weapon_rangedst;
		if (l_full_name == "resource_allotment_specifier_ammost")
			return DF_Type::resource_allotment_specifier_ammost;
		if (l_full_name == "resource_allotment_specifier_anvilst")
			return DF_Type::resource_allotment_specifier_anvilst;
		if (l_full_name == "resource_allotment_specifier_gemsst")
			return DF_Type::resource_allotment_specifier_gemsst;
		if (l_full_name == "resource_allotment_specifier_threadst")
			return DF_Type::resource_allotment_specifier_threadst;
		if (l_full_name == "resource_allotment_specifier_clothst")
			return DF_Type::resource_allotment_specifier_clothst;
		if (l_full_name == "resource_allotment_specifier_leatherst")
			return DF_Type::resource_allotment_specifier_leatherst;
		if (l_full_name == "resource_allotment_specifier_quiverst")
			return DF_Type::resource_allotment_specifier_quiverst;
		if (l_full_name == "resource_allotment_specifier_backpackst")
			return DF_Type::resource_allotment_specifier_backpackst;
		if (l_full_name == "resource_allotment_specifier_flaskst")
			return DF_Type::resource_allotment_specifier_flaskst;
		if (l_full_name == "resource_allotment_specifier_bagst")
			return DF_Type::resource_allotment_specifier_bagst;
		if (l_full_name == "resource_allotment_specifier_tablest")
			return DF_Type::resource_allotment_specifier_tablest;
		if (l_full_name == "resource_allotment_specifier_cabinetst")
			return DF_Type::resource_allotment_specifier_cabinetst;
		if (l_full_name == "resource_allotment_specifier_chairst")
			return DF_Type::resource_allotment_specifier_chairst;
		if (l_full_name == "resource_allotment_specifier_boxst")
			return DF_Type::resource_allotment_specifier_boxst;
		if (l_full_name == "resource_allotment_specifier_bedst")
			return DF_Type::resource_allotment_specifier_bedst;
		if (l_full_name == "resource_allotment_specifier_craftsst")
			return DF_Type::resource_allotment_specifier_craftsst;
		if (l_full_name == "resource_allotment_specifier_meatst")
			return DF_Type::resource_allotment_specifier_meatst;
		if (l_full_name == "resource_allotment_specifier_bonest")
			return DF_Type::resource_allotment_specifier_bonest;
		if (l_full_name == "resource_allotment_specifier_hornst")
			return DF_Type::resource_allotment_specifier_hornst;
		if (l_full_name == "resource_allotment_specifier_shellst")
			return DF_Type::resource_allotment_specifier_shellst;
		if (l_full_name == "resource_allotment_specifier_tallowst")
			return DF_Type::resource_allotment_specifier_tallowst;
		if (l_full_name == "resource_allotment_specifier_toothst")
			return DF_Type::resource_allotment_specifier_toothst;
		if (l_full_name == "resource_allotment_specifier_pearlst")
			return DF_Type::resource_allotment_specifier_pearlst;
		if (l_full_name == "resource_allotment_specifier_soapst")
			return DF_Type::resource_allotment_specifier_soapst;
		if (l_full_name == "resource_allotment_specifier_extractst")
			return DF_Type::resource_allotment_specifier_extractst;
		if (l_full_name == "resource_allotment_specifier_cheesest")
			return DF_Type::resource_allotment_specifier_cheesest;
		if (l_full_name == "resource_allotment_specifier_skinst")
			return DF_Type::resource_allotment_specifier_skinst;
		if (l_full_name == "resource_allotment_specifier_powderst")
			return DF_Type::resource_allotment_specifier_powderst;
	}
	return DF_Type::None;
}

DF_Type creature_interaction_effect_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::creature_interaction_effect*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "creature_interaction_effect_painst")
			return DF_Type::creature_interaction_effect_painst;
		if (l_full_name == "creature_interaction_effect_swellingst")
			return DF_Type::creature_interaction_effect_swellingst;
		if (l_full_name == "creature_interaction_effect_oozingst")
			return DF_Type::creature_interaction_effect_oozingst;
		if (l_full_name == "creature_interaction_effect_bruisingst")
			return DF_Type::creature_interaction_effect_bruisingst;
		if (l_full_name == "creature_interaction_effect_blistersst")
			return DF_Type::creature_interaction_effect_blistersst;
		if (l_full_name == "creature_interaction_effect_numbnessst")
			return DF_Type::creature_interaction_effect_numbnessst;
		if (l_full_name == "creature_interaction_effect_paralysisst")
			return DF_Type::creature_interaction_effect_paralysisst;
		if (l_full_name == "creature_interaction_effect_feverst")
			return DF_Type::creature_interaction_effect_feverst;
		if (l_full_name == "creature_interaction_effect_bleedingst")
			return DF_Type::creature_interaction_effect_bleedingst;
		if (l_full_name == "creature_interaction_effect_cough_bloodst")
			return DF_Type::creature_interaction_effect_cough_bloodst;
		if (l_full_name == "creature_interaction_effect_vomit_bloodst")
			return DF_Type::creature_interaction_effect_vomit_bloodst;
		if (l_full_name == "creature_interaction_effect_nauseast")
			return DF_Type::creature_interaction_effect_nauseast;
		if (l_full_name == "creature_interaction_effect_unconsciousnessst")
			return DF_Type::creature_interaction_effect_unconsciousnessst;
		if (l_full_name == "creature_interaction_effect_necrosisst")
			return DF_Type::creature_interaction_effect_necrosisst;
		if (l_full_name == "creature_interaction_effect_impair_functionst")
			return DF_Type::creature_interaction_effect_impair_functionst;
		if (l_full_name == "creature_interaction_effect_drowsinessst")
			return DF_Type::creature_interaction_effect_drowsinessst;
		if (l_full_name == "creature_interaction_effect_dizzinessst")
			return DF_Type::creature_interaction_effect_dizzinessst;
		if (l_full_name == "creature_interaction_effect_display_namest")
			return DF_Type::creature_interaction_effect_display_namest;
		if (l_full_name == "creature_interaction_effect_body_appearance_modifierst")
			return DF_Type::creature_interaction_effect_body_appearance_modifierst;
		if (l_full_name == "creature_interaction_effect_bp_appearance_modifierst")
			return DF_Type::creature_interaction_effect_bp_appearance_modifierst;
		if (l_full_name == "creature_interaction_effect_body_transformationst")
			return DF_Type::creature_interaction_effect_body_transformationst;
		if (l_full_name == "creature_interaction_effect_skill_roll_adjustst")
			return DF_Type::creature_interaction_effect_skill_roll_adjustst;
		if (l_full_name == "creature_interaction_effect_display_symbolst")
			return DF_Type::creature_interaction_effect_display_symbolst;
		if (l_full_name == "creature_interaction_effect_flash_symbolst")
			return DF_Type::creature_interaction_effect_flash_symbolst;
		if (l_full_name == "creature_interaction_effect_phys_att_changest")
			return DF_Type::creature_interaction_effect_phys_att_changest;
		if (l_full_name == "creature_interaction_effect_ment_att_changest")
			return DF_Type::creature_interaction_effect_ment_att_changest;
		if (l_full_name == "creature_interaction_effect_add_simple_flagst")
			return DF_Type::creature_interaction_effect_add_simple_flagst;
		if (l_full_name == "creature_interaction_effect_remove_simple_flagst")
			return DF_Type::creature_interaction_effect_remove_simple_flagst;
		if (l_full_name == "creature_interaction_effect_speed_changest")
			return DF_Type::creature_interaction_effect_speed_changest;
		if (l_full_name == "creature_interaction_effect_body_mat_interactionst")
			return DF_Type::creature_interaction_effect_body_mat_interactionst;
		if (l_full_name == "creature_interaction_effect_material_force_adjustst")
			return DF_Type::creature_interaction_effect_material_force_adjustst;
		if (l_full_name == "creature_interaction_effect_can_do_interactionst")
			return DF_Type::creature_interaction_effect_can_do_interactionst;
		if (l_full_name == "creature_interaction_effect_sense_creature_classst")
			return DF_Type::creature_interaction_effect_sense_creature_classst;
		if (l_full_name == "creature_interaction_effect_feel_emotionst")
			return DF_Type::creature_interaction_effect_feel_emotionst;
		if (l_full_name == "creature_interaction_effect_change_personalityst")
			return DF_Type::creature_interaction_effect_change_personalityst;
		if (l_full_name == "creature_interaction_effect_erratic_behaviorst")
			return DF_Type::creature_interaction_effect_erratic_behaviorst;
	}
	return DF_Type::None;
}

DF_Type build_req_choicest_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::build_req_choicest*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "build_req_choice_genst")
			return DF_Type::build_req_choice_genst;
		if (l_full_name == "build_req_choice_specst")
			return DF_Type::build_req_choice_specst;
	}
	return DF_Type::None;
}

DF_Type interface_button_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::interface_button*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "interface_button_buildingst")
			return DF_Type::interface_button_buildingst;
		if (l_full_name == "interface_button_building_category_selectorst")
			return DF_Type::interface_button_building_category_selectorst;
		if (l_full_name == "interface_button_building_material_selectorst")
			return DF_Type::interface_button_building_material_selectorst;
		if (l_full_name == "interface_button_building_new_jobst")
			return DF_Type::interface_button_building_new_jobst;
		if (l_full_name == "interface_button_building_custom_category_selectorst")
			return DF_Type::interface_button_building_custom_category_selectorst;
		if (l_full_name == "interface_button_constructionst")
			return DF_Type::interface_button_constructionst;
		if (l_full_name == "interface_button_construction_donest")
			return DF_Type::interface_button_construction_donest;
		if (l_full_name == "interface_button_construction_category_selectorst")
			return DF_Type::interface_button_construction_category_selectorst;
		if (l_full_name == "interface_button_construction_building_selectorst")
			return DF_Type::interface_button_construction_building_selectorst;
	}
	return DF_Type::None;
}

DF_Type viewscreen_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::viewscreen*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "viewscreen_layer")
			return DF_Type::viewscreen_layer;
		if (l_full_name == "viewscreen_layer_arena_creaturest")
			return DF_Type::viewscreen_layer_arena_creaturest;
		if (l_full_name == "viewscreen_layer_assigntradest")
			return DF_Type::viewscreen_layer_assigntradest;
		if (l_full_name == "viewscreen_layer_choose_language_namest")
			return DF_Type::viewscreen_layer_choose_language_namest;
		if (l_full_name == "viewscreen_layer_currencyst")
			return DF_Type::viewscreen_layer_currencyst;
		if (l_full_name == "viewscreen_layer_export_play_mapst")
			return DF_Type::viewscreen_layer_export_play_mapst;
		if (l_full_name == "viewscreen_layer_militaryst")
			return DF_Type::viewscreen_layer_militaryst;
		if (l_full_name == "viewscreen_layer_musicsoundst")
			return DF_Type::viewscreen_layer_musicsoundst;
		if (l_full_name == "viewscreen_layer_noblelistst")
			return DF_Type::viewscreen_layer_noblelistst;
		if (l_full_name == "viewscreen_layer_overall_healthst")
			return DF_Type::viewscreen_layer_overall_healthst;
		if (l_full_name == "viewscreen_layer_reactionst")
			return DF_Type::viewscreen_layer_reactionst;
		if (l_full_name == "viewscreen_layer_squad_schedulest")
			return DF_Type::viewscreen_layer_squad_schedulest;
		if (l_full_name == "viewscreen_layer_stockpilest")
			return DF_Type::viewscreen_layer_stockpilest;
		if (l_full_name == "viewscreen_layer_stone_restrictionst")
			return DF_Type::viewscreen_layer_stone_restrictionst;
		if (l_full_name == "viewscreen_layer_unit_actionst")
			return DF_Type::viewscreen_layer_unit_actionst;
		if (l_full_name == "viewscreen_layer_unit_healthst")
			return DF_Type::viewscreen_layer_unit_healthst;
		if (l_full_name == "viewscreen_layer_unit_relationshipst")
			return DF_Type::viewscreen_layer_unit_relationshipst;
		if (l_full_name == "viewscreen_layer_world_gen_paramst")
			return DF_Type::viewscreen_layer_world_gen_paramst;
		if (l_full_name == "viewscreen_layer_world_gen_param_presetst")
			return DF_Type::viewscreen_layer_world_gen_param_presetst;
		if (l_full_name == "KeybindingScreen")
			return DF_Type::KeybindingScreen;
		if (l_full_name == "MacroScreenLoad")
			return DF_Type::MacroScreenLoad;
		if (l_full_name == "MacroScreenSave")
			return DF_Type::MacroScreenSave;
		if (l_full_name == "viewscreen_adopt_regionst")
			return DF_Type::viewscreen_adopt_regionst;
		if (l_full_name == "viewscreen_adventure_logst")
			return DF_Type::viewscreen_adventure_logst;
		if (l_full_name == "viewscreen_announcelistst")
			return DF_Type::viewscreen_announcelistst;
		if (l_full_name == "viewscreen_assign_display_itemst")
			return DF_Type::viewscreen_assign_display_itemst;
		if (l_full_name == "viewscreen_barterst")
			return DF_Type::viewscreen_barterst;
		if (l_full_name == "viewscreen_buildingst")
			return DF_Type::viewscreen_buildingst;
		if (l_full_name == "viewscreen_buildinglistst")
			return DF_Type::viewscreen_buildinglistst;
		if (l_full_name == "viewscreen_choose_start_sitest")
			return DF_Type::viewscreen_choose_start_sitest;
		if (l_full_name == "viewscreen_civlistst")
			return DF_Type::viewscreen_civlistst;
		if (l_full_name == "viewscreen_createquotast")
			return DF_Type::viewscreen_createquotast;
		if (l_full_name == "viewscreen_customize_unitst")
			return DF_Type::viewscreen_customize_unitst;
		if (l_full_name == "viewscreen_dungeon_monsterstatusst")
			return DF_Type::viewscreen_dungeon_monsterstatusst;
		if (l_full_name == "viewscreen_dungeon_wrestlest")
			return DF_Type::viewscreen_dungeon_wrestlest;
		if (l_full_name == "viewscreen_dungeonmodest")
			return DF_Type::viewscreen_dungeonmodest;
		if (l_full_name == "viewscreen_dwarfmodest")
			return DF_Type::viewscreen_dwarfmodest;
		if (l_full_name == "viewscreen_entityst")
			return DF_Type::viewscreen_entityst;
		if (l_full_name == "viewscreen_export_graphical_mapst")
			return DF_Type::viewscreen_export_graphical_mapst;
		if (l_full_name == "viewscreen_export_regionst")
			return DF_Type::viewscreen_export_regionst;
		if (l_full_name == "viewscreen_game_cleanerst")
			return DF_Type::viewscreen_game_cleanerst;
		if (l_full_name == "viewscreen_image_creatorst")
			return DF_Type::viewscreen_image_creatorst;
		if (l_full_name == "viewscreen_itemst")
			return DF_Type::viewscreen_itemst;
		if (l_full_name == "viewscreen_jobst")
			return DF_Type::viewscreen_jobst;
		if (l_full_name == "viewscreen_joblistst")
			return DF_Type::viewscreen_joblistst;
		if (l_full_name == "viewscreen_jobmanagementst")
			return DF_Type::viewscreen_jobmanagementst;
		if (l_full_name == "viewscreen_justicest")
			return DF_Type::viewscreen_justicest;
		if (l_full_name == "viewscreen_kitchenprefst")
			return DF_Type::viewscreen_kitchenprefst;
		if (l_full_name == "viewscreen_legendsst")
			return DF_Type::viewscreen_legendsst;
		if (l_full_name == "viewscreen_locationsst")
			return DF_Type::viewscreen_locationsst;
		if (l_full_name == "viewscreen_loadgamest")
			return DF_Type::viewscreen_loadgamest;
		if (l_full_name == "viewscreen_meetingst")
			return DF_Type::viewscreen_meetingst;
		if (l_full_name == "viewscreen_movieplayerst")
			return DF_Type::viewscreen_movieplayerst;
		if (l_full_name == "viewscreen_new_regionst")
			return DF_Type::viewscreen_new_regionst;
		if (l_full_name == "viewscreen_noblest")
			return DF_Type::viewscreen_noblest;
		if (l_full_name == "viewscreen_optionst")
			return DF_Type::viewscreen_optionst;
		if (l_full_name == "viewscreen_overallstatusst")
			return DF_Type::viewscreen_overallstatusst;
		if (l_full_name == "viewscreen_petitionsst")
			return DF_Type::viewscreen_petitionsst;
		if (l_full_name == "viewscreen_petst")
			return DF_Type::viewscreen_petst;
		if (l_full_name == "viewscreen_pricest")
			return DF_Type::viewscreen_pricest;
		if (l_full_name == "viewscreen_reportlistst")
			return DF_Type::viewscreen_reportlistst;
		if (l_full_name == "viewscreen_requestagreementst")
			return DF_Type::viewscreen_requestagreementst;
		if (l_full_name == "viewscreen_savegamest")
			return DF_Type::viewscreen_savegamest;
		if (l_full_name == "viewscreen_selectitemst")
			return DF_Type::viewscreen_selectitemst;
		if (l_full_name == "viewscreen_setupadventurest")
			return DF_Type::viewscreen_setupadventurest;
		if (l_full_name == "viewscreen_setupdwarfgamest")
			return DF_Type::viewscreen_setupdwarfgamest;
		if (l_full_name == "viewscreen_storesst")
			return DF_Type::viewscreen_storesst;
		if (l_full_name == "viewscreen_textviewerst")
			return DF_Type::viewscreen_textviewerst;
		if (l_full_name == "viewscreen_titlest")
			return DF_Type::viewscreen_titlest;
		if (l_full_name == "viewscreen_topicmeetingst")
			return DF_Type::viewscreen_topicmeetingst;
		if (l_full_name == "viewscreen_topicmeeting_fill_land_holder_positionsst")
			return DF_Type::viewscreen_topicmeeting_fill_land_holder_positionsst;
		if (l_full_name == "viewscreen_topicmeeting_takerequestsst")
			return DF_Type::viewscreen_topicmeeting_takerequestsst;
		if (l_full_name == "viewscreen_tradeagreementst")
			return DF_Type::viewscreen_tradeagreementst;
		if (l_full_name == "viewscreen_tradegoodsst")
			return DF_Type::viewscreen_tradegoodsst;
		if (l_full_name == "viewscreen_tradelistst")
			return DF_Type::viewscreen_tradelistst;
		if (l_full_name == "viewscreen_treasurelistst")
			return DF_Type::viewscreen_treasurelistst;
		if (l_full_name == "viewscreen_unitst")
			return DF_Type::viewscreen_unitst;
		if (l_full_name == "viewscreen_unitlistst")
			return DF_Type::viewscreen_unitlistst;
		if (l_full_name == "viewscreen_wagesst")
			return DF_Type::viewscreen_wagesst;
		if (l_full_name == "viewscreen_workquota_conditionst")
			return DF_Type::viewscreen_workquota_conditionst;
		if (l_full_name == "viewscreen_workquota_detailsst")
			return DF_Type::viewscreen_workquota_detailsst;
		if (l_full_name == "viewscreen_workshop_profilest")
			return DF_Type::viewscreen_workshop_profilest;
		if (l_full_name == "viewscreen_update_regionst")
			return DF_Type::viewscreen_update_regionst;
	}
	return DF_Type::None;
}

DF_Type layer_object_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::layer_object*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "layer_object_listst")
			return DF_Type::layer_object_listst;
		if (l_full_name == "layer_object_buttonst")
			return DF_Type::layer_object_buttonst;
	}
	return DF_Type::None;
}

DF_Type world_gen_param_basest_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::world_gen_param_basest*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "world_gen_param_seedst")
			return DF_Type::world_gen_param_seedst;
		if (l_full_name == "world_gen_param_valuest")
			return DF_Type::world_gen_param_valuest;
		if (l_full_name == "world_gen_param_charst")
			return DF_Type::world_gen_param_charst;
		if (l_full_name == "world_gen_param_memberst")
			return DF_Type::world_gen_param_memberst;
	}
	return DF_Type::None;
}

DF_Type abstract_building_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::abstract_building*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "abstract_building_mead_hallst")
			return DF_Type::abstract_building_mead_hallst;
		if (l_full_name == "abstract_building_keepst")
			return DF_Type::abstract_building_keepst;
		if (l_full_name == "abstract_building_templest")
			return DF_Type::abstract_building_templest;
		if (l_full_name == "abstract_building_dark_towerst")
			return DF_Type::abstract_building_dark_towerst;
		if (l_full_name == "abstract_building_marketst")
			return DF_Type::abstract_building_marketst;
		if (l_full_name == "abstract_building_tombst")
			return DF_Type::abstract_building_tombst;
		if (l_full_name == "abstract_building_dungeonst")
			return DF_Type::abstract_building_dungeonst;
		if (l_full_name == "abstract_building_underworld_spirest")
			return DF_Type::abstract_building_underworld_spirest;
		if (l_full_name == "abstract_building_inn_tavernst")
			return DF_Type::abstract_building_inn_tavernst;
		if (l_full_name == "abstract_building_libraryst")
			return DF_Type::abstract_building_libraryst;
	}
	return DF_Type::None;
}

DF_Type site_realization_building_infost_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::site_realization_building_infost*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "site_realization_building_info_castle_wallst")
			return DF_Type::site_realization_building_info_castle_wallst;
		if (l_full_name == "site_realization_building_info_castle_towerst")
			return DF_Type::site_realization_building_info_castle_towerst;
		if (l_full_name == "site_realization_building_info_castle_courtyardst")
			return DF_Type::site_realization_building_info_castle_courtyardst;
		if (l_full_name == "site_realization_building_info_shop_housest")
			return DF_Type::site_realization_building_info_shop_housest;
		if (l_full_name == "site_realization_building_info_market_squarest")
			return DF_Type::site_realization_building_info_market_squarest;
		if (l_full_name == "site_realization_building_info_trenchesst")
			return DF_Type::site_realization_building_info_trenchesst;
		if (l_full_name == "site_realization_building_info_tree_housest")
			return DF_Type::site_realization_building_info_tree_housest;
		if (l_full_name == "site_realization_building_info_hillock_housest")
			return DF_Type::site_realization_building_info_hillock_housest;
	}
	return DF_Type::None;
}

DF_Type creation_zone_pwg_alterationst_subtype(uint64_t p_address)
{
	void* void_ptr = (void*)p_address;
	auto object_ptr = (df::creation_zone_pwg_alterationst*)void_ptr;

	DFHack::virtual_identity* id = DFHack::virtual_identity::get(object_ptr);
	if (id != nullptr)
	{
		auto l_full_name = id->getFullName();
		if (l_full_name == "creation_zone_pwg_alteration_location_deathst")
			return DF_Type::creation_zone_pwg_alteration_location_deathst;
		if (l_full_name == "creation_zone_pwg_alteration_campst")
			return DF_Type::creation_zone_pwg_alteration_campst;
		if (l_full_name == "creation_zone_pwg_alteration_srb_ruinedst")
			return DF_Type::creation_zone_pwg_alteration_srb_ruinedst;
		if (l_full_name == "creation_zone_pwg_alteration_srp_ruinedst")
			return DF_Type::creation_zone_pwg_alteration_srp_ruinedst;
	}
	return DF_Type::None;
}


	DF_Type get_df_subtype(DF_Type p_base_type, uint64_t p_address)
	{
		switch(p_base_type)
		{
			case DF_Type::text_info_elementst: return text_info_elementst_subtype(p_address);
			case DF_Type::adventure_optionst: return adventure_optionst_subtype(p_address);
			case DF_Type::adventure_movement_optionst: return adventure_movement_optionst_subtype(p_address);
			case DF_Type::adventure_item_interact_choicest: return adventure_item_interact_choicest_subtype(p_address);
			case DF_Type::art_image_element: return art_image_element_subtype(p_address);
			case DF_Type::art_image_property: return art_image_property_subtype(p_address);
			case DF_Type::building_def: return building_def_subtype(p_address);
			case DF_Type::building: return building_subtype(p_address);
			case DF_Type::mental_picture_propertyst: return mental_picture_propertyst_subtype(p_address);
			case DF_Type::mental_picture_elementst: return mental_picture_elementst_subtype(p_address);
			case DF_Type::history_event: return history_event_subtype(p_address);
			case DF_Type::history_event_collection: return history_event_collection_subtype(p_address);
			case DF_Type::interaction_effect: return interaction_effect_subtype(p_address);
			case DF_Type::interaction_source: return interaction_source_subtype(p_address);
			case DF_Type::interaction_target: return interaction_target_subtype(p_address);
			case DF_Type::itemdef: return itemdef_subtype(p_address);
			case DF_Type::itemimprovement: return itemimprovement_subtype(p_address);
			case DF_Type::spatter_common: return spatter_common_subtype(p_address);
			case DF_Type::item: return item_subtype(p_address);
			case DF_Type::machine: return machine_subtype(p_address);
			case DF_Type::block_square_event: return block_square_event_subtype(p_address);
			case DF_Type::feature: return feature_subtype(p_address);
			case DF_Type::feature_init: return feature_init_subtype(p_address);
			case DF_Type::feature_alteration: return feature_alteration_subtype(p_address);
			case DF_Type::world_construction_square: return world_construction_square_subtype(p_address);
			case DF_Type::world_construction: return world_construction_subtype(p_address);
			case DF_Type::flow_guide: return flow_guide_subtype(p_address);
			case DF_Type::region_block_eventst: return region_block_eventst_subtype(p_address);
			case DF_Type::material_common: return material_common_subtype(p_address);
			case DF_Type::script_stepst: return script_stepst_subtype(p_address);
			case DF_Type::script_varst: return script_varst_subtype(p_address);
			case DF_Type::active_script_varst: return active_script_varst_subtype(p_address);
			case DF_Type::activity_event: return activity_event_subtype(p_address);
			case DF_Type::squad_order: return squad_order_subtype(p_address);
			case DF_Type::projectile: return projectile_subtype(p_address);
			case DF_Type::reaction_reagent: return reaction_reagent_subtype(p_address);
			case DF_Type::reaction_product: return reaction_product_subtype(p_address);
			case DF_Type::general_ref: return general_ref_subtype(p_address);
			case DF_Type::histfig_entity_link: return histfig_entity_link_subtype(p_address);
			case DF_Type::histfig_site_link: return histfig_site_link_subtype(p_address);
			case DF_Type::histfig_hf_link: return histfig_hf_link_subtype(p_address);
			case DF_Type::resource_allotment_specifier: return resource_allotment_specifier_subtype(p_address);
			case DF_Type::creature_interaction_effect: return creature_interaction_effect_subtype(p_address);
			case DF_Type::build_req_choicest: return build_req_choicest_subtype(p_address);
			case DF_Type::interface_button: return interface_button_subtype(p_address);
			case DF_Type::viewscreen: return viewscreen_subtype(p_address);
			case DF_Type::layer_object: return layer_object_subtype(p_address);
			case DF_Type::world_gen_param_basest: return world_gen_param_basest_subtype(p_address);
			case DF_Type::abstract_building: return abstract_building_subtype(p_address);
			case DF_Type::site_realization_building_infost: return site_realization_building_infost_subtype(p_address);
			case DF_Type::creation_zone_pwg_alterationst: return creation_zone_pwg_alterationst_subtype(p_address);
			default: break;
		}
		return DF_Type::None;
	}
