
#include <string>
#include <map>
#include "DF_Types.h"

namespace rdf
{

// Function to return the string value of this enum class
std::string DF_Type_to_string(DF_Type p_type)
{
    switch (p_type)
    {
        case DF_Type::None: return "None";
        case DF_Type::int64_t: return "int64_t";
        case DF_Type::uint64_t: return "uint64_t";
        case DF_Type::int32_t: return "int32_t";
        case DF_Type::int16_t: return "int16_t";
        case DF_Type::uint32_t: return "uint32_t";
        case DF_Type::uint16_t: return "uint16_t";
        case DF_Type::uint8_t: return "uint8_t";
        case DF_Type::int8_t: return "int8_t";
        case DF_Type::Void: return "Void";
        case DF_Type::Char: return "Char";
        case DF_Type::Long: return "Long";
        case DF_Type::Bool: return "Bool";
        case DF_Type::Stl_string: return "Stl_string";
        case DF_Type::Static_string: return "Static_string";
        case DF_Type::Ptr_string: return "Ptr_string";
        case DF_Type::S_float: return "S_float";
        case DF_Type::D_float: return "D_float";
        case DF_Type::S_double: return "S_double";
        case DF_Type::Padding: return "Padding";
        case DF_Type::Stl_fstream: return "Fstream";
		case DF_Type::abstract_building: return "abstract_building";
		case DF_Type::abstract_building__T_inhabitants: return "abstract_building__T_inhabitants";
		case DF_Type::abstract_building__T_unk1: return "abstract_building__T_unk1";
		case DF_Type::abstract_building_contents: return "abstract_building_contents";
		case DF_Type::abstract_building_counting_housest: return "abstract_building_counting_housest";
		case DF_Type::abstract_building_dark_towerst: return "abstract_building_dark_towerst";
		case DF_Type::abstract_building_dungeonst: return "abstract_building_dungeonst";
		case DF_Type::abstract_building_dungeonst__T_dungeon_type: return "abstract_building_dungeonst__T_dungeon_type";
		case DF_Type::abstract_building_flags: return "abstract_building_flags";
		case DF_Type::abstract_building_guildhallst: return "abstract_building_guildhallst";
		case DF_Type::abstract_building_inn_tavernst: return "abstract_building_inn_tavernst";
		case DF_Type::abstract_building_inn_tavernst__T_room_info: return "abstract_building_inn_tavernst__T_room_info";
		case DF_Type::abstract_building_keepst: return "abstract_building_keepst";
		case DF_Type::abstract_building_libraryst: return "abstract_building_libraryst";
		case DF_Type::abstract_building_marketst: return "abstract_building_marketst";
		case DF_Type::abstract_building_mead_hallst: return "abstract_building_mead_hallst";
		case DF_Type::abstract_building_templest: return "abstract_building_templest";
		case DF_Type::abstract_building_tombst: return "abstract_building_tombst";
		case DF_Type::abstract_building_towerst: return "abstract_building_towerst";
		case DF_Type::abstract_building_type: return "abstract_building_type";
		case DF_Type::abstract_building_underworld_spirest: return "abstract_building_underworld_spirest";
		case DF_Type::abstract_building_unk: return "abstract_building_unk";
		case DF_Type::abstract_building_unk__T_anon_1: return "abstract_building_unk__T_anon_1";
		case DF_Type::active_script_var_longst: return "active_script_var_longst";
		case DF_Type::active_script_var_unitst: return "active_script_var_unitst";
		case DF_Type::active_script_varst: return "active_script_varst";
		case DF_Type::activity_entry: return "activity_entry";
		case DF_Type::activity_entry_type: return "activity_entry_type";
		case DF_Type::activity_event: return "activity_event";
		case DF_Type::activity_event__T_flags: return "activity_event__T_flags";
		case DF_Type::activity_event__T_unk_v42_1: return "activity_event__T_unk_v42_1";
		case DF_Type::activity_event__T_unk_v42_2: return "activity_event__T_unk_v42_2";
		case DF_Type::activity_event_combat_trainingst: return "activity_event_combat_trainingst";
		case DF_Type::activity_event_conflictst: return "activity_event_conflictst";
		case DF_Type::activity_event_conflictst__T_sides: return "activity_event_conflictst__T_sides";
		case DF_Type::activity_event_conflictst__T_sides__T_enemies: return "activity_event_conflictst__T_sides__T_enemies";
		case DF_Type::activity_event_conversationst: return "activity_event_conversationst";
		case DF_Type::activity_event_conversationst__T_anon_6: return "activity_event_conversationst__T_anon_6";
		case DF_Type::activity_event_conversationst__T_flags2: return "activity_event_conversationst__T_flags2";
		case DF_Type::activity_event_conversationst__T_participants: return "activity_event_conversationst__T_participants";
		case DF_Type::activity_event_conversationst__T_turns: return "activity_event_conversationst__T_turns";
		case DF_Type::activity_event_conversationst__T_unk2: return "activity_event_conversationst__T_unk2";
		case DF_Type::activity_event_conversationst__T_unk_b4: return "activity_event_conversationst__T_unk_b4";
		case DF_Type::activity_event_copy_written_contentst: return "activity_event_copy_written_contentst";
		case DF_Type::activity_event_copy_written_contentst__T_flagsmaybe: return "activity_event_copy_written_contentst__T_flagsmaybe";
		case DF_Type::activity_event_discuss_topicst: return "activity_event_discuss_topicst";
		case DF_Type::activity_event_encounterst: return "activity_event_encounterst";
		case DF_Type::activity_event_encounterst__T_anon_1: return "activity_event_encounterst__T_anon_1";
		case DF_Type::activity_event_encounterst__T_anon_2: return "activity_event_encounterst__T_anon_2";
		case DF_Type::activity_event_fill_service_orderst: return "activity_event_fill_service_orderst";
		case DF_Type::activity_event_guardst: return "activity_event_guardst";
		case DF_Type::activity_event_harassmentst: return "activity_event_harassmentst";
		case DF_Type::activity_event_harassmentst__T_anon_2: return "activity_event_harassmentst__T_anon_2";
		case DF_Type::activity_event_individual_skill_drillst: return "activity_event_individual_skill_drillst";
		case DF_Type::activity_event_make_believest: return "activity_event_make_believest";
		case DF_Type::activity_event_participants: return "activity_event_participants";
		case DF_Type::activity_event_performancest: return "activity_event_performancest";
		case DF_Type::activity_event_performancest__T_participant_actions: return "activity_event_performancest__T_participant_actions";
		case DF_Type::activity_event_play_with_toyst: return "activity_event_play_with_toyst";
		case DF_Type::activity_event_play_with_toyst__T_unk: return "activity_event_play_with_toyst__T_unk";
		case DF_Type::activity_event_playst: return "activity_event_playst";
		case DF_Type::activity_event_ponder_topicst: return "activity_event_ponder_topicst";
		case DF_Type::activity_event_prayerst: return "activity_event_prayerst";
		case DF_Type::activity_event_ranged_practicest: return "activity_event_ranged_practicest";
		case DF_Type::activity_event_readst: return "activity_event_readst";
		case DF_Type::activity_event_researchst: return "activity_event_researchst";
		case DF_Type::activity_event_reunionst: return "activity_event_reunionst";
		case DF_Type::activity_event_skill_demonstrationst: return "activity_event_skill_demonstrationst";
		case DF_Type::activity_event_socializest: return "activity_event_socializest";
		case DF_Type::activity_event_sparringst: return "activity_event_sparringst";
		case DF_Type::activity_event_sparringst__T_groups: return "activity_event_sparringst__T_groups";
		case DF_Type::activity_event_store_objectst: return "activity_event_store_objectst";
		case DF_Type::activity_event_teach_topicst: return "activity_event_teach_topicst";
		case DF_Type::activity_event_training_sessionst: return "activity_event_training_sessionst";
		case DF_Type::activity_event_type: return "activity_event_type";
		case DF_Type::activity_event_worshipst: return "activity_event_worshipst";
		case DF_Type::activity_event_writest: return "activity_event_writest";
		case DF_Type::activity_info: return "activity_info";
		case DF_Type::activity_info__T_flags: return "activity_info__T_flags";
		case DF_Type::adventure_environment_ingest_from_containerst: return "adventure_environment_ingest_from_containerst";
		case DF_Type::adventure_environment_ingest_materialst: return "adventure_environment_ingest_materialst";
		case DF_Type::adventure_environment_optionst: return "adventure_environment_optionst";
		case DF_Type::adventure_environment_pickup_chop_treest: return "adventure_environment_pickup_chop_treest";
		case DF_Type::adventure_environment_pickup_ignite_vegst: return "adventure_environment_pickup_ignite_vegst";
		case DF_Type::adventure_environment_pickup_make_campfirest: return "adventure_environment_pickup_make_campfirest";
		case DF_Type::adventure_environment_pickup_vermin_eventst: return "adventure_environment_pickup_vermin_eventst";
		case DF_Type::adventure_environment_place_in_bld_containerst: return "adventure_environment_place_in_bld_containerst";
		case DF_Type::adventure_environment_place_in_it_containerst: return "adventure_environment_place_in_it_containerst";
		case DF_Type::adventure_environment_unit_suck_bloodst: return "adventure_environment_unit_suck_bloodst";
		case DF_Type::adventure_item_interact_choicest: return "adventure_item_interact_choicest";
		case DF_Type::adventure_item_interact_fill_from_containerst: return "adventure_item_interact_fill_from_containerst";
		case DF_Type::adventure_item_interact_fill_with_materialst: return "adventure_item_interact_fill_with_materialst";
		case DF_Type::adventure_item_interact_give_namest: return "adventure_item_interact_give_namest";
		case DF_Type::adventure_item_interact_heat_from_tilest: return "adventure_item_interact_heat_from_tilest";
		case DF_Type::adventure_item_interact_pull_outst: return "adventure_item_interact_pull_outst";
		case DF_Type::adventure_item_interact_readst: return "adventure_item_interact_readst";
		case DF_Type::adventure_item_interact_strugglest: return "adventure_item_interact_strugglest";
		case DF_Type::adventure_log_item: return "adventure_log_item";
		case DF_Type::adventure_movement_attack_creaturest: return "adventure_movement_attack_creaturest";
		case DF_Type::adventure_movement_building_interactst: return "adventure_movement_building_interactst";
		case DF_Type::adventure_movement_climbst: return "adventure_movement_climbst";
		case DF_Type::adventure_movement_hold_itemst: return "adventure_movement_hold_itemst";
		case DF_Type::adventure_movement_hold_tilest: return "adventure_movement_hold_tilest";
		case DF_Type::adventure_movement_item_interact_guidest: return "adventure_movement_item_interact_guidest";
		case DF_Type::adventure_movement_item_interact_pushst: return "adventure_movement_item_interact_pushst";
		case DF_Type::adventure_movement_item_interact_ridest: return "adventure_movement_item_interact_ridest";
		case DF_Type::adventure_movement_item_interactst: return "adventure_movement_item_interactst";
		case DF_Type::adventure_movement_movest: return "adventure_movement_movest";
		case DF_Type::adventure_movement_optionst: return "adventure_movement_optionst";
		case DF_Type::adventure_movement_release_hold_itemst: return "adventure_movement_release_hold_itemst";
		case DF_Type::adventure_movement_release_hold_tilest: return "adventure_movement_release_hold_tilest";
		case DF_Type::adventure_option_eat_item_contaminantst: return "adventure_option_eat_item_contaminantst";
		case DF_Type::adventure_option_eat_unit_contaminantst: return "adventure_option_eat_unit_contaminantst";
		case DF_Type::adventure_option_view_contaminantst: return "adventure_option_view_contaminantst";
		case DF_Type::adventure_optionst: return "adventure_optionst";
		case DF_Type::adventurer_attribute_level: return "adventurer_attribute_level";
		case DF_Type::agreement: return "agreement";
		case DF_Type::agreement__T_anon_3: return "agreement__T_anon_3";
		case DF_Type::agreement_details: return "agreement_details";
		case DF_Type::agreement_details__T_data: return "agreement_details__T_data";
		case DF_Type::agreement_details_data_citizenship: return "agreement_details_data_citizenship";
		case DF_Type::agreement_details_data_demonic_binding: return "agreement_details_data_demonic_binding";
		case DF_Type::agreement_details_data_join_party: return "agreement_details_data_join_party";
		case DF_Type::agreement_details_data_location: return "agreement_details_data_location";
		case DF_Type::agreement_details_data_parley: return "agreement_details_data_parley";
		case DF_Type::agreement_details_data_plot_abduct: return "agreement_details_data_plot_abduct";
		case DF_Type::agreement_details_data_plot_assassination: return "agreement_details_data_plot_assassination";
		case DF_Type::agreement_details_data_plot_conviction: return "agreement_details_data_plot_conviction";
		case DF_Type::agreement_details_data_plot_frame_treason: return "agreement_details_data_plot_frame_treason";
		case DF_Type::agreement_details_data_plot_induce_war: return "agreement_details_data_plot_induce_war";
		case DF_Type::agreement_details_data_plot_infiltration_coup: return "agreement_details_data_plot_infiltration_coup";
		case DF_Type::agreement_details_data_plot_steal_artifact: return "agreement_details_data_plot_steal_artifact";
		case DF_Type::agreement_details_data_position_corruption: return "agreement_details_data_position_corruption";
		case DF_Type::agreement_details_data_promise_position: return "agreement_details_data_promise_position";
		case DF_Type::agreement_details_data_residency: return "agreement_details_data_residency";
		case DF_Type::agreement_details_data_unk10: return "agreement_details_data_unk10";
		case DF_Type::agreement_details_type: return "agreement_details_type";
		case DF_Type::agreement_party: return "agreement_party";
		case DF_Type::agreement_party__T_anon_1: return "agreement_party__T_anon_1";
		case DF_Type::ammo_flags: return "ammo_flags";
		case DF_Type::animal_training_level: return "animal_training_level";
		case DF_Type::announcement_flags: return "announcement_flags";
		case DF_Type::announcement_type: return "announcement_type";
		case DF_Type::announcements: return "announcements";
		case DF_Type::appearance_modifier_growth_interval: return "appearance_modifier_growth_interval";
		case DF_Type::appearance_modifier_type: return "appearance_modifier_type";
		case DF_Type::armor_flags: return "armor_flags";
		case DF_Type::armor_general_flags: return "armor_general_flags";
		case DF_Type::armor_properties: return "armor_properties";
		case DF_Type::army: return "army";
		case DF_Type::army__T_members: return "army__T_members";
		case DF_Type::army__T_unk_2c: return "army__T_unk_2c";
		case DF_Type::army_controller: return "army_controller";
		case DF_Type::army_controller__T_type: return "army_controller__T_type";
		case DF_Type::army_controller__T_unk_64: return "army_controller__T_unk_64";
		case DF_Type::army_controller_sub1: return "army_controller_sub1";
		case DF_Type::army_controller_sub11: return "army_controller_sub11";
		case DF_Type::army_controller_sub11__T_anon_3: return "army_controller_sub11__T_anon_3";
		case DF_Type::army_controller_sub12: return "army_controller_sub12";
		case DF_Type::army_controller_sub12__T_anon_4: return "army_controller_sub12__T_anon_4";
		case DF_Type::army_controller_sub13: return "army_controller_sub13";
		case DF_Type::army_controller_sub13__T_anon_4: return "army_controller_sub13__T_anon_4";
		case DF_Type::army_controller_sub14: return "army_controller_sub14";
		case DF_Type::army_controller_sub14__T_anon_4: return "army_controller_sub14__T_anon_4";
		case DF_Type::army_controller_sub15: return "army_controller_sub15";
		case DF_Type::army_controller_sub15__T_anon_3: return "army_controller_sub15__T_anon_3";
		case DF_Type::army_controller_sub16: return "army_controller_sub16";
		case DF_Type::army_controller_sub17: return "army_controller_sub17";
		case DF_Type::army_controller_sub18: return "army_controller_sub18";
		case DF_Type::army_controller_sub2: return "army_controller_sub2";
		case DF_Type::army_controller_sub24: return "army_controller_sub24";
		case DF_Type::army_controller_sub2__T_anon_5: return "army_controller_sub2__T_anon_5";
		case DF_Type::army_controller_sub4: return "army_controller_sub4";
		case DF_Type::army_controller_sub4__T_unk_2: return "army_controller_sub4__T_unk_2";
		case DF_Type::army_controller_sub5: return "army_controller_sub5";
		case DF_Type::army_controller_sub6: return "army_controller_sub6";
		case DF_Type::army_controller_sub7: return "army_controller_sub7";
		case DF_Type::army_controller_sub7__T_anon_3: return "army_controller_sub7__T_anon_3";
		case DF_Type::army_flags: return "army_flags";
		case DF_Type::art_facet_type: return "art_facet_type";
		case DF_Type::art_image: return "art_image";
		case DF_Type::art_image_chunk: return "art_image_chunk";
		case DF_Type::art_image_element: return "art_image_element";
		case DF_Type::art_image_element_creaturest: return "art_image_element_creaturest";
		case DF_Type::art_image_element_itemst: return "art_image_element_itemst";
		case DF_Type::art_image_element_plantst: return "art_image_element_plantst";
		case DF_Type::art_image_element_shapest: return "art_image_element_shapest";
		case DF_Type::art_image_element_treest: return "art_image_element_treest";
		case DF_Type::art_image_element_type: return "art_image_element_type";
		case DF_Type::art_image_property: return "art_image_property";
		case DF_Type::art_image_property_intransitive_verbst: return "art_image_property_intransitive_verbst";
		case DF_Type::art_image_property_transitive_verbst: return "art_image_property_transitive_verbst";
		case DF_Type::art_image_property_type: return "art_image_property_type";
		case DF_Type::art_image_property_verb: return "art_image_property_verb";
		case DF_Type::art_image_ref: return "art_image_ref";
		case DF_Type::artifact_claim: return "artifact_claim";
		case DF_Type::artifact_claim_type: return "artifact_claim_type";
		case DF_Type::artifact_record: return "artifact_record";
		case DF_Type::assign_trade_status: return "assign_trade_status";
		case DF_Type::assign_trade_status__T_status: return "assign_trade_status__T_status";
		case DF_Type::assume_identity_mode: return "assume_identity_mode";
		case DF_Type::barrack_preference_category: return "barrack_preference_category";
		case DF_Type::belief_system: return "belief_system";
		case DF_Type::biome_type: return "biome_type";
		case DF_Type::block_burrow: return "block_burrow";
		case DF_Type::block_burrow_link: return "block_burrow_link";
		case DF_Type::block_flags: return "block_flags";
		case DF_Type::block_square_event: return "block_square_event";
		case DF_Type::block_square_event_designation_priorityst: return "block_square_event_designation_priorityst";
		case DF_Type::block_square_event_frozen_liquidst: return "block_square_event_frozen_liquidst";
		case DF_Type::block_square_event_grassst: return "block_square_event_grassst";
		case DF_Type::block_square_event_item_spatterst: return "block_square_event_item_spatterst";
		case DF_Type::block_square_event_material_spatterst: return "block_square_event_material_spatterst";
		case DF_Type::block_square_event_mineralst: return "block_square_event_mineralst";
		case DF_Type::block_square_event_mineralst__T_flags: return "block_square_event_mineralst__T_flags";
		case DF_Type::block_square_event_spoorst: return "block_square_event_spoorst";
		case DF_Type::block_square_event_type: return "block_square_event_type";
		case DF_Type::block_square_event_world_constructionst: return "block_square_event_world_constructionst";
		case DF_Type::body_appearance_modifier: return "body_appearance_modifier";
		case DF_Type::body_component_info: return "body_component_info";
		case DF_Type::body_detail_plan: return "body_detail_plan";
		case DF_Type::body_layer_status: return "body_layer_status";
		case DF_Type::body_part_layer_flags: return "body_part_layer_flags";
		case DF_Type::body_part_layer_raw: return "body_part_layer_raw";
		case DF_Type::body_part_raw: return "body_part_raw";
		case DF_Type::body_part_raw_flags: return "body_part_raw_flags";
		case DF_Type::body_part_status: return "body_part_status";
		case DF_Type::body_part_template: return "body_part_template";
		case DF_Type::body_part_template_contype: return "body_part_template_contype";
		case DF_Type::body_part_template_flags: return "body_part_template_flags";
		case DF_Type::body_size_info: return "body_size_info";
		case DF_Type::body_template: return "body_template";
		case DF_Type::bp_appearance_modifier: return "bp_appearance_modifier";
		case DF_Type::breath_attack_type: return "breath_attack_type";
		case DF_Type::build_req_choice_genst: return "build_req_choice_genst";
		case DF_Type::build_req_choice_specst: return "build_req_choice_specst";
		case DF_Type::build_req_choice_type: return "build_req_choice_type";
		case DF_Type::build_req_choicest: return "build_req_choicest";
		case DF_Type::building: return "building";
		case DF_Type::building__T_activities: return "building__T_activities";
		case DF_Type::building__T_job_claim_suppress: return "building__T_job_claim_suppress";
		case DF_Type::building_actual: return "building_actual";
		case DF_Type::building_actual__T_contained_items: return "building_actual__T_contained_items";
		case DF_Type::building_animaltrapst: return "building_animaltrapst";
		case DF_Type::building_archerytargetst: return "building_archerytargetst";
		case DF_Type::building_archerytargetst__T_archery_direction: return "building_archerytargetst__T_archery_direction";
		case DF_Type::building_armorstandst: return "building_armorstandst";
		case DF_Type::building_axle_horizontalst: return "building_axle_horizontalst";
		case DF_Type::building_axle_verticalst: return "building_axle_verticalst";
		case DF_Type::building_bars_floorst: return "building_bars_floorst";
		case DF_Type::building_bars_verticalst: return "building_bars_verticalst";
		case DF_Type::building_bedst: return "building_bedst";
		case DF_Type::building_bedst__T_bed_flags: return "building_bedst__T_bed_flags";
		case DF_Type::building_bookcasest: return "building_bookcasest";
		case DF_Type::building_boxst: return "building_boxst";
		case DF_Type::building_bridgest: return "building_bridgest";
		case DF_Type::building_bridgest__T_direction: return "building_bridgest__T_direction";
		case DF_Type::building_cabinetst: return "building_cabinetst";
		case DF_Type::building_cagest: return "building_cagest";
		case DF_Type::building_cagest__T_cage_flags: return "building_cagest__T_cage_flags";
		case DF_Type::building_chainst: return "building_chainst";
		case DF_Type::building_chainst__T_chain_flags: return "building_chainst__T_chain_flags";
		case DF_Type::building_chairst: return "building_chairst";
		case DF_Type::building_civzonest: return "building_civzonest";
		case DF_Type::building_civzonest__T_gather_flags: return "building_civzonest__T_gather_flags";
		case DF_Type::building_civzonest__T_pit_flags: return "building_civzonest__T_pit_flags";
		case DF_Type::building_civzonest__T_zone_flags: return "building_civzonest__T_zone_flags";
		case DF_Type::building_coffinst: return "building_coffinst";
		case DF_Type::building_coffinst__T_burial_mode: return "building_coffinst__T_burial_mode";
		case DF_Type::building_constructionst: return "building_constructionst";
		case DF_Type::building_def: return "building_def";
		case DF_Type::building_def_furnacest: return "building_def_furnacest";
		case DF_Type::building_def_item: return "building_def_item";
		case DF_Type::building_def_workshopst: return "building_def_workshopst";
		case DF_Type::building_design: return "building_design";
		case DF_Type::building_design__T_flags: return "building_design__T_flags";
		case DF_Type::building_display_furniturest: return "building_display_furniturest";
		case DF_Type::building_doorst: return "building_doorst";
		case DF_Type::building_drawbuffer: return "building_drawbuffer";
		case DF_Type::building_extents: return "building_extents";
		case DF_Type::building_farmplotst: return "building_farmplotst";
		case DF_Type::building_flags: return "building_flags";
		case DF_Type::building_floodgatest: return "building_floodgatest";
		case DF_Type::building_furnacest: return "building_furnacest";
		case DF_Type::building_gear_assemblyst: return "building_gear_assemblyst";
		case DF_Type::building_gear_assemblyst__T_gear_flags: return "building_gear_assemblyst__T_gear_flags";
		case DF_Type::building_grate_floorst: return "building_grate_floorst";
		case DF_Type::building_grate_wallst: return "building_grate_wallst";
		case DF_Type::building_handler: return "building_handler";
		case DF_Type::building_hatchst: return "building_hatchst";
		case DF_Type::building_hivest: return "building_hivest";
		case DF_Type::building_instrumentst: return "building_instrumentst";
		case DF_Type::building_nest_boxst: return "building_nest_boxst";
		case DF_Type::building_nestst: return "building_nestst";
		case DF_Type::building_offering_placest: return "building_offering_placest";
		case DF_Type::building_road_dirtst: return "building_road_dirtst";
		case DF_Type::building_road_pavedst: return "building_road_pavedst";
		case DF_Type::building_roadst: return "building_roadst";
		case DF_Type::building_rollersst: return "building_rollersst";
		case DF_Type::building_screw_pumpst: return "building_screw_pumpst";
		case DF_Type::building_shopst: return "building_shopst";
		case DF_Type::building_shopst__T_shop_flags: return "building_shopst__T_shop_flags";
		case DF_Type::building_siegeenginest: return "building_siegeenginest";
		case DF_Type::building_siegeenginest__T_action: return "building_siegeenginest__T_action";
		case DF_Type::building_siegeenginest__T_facing: return "building_siegeenginest__T_facing";
		case DF_Type::building_slabst: return "building_slabst";
		case DF_Type::building_squad_use: return "building_squad_use";
		case DF_Type::building_statuest: return "building_statuest";
		case DF_Type::building_stockpilest: return "building_stockpilest";
		case DF_Type::building_supportst: return "building_supportst";
		case DF_Type::building_supportst__T_support_flags: return "building_supportst__T_support_flags";
		case DF_Type::building_tablest: return "building_tablest";
		case DF_Type::building_tablest__T_table_flags: return "building_tablest__T_table_flags";
		case DF_Type::building_traction_benchst: return "building_traction_benchst";
		case DF_Type::building_tradedepotst: return "building_tradedepotst";
		case DF_Type::building_tradedepotst__T_trade_flags: return "building_tradedepotst__T_trade_flags";
		case DF_Type::building_trapst: return "building_trapst";
		case DF_Type::building_trapst__T_stop_flags: return "building_trapst__T_stop_flags";
		case DF_Type::building_type: return "building_type";
		case DF_Type::building_users: return "building_users";
		case DF_Type::building_wagonst: return "building_wagonst";
		case DF_Type::building_water_wheelst: return "building_water_wheelst";
		case DF_Type::building_weaponrackst: return "building_weaponrackst";
		case DF_Type::building_weaponst: return "building_weaponst";
		case DF_Type::building_wellst: return "building_wellst";
		case DF_Type::building_wellst__T_well_flags: return "building_wellst__T_well_flags";
		case DF_Type::building_windmillst: return "building_windmillst";
		case DF_Type::building_window_gemst: return "building_window_gemst";
		case DF_Type::building_window_glassst: return "building_window_glassst";
		case DF_Type::building_windowst: return "building_windowst";
		case DF_Type::building_workshopst: return "building_workshopst";
		case DF_Type::buildings_other_id: return "buildings_other_id";
		case DF_Type::builtin_mats: return "builtin_mats";
		case DF_Type::burrow: return "burrow";
		case DF_Type::campfire: return "campfire";
		case DF_Type::caravan_state: return "caravan_state";
		case DF_Type::caravan_state__T_flags: return "caravan_state__T_flags";
		case DF_Type::caravan_state__T_trade_state: return "caravan_state__T_trade_state";
		case DF_Type::caste_attack: return "caste_attack";
		case DF_Type::caste_attack__T_flags: return "caste_attack__T_flags";
		case DF_Type::caste_body_info: return "caste_body_info";
		case DF_Type::caste_body_info__T_extra_butcher_objects: return "caste_body_info__T_extra_butcher_objects";
		case DF_Type::caste_body_info__T_flags: return "caste_body_info__T_flags";
		case DF_Type::caste_body_info__T_interactions: return "caste_body_info__T_interactions";
		case DF_Type::caste_body_info__T_interactions__T_type: return "caste_body_info__T_interactions__T_type";
		case DF_Type::caste_clothing_item: return "caste_clothing_item";
		case DF_Type::caste_raw: return "caste_raw";
		case DF_Type::caste_raw__T_anon_1: return "caste_raw__T_anon_1";
		case DF_Type::caste_raw__T_attributes: return "caste_raw__T_attributes";
		case DF_Type::caste_raw__T_bp_appearance: return "caste_raw__T_bp_appearance";
		case DF_Type::caste_raw__T_caste_profession_name: return "caste_raw__T_caste_profession_name";
		case DF_Type::caste_raw__T_extracts: return "caste_raw__T_extracts";
		case DF_Type::caste_raw__T_lair_hunter_speech: return "caste_raw__T_lair_hunter_speech";
		case DF_Type::caste_raw__T_misc: return "caste_raw__T_misc";
		case DF_Type::caste_raw__T_personality: return "caste_raw__T_personality";
		case DF_Type::caste_raw__T_secretion: return "caste_raw__T_secretion";
		case DF_Type::caste_raw__T_shearable_tissue_layer: return "caste_raw__T_shearable_tissue_layer";
		case DF_Type::caste_raw__T_sound: return "caste_raw__T_sound";
		case DF_Type::caste_raw__T_unk29: return "caste_raw__T_unk29";
		case DF_Type::caste_raw__T_unknown2: return "caste_raw__T_unknown2";
		case DF_Type::caste_raw_flags: return "caste_raw_flags";
		case DF_Type::cave_column: return "cave_column";
		case DF_Type::cave_column_link: return "cave_column_link";
		case DF_Type::cave_column_rectangle: return "cave_column_rectangle";
		case DF_Type::cie_add_tag_mask1: return "cie_add_tag_mask1";
		case DF_Type::cie_add_tag_mask2: return "cie_add_tag_mask2";
		case DF_Type::civzone_type: return "civzone_type";
		case DF_Type::coin_batch: return "coin_batch";
		case DF_Type::coin_batch__T_image_back: return "coin_batch__T_image_back";
		case DF_Type::coin_batch__T_image_front: return "coin_batch__T_image_front";
		case DF_Type::color_modifier_raw: return "color_modifier_raw";
		case DF_Type::combat_report_event_type: return "combat_report_event_type";
		case DF_Type::conflict_level: return "conflict_level";
		case DF_Type::construction: return "construction";
		case DF_Type::construction_flags: return "construction_flags";
		case DF_Type::construction_type: return "construction_type";
		case DF_Type::conversation: return "conversation";
		case DF_Type::conversation__T_speech: return "conversation__T_speech";
		case DF_Type::conversation__T_state: return "conversation__T_state";
		case DF_Type::conversation_menu: return "conversation_menu";
		case DF_Type::coord: return "coord";
		case DF_Type::coord2d: return "coord2d";
		case DF_Type::coord2d_path: return "coord2d_path";
		case DF_Type::coord_path: return "coord_path";
		case DF_Type::coord_rect: return "coord_rect";
		case DF_Type::corpse_material_type: return "corpse_material_type";
		case DF_Type::craft_material_class: return "craft_material_class";
		case DF_Type::creation_zone_pwg_alteration_campst: return "creation_zone_pwg_alteration_campst";
		case DF_Type::creation_zone_pwg_alteration_location_deathst: return "creation_zone_pwg_alteration_location_deathst";
		case DF_Type::creation_zone_pwg_alteration_location_deathst__T_unk_1: return "creation_zone_pwg_alteration_location_deathst__T_unk_1";
		case DF_Type::creation_zone_pwg_alteration_location_deathst__T_unk_1__T_anon_1: return "creation_zone_pwg_alteration_location_deathst__T_unk_1__T_anon_1";
		case DF_Type::creation_zone_pwg_alteration_srb_ruinedst: return "creation_zone_pwg_alteration_srb_ruinedst";
		case DF_Type::creation_zone_pwg_alteration_srp_ruinedst: return "creation_zone_pwg_alteration_srp_ruinedst";
		case DF_Type::creation_zone_pwg_alteration_type: return "creation_zone_pwg_alteration_type";
		case DF_Type::creation_zone_pwg_alterationst: return "creation_zone_pwg_alterationst";
		case DF_Type::creature_graphics_appointment: return "creature_graphics_appointment";
		case DF_Type::creature_graphics_role: return "creature_graphics_role";
		case DF_Type::creature_handler: return "creature_handler";
		case DF_Type::creature_interaction: return "creature_interaction";
		case DF_Type::creature_interaction__T_flags: return "creature_interaction__T_flags";
		case DF_Type::creature_interaction_effect: return "creature_interaction_effect";
		case DF_Type::creature_interaction_effect__T_counter_trigger: return "creature_interaction_effect__T_counter_trigger";
		case DF_Type::creature_interaction_effect_add_simple_flagst: return "creature_interaction_effect_add_simple_flagst";
		case DF_Type::creature_interaction_effect_bleedingst: return "creature_interaction_effect_bleedingst";
		case DF_Type::creature_interaction_effect_blistersst: return "creature_interaction_effect_blistersst";
		case DF_Type::creature_interaction_effect_body_appearance_modifierst: return "creature_interaction_effect_body_appearance_modifierst";
		case DF_Type::creature_interaction_effect_body_mat_interactionst: return "creature_interaction_effect_body_mat_interactionst";
		case DF_Type::creature_interaction_effect_body_transformationst: return "creature_interaction_effect_body_transformationst";
		case DF_Type::creature_interaction_effect_bp_appearance_modifierst: return "creature_interaction_effect_bp_appearance_modifierst";
		case DF_Type::creature_interaction_effect_bruisingst: return "creature_interaction_effect_bruisingst";
		case DF_Type::creature_interaction_effect_can_do_interactionst: return "creature_interaction_effect_can_do_interactionst";
		case DF_Type::creature_interaction_effect_change_personalityst: return "creature_interaction_effect_change_personalityst";
		case DF_Type::creature_interaction_effect_close_open_woundsst: return "creature_interaction_effect_close_open_woundsst";
		case DF_Type::creature_interaction_effect_cough_bloodst: return "creature_interaction_effect_cough_bloodst";
		case DF_Type::creature_interaction_effect_cure_infectionsst: return "creature_interaction_effect_cure_infectionsst";
		case DF_Type::creature_interaction_effect_cure_infectionst: return "creature_interaction_effect_cure_infectionst";
		case DF_Type::creature_interaction_effect_display_namest: return "creature_interaction_effect_display_namest";
		case DF_Type::creature_interaction_effect_display_symbolst: return "creature_interaction_effect_display_symbolst";
		case DF_Type::creature_interaction_effect_dizzinessst: return "creature_interaction_effect_dizzinessst";
		case DF_Type::creature_interaction_effect_drowsinessst: return "creature_interaction_effect_drowsinessst";
		case DF_Type::creature_interaction_effect_erratic_behaviorst: return "creature_interaction_effect_erratic_behaviorst";
		case DF_Type::creature_interaction_effect_feel_emotionst: return "creature_interaction_effect_feel_emotionst";
		case DF_Type::creature_interaction_effect_feverst: return "creature_interaction_effect_feverst";
		case DF_Type::creature_interaction_effect_flags: return "creature_interaction_effect_flags";
		case DF_Type::creature_interaction_effect_flash_symbolst: return "creature_interaction_effect_flash_symbolst";
		case DF_Type::creature_interaction_effect_heal_nervesst: return "creature_interaction_effect_heal_nervesst";
		case DF_Type::creature_interaction_effect_heal_tissuesst: return "creature_interaction_effect_heal_tissuesst";
		case DF_Type::creature_interaction_effect_impair_functionst: return "creature_interaction_effect_impair_functionst";
		case DF_Type::creature_interaction_effect_material_force_adjustst: return "creature_interaction_effect_material_force_adjustst";
		case DF_Type::creature_interaction_effect_ment_att_changest: return "creature_interaction_effect_ment_att_changest";
		case DF_Type::creature_interaction_effect_nauseast: return "creature_interaction_effect_nauseast";
		case DF_Type::creature_interaction_effect_necrosisst: return "creature_interaction_effect_necrosisst";
		case DF_Type::creature_interaction_effect_numbnessst: return "creature_interaction_effect_numbnessst";
		case DF_Type::creature_interaction_effect_oozingst: return "creature_interaction_effect_oozingst";
		case DF_Type::creature_interaction_effect_painst: return "creature_interaction_effect_painst";
		case DF_Type::creature_interaction_effect_paralysisst: return "creature_interaction_effect_paralysisst";
		case DF_Type::creature_interaction_effect_phys_att_changest: return "creature_interaction_effect_phys_att_changest";
		case DF_Type::creature_interaction_effect_reduce_dizzinessst: return "creature_interaction_effect_reduce_dizzinessst";
		case DF_Type::creature_interaction_effect_reduce_feverst: return "creature_interaction_effect_reduce_feverst";
		case DF_Type::creature_interaction_effect_reduce_nauseast: return "creature_interaction_effect_reduce_nauseast";
		case DF_Type::creature_interaction_effect_reduce_painst: return "creature_interaction_effect_reduce_painst";
		case DF_Type::creature_interaction_effect_reduce_paralysisst: return "creature_interaction_effect_reduce_paralysisst";
		case DF_Type::creature_interaction_effect_reduce_swellingst: return "creature_interaction_effect_reduce_swellingst";
		case DF_Type::creature_interaction_effect_regrow_partsst: return "creature_interaction_effect_regrow_partsst";
		case DF_Type::creature_interaction_effect_remove_simple_flagst: return "creature_interaction_effect_remove_simple_flagst";
		case DF_Type::creature_interaction_effect_sense_creature_classst: return "creature_interaction_effect_sense_creature_classst";
		case DF_Type::creature_interaction_effect_skill_roll_adjustst: return "creature_interaction_effect_skill_roll_adjustst";
		case DF_Type::creature_interaction_effect_special_attack_interactionst: return "creature_interaction_effect_special_attack_interactionst";
		case DF_Type::creature_interaction_effect_speed_changest: return "creature_interaction_effect_speed_changest";
		case DF_Type::creature_interaction_effect_stop_bleedingst: return "creature_interaction_effect_stop_bleedingst";
		case DF_Type::creature_interaction_effect_swellingst: return "creature_interaction_effect_swellingst";
		case DF_Type::creature_interaction_effect_target: return "creature_interaction_effect_target";
		case DF_Type::creature_interaction_effect_target_mode: return "creature_interaction_effect_target_mode";
		case DF_Type::creature_interaction_effect_type: return "creature_interaction_effect_type";
		case DF_Type::creature_interaction_effect_unconsciousnessst: return "creature_interaction_effect_unconsciousnessst";
		case DF_Type::creature_interaction_effect_vomit_bloodst: return "creature_interaction_effect_vomit_bloodst";
		case DF_Type::creature_interaction_target_flags: return "creature_interaction_target_flags";
		case DF_Type::creature_raw: return "creature_raw";
		case DF_Type::creature_raw__T_graphics: return "creature_raw__T_graphics";
		case DF_Type::creature_raw__T_hive_product: return "creature_raw__T_hive_product";
		case DF_Type::creature_raw__T_profession_name: return "creature_raw__T_profession_name";
		case DF_Type::creature_raw_flags: return "creature_raw_flags";
		case DF_Type::creature_variation: return "creature_variation";
		case DF_Type::creature_variation_convert_tag: return "creature_variation_convert_tag";
		case DF_Type::crime: return "crime";
		case DF_Type::crime__T_counterintelligence: return "crime__T_counterintelligence";
		case DF_Type::crime__T_flags: return "crime__T_flags";
		case DF_Type::crime__T_mode: return "crime__T_mode";
		case DF_Type::crime__T_punishment: return "crime__T_punishment";
		case DF_Type::crime__T_reports: return "crime__T_reports";
		case DF_Type::crime_type: return "crime_type";
		case DF_Type::cultural_identity: return "cultural_identity";
		case DF_Type::cultural_identity__T_anon_1: return "cultural_identity__T_anon_1";
		case DF_Type::cultural_identity__T_anon_2: return "cultural_identity__T_anon_2";
		case DF_Type::cultural_identity__T_group_log: return "cultural_identity__T_group_log";
		case DF_Type::cultural_identity__T_group_log__T_join_type: return "cultural_identity__T_group_log__T_join_type";
		case DF_Type::cumulus_type: return "cumulus_type";
		case DF_Type::curse_attr_change: return "curse_attr_change";
		case DF_Type::d_init: return "d_init";
		case DF_Type::d_init__T_store_dist: return "d_init__T_store_dist";
		case DF_Type::d_init__T_wound_color: return "d_init__T_wound_color";
		case DF_Type::d_init_embark_confirm: return "d_init_embark_confirm";
		case DF_Type::d_init_flags1: return "d_init_flags1";
		case DF_Type::d_init_flags2: return "d_init_flags2";
		case DF_Type::d_init_flags3: return "d_init_flags3";
		case DF_Type::d_init_flags4: return "d_init_flags4";
		case DF_Type::d_init_idlers: return "d_init_idlers";
		case DF_Type::d_init_nickname: return "d_init_nickname";
		case DF_Type::d_init_tunnel: return "d_init_tunnel";
		case DF_Type::d_init_z_view: return "d_init_z_view";
		case DF_Type::dance_form: return "dance_form";
		case DF_Type::dance_form_sub1: return "dance_form_sub1";
		case DF_Type::dance_form_sub2: return "dance_form_sub2";
		case DF_Type::death_condition_type: return "death_condition_type";
		case DF_Type::death_type: return "death_type";
		case DF_Type::deep_vein_hollow: return "deep_vein_hollow";
		case DF_Type::descriptor_color: return "descriptor_color";
		case DF_Type::descriptor_pattern: return "descriptor_pattern";
		case DF_Type::descriptor_shape: return "descriptor_shape";
		case DF_Type::descriptor_shape__T_gems_use: return "descriptor_shape__T_gems_use";
		case DF_Type::dfhack_knowledge_scholar_flag: return "dfhack_knowledge_scholar_flag";
		case DF_Type::dfhack_material_category: return "dfhack_material_category";
		case DF_Type::dfhack_room_quality_level: return "dfhack_room_quality_level";
		case DF_Type::dipscript_info: return "dipscript_info";
		case DF_Type::dipscript_popup: return "dipscript_popup";
		case DF_Type::dipscript_popup__T_flags: return "dipscript_popup__T_flags";
		case DF_Type::divination_set: return "divination_set";
		case DF_Type::divination_set_roll: return "divination_set_roll";
		case DF_Type::door_flags: return "door_flags";
		case DF_Type::dye_info: return "dye_info";
		case DF_Type::effect_info: return "effect_info";
		case DF_Type::embark_feature: return "embark_feature";
		case DF_Type::embark_finder_option: return "embark_finder_option";
		case DF_Type::embark_item_choice: return "embark_item_choice";
		case DF_Type::embark_item_choice__T_list: return "embark_item_choice__T_list";
		case DF_Type::embark_location: return "embark_location";
		case DF_Type::embark_note: return "embark_note";
		case DF_Type::embark_profile: return "embark_profile";
		case DF_Type::emotion_type: return "emotion_type";
		case DF_Type::enabler: return "enabler";
		case DF_Type::enabler__T_async_frombox: return "enabler__T_async_frombox";
		case DF_Type::enabler__T_async_frombox__T_queue: return "enabler__T_async_frombox__T_queue";
		case DF_Type::enabler__T_async_frombox__T_queue___union0: return "enabler__T_async_frombox__T_queue___union0";
		case DF_Type::enabler__T_async_frombox__T_queue___union0___struct1: return "enabler__T_async_frombox__T_queue___union0___struct1";
		case DF_Type::enabler__T_async_frombox__T_queue__T_msg: return "enabler__T_async_frombox__T_queue__T_msg";
		case DF_Type::enabler__T_async_tobox: return "enabler__T_async_tobox";
		case DF_Type::enabler__T_async_tobox__T_queue: return "enabler__T_async_tobox__T_queue";
		case DF_Type::enabler__T_async_tobox__T_queue__T_cmd: return "enabler__T_async_tobox__T_queue__T_cmd";
		case DF_Type::enabler__T_async_zoom: return "enabler__T_async_zoom";
		case DF_Type::enabler__T_flag: return "enabler__T_flag";
		case DF_Type::enabler__T_gputicks: return "enabler__T_gputicks";
		case DF_Type::enabler__T_overridden_grid_sizes: return "enabler__T_overridden_grid_sizes";
		case DF_Type::enabler__T_simticks: return "enabler__T_simticks";
		case DF_Type::enabler__T_text_system: return "enabler__T_text_system";
		case DF_Type::enabler__T_text_system__T_file_info: return "enabler__T_text_system__T_file_info";
		case DF_Type::enabler__T_textures: return "enabler__T_textures";
		case DF_Type::engraving: return "engraving";
		case DF_Type::engraving_flags: return "engraving_flags";
		case DF_Type::entity_action_type: return "entity_action_type";
		case DF_Type::entity_activity_statistics: return "entity_activity_statistics";
		case DF_Type::entity_activity_statistics__T_food: return "entity_activity_statistics__T_food";
		case DF_Type::entity_activity_statistics__T_found_misc: return "entity_activity_statistics__T_found_misc";
		case DF_Type::entity_activity_statistics__T_wealth: return "entity_activity_statistics__T_wealth";
		case DF_Type::entity_animal_raw: return "entity_animal_raw";
		case DF_Type::entity_animal_raw__T_flags: return "entity_animal_raw__T_flags";
		case DF_Type::entity_buy_prices: return "entity_buy_prices";
		case DF_Type::entity_buy_requests: return "entity_buy_requests";
		case DF_Type::entity_claim_mask: return "entity_claim_mask";
		case DF_Type::entity_claim_mask__T_map: return "entity_claim_mask__T_map";
		case DF_Type::entity_entity_link: return "entity_entity_link";
		case DF_Type::entity_entity_link_type: return "entity_entity_link_type";
		case DF_Type::entity_event: return "entity_event";
		case DF_Type::entity_event__T_data: return "entity_event__T_data";
		case DF_Type::entity_event__T_data__T_abandon: return "entity_event__T_data__T_abandon";
		case DF_Type::entity_event__T_data__T_abduction: return "entity_event__T_data__T_abduction";
		case DF_Type::entity_event__T_data__T_accept_peace_offer: return "entity_event__T_data__T_accept_peace_offer";
		case DF_Type::entity_event__T_data__T_accept_tribute_demand: return "entity_event__T_data__T_accept_tribute_demand";
		case DF_Type::entity_event__T_data__T_accept_tribute_offer: return "entity_event__T_data__T_accept_tribute_offer";
		case DF_Type::entity_event__T_data__T_artifact_destroyed: return "entity_event__T_data__T_artifact_destroyed";
		case DF_Type::entity_event__T_data__T_artifact_in_feature_layer: return "entity_event__T_data__T_artifact_in_feature_layer";
		case DF_Type::entity_event__T_data__T_artifact_in_inventory: return "entity_event__T_data__T_artifact_in_inventory";
		case DF_Type::entity_event__T_data__T_artifact_in_site: return "entity_event__T_data__T_artifact_in_site";
		case DF_Type::entity_event__T_data__T_artifact_in_subregion: return "entity_event__T_data__T_artifact_in_subregion";
		case DF_Type::entity_event__T_data__T_artifact_not_in_feature_layer: return "entity_event__T_data__T_artifact_not_in_feature_layer";
		case DF_Type::entity_event__T_data__T_artifact_not_in_inventory: return "entity_event__T_data__T_artifact_not_in_inventory";
		case DF_Type::entity_event__T_data__T_artifact_not_in_site: return "entity_event__T_data__T_artifact_not_in_site";
		case DF_Type::entity_event__T_data__T_artifact_not_in_subregion: return "entity_event__T_data__T_artifact_not_in_subregion";
		case DF_Type::entity_event__T_data__T_beast: return "entity_event__T_data__T_beast";
		case DF_Type::entity_event__T_data__T_cease_tribute_offer: return "entity_event__T_data__T_cease_tribute_offer";
		case DF_Type::entity_event__T_data__T_claim: return "entity_event__T_data__T_claim";
		case DF_Type::entity_event__T_data__T_flee: return "entity_event__T_data__T_flee";
		case DF_Type::entity_event__T_data__T_founded: return "entity_event__T_data__T_founded";
		case DF_Type::entity_event__T_data__T_founding: return "entity_event__T_data__T_founding";
		case DF_Type::entity_event__T_data__T_group: return "entity_event__T_data__T_group";
		case DF_Type::entity_event__T_data__T_harass: return "entity_event__T_data__T_harass";
		case DF_Type::entity_event__T_data__T_incident: return "entity_event__T_data__T_incident";
		case DF_Type::entity_event__T_data__T_insurrection: return "entity_event__T_data__T_insurrection";
		case DF_Type::entity_event__T_data__T_insurrection_end: return "entity_event__T_data__T_insurrection_end";
		case DF_Type::entity_event__T_data__T_insurrection_end__T_result: return "entity_event__T_data__T_insurrection_end__T_result";
		case DF_Type::entity_event__T_data__T_invasion: return "entity_event__T_data__T_invasion";
		case DF_Type::entity_event__T_data__T_leave: return "entity_event__T_data__T_leave";
		case DF_Type::entity_event__T_data__T_occupation: return "entity_event__T_data__T_occupation";
		case DF_Type::entity_event__T_data__T_reclaimed: return "entity_event__T_data__T_reclaimed";
		case DF_Type::entity_event__T_data__T_reclaiming: return "entity_event__T_data__T_reclaiming";
		case DF_Type::entity_event__T_data__T_refuse_peace_offer: return "entity_event__T_data__T_refuse_peace_offer";
		case DF_Type::entity_event__T_data__T_refuse_tribute_demand: return "entity_event__T_data__T_refuse_tribute_demand";
		case DF_Type::entity_event__T_data__T_refuse_tribute_offer: return "entity_event__T_data__T_refuse_tribute_offer";
		case DF_Type::entity_event__T_data__T_succession: return "entity_event__T_data__T_succession";
		case DF_Type::entity_event_type: return "entity_event_type";
		case DF_Type::entity_material_category: return "entity_material_category";
		case DF_Type::entity_name_type: return "entity_name_type";
		case DF_Type::entity_occasion: return "entity_occasion";
		case DF_Type::entity_occasion_info: return "entity_occasion_info";
		case DF_Type::entity_occasion_schedule: return "entity_occasion_schedule";
		case DF_Type::entity_occasion_schedule_feature: return "entity_occasion_schedule_feature";
		case DF_Type::entity_population: return "entity_population";
		case DF_Type::entity_population_unk4: return "entity_population_unk4";
		case DF_Type::entity_population_unk4__T_anon_1: return "entity_population_unk4__T_anon_1";
		case DF_Type::entity_population_unk4__T_anon_2: return "entity_population_unk4__T_anon_2";
		case DF_Type::entity_population_unk4__T_anon_3: return "entity_population_unk4__T_anon_3";
		case DF_Type::entity_position: return "entity_position";
		case DF_Type::entity_position_assignment: return "entity_position_assignment";
		case DF_Type::entity_position_flags: return "entity_position_flags";
		case DF_Type::entity_position_raw: return "entity_position_raw";
		case DF_Type::entity_position_raw_flags: return "entity_position_raw_flags";
		case DF_Type::entity_position_responsibility: return "entity_position_responsibility";
		case DF_Type::entity_raw: return "entity_raw";
		case DF_Type::entity_raw__T_equipment: return "entity_raw__T_equipment";
		case DF_Type::entity_raw__T_jobs: return "entity_raw__T_jobs";
		case DF_Type::entity_raw__T_land_holder_trigger: return "entity_raw__T_land_holder_trigger";
		case DF_Type::entity_raw__T_progress_trigger: return "entity_raw__T_progress_trigger";
		case DF_Type::entity_raw__T_scholar: return "entity_raw__T_scholar";
		case DF_Type::entity_raw__T_symbols: return "entity_raw__T_symbols";
		case DF_Type::entity_raw__T_tissue_styles: return "entity_raw__T_tissue_styles";
		case DF_Type::entity_raw__T_workshops: return "entity_raw__T_workshops";
		case DF_Type::entity_raw_flags: return "entity_raw_flags";
		case DF_Type::entity_recipe: return "entity_recipe";
		case DF_Type::entity_sell_category: return "entity_sell_category";
		case DF_Type::entity_sell_prices: return "entity_sell_prices";
		case DF_Type::entity_sell_requests: return "entity_sell_requests";
		case DF_Type::entity_site_link: return "entity_site_link";
		case DF_Type::entity_site_link__T_unk_7: return "entity_site_link__T_unk_7";
		case DF_Type::entity_site_link_flags: return "entity_site_link_flags";
		case DF_Type::entity_site_link_status_flags: return "entity_site_link_status_flags";
		case DF_Type::entity_site_link_type: return "entity_site_link_type";
		case DF_Type::entity_tissue_style: return "entity_tissue_style";
		case DF_Type::entity_uniform: return "entity_uniform";
		case DF_Type::entity_uniform_item: return "entity_uniform_item";
		case DF_Type::entity_unk_v47_1: return "entity_unk_v47_1";
		case DF_Type::environment_type: return "environment_type";
		case DF_Type::era_type: return "era_type";
		case DF_Type::ethic_response: return "ethic_response";
		case DF_Type::ethic_type: return "ethic_type";
		case DF_Type::export_map_type: return "export_map_type";
		case DF_Type::feature: return "feature";
		case DF_Type::feature_alteration: return "feature_alteration";
		case DF_Type::feature_alteration_new_lava_fill_zst: return "feature_alteration_new_lava_fill_zst";
		case DF_Type::feature_alteration_new_pop_maxst: return "feature_alteration_new_pop_maxst";
		case DF_Type::feature_alteration_type: return "feature_alteration_type";
		case DF_Type::feature_cavest: return "feature_cavest";
		case DF_Type::feature_deep_special_tubest: return "feature_deep_special_tubest";
		case DF_Type::feature_deep_surface_portalst: return "feature_deep_surface_portalst";
		case DF_Type::feature_init: return "feature_init";
		case DF_Type::feature_init_cavest: return "feature_init_cavest";
		case DF_Type::feature_init_deep_special_tubest: return "feature_init_deep_special_tubest";
		case DF_Type::feature_init_deep_surface_portalst: return "feature_init_deep_surface_portalst";
		case DF_Type::feature_init_flags: return "feature_init_flags";
		case DF_Type::feature_init_magma_core_from_layerst: return "feature_init_magma_core_from_layerst";
		case DF_Type::feature_init_magma_poolst: return "feature_init_magma_poolst";
		case DF_Type::feature_init_outdoor_riverst: return "feature_init_outdoor_riverst";
		case DF_Type::feature_init_pitst: return "feature_init_pitst";
		case DF_Type::feature_init_subterranean_from_layerst: return "feature_init_subterranean_from_layerst";
		case DF_Type::feature_init_underworld_from_layerst: return "feature_init_underworld_from_layerst";
		case DF_Type::feature_init_volcanost: return "feature_init_volcanost";
		case DF_Type::feature_magma_core_from_layerst: return "feature_magma_core_from_layerst";
		case DF_Type::feature_magma_poolst: return "feature_magma_poolst";
		case DF_Type::feature_outdoor_riverst: return "feature_outdoor_riverst";
		case DF_Type::feature_pitst: return "feature_pitst";
		case DF_Type::feature_subterranean_from_layerst: return "feature_subterranean_from_layerst";
		case DF_Type::feature_type: return "feature_type";
		case DF_Type::feature_underworld_from_layerst: return "feature_underworld_from_layerst";
		case DF_Type::feature_volcanost: return "feature_volcanost";
		case DF_Type::file_compressorst: return "file_compressorst";
		case DF_Type::fire: return "fire";
		case DF_Type::flow_guide: return "flow_guide";
		case DF_Type::flow_guide_item_cloudst: return "flow_guide_item_cloudst";
		case DF_Type::flow_guide_trailing_flowst: return "flow_guide_trailing_flowst";
		case DF_Type::flow_guide_type: return "flow_guide_type";
		case DF_Type::flow_info: return "flow_info";
		case DF_Type::flow_reuse_pool: return "flow_reuse_pool";
		case DF_Type::flow_reuse_pool__T_flags: return "flow_reuse_pool__T_flags";
		case DF_Type::flow_type: return "flow_type";
		case DF_Type::fog_type: return "fog_type";
		case DF_Type::fortress_type: return "fortress_type";
		case DF_Type::front_type: return "front_type";
		case DF_Type::furnace_type: return "furnace_type";
		case DF_Type::furniture_type: return "furniture_type";
		case DF_Type::gait_info: return "gait_info";
		case DF_Type::gait_info__T_flags: return "gait_info__T_flags";
		case DF_Type::gait_type: return "gait_type";
		case DF_Type::game_mode: return "game_mode";
		case DF_Type::game_type: return "game_type";
		case DF_Type::gate_flags: return "gate_flags";
		case DF_Type::general_ref: return "general_ref";
		case DF_Type::general_ref_abstract_buildingst: return "general_ref_abstract_buildingst";
		case DF_Type::general_ref_activity_eventst: return "general_ref_activity_eventst";
		case DF_Type::general_ref_artifact: return "general_ref_artifact";
		case DF_Type::general_ref_building: return "general_ref_building";
		case DF_Type::general_ref_building_cagedst: return "general_ref_building_cagedst";
		case DF_Type::general_ref_building_chainst: return "general_ref_building_chainst";
		case DF_Type::general_ref_building_civzone_assignedst: return "general_ref_building_civzone_assignedst";
		case DF_Type::general_ref_building_destinationst: return "general_ref_building_destinationst";
		case DF_Type::general_ref_building_display_furniturest: return "general_ref_building_display_furniturest";
		case DF_Type::general_ref_building_holderst: return "general_ref_building_holderst";
		case DF_Type::general_ref_building_nest_boxst: return "general_ref_building_nest_boxst";
		case DF_Type::general_ref_building_triggerst: return "general_ref_building_triggerst";
		case DF_Type::general_ref_building_triggertargetst: return "general_ref_building_triggertargetst";
		case DF_Type::general_ref_building_use_target_1st: return "general_ref_building_use_target_1st";
		case DF_Type::general_ref_building_use_target_2st: return "general_ref_building_use_target_2st";
		case DF_Type::general_ref_building_well_tag: return "general_ref_building_well_tag";
		case DF_Type::general_ref_coinbatch: return "general_ref_coinbatch";
		case DF_Type::general_ref_contained_in_itemst: return "general_ref_contained_in_itemst";
		case DF_Type::general_ref_contains_itemst: return "general_ref_contains_itemst";
		case DF_Type::general_ref_contains_unitst: return "general_ref_contains_unitst";
		case DF_Type::general_ref_creaturest: return "general_ref_creaturest";
		case DF_Type::general_ref_creaturest__T_flags: return "general_ref_creaturest__T_flags";
		case DF_Type::general_ref_dance_formst: return "general_ref_dance_formst";
		case DF_Type::general_ref_entity: return "general_ref_entity";
		case DF_Type::general_ref_entity_art_image: return "general_ref_entity_art_image";
		case DF_Type::general_ref_entity_itemownerst: return "general_ref_entity_itemownerst";
		case DF_Type::general_ref_entity_offeredst: return "general_ref_entity_offeredst";
		case DF_Type::general_ref_entity_popst: return "general_ref_entity_popst";
		case DF_Type::general_ref_entity_popst__T_flags: return "general_ref_entity_popst__T_flags";
		case DF_Type::general_ref_entity_stolenst: return "general_ref_entity_stolenst";
		case DF_Type::general_ref_feature_layerst: return "general_ref_feature_layerst";
		case DF_Type::general_ref_historical_eventst: return "general_ref_historical_eventst";
		case DF_Type::general_ref_historical_figurest: return "general_ref_historical_figurest";
		case DF_Type::general_ref_interactionst: return "general_ref_interactionst";
		case DF_Type::general_ref_is_artifactst: return "general_ref_is_artifactst";
		case DF_Type::general_ref_is_nemesisst: return "general_ref_is_nemesisst";
		case DF_Type::general_ref_item: return "general_ref_item";
		case DF_Type::general_ref_item_type: return "general_ref_item_type";
		case DF_Type::general_ref_knowledge_scholar_flagst: return "general_ref_knowledge_scholar_flagst";
		case DF_Type::general_ref_languagest: return "general_ref_languagest";
		case DF_Type::general_ref_locationst: return "general_ref_locationst";
		case DF_Type::general_ref_mapsquare: return "general_ref_mapsquare";
		case DF_Type::general_ref_musical_formst: return "general_ref_musical_formst";
		case DF_Type::general_ref_nemesis: return "general_ref_nemesis";
		case DF_Type::general_ref_poetic_formst: return "general_ref_poetic_formst";
		case DF_Type::general_ref_projectile: return "general_ref_projectile";
		case DF_Type::general_ref_sitest: return "general_ref_sitest";
		case DF_Type::general_ref_spherest: return "general_ref_spherest";
		case DF_Type::general_ref_subregionst: return "general_ref_subregionst";
		case DF_Type::general_ref_type: return "general_ref_type";
		case DF_Type::general_ref_unit: return "general_ref_unit";
		case DF_Type::general_ref_unit_beateest: return "general_ref_unit_beateest";
		case DF_Type::general_ref_unit_cageest: return "general_ref_unit_cageest";
		case DF_Type::general_ref_unit_climberst: return "general_ref_unit_climberst";
		case DF_Type::general_ref_unit_foodreceiverst: return "general_ref_unit_foodreceiverst";
		case DF_Type::general_ref_unit_geldeest: return "general_ref_unit_geldeest";
		case DF_Type::general_ref_unit_holderst: return "general_ref_unit_holderst";
		case DF_Type::general_ref_unit_infantst: return "general_ref_unit_infantst";
		case DF_Type::general_ref_unit_interrogateest: return "general_ref_unit_interrogateest";
		case DF_Type::general_ref_unit_itemownerst: return "general_ref_unit_itemownerst";
		case DF_Type::general_ref_unit_itemownerst__T_flags: return "general_ref_unit_itemownerst__T_flags";
		case DF_Type::general_ref_unit_kidnapeest: return "general_ref_unit_kidnapeest";
		case DF_Type::general_ref_unit_milkeest: return "general_ref_unit_milkeest";
		case DF_Type::general_ref_unit_patientst: return "general_ref_unit_patientst";
		case DF_Type::general_ref_unit_reporteest: return "general_ref_unit_reporteest";
		case DF_Type::general_ref_unit_riderst: return "general_ref_unit_riderst";
		case DF_Type::general_ref_unit_sheareest: return "general_ref_unit_sheareest";
		case DF_Type::general_ref_unit_slaughtereest: return "general_ref_unit_slaughtereest";
		case DF_Type::general_ref_unit_suckeest: return "general_ref_unit_suckeest";
		case DF_Type::general_ref_unit_tradebringerst: return "general_ref_unit_tradebringerst";
		case DF_Type::general_ref_unit_traineest: return "general_ref_unit_traineest";
		case DF_Type::general_ref_unit_workerst: return "general_ref_unit_workerst";
		case DF_Type::general_ref_value_levelst: return "general_ref_value_levelst";
		case DF_Type::general_ref_written_contentst: return "general_ref_written_contentst";
		case DF_Type::geo_layer_type: return "geo_layer_type";
		case DF_Type::ghost_goal: return "ghost_goal";
		case DF_Type::ghost_type: return "ghost_type";
		case DF_Type::gloves_flags: return "gloves_flags";
		case DF_Type::glowing_barrier: return "glowing_barrier";
		case DF_Type::goal_type: return "goal_type";
		case DF_Type::graphic: return "graphic";
		case DF_Type::guild_id: return "guild_id";
		case DF_Type::hauler_type: return "hauler_type";
		case DF_Type::hauling_route: return "hauling_route";
		case DF_Type::hauling_stop: return "hauling_stop";
		case DF_Type::health_view_bits1: return "health_view_bits1";
		case DF_Type::health_view_bits2: return "health_view_bits2";
		case DF_Type::health_view_bits3: return "health_view_bits3";
		case DF_Type::helm_flags: return "helm_flags";
		case DF_Type::hillock_house_type: return "hillock_house_type";
		case DF_Type::histfig_body_state: return "histfig_body_state";
		case DF_Type::histfig_entity_link: return "histfig_entity_link";
		case DF_Type::histfig_entity_link_criminalst: return "histfig_entity_link_criminalst";
		case DF_Type::histfig_entity_link_enemyst: return "histfig_entity_link_enemyst";
		case DF_Type::histfig_entity_link_former_memberst: return "histfig_entity_link_former_memberst";
		case DF_Type::histfig_entity_link_former_mercenaryst: return "histfig_entity_link_former_mercenaryst";
		case DF_Type::histfig_entity_link_former_occupationst: return "histfig_entity_link_former_occupationst";
		case DF_Type::histfig_entity_link_former_positionst: return "histfig_entity_link_former_positionst";
		case DF_Type::histfig_entity_link_former_prisonerst: return "histfig_entity_link_former_prisonerst";
		case DF_Type::histfig_entity_link_former_slavest: return "histfig_entity_link_former_slavest";
		case DF_Type::histfig_entity_link_former_squadst: return "histfig_entity_link_former_squadst";
		case DF_Type::histfig_entity_link_memberst: return "histfig_entity_link_memberst";
		case DF_Type::histfig_entity_link_mercenaryst: return "histfig_entity_link_mercenaryst";
		case DF_Type::histfig_entity_link_occupationst: return "histfig_entity_link_occupationst";
		case DF_Type::histfig_entity_link_position_claimst: return "histfig_entity_link_position_claimst";
		case DF_Type::histfig_entity_link_positionst: return "histfig_entity_link_positionst";
		case DF_Type::histfig_entity_link_prisonerst: return "histfig_entity_link_prisonerst";
		case DF_Type::histfig_entity_link_slavest: return "histfig_entity_link_slavest";
		case DF_Type::histfig_entity_link_squadst: return "histfig_entity_link_squadst";
		case DF_Type::histfig_entity_link_type: return "histfig_entity_link_type";
		case DF_Type::histfig_flags: return "histfig_flags";
		case DF_Type::histfig_hf_link: return "histfig_hf_link";
		case DF_Type::histfig_hf_link_apprenticest: return "histfig_hf_link_apprenticest";
		case DF_Type::histfig_hf_link_childst: return "histfig_hf_link_childst";
		case DF_Type::histfig_hf_link_companionst: return "histfig_hf_link_companionst";
		case DF_Type::histfig_hf_link_deceased_spousest: return "histfig_hf_link_deceased_spousest";
		case DF_Type::histfig_hf_link_deityst: return "histfig_hf_link_deityst";
		case DF_Type::histfig_hf_link_fatherst: return "histfig_hf_link_fatherst";
		case DF_Type::histfig_hf_link_former_apprenticest: return "histfig_hf_link_former_apprenticest";
		case DF_Type::histfig_hf_link_former_masterst: return "histfig_hf_link_former_masterst";
		case DF_Type::histfig_hf_link_former_spousest: return "histfig_hf_link_former_spousest";
		case DF_Type::histfig_hf_link_imprisonerst: return "histfig_hf_link_imprisonerst";
		case DF_Type::histfig_hf_link_loverst: return "histfig_hf_link_loverst";
		case DF_Type::histfig_hf_link_masterst: return "histfig_hf_link_masterst";
		case DF_Type::histfig_hf_link_motherst: return "histfig_hf_link_motherst";
		case DF_Type::histfig_hf_link_pet_ownerst: return "histfig_hf_link_pet_ownerst";
		case DF_Type::histfig_hf_link_prisonerst: return "histfig_hf_link_prisonerst";
		case DF_Type::histfig_hf_link_spousest: return "histfig_hf_link_spousest";
		case DF_Type::histfig_hf_link_type: return "histfig_hf_link_type";
		case DF_Type::histfig_relationship_type: return "histfig_relationship_type";
		case DF_Type::histfig_site_link: return "histfig_site_link";
		case DF_Type::histfig_site_link_hangoutst: return "histfig_site_link_hangoutst";
		case DF_Type::histfig_site_link_home_site_abstract_buildingst: return "histfig_site_link_home_site_abstract_buildingst";
		case DF_Type::histfig_site_link_home_site_realization_buildingst: return "histfig_site_link_home_site_realization_buildingst";
		case DF_Type::histfig_site_link_home_site_realization_sulst: return "histfig_site_link_home_site_realization_sulst";
		case DF_Type::histfig_site_link_home_site_saved_civzonest: return "histfig_site_link_home_site_saved_civzonest";
		case DF_Type::histfig_site_link_lairst: return "histfig_site_link_lairst";
		case DF_Type::histfig_site_link_occupationst: return "histfig_site_link_occupationst";
		case DF_Type::histfig_site_link_prison_abstract_buildingst: return "histfig_site_link_prison_abstract_buildingst";
		case DF_Type::histfig_site_link_prison_site_building_profilest: return "histfig_site_link_prison_site_building_profilest";
		case DF_Type::histfig_site_link_seat_of_powerst: return "histfig_site_link_seat_of_powerst";
		case DF_Type::histfig_site_link_type: return "histfig_site_link_type";
		case DF_Type::historical_entity: return "historical_entity";
		case DF_Type::historical_entity__T_claims: return "historical_entity__T_claims";
		case DF_Type::historical_entity__T_derived_resources: return "historical_entity__T_derived_resources";
		case DF_Type::historical_entity__T_flags: return "historical_entity__T_flags";
		case DF_Type::historical_entity__T_guild_professions: return "historical_entity__T_guild_professions";
		case DF_Type::historical_entity__T_positions: return "historical_entity__T_positions";
		case DF_Type::historical_entity__T_relations: return "historical_entity__T_relations";
		case DF_Type::historical_entity__T_relations__T_constructions: return "historical_entity__T_relations__T_constructions";
		case DF_Type::historical_entity__T_relations__T_diplomacy: return "historical_entity__T_relations__T_diplomacy";
		case DF_Type::historical_entity__T_resources: return "historical_entity__T_resources";
		case DF_Type::historical_entity__T_resources__T_animals: return "historical_entity__T_resources__T_animals";
		case DF_Type::historical_entity__T_resources__T_metal: return "historical_entity__T_resources__T_metal";
		case DF_Type::historical_entity__T_resources__T_misc_mat: return "historical_entity__T_resources__T_misc_mat";
		case DF_Type::historical_entity__T_resources__T_organic: return "historical_entity__T_resources__T_organic";
		case DF_Type::historical_entity__T_resources__T_refuse: return "historical_entity__T_resources__T_refuse";
		case DF_Type::historical_entity__T_resources__T_unk13: return "historical_entity__T_resources__T_unk13";
		case DF_Type::historical_entity__T_resources__T_wood_products: return "historical_entity__T_resources__T_wood_products";
		case DF_Type::historical_entity__T_tissue_styles: return "historical_entity__T_tissue_styles";
		case DF_Type::historical_entity__T_training_knowledge: return "historical_entity__T_training_knowledge";
		case DF_Type::historical_entity__T_unk_v47_1: return "historical_entity__T_unk_v47_1";
		case DF_Type::historical_entity__T_unknown1d: return "historical_entity__T_unknown1d";
		case DF_Type::historical_entity__T_unknown1e: return "historical_entity__T_unknown1e";
		case DF_Type::historical_entity__T_unknown2: return "historical_entity__T_unknown2";
		case DF_Type::historical_entity_type: return "historical_entity_type";
		case DF_Type::historical_figure: return "historical_figure";
		case DF_Type::historical_figure__T_unk_fc: return "historical_figure__T_unk_fc";
		case DF_Type::historical_figure__T_vague_relationships: return "historical_figure__T_vague_relationships";
		case DF_Type::historical_figure_info: return "historical_figure_info";
		case DF_Type::historical_figure_info__T_books: return "historical_figure_info__T_books";
		case DF_Type::historical_figure_info__T_books__T_flags: return "historical_figure_info__T_books__T_flags";
		case DF_Type::historical_figure_info__T_curse: return "historical_figure_info__T_curse";
		case DF_Type::historical_figure_info__T_curse__T_anon_1: return "historical_figure_info__T_curse__T_anon_1";
		case DF_Type::historical_figure_info__T_curse__T_experiments: return "historical_figure_info__T_curse__T_experiments";
		case DF_Type::historical_figure_info__T_known_info: return "historical_figure_info__T_known_info";
		case DF_Type::historical_figure_info__T_known_info__T_anon_1: return "historical_figure_info__T_known_info__T_anon_1";
		case DF_Type::historical_figure_info__T_known_info__T_anon_6: return "historical_figure_info__T_known_info__T_anon_6";
		case DF_Type::historical_figure_info__T_known_info__T_knowledge: return "historical_figure_info__T_known_info__T_knowledge";
		case DF_Type::historical_figure_info__T_known_info__T_knowledge__T_knowledge_goal: return "historical_figure_info__T_known_info__T_knowledge__T_knowledge_goal";
		case DF_Type::historical_figure_info__T_known_info__T_unk_a8: return "historical_figure_info__T_known_info__T_unk_a8";
		case DF_Type::historical_figure_info__T_masterpieces: return "historical_figure_info__T_masterpieces";
		case DF_Type::historical_figure_info__T_personality: return "historical_figure_info__T_personality";
		case DF_Type::historical_figure_info__T_relationships: return "historical_figure_info__T_relationships";
		case DF_Type::historical_figure_info__T_relationships__T_anon_1: return "historical_figure_info__T_relationships__T_anon_1";
		case DF_Type::historical_figure_info__T_relationships__T_artifact_claims: return "historical_figure_info__T_relationships__T_artifact_claims";
		case DF_Type::historical_figure_info__T_relationships__T_hf_historical: return "historical_figure_info__T_relationships__T_hf_historical";
		case DF_Type::historical_figure_info__T_relationships__T_hf_visual: return "historical_figure_info__T_relationships__T_hf_visual";
		case DF_Type::historical_figure_info__T_relationships__T_intrigues: return "historical_figure_info__T_relationships__T_intrigues";
		case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_intrigue: return "historical_figure_info__T_relationships__T_intrigues__T_intrigue";
		case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots: return "historical_figure_info__T_relationships__T_intrigues__T_plots";
		case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data: return "historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data";
		case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data__T_Infiltrate_Society: return "historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data__T_Infiltrate_Society";
		case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data__T_Sabotage_Actor: return "historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data__T_Sabotage_Actor";
		case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_type: return "historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_type";
		case DF_Type::historical_figure_info__T_reputation: return "historical_figure_info__T_reputation";
		case DF_Type::historical_figure_info__T_reputation__T_anon_1: return "historical_figure_info__T_reputation__T_anon_1";
		case DF_Type::historical_figure_info__T_reputation__T_unk_2c: return "historical_figure_info__T_reputation__T_unk_2c";
		case DF_Type::historical_figure_info__T_reputation__T_unk_2c__T_anon_12: return "historical_figure_info__T_reputation__T_unk_2c__T_anon_12";
		case DF_Type::historical_figure_info__T_reputation__T_wanted: return "historical_figure_info__T_reputation__T_wanted";
		case DF_Type::historical_figure_info__T_reputation__T_wanted__T_unk: return "historical_figure_info__T_reputation__T_wanted__T_unk";
		case DF_Type::historical_figure_info__T_skills: return "historical_figure_info__T_skills";
		case DF_Type::historical_figure_info__T_skills__T_employment_held: return "historical_figure_info__T_skills__T_employment_held";
		case DF_Type::historical_figure_info__T_skills__T_employment_held__T_employment: return "historical_figure_info__T_skills__T_employment_held__T_employment";
		case DF_Type::historical_figure_info__T_whereabouts: return "historical_figure_info__T_whereabouts";
		case DF_Type::historical_figure_info__T_wounds: return "historical_figure_info__T_wounds";
		case DF_Type::historical_kills: return "historical_kills";
		case DF_Type::historical_kills__T_killed_undead: return "historical_kills__T_killed_undead";
		case DF_Type::history_era: return "history_era";
		case DF_Type::history_era__T_details: return "history_era__T_details";
		case DF_Type::history_era__T_title: return "history_era__T_title";
		case DF_Type::history_event: return "history_event";
		case DF_Type::history_event_add_entity_site_profile_flagst: return "history_event_add_entity_site_profile_flagst";
		case DF_Type::history_event_add_hf_entity_honorst: return "history_event_add_hf_entity_honorst";
		case DF_Type::history_event_add_hf_entity_linkst: return "history_event_add_hf_entity_linkst";
		case DF_Type::history_event_add_hf_hf_linkst: return "history_event_add_hf_hf_linkst";
		case DF_Type::history_event_add_hf_site_linkst: return "history_event_add_hf_site_linkst";
		case DF_Type::history_event_agreement_concludedst: return "history_event_agreement_concludedst";
		case DF_Type::history_event_agreement_formedst: return "history_event_agreement_formedst";
		case DF_Type::history_event_agreements_voidedst: return "history_event_agreements_voidedst";
		case DF_Type::history_event_artifact_claim_formedst: return "history_event_artifact_claim_formedst";
		case DF_Type::history_event_artifact_copiedst: return "history_event_artifact_copiedst";
		case DF_Type::history_event_artifact_copiedst__T_flags2: return "history_event_artifact_copiedst__T_flags2";
		case DF_Type::history_event_artifact_createdst: return "history_event_artifact_createdst";
		case DF_Type::history_event_artifact_createdst__T_flags2: return "history_event_artifact_createdst__T_flags2";
		case DF_Type::history_event_artifact_destroyedst: return "history_event_artifact_destroyedst";
		case DF_Type::history_event_artifact_droppedst: return "history_event_artifact_droppedst";
		case DF_Type::history_event_artifact_foundst: return "history_event_artifact_foundst";
		case DF_Type::history_event_artifact_givenst: return "history_event_artifact_givenst";
		case DF_Type::history_event_artifact_hiddenst: return "history_event_artifact_hiddenst";
		case DF_Type::history_event_artifact_lostst: return "history_event_artifact_lostst";
		case DF_Type::history_event_artifact_possessedst: return "history_event_artifact_possessedst";
		case DF_Type::history_event_artifact_recoveredst: return "history_event_artifact_recoveredst";
		case DF_Type::history_event_artifact_storedst: return "history_event_artifact_storedst";
		case DF_Type::history_event_artifact_transformedst: return "history_event_artifact_transformedst";
		case DF_Type::history_event_assume_identityst: return "history_event_assume_identityst";
		case DF_Type::history_event_body_abusedst: return "history_event_body_abusedst";
		case DF_Type::history_event_body_abusedst__T_abuse_data: return "history_event_body_abusedst__T_abuse_data";
		case DF_Type::history_event_body_abusedst__T_abuse_data__T_Animated: return "history_event_body_abusedst__T_abuse_data__T_Animated";
		case DF_Type::history_event_body_abusedst__T_abuse_data__T_Flayed: return "history_event_body_abusedst__T_abuse_data__T_Flayed";
		case DF_Type::history_event_body_abusedst__T_abuse_data__T_Hung: return "history_event_body_abusedst__T_abuse_data__T_Hung";
		case DF_Type::history_event_body_abusedst__T_abuse_data__T_Impaled: return "history_event_body_abusedst__T_abuse_data__T_Impaled";
		case DF_Type::history_event_body_abusedst__T_abuse_data__T_Piled: return "history_event_body_abusedst__T_abuse_data__T_Piled";
		case DF_Type::history_event_body_abusedst__T_abuse_data__T_Piled__T_pile_type: return "history_event_body_abusedst__T_abuse_data__T_Piled__T_pile_type";
		case DF_Type::history_event_body_abusedst__T_abuse_type: return "history_event_body_abusedst__T_abuse_type";
		case DF_Type::history_event_building_profile_acquiredst: return "history_event_building_profile_acquiredst";
		case DF_Type::history_event_ceremonyst: return "history_event_ceremonyst";
		case DF_Type::history_event_change_creature_typest: return "history_event_change_creature_typest";
		case DF_Type::history_event_change_hf_body_statest: return "history_event_change_hf_body_statest";
		case DF_Type::history_event_change_hf_jobst: return "history_event_change_hf_jobst";
		case DF_Type::history_event_change_hf_moodst: return "history_event_change_hf_moodst";
		case DF_Type::history_event_change_hf_statest: return "history_event_change_hf_statest";
		case DF_Type::history_event_change_hf_statest__T_state: return "history_event_change_hf_statest__T_state";
		case DF_Type::history_event_circumstance_info: return "history_event_circumstance_info";
		case DF_Type::history_event_circumstance_info__T_data: return "history_event_circumstance_info__T_data";
		case DF_Type::history_event_collection: return "history_event_collection";
		case DF_Type::history_event_collection_abductionst: return "history_event_collection_abductionst";
		case DF_Type::history_event_collection_battlest: return "history_event_collection_battlest";
		case DF_Type::history_event_collection_beast_attackst: return "history_event_collection_beast_attackst";
		case DF_Type::history_event_collection_ceremonyst: return "history_event_collection_ceremonyst";
		case DF_Type::history_event_collection_competitionst: return "history_event_collection_competitionst";
		case DF_Type::history_event_collection_duelst: return "history_event_collection_duelst";
		case DF_Type::history_event_collection_entity_overthrownst: return "history_event_collection_entity_overthrownst";
		case DF_Type::history_event_collection_insurrectionst: return "history_event_collection_insurrectionst";
		case DF_Type::history_event_collection_journeyst: return "history_event_collection_journeyst";
		case DF_Type::history_event_collection_occasionst: return "history_event_collection_occasionst";
		case DF_Type::history_event_collection_performancest: return "history_event_collection_performancest";
		case DF_Type::history_event_collection_persecutionst: return "history_event_collection_persecutionst";
		case DF_Type::history_event_collection_processionst: return "history_event_collection_processionst";
		case DF_Type::history_event_collection_purgest: return "history_event_collection_purgest";
		case DF_Type::history_event_collection_raidst: return "history_event_collection_raidst";
		case DF_Type::history_event_collection_site_conqueredst: return "history_event_collection_site_conqueredst";
		case DF_Type::history_event_collection_theftst: return "history_event_collection_theftst";
		case DF_Type::history_event_collection_type: return "history_event_collection_type";
		case DF_Type::history_event_collection_warst: return "history_event_collection_warst";
		case DF_Type::history_event_collection_warst__T_unk: return "history_event_collection_warst__T_unk";
		case DF_Type::history_event_competitionst: return "history_event_competitionst";
		case DF_Type::history_event_context: return "history_event_context";
		case DF_Type::history_event_context__T_unk_10: return "history_event_context__T_unk_10";
		case DF_Type::history_event_create_entity_positionst: return "history_event_create_entity_positionst";
		case DF_Type::history_event_created_buildingst: return "history_event_created_buildingst";
		case DF_Type::history_event_created_sitest: return "history_event_created_sitest";
		case DF_Type::history_event_created_world_constructionst: return "history_event_created_world_constructionst";
		case DF_Type::history_event_creature_devouredst: return "history_event_creature_devouredst";
		case DF_Type::history_event_dance_form_createdst: return "history_event_dance_form_createdst";
		case DF_Type::history_event_diplomat_lostst: return "history_event_diplomat_lostst";
		case DF_Type::history_event_entity_actionst: return "history_event_entity_actionst";
		case DF_Type::history_event_entity_alliance_formedst: return "history_event_entity_alliance_formedst";
		case DF_Type::history_event_entity_breach_feature_layerst: return "history_event_entity_breach_feature_layerst";
		case DF_Type::history_event_entity_createdst: return "history_event_entity_createdst";
		case DF_Type::history_event_entity_dissolvedst: return "history_event_entity_dissolvedst";
		case DF_Type::history_event_entity_equipment_purchasest: return "history_event_entity_equipment_purchasest";
		case DF_Type::history_event_entity_expels_hfst: return "history_event_entity_expels_hfst";
		case DF_Type::history_event_entity_fled_sitest: return "history_event_entity_fled_sitest";
		case DF_Type::history_event_entity_incorporatedst: return "history_event_entity_incorporatedst";
		case DF_Type::history_event_entity_lawst: return "history_event_entity_lawst";
		case DF_Type::history_event_entity_lawst__T_add_flags: return "history_event_entity_lawst__T_add_flags";
		case DF_Type::history_event_entity_lawst__T_remove_flags: return "history_event_entity_lawst__T_remove_flags";
		case DF_Type::history_event_entity_overthrownst: return "history_event_entity_overthrownst";
		case DF_Type::history_event_entity_persecutedst: return "history_event_entity_persecutedst";
		case DF_Type::history_event_entity_rampaged_in_sitest: return "history_event_entity_rampaged_in_sitest";
		case DF_Type::history_event_entity_razed_buildingst: return "history_event_entity_razed_buildingst";
		case DF_Type::history_event_entity_searched_sitest: return "history_event_entity_searched_sitest";
		case DF_Type::history_event_failed_frame_attemptst: return "history_event_failed_frame_attemptst";
		case DF_Type::history_event_failed_intrigue_corruptionst: return "history_event_failed_intrigue_corruptionst";
		case DF_Type::history_event_first_contact_failedst: return "history_event_first_contact_failedst";
		case DF_Type::history_event_first_contactst: return "history_event_first_contactst";
		case DF_Type::history_event_flags: return "history_event_flags";
		case DF_Type::history_event_gamblest: return "history_event_gamblest";
		case DF_Type::history_event_hf_act_on_artifactst: return "history_event_hf_act_on_artifactst";
		case DF_Type::history_event_hf_act_on_artifactst__T_action: return "history_event_hf_act_on_artifactst__T_action";
		case DF_Type::history_event_hf_act_on_buildingst: return "history_event_hf_act_on_buildingst";
		case DF_Type::history_event_hf_act_on_buildingst__T_action: return "history_event_hf_act_on_buildingst__T_action";
		case DF_Type::history_event_hf_attacked_sitest: return "history_event_hf_attacked_sitest";
		case DF_Type::history_event_hf_confrontedst: return "history_event_hf_confrontedst";
		case DF_Type::history_event_hf_convictedst: return "history_event_hf_convictedst";
		case DF_Type::history_event_hf_convictedst__T_plot_flags: return "history_event_hf_convictedst__T_plot_flags";
		case DF_Type::history_event_hf_convictedst__T_punishment_flags: return "history_event_hf_convictedst__T_punishment_flags";
		case DF_Type::history_event_hf_destroyed_sitest: return "history_event_hf_destroyed_sitest";
		case DF_Type::history_event_hf_does_interactionst: return "history_event_hf_does_interactionst";
		case DF_Type::history_event_hf_enslavedst: return "history_event_hf_enslavedst";
		case DF_Type::history_event_hf_freedst: return "history_event_hf_freedst";
		case DF_Type::history_event_hf_gains_secret_goalst: return "history_event_hf_gains_secret_goalst";
		case DF_Type::history_event_hf_interrogatedst: return "history_event_hf_interrogatedst";
		case DF_Type::history_event_hf_interrogatedst__T_interrogation_flags: return "history_event_hf_interrogatedst__T_interrogation_flags";
		case DF_Type::history_event_hf_learns_secretst: return "history_event_hf_learns_secretst";
		case DF_Type::history_event_hf_preachst: return "history_event_hf_preachst";
		case DF_Type::history_event_hf_ransomedst: return "history_event_hf_ransomedst";
		case DF_Type::history_event_hf_razed_buildingst: return "history_event_hf_razed_buildingst";
		case DF_Type::history_event_hf_recruited_unit_type_for_entityst: return "history_event_hf_recruited_unit_type_for_entityst";
		case DF_Type::history_event_hf_relationship_deniedst: return "history_event_hf_relationship_deniedst";
		case DF_Type::history_event_hfs_formed_intrigue_relationshipst: return "history_event_hfs_formed_intrigue_relationshipst";
		case DF_Type::history_event_hfs_formed_reputation_relationshipst: return "history_event_hfs_formed_reputation_relationshipst";
		case DF_Type::history_event_hist_figure_abductedst: return "history_event_hist_figure_abductedst";
		case DF_Type::history_event_hist_figure_diedst: return "history_event_hist_figure_diedst";
		case DF_Type::history_event_hist_figure_new_petst: return "history_event_hist_figure_new_petst";
		case DF_Type::history_event_hist_figure_reach_summitst: return "history_event_hist_figure_reach_summitst";
		case DF_Type::history_event_hist_figure_reunionst: return "history_event_hist_figure_reunionst";
		case DF_Type::history_event_hist_figure_revivedst: return "history_event_hist_figure_revivedst";
		case DF_Type::history_event_hist_figure_revivedst__T_flags2: return "history_event_hist_figure_revivedst__T_flags2";
		case DF_Type::history_event_hist_figure_simple_actionst: return "history_event_hist_figure_simple_actionst";
		case DF_Type::history_event_hist_figure_simple_battle_eventst: return "history_event_hist_figure_simple_battle_eventst";
		case DF_Type::history_event_hist_figure_travelst: return "history_event_hist_figure_travelst";
		case DF_Type::history_event_hist_figure_travelst__T_reason: return "history_event_hist_figure_travelst__T_reason";
		case DF_Type::history_event_hist_figure_woundedst: return "history_event_hist_figure_woundedst";
		case DF_Type::history_event_hist_figure_woundedst__T_flags2: return "history_event_hist_figure_woundedst__T_flags2";
		case DF_Type::history_event_hist_figure_woundedst__T_injury_type: return "history_event_hist_figure_woundedst__T_injury_type";
		case DF_Type::history_event_insurrection_endedst: return "history_event_insurrection_endedst";
		case DF_Type::history_event_insurrection_startedst: return "history_event_insurrection_startedst";
		case DF_Type::history_event_item_stolenst: return "history_event_item_stolenst";
		case DF_Type::history_event_knowledge_discoveredst: return "history_event_knowledge_discoveredst";
		case DF_Type::history_event_masterpiece_created_arch_constructst: return "history_event_masterpiece_created_arch_constructst";
		case DF_Type::history_event_masterpiece_created_arch_designst: return "history_event_masterpiece_created_arch_designst";
		case DF_Type::history_event_masterpiece_created_dye_itemst: return "history_event_masterpiece_created_dye_itemst";
		case DF_Type::history_event_masterpiece_created_engravingst: return "history_event_masterpiece_created_engravingst";
		case DF_Type::history_event_masterpiece_created_foodst: return "history_event_masterpiece_created_foodst";
		case DF_Type::history_event_masterpiece_created_item_improvementst: return "history_event_masterpiece_created_item_improvementst";
		case DF_Type::history_event_masterpiece_created_itemst: return "history_event_masterpiece_created_itemst";
		case DF_Type::history_event_masterpiece_createdst: return "history_event_masterpiece_createdst";
		case DF_Type::history_event_masterpiece_lostst: return "history_event_masterpiece_lostst";
		case DF_Type::history_event_merchantst: return "history_event_merchantst";
		case DF_Type::history_event_modified_buildingst: return "history_event_modified_buildingst";
		case DF_Type::history_event_modified_buildingst__T_modification: return "history_event_modified_buildingst__T_modification";
		case DF_Type::history_event_musical_form_createdst: return "history_event_musical_form_createdst";
		case DF_Type::history_event_performancest: return "history_event_performancest";
		case DF_Type::history_event_poetic_form_createdst: return "history_event_poetic_form_createdst";
		case DF_Type::history_event_processionst: return "history_event_processionst";
		case DF_Type::history_event_reason: return "history_event_reason";
		case DF_Type::history_event_reason_info: return "history_event_reason_info";
		case DF_Type::history_event_reason_info__T_data: return "history_event_reason_info__T_data";
		case DF_Type::history_event_reclaim_sitest: return "history_event_reclaim_sitest";
		case DF_Type::history_event_reclaim_sitest__T_flags2: return "history_event_reclaim_sitest__T_flags2";
		case DF_Type::history_event_regionpop_incorporated_into_entityst: return "history_event_regionpop_incorporated_into_entityst";
		case DF_Type::history_event_remove_hf_entity_linkst: return "history_event_remove_hf_entity_linkst";
		case DF_Type::history_event_remove_hf_hf_linkst: return "history_event_remove_hf_hf_linkst";
		case DF_Type::history_event_remove_hf_site_linkst: return "history_event_remove_hf_site_linkst";
		case DF_Type::history_event_replaced_buildingst: return "history_event_replaced_buildingst";
		case DF_Type::history_event_sabotagest: return "history_event_sabotagest";
		case DF_Type::history_event_simple_battle_subtype: return "history_event_simple_battle_subtype";
		case DF_Type::history_event_site_diedst: return "history_event_site_diedst";
		case DF_Type::history_event_site_diedst__T_flags2: return "history_event_site_diedst__T_flags2";
		case DF_Type::history_event_site_disputest: return "history_event_site_disputest";
		case DF_Type::history_event_site_retiredst: return "history_event_site_retiredst";
		case DF_Type::history_event_site_retiredst__T_flags2: return "history_event_site_retiredst__T_flags2";
		case DF_Type::history_event_site_surrenderedst: return "history_event_site_surrenderedst";
		case DF_Type::history_event_sneak_into_sitest: return "history_event_sneak_into_sitest";
		case DF_Type::history_event_spotted_leaving_sitest: return "history_event_spotted_leaving_sitest";
		case DF_Type::history_event_squad_vs_squadst: return "history_event_squad_vs_squadst";
		case DF_Type::history_event_tactical_situationst: return "history_event_tactical_situationst";
		case DF_Type::history_event_tactical_situationst__T_tactics_flags: return "history_event_tactical_situationst__T_tactics_flags";
		case DF_Type::history_event_topicagreement_concludedst: return "history_event_topicagreement_concludedst";
		case DF_Type::history_event_topicagreement_madest: return "history_event_topicagreement_madest";
		case DF_Type::history_event_topicagreement_rejectedst: return "history_event_topicagreement_rejectedst";
		case DF_Type::history_event_tradest: return "history_event_tradest";
		case DF_Type::history_event_type: return "history_event_type";
		case DF_Type::history_event_war_attacked_sitest: return "history_event_war_attacked_sitest";
		case DF_Type::history_event_war_destroyed_sitest: return "history_event_war_destroyed_sitest";
		case DF_Type::history_event_war_field_battlest: return "history_event_war_field_battlest";
		case DF_Type::history_event_war_peace_acceptedst: return "history_event_war_peace_acceptedst";
		case DF_Type::history_event_war_peace_rejectedst: return "history_event_war_peace_rejectedst";
		case DF_Type::history_event_war_plundered_sitest: return "history_event_war_plundered_sitest";
		case DF_Type::history_event_war_site_new_leaderst: return "history_event_war_site_new_leaderst";
		case DF_Type::history_event_war_site_taken_overst: return "history_event_war_site_taken_overst";
		case DF_Type::history_event_war_site_tribute_forcedst: return "history_event_war_site_tribute_forcedst";
		case DF_Type::history_event_war_site_tribute_forcedst__T_tribute_flags: return "history_event_war_site_tribute_forcedst__T_tribute_flags";
		case DF_Type::history_event_written_content_composedst: return "history_event_written_content_composedst";
		case DF_Type::history_hit_item: return "history_hit_item";
		case DF_Type::hive_flags: return "hive_flags";
		case DF_Type::honors_type: return "honors_type";
		case DF_Type::honors_type__T_flags: return "honors_type__T_flags";
		case DF_Type::honors_type__T_required_skill_type: return "honors_type__T_required_skill_type";
		case DF_Type::hospital_supplies: return "hospital_supplies";
		case DF_Type::hospital_supplies__T_supplies_needed: return "hospital_supplies__T_supplies_needed";
		case DF_Type::identity: return "identity";
		case DF_Type::identity_unk_94: return "identity_unk_94";
		case DF_Type::improvement_type: return "improvement_type";
		case DF_Type::incident: return "incident";
		case DF_Type::incident__T_data: return "incident__T_data";
		case DF_Type::incident__T_flags: return "incident__T_flags";
		case DF_Type::incident__T_type: return "incident__T_type";
		case DF_Type::incident_hfid: return "incident_hfid";
		case DF_Type::incident_sub10: return "incident_sub10";
		case DF_Type::incident_sub6_performance: return "incident_sub6_performance";
		case DF_Type::incident_sub6_performance__T_participants: return "incident_sub6_performance__T_participants";
		case DF_Type::incident_sub7: return "incident_sub7";
		case DF_Type::incident_sub8: return "incident_sub8";
		case DF_Type::incident_sub9: return "incident_sub9";
		case DF_Type::inclusion_type: return "inclusion_type";
		case DF_Type::init: return "init";
		case DF_Type::init_display: return "init_display";
		case DF_Type::init_display__T_windowed: return "init_display__T_windowed";
		case DF_Type::init_display_flags: return "init_display_flags";
		case DF_Type::init_font: return "init_font";
		case DF_Type::init_font__T_use_ttf: return "init_font__T_use_ttf";
		case DF_Type::init_input: return "init_input";
		case DF_Type::init_input_flags: return "init_input_flags";
		case DF_Type::init_media: return "init_media";
		case DF_Type::init_media_flags: return "init_media_flags";
		case DF_Type::init_window: return "init_window";
		case DF_Type::init_window_flags: return "init_window_flags";
		case DF_Type::inorganic_flags: return "inorganic_flags";
		case DF_Type::inorganic_raw: return "inorganic_raw";
		case DF_Type::inorganic_raw__T_environment: return "inorganic_raw__T_environment";
		case DF_Type::inorganic_raw__T_environment_spec: return "inorganic_raw__T_environment_spec";
		case DF_Type::inorganic_raw__T_metal_ore: return "inorganic_raw__T_metal_ore";
		case DF_Type::inorganic_raw__T_thread_metal: return "inorganic_raw__T_thread_metal";
		case DF_Type::instrument_flags: return "instrument_flags";
		case DF_Type::instrument_piece: return "instrument_piece";
		case DF_Type::instrument_piece__T_flags: return "instrument_piece__T_flags";
		case DF_Type::instrument_register: return "instrument_register";
		case DF_Type::insurrection_outcome: return "insurrection_outcome";
		case DF_Type::interaction: return "interaction";
		case DF_Type::interaction_effect: return "interaction_effect";
		case DF_Type::interaction_effect__T_flags: return "interaction_effect__T_flags";
		case DF_Type::interaction_effect_add_syndromest: return "interaction_effect_add_syndromest";
		case DF_Type::interaction_effect_animatest: return "interaction_effect_animatest";
		case DF_Type::interaction_effect_change_item_qualityst: return "interaction_effect_change_item_qualityst";
		case DF_Type::interaction_effect_change_weatherst: return "interaction_effect_change_weatherst";
		case DF_Type::interaction_effect_cleanst: return "interaction_effect_cleanst";
		case DF_Type::interaction_effect_contactst: return "interaction_effect_contactst";
		case DF_Type::interaction_effect_create_itemst: return "interaction_effect_create_itemst";
		case DF_Type::interaction_effect_hidest: return "interaction_effect_hidest";
		case DF_Type::interaction_effect_location_hint: return "interaction_effect_location_hint";
		case DF_Type::interaction_effect_material_emissionst: return "interaction_effect_material_emissionst";
		case DF_Type::interaction_effect_propel_unitst: return "interaction_effect_propel_unitst";
		case DF_Type::interaction_effect_resurrectst: return "interaction_effect_resurrectst";
		case DF_Type::interaction_effect_summon_unitst: return "interaction_effect_summon_unitst";
		case DF_Type::interaction_effect_type: return "interaction_effect_type";
		case DF_Type::interaction_flags: return "interaction_flags";
		case DF_Type::interaction_instance: return "interaction_instance";
		case DF_Type::interaction_source: return "interaction_source";
		case DF_Type::interaction_source_attackst: return "interaction_source_attackst";
		case DF_Type::interaction_source_creature_actionst: return "interaction_source_creature_actionst";
		case DF_Type::interaction_source_deityst: return "interaction_source_deityst";
		case DF_Type::interaction_source_disturbancest: return "interaction_source_disturbancest";
		case DF_Type::interaction_source_experimentst: return "interaction_source_experimentst";
		case DF_Type::interaction_source_ingestionst: return "interaction_source_ingestionst";
		case DF_Type::interaction_source_regionst: return "interaction_source_regionst";
		case DF_Type::interaction_source_regionst__T_region_flags: return "interaction_source_regionst__T_region_flags";
		case DF_Type::interaction_source_secretst: return "interaction_source_secretst";
		case DF_Type::interaction_source_secretst__T_learn_flags: return "interaction_source_secretst__T_learn_flags";
		case DF_Type::interaction_source_type: return "interaction_source_type";
		case DF_Type::interaction_source_underground_specialst: return "interaction_source_underground_specialst";
		case DF_Type::interaction_source_usage_hint: return "interaction_source_usage_hint";
		case DF_Type::interaction_target: return "interaction_target";
		case DF_Type::interaction_target_corpsest: return "interaction_target_corpsest";
		case DF_Type::interaction_target_creaturest: return "interaction_target_creaturest";
		case DF_Type::interaction_target_info: return "interaction_target_info";
		case DF_Type::interaction_target_info__T_restrictions: return "interaction_target_info__T_restrictions";
		case DF_Type::interaction_target_location_type: return "interaction_target_location_type";
		case DF_Type::interaction_target_locationst: return "interaction_target_locationst";
		case DF_Type::interaction_target_materialst: return "interaction_target_materialst";
		case DF_Type::interaction_target_materialst__T_restrictions: return "interaction_target_materialst__T_restrictions";
		case DF_Type::interaction_target_type: return "interaction_target_type";
		case DF_Type::interface_breakdown_types: return "interface_breakdown_types";
		case DF_Type::interface_button: return "interface_button";
		case DF_Type::interface_button_building_category_selectorst: return "interface_button_building_category_selectorst";
		case DF_Type::interface_button_building_custom_category_selectorst: return "interface_button_building_custom_category_selectorst";
		case DF_Type::interface_button_building_material_selectorst: return "interface_button_building_material_selectorst";
		case DF_Type::interface_button_building_new_jobst: return "interface_button_building_new_jobst";
		case DF_Type::interface_button_buildingst: return "interface_button_buildingst";
		case DF_Type::interface_button_construction_building_selectorst: return "interface_button_construction_building_selectorst";
		case DF_Type::interface_button_construction_category_selectorst: return "interface_button_construction_category_selectorst";
		case DF_Type::interface_button_construction_category_selectorst__T_category_id: return "interface_button_construction_category_selectorst__T_category_id";
		case DF_Type::interface_button_construction_donest: return "interface_button_construction_donest";
		case DF_Type::interface_button_constructionst: return "interface_button_constructionst";
		case DF_Type::interface_key: return "interface_key";
		case DF_Type::interfacest: return "interfacest";
		case DF_Type::invasion_info: return "invasion_info";
		case DF_Type::invasion_info__T_flags: return "invasion_info__T_flags";
		case DF_Type::item: return "item";
		case DF_Type::item_actual: return "item_actual";
		case DF_Type::item_ammost: return "item_ammost";
		case DF_Type::item_amuletst: return "item_amuletst";
		case DF_Type::item_animaltrapst: return "item_animaltrapst";
		case DF_Type::item_anvilst: return "item_anvilst";
		case DF_Type::item_armorst: return "item_armorst";
		case DF_Type::item_armorstandst: return "item_armorstandst";
		case DF_Type::item_backpackst: return "item_backpackst";
		case DF_Type::item_ballistaarrowheadst: return "item_ballistaarrowheadst";
		case DF_Type::item_ballistapartsst: return "item_ballistapartsst";
		case DF_Type::item_barrelst: return "item_barrelst";
		case DF_Type::item_barst: return "item_barst";
		case DF_Type::item_bedst: return "item_bedst";
		case DF_Type::item_binst: return "item_binst";
		case DF_Type::item_blocksst: return "item_blocksst";
		case DF_Type::item_body_component: return "item_body_component";
		case DF_Type::item_body_component__T_appearance: return "item_body_component__T_appearance";
		case DF_Type::item_body_component__T_body: return "item_body_component__T_body";
		case DF_Type::item_body_component__T_bone1: return "item_body_component__T_bone1";
		case DF_Type::item_body_component__T_bone2: return "item_body_component__T_bone2";
		case DF_Type::item_body_component__T_corpse_flags: return "item_body_component__T_corpse_flags";
		case DF_Type::item_bookst: return "item_bookst";
		case DF_Type::item_boulderst: return "item_boulderst";
		case DF_Type::item_boxst: return "item_boxst";
		case DF_Type::item_braceletst: return "item_braceletst";
		case DF_Type::item_branchst: return "item_branchst";
		case DF_Type::item_bucketst: return "item_bucketst";
		case DF_Type::item_cabinetst: return "item_cabinetst";
		case DF_Type::item_cagest: return "item_cagest";
		case DF_Type::item_catapultpartsst: return "item_catapultpartsst";
		case DF_Type::item_chainst: return "item_chainst";
		case DF_Type::item_chairst: return "item_chairst";
		case DF_Type::item_cheesest: return "item_cheesest";
		case DF_Type::item_clothst: return "item_clothst";
		case DF_Type::item_coffinst: return "item_coffinst";
		case DF_Type::item_coinst: return "item_coinst";
		case DF_Type::item_constructed: return "item_constructed";
		case DF_Type::item_corpsepiecest: return "item_corpsepiecest";
		case DF_Type::item_corpsest: return "item_corpsest";
		case DF_Type::item_crafted: return "item_crafted";
		case DF_Type::item_critter: return "item_critter";
		case DF_Type::item_crownst: return "item_crownst";
		case DF_Type::item_crutchst: return "item_crutchst";
		case DF_Type::item_doorst: return "item_doorst";
		case DF_Type::item_drinkst: return "item_drinkst";
		case DF_Type::item_earringst: return "item_earringst";
		case DF_Type::item_eggst: return "item_eggst";
		case DF_Type::item_eggst__T_egg_flags: return "item_eggst__T_egg_flags";
		case DF_Type::item_figurinest: return "item_figurinest";
		case DF_Type::item_filter_spec: return "item_filter_spec";
		case DF_Type::item_fish_rawst: return "item_fish_rawst";
		case DF_Type::item_fishst: return "item_fishst";
		case DF_Type::item_flags: return "item_flags";
		case DF_Type::item_flags2: return "item_flags2";
		case DF_Type::item_flaskst: return "item_flaskst";
		case DF_Type::item_floodgatest: return "item_floodgatest";
		case DF_Type::item_foodst: return "item_foodst";
		case DF_Type::item_foodst__T_ingredients: return "item_foodst__T_ingredients";
		case DF_Type::item_gemst: return "item_gemst";
		case DF_Type::item_globst: return "item_globst";
		case DF_Type::item_glovesst: return "item_glovesst";
		case DF_Type::item_gobletst: return "item_gobletst";
		case DF_Type::item_gratest: return "item_gratest";
		case DF_Type::item_hatch_coverst: return "item_hatch_coverst";
		case DF_Type::item_helmst: return "item_helmst";
		case DF_Type::item_history_info: return "item_history_info";
		case DF_Type::item_instrumentst: return "item_instrumentst";
		case DF_Type::item_kill_info: return "item_kill_info";
		case DF_Type::item_liquid: return "item_liquid";
		case DF_Type::item_liquid_miscst: return "item_liquid_miscst";
		case DF_Type::item_liquipowder: return "item_liquipowder";
		case DF_Type::item_magicness: return "item_magicness";
		case DF_Type::item_magicness_type: return "item_magicness_type";
		case DF_Type::item_matstate: return "item_matstate";
		case DF_Type::item_meatst: return "item_meatst";
		case DF_Type::item_millstonest: return "item_millstonest";
		case DF_Type::item_orthopedic_castst: return "item_orthopedic_castst";
		case DF_Type::item_pantsst: return "item_pantsst";
		case DF_Type::item_petst: return "item_petst";
		case DF_Type::item_petst__T_pet_flags: return "item_petst__T_pet_flags";
		case DF_Type::item_pipe_sectionst: return "item_pipe_sectionst";
		case DF_Type::item_plant_growthst: return "item_plant_growthst";
		case DF_Type::item_plantst: return "item_plantst";
		case DF_Type::item_powder: return "item_powder";
		case DF_Type::item_powder_miscst: return "item_powder_miscst";
		case DF_Type::item_quality: return "item_quality";
		case DF_Type::item_quernst: return "item_quernst";
		case DF_Type::item_quiverst: return "item_quiverst";
		case DF_Type::item_remainsst: return "item_remainsst";
		case DF_Type::item_ringst: return "item_ringst";
		case DF_Type::item_rockst: return "item_rockst";
		case DF_Type::item_roughst: return "item_roughst";
		case DF_Type::item_scepterst: return "item_scepterst";
		case DF_Type::item_seedsst: return "item_seedsst";
		case DF_Type::item_sheetst: return "item_sheetst";
		case DF_Type::item_shieldst: return "item_shieldst";
		case DF_Type::item_shoesst: return "item_shoesst";
		case DF_Type::item_siegeammost: return "item_siegeammost";
		case DF_Type::item_skin_tannedst: return "item_skin_tannedst";
		case DF_Type::item_slabst: return "item_slabst";
		case DF_Type::item_smallgemst: return "item_smallgemst";
		case DF_Type::item_splintst: return "item_splintst";
		case DF_Type::item_statuest: return "item_statuest";
		case DF_Type::item_stockpile_ref: return "item_stockpile_ref";
		case DF_Type::item_tablest: return "item_tablest";
		case DF_Type::item_threadst: return "item_threadst";
		case DF_Type::item_toolst: return "item_toolst";
		case DF_Type::item_totemst: return "item_totemst";
		case DF_Type::item_toyst: return "item_toyst";
		case DF_Type::item_traction_benchst: return "item_traction_benchst";
		case DF_Type::item_trapcompst: return "item_trapcompst";
		case DF_Type::item_trappartsst: return "item_trappartsst";
		case DF_Type::item_type: return "item_type";
		case DF_Type::item_verminst: return "item_verminst";
		case DF_Type::item_weaponrackst: return "item_weaponrackst";
		case DF_Type::item_weaponst: return "item_weaponst";
		case DF_Type::item_windowst: return "item_windowst";
		case DF_Type::item_woodst: return "item_woodst";
		case DF_Type::itemdef: return "itemdef";
		case DF_Type::itemdef_ammost: return "itemdef_ammost";
		case DF_Type::itemdef_armorst: return "itemdef_armorst";
		case DF_Type::itemdef_foodst: return "itemdef_foodst";
		case DF_Type::itemdef_glovesst: return "itemdef_glovesst";
		case DF_Type::itemdef_helmst: return "itemdef_helmst";
		case DF_Type::itemdef_instrumentst: return "itemdef_instrumentst";
		case DF_Type::itemdef_pantsst: return "itemdef_pantsst";
		case DF_Type::itemdef_shieldst: return "itemdef_shieldst";
		case DF_Type::itemdef_shoesst: return "itemdef_shoesst";
		case DF_Type::itemdef_siegeammost: return "itemdef_siegeammost";
		case DF_Type::itemdef_toolst: return "itemdef_toolst";
		case DF_Type::itemdef_toolst__T_default_improvements: return "itemdef_toolst__T_default_improvements";
		case DF_Type::itemdef_toyst: return "itemdef_toyst";
		case DF_Type::itemdef_trapcompst: return "itemdef_trapcompst";
		case DF_Type::itemdef_weaponst: return "itemdef_weaponst";
		case DF_Type::itemimprovement: return "itemimprovement";
		case DF_Type::itemimprovement_art_imagest: return "itemimprovement_art_imagest";
		case DF_Type::itemimprovement_bandsst: return "itemimprovement_bandsst";
		case DF_Type::itemimprovement_clothst: return "itemimprovement_clothst";
		case DF_Type::itemimprovement_coveredst: return "itemimprovement_coveredst";
		case DF_Type::itemimprovement_coveredst__T_cover_flags: return "itemimprovement_coveredst__T_cover_flags";
		case DF_Type::itemimprovement_illustrationst: return "itemimprovement_illustrationst";
		case DF_Type::itemimprovement_instrument_piecest: return "itemimprovement_instrument_piecest";
		case DF_Type::itemimprovement_itemspecificst: return "itemimprovement_itemspecificst";
		case DF_Type::itemimprovement_pagesst: return "itemimprovement_pagesst";
		case DF_Type::itemimprovement_rings_hangingst: return "itemimprovement_rings_hangingst";
		case DF_Type::itemimprovement_sewn_imagest: return "itemimprovement_sewn_imagest";
		case DF_Type::itemimprovement_sewn_imagest__T_cloth: return "itemimprovement_sewn_imagest__T_cloth";
		case DF_Type::itemimprovement_specific_type: return "itemimprovement_specific_type";
		case DF_Type::itemimprovement_spikesst: return "itemimprovement_spikesst";
		case DF_Type::itemimprovement_threadst: return "itemimprovement_threadst";
		case DF_Type::itemimprovement_writingst: return "itemimprovement_writingst";
		case DF_Type::items_other_id: return "items_other_id";
		case DF_Type::job: return "job";
		case DF_Type::job_art_specification: return "job_art_specification";
		case DF_Type::job_art_specification__T_type: return "job_art_specification__T_type";
		case DF_Type::job_flags: return "job_flags";
		case DF_Type::job_handler: return "job_handler";
		case DF_Type::job_handler__T_anon_1: return "job_handler__T_anon_1";
		case DF_Type::job_handler__T_postings: return "job_handler__T_postings";
		case DF_Type::job_handler__T_postings__T_flags: return "job_handler__T_postings__T_flags";
		case DF_Type::job_item: return "job_item";
		case DF_Type::job_item_filter: return "job_item_filter";
		case DF_Type::job_item_flags1: return "job_item_flags1";
		case DF_Type::job_item_flags2: return "job_item_flags2";
		case DF_Type::job_item_flags3: return "job_item_flags3";
		case DF_Type::job_item_ref: return "job_item_ref";
		case DF_Type::job_item_ref__T_role: return "job_item_ref__T_role";
		case DF_Type::job_item_vector_id: return "job_item_vector_id";
		case DF_Type::job_list_link: return "job_list_link";
		case DF_Type::job_material_category: return "job_material_category";
		case DF_Type::job_skill: return "job_skill";
		case DF_Type::job_skill_class: return "job_skill_class";
		case DF_Type::job_subtype_surgery: return "job_subtype_surgery";
		case DF_Type::job_type: return "job_type";
		case DF_Type::job_type_class: return "job_type_class";
		case DF_Type::KeybindingScreen: return "KeybindingScreen";
		case DF_Type::KeybindingScreen__T_mode: return "KeybindingScreen__T_mode";
		case DF_Type::kitchen_exc_type: return "kitchen_exc_type";
		case DF_Type::kitchen_pref_flag: return "kitchen_pref_flag";
		case DF_Type::knowledge_scholar_category_flag: return "knowledge_scholar_category_flag";
		case DF_Type::knowledge_scholar_category_flag__T_flag_data: return "knowledge_scholar_category_flag__T_flag_data";
		case DF_Type::knowledge_scholar_category_flag__T_flag_type: return "knowledge_scholar_category_flag__T_flag_type";
		case DF_Type::knowledge_scholar_flags_0: return "knowledge_scholar_flags_0";
		case DF_Type::knowledge_scholar_flags_1: return "knowledge_scholar_flags_1";
		case DF_Type::knowledge_scholar_flags_10: return "knowledge_scholar_flags_10";
		case DF_Type::knowledge_scholar_flags_11: return "knowledge_scholar_flags_11";
		case DF_Type::knowledge_scholar_flags_12: return "knowledge_scholar_flags_12";
		case DF_Type::knowledge_scholar_flags_13: return "knowledge_scholar_flags_13";
		case DF_Type::knowledge_scholar_flags_2: return "knowledge_scholar_flags_2";
		case DF_Type::knowledge_scholar_flags_3: return "knowledge_scholar_flags_3";
		case DF_Type::knowledge_scholar_flags_4: return "knowledge_scholar_flags_4";
		case DF_Type::knowledge_scholar_flags_5: return "knowledge_scholar_flags_5";
		case DF_Type::knowledge_scholar_flags_6: return "knowledge_scholar_flags_6";
		case DF_Type::knowledge_scholar_flags_7: return "knowledge_scholar_flags_7";
		case DF_Type::knowledge_scholar_flags_8: return "knowledge_scholar_flags_8";
		case DF_Type::knowledge_scholar_flags_9: return "knowledge_scholar_flags_9";
		case DF_Type::lair_type: return "lair_type";
		case DF_Type::language_name: return "language_name";
		case DF_Type::language_name_category: return "language_name_category";
		case DF_Type::language_symbol: return "language_symbol";
		case DF_Type::language_translation: return "language_translation";
		case DF_Type::language_word: return "language_word";
		case DF_Type::language_word_flags: return "language_word_flags";
		case DF_Type::language_word_table: return "language_word_table";
		case DF_Type::large_integer: return "large_integer";
		case DF_Type::large_integer___struct0: return "large_integer___struct0";
		case DF_Type::large_integer__T_u: return "large_integer__T_u";
		case DF_Type::layer_object: return "layer_object";
		case DF_Type::layer_object_buttonst: return "layer_object_buttonst";
		case DF_Type::layer_object_listst: return "layer_object_listst";
		case DF_Type::layer_type: return "layer_type";
		case DF_Type::lever_target_type: return "lever_target_type";
		case DF_Type::loadgame_save_info: return "loadgame_save_info";
		case DF_Type::local_population: return "local_population";
		case DF_Type::local_population___union3: return "local_population___union3";
		case DF_Type::local_population__T_flags: return "local_population__T_flags";
		case DF_Type::location_scribe_jobs: return "location_scribe_jobs";
		case DF_Type::machine: return "machine";
		case DF_Type::machine__T_components: return "machine__T_components";
		case DF_Type::machine__T_flags: return "machine__T_flags";
		case DF_Type::machine_conn_modes: return "machine_conn_modes";
		case DF_Type::machine_handler: return "machine_handler";
		case DF_Type::machine_info: return "machine_info";
		case DF_Type::machine_info__T_flags: return "machine_info__T_flags";
		case DF_Type::machine_standardst: return "machine_standardst";
		case DF_Type::machine_tile_set: return "machine_tile_set";
		case DF_Type::machine_type: return "machine_type";
		case DF_Type::MacroScreenLoad: return "MacroScreenLoad";
		case DF_Type::MacroScreenSave: return "MacroScreenSave";
		case DF_Type::manager_order: return "manager_order";
		case DF_Type::manager_order__T_frequency: return "manager_order__T_frequency";
		case DF_Type::manager_order_condition_item: return "manager_order_condition_item";
		case DF_Type::manager_order_condition_item__T_compare_type: return "manager_order_condition_item__T_compare_type";
		case DF_Type::manager_order_condition_order: return "manager_order_condition_order";
		case DF_Type::manager_order_condition_order__T_condition: return "manager_order_condition_order__T_condition";
		case DF_Type::manager_order_status: return "manager_order_status";
		case DF_Type::manager_order_template: return "manager_order_template";
		case DF_Type::mandate: return "mandate";
		case DF_Type::mandate__T_mode: return "mandate__T_mode";
		case DF_Type::mandate__T_punishment: return "mandate__T_punishment";
		case DF_Type::map_block: return "map_block";
		case DF_Type::map_block_column: return "map_block_column";
		case DF_Type::map_block_column__T_unmined_glyphs: return "map_block_column__T_unmined_glyphs";
		case DF_Type::map_renderer: return "map_renderer";
		case DF_Type::map_renderer__T_anon_4: return "map_renderer__T_anon_4";
		case DF_Type::map_viewport: return "map_viewport";
		case DF_Type::masterpiece_loss_type: return "masterpiece_loss_type";
		case DF_Type::material: return "material";
		case DF_Type::material_common: return "material_common";
		case DF_Type::material_common__T_hardens_with_water: return "material_common__T_hardens_with_water";
		case DF_Type::material_common__T_heat: return "material_common__T_heat";
		case DF_Type::material_common__T_reaction_product: return "material_common__T_reaction_product";
		case DF_Type::material_common__T_strength: return "material_common__T_strength";
		case DF_Type::material_flags: return "material_flags";
		case DF_Type::material_template: return "material_template";
		case DF_Type::material_vec_ref: return "material_vec_ref";
		case DF_Type::matgloss_list: return "matgloss_list";
		case DF_Type::matgloss_list__T_unk_0: return "matgloss_list__T_unk_0";
		case DF_Type::matter_state: return "matter_state";
		case DF_Type::meeting_context: return "meeting_context";
		case DF_Type::meeting_diplomat_info: return "meeting_diplomat_info";
		case DF_Type::meeting_diplomat_info__T_flags: return "meeting_diplomat_info__T_flags";
		case DF_Type::meeting_event: return "meeting_event";
		case DF_Type::meeting_event_type: return "meeting_event_type";
		case DF_Type::meeting_topic: return "meeting_topic";
		case DF_Type::meeting_variable: return "meeting_variable";
		case DF_Type::mental_attribute_type: return "mental_attribute_type";
		case DF_Type::mental_picture: return "mental_picture";
		case DF_Type::mental_picture__T_unk: return "mental_picture__T_unk";
		case DF_Type::mental_picture_element_hfst: return "mental_picture_element_hfst";
		case DF_Type::mental_picture_element_regionst: return "mental_picture_element_regionst";
		case DF_Type::mental_picture_element_sitest: return "mental_picture_element_sitest";
		case DF_Type::mental_picture_element_type: return "mental_picture_element_type";
		case DF_Type::mental_picture_elementst: return "mental_picture_elementst";
		case DF_Type::mental_picture_property_actionst: return "mental_picture_property_actionst";
		case DF_Type::mental_picture_property_adjectivest: return "mental_picture_property_adjectivest";
		case DF_Type::mental_picture_property_color_patternst: return "mental_picture_property_color_patternst";
		case DF_Type::mental_picture_property_datest: return "mental_picture_property_datest";
		case DF_Type::mental_picture_property_emotionst: return "mental_picture_property_emotionst";
		case DF_Type::mental_picture_property_positionst: return "mental_picture_property_positionst";
		case DF_Type::mental_picture_property_shapest: return "mental_picture_property_shapest";
		case DF_Type::mental_picture_property_timest: return "mental_picture_property_timest";
		case DF_Type::mental_picture_property_toolst: return "mental_picture_property_toolst";
		case DF_Type::mental_picture_property_type: return "mental_picture_property_type";
		case DF_Type::mental_picture_propertyst: return "mental_picture_propertyst";
		case DF_Type::misc_trait_type: return "misc_trait_type";
		case DF_Type::mission: return "mission";
		case DF_Type::mission__T_details: return "mission__T_details";
		case DF_Type::mission__T_details__T_raid: return "mission__T_details__T_raid";
		case DF_Type::mission__T_details__T_raid__T_raid_flags: return "mission__T_details__T_raid__T_raid_flags";
		case DF_Type::mission__T_details__T_raid__T_raid_type: return "mission__T_details__T_raid__T_raid_type";
		case DF_Type::mission__T_details__T_recovery: return "mission__T_details__T_recovery";
		case DF_Type::mission__T_details__T_request: return "mission__T_details__T_request";
		case DF_Type::mission__T_details__T_rescue: return "mission__T_details__T_rescue";
		case DF_Type::mission__T_type: return "mission__T_type";
		case DF_Type::mission_campaign_report: return "mission_campaign_report";
		case DF_Type::mission_report: return "mission_report";
		case DF_Type::monument_type: return "monument_type";
		case DF_Type::mood_type: return "mood_type";
		case DF_Type::mountain_peak_flags: return "mountain_peak_flags";
		case DF_Type::moving_party: return "moving_party";
		case DF_Type::moving_party__T_members: return "moving_party__T_members";
		case DF_Type::musical_form: return "musical_form";
		case DF_Type::musical_form__T_flags: return "musical_form__T_flags";
		case DF_Type::musical_form_feature: return "musical_form_feature";
		case DF_Type::musical_form_instruments: return "musical_form_instruments";
		case DF_Type::musical_form_instruments__T_substitutions: return "musical_form_instruments__T_substitutions";
		case DF_Type::musical_form_interval: return "musical_form_interval";
		case DF_Type::musical_form_interval__T_flags: return "musical_form_interval__T_flags";
		case DF_Type::musical_form_melodies: return "musical_form_melodies";
		case DF_Type::musical_form_pitch_style: return "musical_form_pitch_style";
		case DF_Type::musical_form_purpose: return "musical_form_purpose";
		case DF_Type::musical_form_style: return "musical_form_style";
		case DF_Type::musical_form_sub4: return "musical_form_sub4";
		case DF_Type::musical_form_vocals: return "musical_form_vocals";
		case DF_Type::need_type: return "need_type";
		case DF_Type::nemesis_flags: return "nemesis_flags";
		case DF_Type::nemesis_offload: return "nemesis_offload";
		case DF_Type::nemesis_record: return "nemesis_record";
		case DF_Type::next_global_id: return "next_global_id";
		case DF_Type::occasion_schedule_feature: return "occasion_schedule_feature";
		case DF_Type::occasion_schedule_type: return "occasion_schedule_type";
		case DF_Type::occupation: return "occupation";
		case DF_Type::occupation_sub1: return "occupation_sub1";
		case DF_Type::occupation_type: return "occupation_type";
		case DF_Type::ocean_wave: return "ocean_wave";
		case DF_Type::organic_mat_category: return "organic_mat_category";
		case DF_Type::orientation_flags: return "orientation_flags";
		case DF_Type::pants_flags: return "pants_flags";
		case DF_Type::part_of_speech: return "part_of_speech";
		case DF_Type::party_info: return "party_info";
		case DF_Type::pattern_type: return "pattern_type";
		case DF_Type::performance_event_type: return "performance_event_type";
		case DF_Type::performance_participant_type: return "performance_participant_type";
		case DF_Type::performance_play_orderst: return "performance_play_orderst";
		case DF_Type::performance_play_orderst__T_anon_4: return "performance_play_orderst__T_anon_4";
		case DF_Type::personality_facet_type: return "personality_facet_type";
		case DF_Type::physical_attribute_type: return "physical_attribute_type";
		case DF_Type::pitch_choice_type: return "pitch_choice_type";
		case DF_Type::plant: return "plant";
		case DF_Type::plant__T_damage_flags: return "plant__T_damage_flags";
		case DF_Type::plant_flags: return "plant_flags";
		case DF_Type::plant_growth: return "plant_growth";
		case DF_Type::plant_growth__T_behavior: return "plant_growth__T_behavior";
		case DF_Type::plant_growth__T_locations: return "plant_growth__T_locations";
		case DF_Type::plant_growth_print: return "plant_growth_print";
		case DF_Type::plant_raw: return "plant_raw";
		case DF_Type::plant_raw__T_colors: return "plant_raw__T_colors";
		case DF_Type::plant_raw__T_material_defs: return "plant_raw__T_material_defs";
		case DF_Type::plant_raw__T_stockpile_growth_flags: return "plant_raw__T_stockpile_growth_flags";
		case DF_Type::plant_raw__T_tiles: return "plant_raw__T_tiles";
		case DF_Type::plant_raw_flags: return "plant_raw_flags";
		case DF_Type::plant_tree_info: return "plant_tree_info";
		case DF_Type::plant_tree_tile: return "plant_tree_tile";
		case DF_Type::plot_agreement: return "plot_agreement";
		case DF_Type::plot_role_type: return "plot_role_type";
		case DF_Type::plot_strategy_type: return "plot_strategy_type";
		case DF_Type::poetic_form: return "poetic_form";
		case DF_Type::poetic_form__T_flags: return "poetic_form__T_flags";
		case DF_Type::poetic_form_action: return "poetic_form_action";
		case DF_Type::poetic_form_additional_feature: return "poetic_form_additional_feature";
		case DF_Type::poetic_form_caesura_position: return "poetic_form_caesura_position";
		case DF_Type::poetic_form_feature: return "poetic_form_feature";
		case DF_Type::poetic_form_mood: return "poetic_form_mood";
		case DF_Type::poetic_form_part: return "poetic_form_part";
		case DF_Type::poetic_form_part__T_flags: return "poetic_form_part__T_flags";
		case DF_Type::poetic_form_pattern: return "poetic_form_pattern";
		case DF_Type::poetic_form_perspective: return "poetic_form_perspective";
		case DF_Type::poetic_form_perspective__T_type: return "poetic_form_perspective__T_type";
		case DF_Type::poetic_form_subject: return "poetic_form_subject";
		case DF_Type::poetic_form_subject_target: return "poetic_form_subject_target";
		case DF_Type::poetic_form_subject_target__T_Concept: return "poetic_form_subject_target__T_Concept";
		case DF_Type::poetic_form_subject_target__T_Histfig: return "poetic_form_subject_target__T_Histfig";
		case DF_Type::popup_message: return "popup_message";
		case DF_Type::power_info: return "power_info";
		case DF_Type::pressure_plate_info: return "pressure_plate_info";
		case DF_Type::pressure_plate_info__T_flags: return "pressure_plate_info__T_flags";
		case DF_Type::profession: return "profession";
		case DF_Type::proj_itemst: return "proj_itemst";
		case DF_Type::proj_list_link: return "proj_list_link";
		case DF_Type::proj_magicst: return "proj_magicst";
		case DF_Type::proj_unitst: return "proj_unitst";
		case DF_Type::projectile: return "projectile";
		case DF_Type::projectile_flags: return "projectile_flags";
		case DF_Type::projectile_type: return "projectile_type";
		case DF_Type::property_ownership: return "property_ownership";
		case DF_Type::punishment: return "punishment";
		case DF_Type::reaction: return "reaction";
		case DF_Type::reaction__T_building: return "reaction__T_building";
		case DF_Type::reaction_category: return "reaction_category";
		case DF_Type::reaction_description: return "reaction_description";
		case DF_Type::reaction_flags: return "reaction_flags";
		case DF_Type::reaction_product: return "reaction_product";
		case DF_Type::reaction_product_improvement_flags: return "reaction_product_improvement_flags";
		case DF_Type::reaction_product_item_flags: return "reaction_product_item_flags";
		case DF_Type::reaction_product_item_improvementst: return "reaction_product_item_improvementst";
		case DF_Type::reaction_product_item_improvementst__T_get_material: return "reaction_product_item_improvementst__T_get_material";
		case DF_Type::reaction_product_itemst: return "reaction_product_itemst";
		case DF_Type::reaction_product_itemst__T_get_material: return "reaction_product_itemst__T_get_material";
		case DF_Type::reaction_product_type: return "reaction_product_type";
		case DF_Type::reaction_reagent: return "reaction_reagent";
		case DF_Type::reaction_reagent_flags: return "reaction_reagent_flags";
		case DF_Type::reaction_reagent_itemst: return "reaction_reagent_itemst";
		case DF_Type::reaction_reagent_type: return "reaction_reagent_type";
		case DF_Type::region_block_event_sphere_fieldst: return "region_block_event_sphere_fieldst";
		case DF_Type::region_block_event_type: return "region_block_event_type";
		case DF_Type::region_block_eventst: return "region_block_eventst";
		case DF_Type::region_map_entry: return "region_map_entry";
		case DF_Type::region_map_entry__T_clouds: return "region_map_entry__T_clouds";
		case DF_Type::region_map_entry__T_wind: return "region_map_entry__T_wind";
		case DF_Type::region_map_entry_flags: return "region_map_entry_flags";
		case DF_Type::relationship_event: return "relationship_event";
		case DF_Type::relationship_event_supplement: return "relationship_event_supplement";
		case DF_Type::renderer: return "renderer";
		case DF_Type::report: return "report";
		case DF_Type::report__T_flags: return "report__T_flags";
		case DF_Type::reputation_type: return "reputation_type";
		case DF_Type::resource_allotment_data: return "resource_allotment_data";
		case DF_Type::resource_allotment_data__T_unk_654: return "resource_allotment_data__T_unk_654";
		case DF_Type::resource_allotment_specifier: return "resource_allotment_specifier";
		case DF_Type::resource_allotment_specifier_ammost: return "resource_allotment_specifier_ammost";
		case DF_Type::resource_allotment_specifier_anvilst: return "resource_allotment_specifier_anvilst";
		case DF_Type::resource_allotment_specifier_armor_bodyst: return "resource_allotment_specifier_armor_bodyst";
		case DF_Type::resource_allotment_specifier_armor_bootsst: return "resource_allotment_specifier_armor_bootsst";
		case DF_Type::resource_allotment_specifier_armor_glovesst: return "resource_allotment_specifier_armor_glovesst";
		case DF_Type::resource_allotment_specifier_armor_helmst: return "resource_allotment_specifier_armor_helmst";
		case DF_Type::resource_allotment_specifier_armor_pantsst: return "resource_allotment_specifier_armor_pantsst";
		case DF_Type::resource_allotment_specifier_backpackst: return "resource_allotment_specifier_backpackst";
		case DF_Type::resource_allotment_specifier_bagst: return "resource_allotment_specifier_bagst";
		case DF_Type::resource_allotment_specifier_bedst: return "resource_allotment_specifier_bedst";
		case DF_Type::resource_allotment_specifier_bonest: return "resource_allotment_specifier_bonest";
		case DF_Type::resource_allotment_specifier_boxst: return "resource_allotment_specifier_boxst";
		case DF_Type::resource_allotment_specifier_cabinetst: return "resource_allotment_specifier_cabinetst";
		case DF_Type::resource_allotment_specifier_chairst: return "resource_allotment_specifier_chairst";
		case DF_Type::resource_allotment_specifier_cheesest: return "resource_allotment_specifier_cheesest";
		case DF_Type::resource_allotment_specifier_clothing_bodyst: return "resource_allotment_specifier_clothing_bodyst";
		case DF_Type::resource_allotment_specifier_clothing_bootsst: return "resource_allotment_specifier_clothing_bootsst";
		case DF_Type::resource_allotment_specifier_clothing_glovesst: return "resource_allotment_specifier_clothing_glovesst";
		case DF_Type::resource_allotment_specifier_clothing_helmst: return "resource_allotment_specifier_clothing_helmst";
		case DF_Type::resource_allotment_specifier_clothing_pantsst: return "resource_allotment_specifier_clothing_pantsst";
		case DF_Type::resource_allotment_specifier_clothst: return "resource_allotment_specifier_clothst";
		case DF_Type::resource_allotment_specifier_craftsst: return "resource_allotment_specifier_craftsst";
		case DF_Type::resource_allotment_specifier_cropst: return "resource_allotment_specifier_cropst";
		case DF_Type::resource_allotment_specifier_extractst: return "resource_allotment_specifier_extractst";
		case DF_Type::resource_allotment_specifier_flaskst: return "resource_allotment_specifier_flaskst";
		case DF_Type::resource_allotment_specifier_gemsst: return "resource_allotment_specifier_gemsst";
		case DF_Type::resource_allotment_specifier_hornst: return "resource_allotment_specifier_hornst";
		case DF_Type::resource_allotment_specifier_leatherst: return "resource_allotment_specifier_leatherst";
		case DF_Type::resource_allotment_specifier_meatst: return "resource_allotment_specifier_meatst";
		case DF_Type::resource_allotment_specifier_metalst: return "resource_allotment_specifier_metalst";
		case DF_Type::resource_allotment_specifier_pearlst: return "resource_allotment_specifier_pearlst";
		case DF_Type::resource_allotment_specifier_powderst: return "resource_allotment_specifier_powderst";
		case DF_Type::resource_allotment_specifier_quiverst: return "resource_allotment_specifier_quiverst";
		case DF_Type::resource_allotment_specifier_shellst: return "resource_allotment_specifier_shellst";
		case DF_Type::resource_allotment_specifier_skinst: return "resource_allotment_specifier_skinst";
		case DF_Type::resource_allotment_specifier_soapst: return "resource_allotment_specifier_soapst";
		case DF_Type::resource_allotment_specifier_stonest: return "resource_allotment_specifier_stonest";
		case DF_Type::resource_allotment_specifier_tablest: return "resource_allotment_specifier_tablest";
		case DF_Type::resource_allotment_specifier_tallowst: return "resource_allotment_specifier_tallowst";
		case DF_Type::resource_allotment_specifier_threadst: return "resource_allotment_specifier_threadst";
		case DF_Type::resource_allotment_specifier_toothst: return "resource_allotment_specifier_toothst";
		case DF_Type::resource_allotment_specifier_type: return "resource_allotment_specifier_type";
		case DF_Type::resource_allotment_specifier_weapon_meleest: return "resource_allotment_specifier_weapon_meleest";
		case DF_Type::resource_allotment_specifier_weapon_rangedst: return "resource_allotment_specifier_weapon_rangedst";
		case DF_Type::resource_allotment_specifier_woodst: return "resource_allotment_specifier_woodst";
		case DF_Type::rhythm: return "rhythm";
		case DF_Type::rhythm_sub1: return "rhythm_sub1";
		case DF_Type::rhythm_sub1__T_anon_1: return "rhythm_sub1__T_anon_1";
		case DF_Type::rhythm_sub2: return "rhythm_sub2";
		case DF_Type::room_rent_info: return "room_rent_info";
		case DF_Type::room_rent_info__T_flags: return "room_rent_info__T_flags";
		case DF_Type::route_stockpile_link: return "route_stockpile_link";
		case DF_Type::route_stockpile_link__T_mode: return "route_stockpile_link__T_mode";
		case DF_Type::scale: return "scale";
		case DF_Type::scale__T_unk1: return "scale__T_unk1";
		case DF_Type::scale_sub1: return "scale_sub1";
		case DF_Type::scale_sub2: return "scale_sub2";
		case DF_Type::schedule_info: return "schedule_info";
		case DF_Type::schedule_slot: return "schedule_slot";
		case DF_Type::screw_pump_direction: return "screw_pump_direction";
		case DF_Type::scribejob: return "scribejob";
		case DF_Type::script_step_conditionalst: return "script_step_conditionalst";
		case DF_Type::script_step_conditionalst__T_condition: return "script_step_conditionalst__T_condition";
		case DF_Type::script_step_constructtopiclistst: return "script_step_constructtopiclistst";
		case DF_Type::script_step_dipeventst: return "script_step_dipeventst";
		case DF_Type::script_step_diphistoryst: return "script_step_diphistoryst";
		case DF_Type::script_step_discussst: return "script_step_discussst";
		case DF_Type::script_step_eventst: return "script_step_eventst";
		case DF_Type::script_step_invasionst: return "script_step_invasionst";
		case DF_Type::script_step_setvarst: return "script_step_setvarst";
		case DF_Type::script_step_simpleactionst: return "script_step_simpleactionst";
		case DF_Type::script_step_textviewerst: return "script_step_textviewerst";
		case DF_Type::script_step_topicdiscussionst: return "script_step_topicdiscussionst";
		case DF_Type::script_stepst: return "script_stepst";
		case DF_Type::script_var_longst: return "script_var_longst";
		case DF_Type::script_var_unitst: return "script_var_unitst";
		case DF_Type::script_varst: return "script_varst";
		case DF_Type::setup_character_info: return "setup_character_info";
		case DF_Type::setup_character_info__T_available_embark_items: return "setup_character_info__T_available_embark_items";
		case DF_Type::setup_character_info__T_page: return "setup_character_info__T_page";
		case DF_Type::setup_character_info__T_sel_trait_column: return "setup_character_info__T_sel_trait_column";
		case DF_Type::setup_character_info__T_status: return "setup_character_info__T_status";
		case DF_Type::shoes_flags: return "shoes_flags";
		case DF_Type::shop_type: return "shop_type";
		case DF_Type::siegeengine_type: return "siegeengine_type";
		case DF_Type::site_building_item: return "site_building_item";
		case DF_Type::site_dispute_type: return "site_dispute_type";
		case DF_Type::site_realization_building: return "site_realization_building";
		case DF_Type::site_realization_building__T_unk_4c: return "site_realization_building__T_unk_4c";
		case DF_Type::site_realization_building_info_castle_courtyardst: return "site_realization_building_info_castle_courtyardst";
		case DF_Type::site_realization_building_info_castle_towerst: return "site_realization_building_info_castle_towerst";
		case DF_Type::site_realization_building_info_castle_wallst: return "site_realization_building_info_castle_wallst";
		case DF_Type::site_realization_building_info_hillock_housest: return "site_realization_building_info_hillock_housest";
		case DF_Type::site_realization_building_info_market_squarest: return "site_realization_building_info_market_squarest";
		case DF_Type::site_realization_building_info_shop_housest: return "site_realization_building_info_shop_housest";
		case DF_Type::site_realization_building_info_tree_housest: return "site_realization_building_info_tree_housest";
		case DF_Type::site_realization_building_info_trenchesst: return "site_realization_building_info_trenchesst";
		case DF_Type::site_realization_building_info_trenchesst__T_spokes: return "site_realization_building_info_trenchesst__T_spokes";
		case DF_Type::site_realization_building_infost: return "site_realization_building_infost";
		case DF_Type::site_realization_building_type: return "site_realization_building_type";
		case DF_Type::site_realization_crossroads: return "site_realization_crossroads";
		case DF_Type::site_reputation_info: return "site_reputation_info";
		case DF_Type::site_reputation_report: return "site_reputation_report";
		case DF_Type::site_shop_type: return "site_shop_type";
		case DF_Type::site_type: return "site_type";
		case DF_Type::skill_rating: return "skill_rating";
		case DF_Type::slab_engraving_type: return "slab_engraving_type";
		case DF_Type::sound_production_type: return "sound_production_type";
		case DF_Type::spatter: return "spatter";
		case DF_Type::spatter__T_flags: return "spatter__T_flags";
		case DF_Type::spatter_common: return "spatter_common";
		case DF_Type::spatter_common__T_base_flags: return "spatter_common__T_base_flags";
		case DF_Type::special_mat_table: return "special_mat_table";
		case DF_Type::specific_ref: return "specific_ref";
		case DF_Type::specific_ref__T_data: return "specific_ref__T_data";
		case DF_Type::specific_ref__T_data__T_UNIT_ITEM_WRESTLE: return "specific_ref__T_data__T_UNIT_ITEM_WRESTLE";
		case DF_Type::specific_ref_type: return "specific_ref_type";
		case DF_Type::sphere_type: return "sphere_type";
		case DF_Type::spoils_report: return "spoils_report";
		case DF_Type::squad: return "squad";
		case DF_Type::squad__T_rooms: return "squad__T_rooms";
		case DF_Type::squad_ammo_spec: return "squad_ammo_spec";
		case DF_Type::squad_ammo_spec__T_flags: return "squad_ammo_spec__T_flags";
		case DF_Type::squad_event_type: return "squad_event_type";
		case DF_Type::squad_order: return "squad_order";
		case DF_Type::squad_order_cannot_reason: return "squad_order_cannot_reason";
		case DF_Type::squad_order_cause_trouble_for_entityst: return "squad_order_cause_trouble_for_entityst";
		case DF_Type::squad_order_defend_burrowsst: return "squad_order_defend_burrowsst";
		case DF_Type::squad_order_drive_armies_from_sitest: return "squad_order_drive_armies_from_sitest";
		case DF_Type::squad_order_drive_entity_off_sitest: return "squad_order_drive_entity_off_sitest";
		case DF_Type::squad_order_kill_hfst: return "squad_order_kill_hfst";
		case DF_Type::squad_order_kill_listst: return "squad_order_kill_listst";
		case DF_Type::squad_order_movest: return "squad_order_movest";
		case DF_Type::squad_order_patrol_routest: return "squad_order_patrol_routest";
		case DF_Type::squad_order_raid_sitest: return "squad_order_raid_sitest";
		case DF_Type::squad_order_rescue_hfst: return "squad_order_rescue_hfst";
		case DF_Type::squad_order_retrieve_artifactst: return "squad_order_retrieve_artifactst";
		case DF_Type::squad_order_trainst: return "squad_order_trainst";
		case DF_Type::squad_order_type: return "squad_order_type";
		case DF_Type::squad_position: return "squad_position";
		case DF_Type::squad_schedule_entry: return "squad_schedule_entry";
		case DF_Type::squad_schedule_order: return "squad_schedule_order";
		case DF_Type::squad_uniform_spec: return "squad_uniform_spec";
		case DF_Type::squad_use_flags: return "squad_use_flags";
		case DF_Type::stockpile_category: return "stockpile_category";
		case DF_Type::stockpile_group_set: return "stockpile_group_set";
		case DF_Type::stockpile_links: return "stockpile_links";
		case DF_Type::stockpile_list: return "stockpile_list";
		case DF_Type::stockpile_settings: return "stockpile_settings";
		case DF_Type::stockpile_settings__T_ammo: return "stockpile_settings__T_ammo";
		case DF_Type::stockpile_settings__T_animals: return "stockpile_settings__T_animals";
		case DF_Type::stockpile_settings__T_armor: return "stockpile_settings__T_armor";
		case DF_Type::stockpile_settings__T_bars_blocks: return "stockpile_settings__T_bars_blocks";
		case DF_Type::stockpile_settings__T_cloth: return "stockpile_settings__T_cloth";
		case DF_Type::stockpile_settings__T_coins: return "stockpile_settings__T_coins";
		case DF_Type::stockpile_settings__T_finished_goods: return "stockpile_settings__T_finished_goods";
		case DF_Type::stockpile_settings__T_food: return "stockpile_settings__T_food";
		case DF_Type::stockpile_settings__T_furniture: return "stockpile_settings__T_furniture";
		case DF_Type::stockpile_settings__T_gems: return "stockpile_settings__T_gems";
		case DF_Type::stockpile_settings__T_leather: return "stockpile_settings__T_leather";
		case DF_Type::stockpile_settings__T_ore: return "stockpile_settings__T_ore";
		case DF_Type::stockpile_settings__T_refuse: return "stockpile_settings__T_refuse";
		case DF_Type::stockpile_settings__T_sheet: return "stockpile_settings__T_sheet";
		case DF_Type::stockpile_settings__T_stone: return "stockpile_settings__T_stone";
		case DF_Type::stockpile_settings__T_weapons: return "stockpile_settings__T_weapons";
		case DF_Type::stockpile_settings__T_wood: return "stockpile_settings__T_wood";
		case DF_Type::stop_depart_condition: return "stop_depart_condition";
		case DF_Type::stop_depart_condition__T_direction: return "stop_depart_condition__T_direction";
		case DF_Type::stop_depart_condition__T_flags: return "stop_depart_condition__T_flags";
		case DF_Type::stop_depart_condition__T_mode: return "stop_depart_condition__T_mode";
		case DF_Type::strain_type: return "strain_type";
		case DF_Type::stratus_type: return "stratus_type";
		case DF_Type::syndrome: return "syndrome";
		case DF_Type::syndrome_flags: return "syndrome_flags";
		case DF_Type::T_cursor: return "T_cursor";
		case DF_Type::T_selection_rect: return "T_selection_rect";
		case DF_Type::tactical_situation: return "tactical_situation";
		case DF_Type::talk_choice: return "talk_choice";
		case DF_Type::talk_choice__T_unk: return "talk_choice__T_unk";
		case DF_Type::talk_choice_type: return "talk_choice_type";
		case DF_Type::temperaturest: return "temperaturest";
		case DF_Type::temple_deity_data: return "temple_deity_data";
		case DF_Type::temple_deity_type: return "temple_deity_type";
		case DF_Type::text_info_element_longst: return "text_info_element_longst";
		case DF_Type::text_info_element_stringst: return "text_info_element_stringst";
		case DF_Type::text_info_elementst: return "text_info_elementst";
		case DF_Type::texture_handler: return "texture_handler";
		case DF_Type::tile_bitmask: return "tile_bitmask";
		case DF_Type::tile_building_occ: return "tile_building_occ";
		case DF_Type::tile_designation: return "tile_designation";
		case DF_Type::tile_dig_designation: return "tile_dig_designation";
		case DF_Type::tile_liquid: return "tile_liquid";
		case DF_Type::tile_liquid_flow: return "tile_liquid_flow";
		case DF_Type::tile_liquid_flow_dir: return "tile_liquid_flow_dir";
		case DF_Type::tile_occupancy: return "tile_occupancy";
		case DF_Type::tile_page: return "tile_page";
		case DF_Type::tile_traffic: return "tile_traffic";
		case DF_Type::tiletype: return "tiletype";
		case DF_Type::tiletype_material: return "tiletype_material";
		case DF_Type::tiletype_shape: return "tiletype_shape";
		case DF_Type::tiletype_shape_basic: return "tiletype_shape_basic";
		case DF_Type::tiletype_special: return "tiletype_special";
		case DF_Type::tiletype_variant: return "tiletype_variant";
		case DF_Type::timbre_type: return "timbre_type";
		case DF_Type::timed_event: return "timed_event";
		case DF_Type::timed_event_type: return "timed_event_type";
		case DF_Type::tissue: return "tissue";
		case DF_Type::tissue_flags: return "tissue_flags";
		case DF_Type::tissue_style_raw: return "tissue_style_raw";
		case DF_Type::tissue_style_type: return "tissue_style_type";
		case DF_Type::tissue_template: return "tissue_template";
		case DF_Type::tool_flags: return "tool_flags";
		case DF_Type::tool_uses: return "tool_uses";
		case DF_Type::tower_shape: return "tower_shape";
		case DF_Type::toy_flags: return "toy_flags";
		case DF_Type::training_assignment: return "training_assignment";
		case DF_Type::training_assignment__T_flags: return "training_assignment__T_flags";
		case DF_Type::training_knowledge_level: return "training_knowledge_level";
		case DF_Type::trap_type: return "trap_type";
		case DF_Type::trapcomp_flags: return "trapcomp_flags";
		case DF_Type::tree_house_type: return "tree_house_type";
		case DF_Type::tuning_type: return "tuning_type";
		case DF_Type::ui: return "ui";
		case DF_Type::ui__T_alerts: return "ui__T_alerts";
		case DF_Type::ui__T_alerts__T_list: return "ui__T_alerts__T_list";
		case DF_Type::ui__T_becoming_capital: return "ui__T_becoming_capital";
		case DF_Type::ui__T_burrows: return "ui__T_burrows";
		case DF_Type::ui__T_economy_prices: return "ui__T_economy_prices";
		case DF_Type::ui__T_economy_prices__T_price_adjustment: return "ui__T_economy_prices__T_price_adjustment";
		case DF_Type::ui__T_economy_prices__T_price_setter: return "ui__T_economy_prices__T_price_setter";
		case DF_Type::ui__T_equipment: return "ui__T_equipment";
		case DF_Type::ui__T_equipment__T_update: return "ui__T_equipment__T_update";
		case DF_Type::ui__T_hauling: return "ui__T_hauling";
		case DF_Type::ui__T_invasions: return "ui__T_invasions";
		case DF_Type::ui__T_kitchen: return "ui__T_kitchen";
		case DF_Type::ui__T_main: return "ui__T_main";
		case DF_Type::ui__T_main__T_dead_citizens: return "ui__T_main__T_dead_citizens";
		case DF_Type::ui__T_map_edge: return "ui__T_map_edge";
		case DF_Type::ui__T_squads: return "ui__T_squads";
		case DF_Type::ui__T_stockpile: return "ui__T_stockpile";
		case DF_Type::ui__T_tax_collection: return "ui__T_tax_collection";
		case DF_Type::ui__T_unk23c8_flags: return "ui__T_unk23c8_flags";
		case DF_Type::ui__T_unk2a8c: return "ui__T_unk2a8c";
		case DF_Type::ui__T_waypoints: return "ui__T_waypoints";
		case DF_Type::ui__T_waypoints__T_points: return "ui__T_waypoints__T_points";
		case DF_Type::ui__T_waypoints__T_routes: return "ui__T_waypoints__T_routes";
		case DF_Type::ui_advmode: return "ui_advmode";
		case DF_Type::ui_advmode__T_assume_identity: return "ui_advmode__T_assume_identity";
		case DF_Type::ui_advmode__T_companions: return "ui_advmode__T_companions";
		case DF_Type::ui_advmode__T_conversation: return "ui_advmode__T_conversation";
		case DF_Type::ui_advmode__T_conversation__T_choices: return "ui_advmode__T_conversation__T_choices";
		case DF_Type::ui_advmode__T_conversation__T_targets: return "ui_advmode__T_conversation__T_targets";
		case DF_Type::ui_advmode__T_conversation__T_targets__T_type: return "ui_advmode__T_conversation__T_targets__T_type";
		case DF_Type::ui_advmode__T_interactions: return "ui_advmode__T_interactions";
		case DF_Type::ui_advmode__T_show_menu: return "ui_advmode__T_show_menu";
		case DF_Type::ui_advmode__T_travel_right_map: return "ui_advmode__T_travel_right_map";
		case DF_Type::ui_advmode__T_unk_3124: return "ui_advmode__T_unk_3124";
		case DF_Type::ui_advmode__T_unk_3170: return "ui_advmode__T_unk_3170";
		case DF_Type::ui_advmode__T_unk_3170__T_unk_2: return "ui_advmode__T_unk_3170__T_unk_2";
		case DF_Type::ui_advmode__T_unk_v40_1: return "ui_advmode__T_unk_v40_1";
		case DF_Type::ui_advmode__T_unk_v40_2: return "ui_advmode__T_unk_v40_2";
		case DF_Type::ui_advmode__T_unk_v40_3: return "ui_advmode__T_unk_v40_3";
		case DF_Type::ui_advmode__T_unk_v40_4: return "ui_advmode__T_unk_v40_4";
		case DF_Type::ui_advmode__T_unk_v40_4__T_unk_v40_4a: return "ui_advmode__T_unk_v40_4__T_unk_v40_4a";
		case DF_Type::ui_advmode__T_unk_v40_5: return "ui_advmode__T_unk_v40_5";
		case DF_Type::ui_advmode__T_unk_v42_1: return "ui_advmode__T_unk_v42_1";
		case DF_Type::ui_advmode_menu: return "ui_advmode_menu";
		case DF_Type::ui_build_item_req: return "ui_build_item_req";
		case DF_Type::ui_build_selector: return "ui_build_selector";
		case DF_Type::ui_hotkey: return "ui_hotkey";
		case DF_Type::ui_hotkey___union1: return "ui_hotkey___union1";
		case DF_Type::ui_hotkey__T_cmd: return "ui_hotkey__T_cmd";
		case DF_Type::ui_look_list: return "ui_look_list";
		case DF_Type::ui_look_list__T_items: return "ui_look_list__T_items";
		case DF_Type::ui_look_list__T_items__T_data: return "ui_look_list__T_items__T_data";
		case DF_Type::ui_look_list__T_items__T_data__T_Magma: return "ui_look_list__T_items__T_data__T_Magma";
		case DF_Type::ui_look_list__T_items__T_data__T_Spatter: return "ui_look_list__T_items__T_data__T_Spatter";
		case DF_Type::ui_look_list__T_items__T_data__T_Water: return "ui_look_list__T_items__T_data__T_Water";
		case DF_Type::ui_look_list__T_items__T_type: return "ui_look_list__T_items__T_type";
		case DF_Type::ui_sidebar_menus: return "ui_sidebar_menus";
		case DF_Type::ui_sidebar_menus__T_barracks: return "ui_sidebar_menus__T_barracks";
		case DF_Type::ui_sidebar_menus__T_building: return "ui_sidebar_menus__T_building";
		case DF_Type::ui_sidebar_menus__T_command_line: return "ui_sidebar_menus__T_command_line";
		case DF_Type::ui_sidebar_menus__T_designation: return "ui_sidebar_menus__T_designation";
		case DF_Type::ui_sidebar_menus__T_designation__T_mine_mode: return "ui_sidebar_menus__T_designation__T_mine_mode";
		case DF_Type::ui_sidebar_menus__T_hospital: return "ui_sidebar_menus__T_hospital";
		case DF_Type::ui_sidebar_menus__T_job_details: return "ui_sidebar_menus__T_job_details";
		case DF_Type::ui_sidebar_menus__T_location: return "ui_sidebar_menus__T_location";
		case DF_Type::ui_sidebar_menus__T_minimap: return "ui_sidebar_menus__T_minimap";
		case DF_Type::ui_sidebar_menus__T_unit: return "ui_sidebar_menus__T_unit";
		case DF_Type::ui_sidebar_menus__T_unit__T_expel_error: return "ui_sidebar_menus__T_unit__T_expel_error";
		case DF_Type::ui_sidebar_menus__T_unit_cursor: return "ui_sidebar_menus__T_unit_cursor";
		case DF_Type::ui_sidebar_menus__T_unit_skills: return "ui_sidebar_menus__T_unit_skills";
		case DF_Type::ui_sidebar_menus__T_workshop_job: return "ui_sidebar_menus__T_workshop_job";
		case DF_Type::ui_sidebar_menus__T_zone: return "ui_sidebar_menus__T_zone";
		case DF_Type::ui_sidebar_menus__T_zone__T_mode: return "ui_sidebar_menus__T_zone__T_mode";
		case DF_Type::ui_sidebar_mode: return "ui_sidebar_mode";
		case DF_Type::ui_unit_view_mode: return "ui_unit_view_mode";
		case DF_Type::ui_unit_view_mode__T_value: return "ui_unit_view_mode__T_value";
		case DF_Type::uniform_category: return "uniform_category";
		case DF_Type::uniform_flags: return "uniform_flags";
		case DF_Type::uniform_indiv_choice: return "uniform_indiv_choice";
		case DF_Type::unit: return "unit";
		case DF_Type::unit__T_animal: return "unit__T_animal";
		case DF_Type::unit__T_appearance: return "unit__T_appearance";
		case DF_Type::unit__T_body: return "unit__T_body";
		case DF_Type::unit__T_counters: return "unit__T_counters";
		case DF_Type::unit__T_counters2: return "unit__T_counters2";
		case DF_Type::unit__T_counters__T_soldier_mood: return "unit__T_counters__T_soldier_mood";
		case DF_Type::unit__T_curse: return "unit__T_curse";
		case DF_Type::unit__T_enemy: return "unit__T_enemy";
		case DF_Type::unit__T_enemy__T_undead: return "unit__T_enemy__T_undead";
		case DF_Type::unit__T_enemy__T_unk_448: return "unit__T_enemy__T_unk_448";
		case DF_Type::unit__T_enemy__T_unk_448__T_unk: return "unit__T_enemy__T_unk_448__T_unk";
		case DF_Type::unit__T_enemy__T_unk_44c: return "unit__T_enemy__T_unk_44c";
		case DF_Type::unit__T_enemy__T_unk_v40_sub3: return "unit__T_enemy__T_unk_v40_sub3";
		case DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_2: return "unit__T_enemy__T_unk_v40_sub3__T_unk_2";
		case DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_6: return "unit__T_enemy__T_unk_v40_sub3__T_unk_6";
		case DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_7: return "unit__T_enemy__T_unk_v40_sub3__T_unk_7";
		case DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_7__T_unk_sub1: return "unit__T_enemy__T_unk_v40_sub3__T_unk_7__T_unk_sub1";
		case DF_Type::unit__T_enemy__T_witness_reports: return "unit__T_enemy__T_witness_reports";
		case DF_Type::unit__T_job: return "unit__T_job";
		case DF_Type::unit__T_meeting: return "unit__T_meeting";
		case DF_Type::unit__T_meeting__T_state: return "unit__T_meeting__T_state";
		case DF_Type::unit__T_military: return "unit__T_military";
		case DF_Type::unit__T_military__T_pickup_flags: return "unit__T_military__T_pickup_flags";
		case DF_Type::unit__T_opponent: return "unit__T_opponent";
		case DF_Type::unit__T_path: return "unit__T_path";
		case DF_Type::unit__T_reports: return "unit__T_reports";
		case DF_Type::unit__T_status: return "unit__T_status";
		case DF_Type::unit__T_status2: return "unit__T_status2";
		case DF_Type::unit__T_status__T_eat_history: return "unit__T_status__T_eat_history";
		case DF_Type::unit__T_status__T_eat_history__T_drink: return "unit__T_status__T_eat_history__T_drink";
		case DF_Type::unit__T_status__T_eat_history__T_food: return "unit__T_status__T_eat_history__T_food";
		case DF_Type::unit__T_syndromes: return "unit__T_syndromes";
		case DF_Type::unit__T_unknown7: return "unit__T_unknown7";
		case DF_Type::unit_action: return "unit_action";
		case DF_Type::unit_action__T_data: return "unit_action__T_data";
		case DF_Type::unit_action_data_attack: return "unit_action_data_attack";
		case DF_Type::unit_action_data_attack__T_flags: return "unit_action_data_attack__T_flags";
		case DF_Type::unit_action_data_attack__T_unk_4: return "unit_action_data_attack__T_unk_4";
		case DF_Type::unit_action_data_attack__T_unk_4__T_wrestle_type: return "unit_action_data_attack__T_unk_4__T_wrestle_type";
		case DF_Type::unit_action_data_block: return "unit_action_data_block";
		case DF_Type::unit_action_data_climb: return "unit_action_data_climb";
		case DF_Type::unit_action_data_dodge: return "unit_action_data_dodge";
		case DF_Type::unit_action_data_hold_item: return "unit_action_data_hold_item";
		case DF_Type::unit_action_data_hold_terrain: return "unit_action_data_hold_terrain";
		case DF_Type::unit_action_data_job: return "unit_action_data_job";
		case DF_Type::unit_action_data_job2: return "unit_action_data_job2";
		case DF_Type::unit_action_data_jump: return "unit_action_data_jump";
		case DF_Type::unit_action_data_lie_down: return "unit_action_data_lie_down";
		case DF_Type::unit_action_data_move: return "unit_action_data_move";
		case DF_Type::unit_action_data_move__T_flags: return "unit_action_data_move__T_flags";
		case DF_Type::unit_action_data_parry: return "unit_action_data_parry";
		case DF_Type::unit_action_data_push_object: return "unit_action_data_push_object";
		case DF_Type::unit_action_data_recover: return "unit_action_data_recover";
		case DF_Type::unit_action_data_release_item: return "unit_action_data_release_item";
		case DF_Type::unit_action_data_release_terrain: return "unit_action_data_release_terrain";
		case DF_Type::unit_action_data_stand_up: return "unit_action_data_stand_up";
		case DF_Type::unit_action_data_suck_blood: return "unit_action_data_suck_blood";
		case DF_Type::unit_action_data_talk: return "unit_action_data_talk";
		case DF_Type::unit_action_data_unsteady: return "unit_action_data_unsteady";
		case DF_Type::unit_action_type: return "unit_action_type";
		case DF_Type::unit_appearance: return "unit_appearance";
		case DF_Type::unit_attribute: return "unit_attribute";
		case DF_Type::unit_bp_health_flags: return "unit_bp_health_flags";
		case DF_Type::unit_chunk: return "unit_chunk";
		case DF_Type::unit_chunk__T_units: return "unit_chunk__T_units";
		case DF_Type::unit_coin_debt: return "unit_coin_debt";
		case DF_Type::unit_complaint: return "unit_complaint";
		case DF_Type::unit_complaint__T_type: return "unit_complaint__T_type";
		case DF_Type::unit_dance_skill: return "unit_dance_skill";
		case DF_Type::unit_demand: return "unit_demand";
		case DF_Type::unit_demand__T_place: return "unit_demand__T_place";
		case DF_Type::unit_emotion_memory: return "unit_emotion_memory";
		case DF_Type::unit_flags1: return "unit_flags1";
		case DF_Type::unit_flags2: return "unit_flags2";
		case DF_Type::unit_flags3: return "unit_flags3";
		case DF_Type::unit_flags4: return "unit_flags4";
		case DF_Type::unit_genes: return "unit_genes";
		case DF_Type::unit_ghost_info: return "unit_ghost_info";
		case DF_Type::unit_ghost_info__T_flags: return "unit_ghost_info__T_flags";
		case DF_Type::unit_ghost_info__T_target: return "unit_ghost_info__T_target";
		case DF_Type::unit_health_flags: return "unit_health_flags";
		case DF_Type::unit_health_info: return "unit_health_info";
		case DF_Type::unit_health_info__T_op_history: return "unit_health_info__T_op_history";
		case DF_Type::unit_health_info__T_op_history__T_info: return "unit_health_info__T_op_history__T_info";
		case DF_Type::unit_health_info__T_op_history__T_info__T_bandage: return "unit_health_info__T_op_history__T_info__T_bandage";
		case DF_Type::unit_health_info__T_op_history__T_info__T_crutch: return "unit_health_info__T_op_history__T_info__T_crutch";
		case DF_Type::unit_instrument_skill: return "unit_instrument_skill";
		case DF_Type::unit_inventory_item: return "unit_inventory_item";
		case DF_Type::unit_inventory_item__T_mode: return "unit_inventory_item__T_mode";
		case DF_Type::unit_item_use: return "unit_item_use";
		case DF_Type::unit_item_wrestle: return "unit_item_wrestle";
		case DF_Type::unit_labor: return "unit_labor";
		case DF_Type::unit_labor_category: return "unit_labor_category";
		case DF_Type::unit_misc_trait: return "unit_misc_trait";
		case DF_Type::unit_musical_skill: return "unit_musical_skill";
		case DF_Type::unit_path_goal: return "unit_path_goal";
		case DF_Type::unit_personality: return "unit_personality";
		case DF_Type::unit_personality__T_dreams: return "unit_personality__T_dreams";
		case DF_Type::unit_personality__T_emotions: return "unit_personality__T_emotions";
		case DF_Type::unit_personality__T_emotions__T_flags: return "unit_personality__T_emotions__T_flags";
		case DF_Type::unit_personality__T_flags: return "unit_personality__T_flags";
		case DF_Type::unit_personality__T_memories: return "unit_personality__T_memories";
		case DF_Type::unit_personality__T_memories__T_reflected_on: return "unit_personality__T_memories__T_reflected_on";
		case DF_Type::unit_personality__T_needs: return "unit_personality__T_needs";
		case DF_Type::unit_personality__T_unk5: return "unit_personality__T_unk5";
		case DF_Type::unit_personality__T_unk_v40_2: return "unit_personality__T_unk_v40_2";
		case DF_Type::unit_personality__T_unk_v40_6: return "unit_personality__T_unk_v40_6";
		case DF_Type::unit_personality__T_values: return "unit_personality__T_values";
		case DF_Type::unit_poetic_skill: return "unit_poetic_skill";
		case DF_Type::unit_preference: return "unit_preference";
		case DF_Type::unit_preference___union2: return "unit_preference___union2";
		case DF_Type::unit_preference__T_type: return "unit_preference__T_type";
		case DF_Type::unit_relationship_type: return "unit_relationship_type";
		case DF_Type::unit_report_type: return "unit_report_type";
		case DF_Type::unit_request: return "unit_request";
		case DF_Type::unit_request__T_type: return "unit_request__T_type";
		case DF_Type::unit_skill: return "unit_skill";
		case DF_Type::unit_soul: return "unit_soul";
		case DF_Type::unit_soul__T_performance_skills: return "unit_soul__T_performance_skills";
		case DF_Type::unit_station_type: return "unit_station_type";
		case DF_Type::unit_storage_status: return "unit_storage_status";
		case DF_Type::unit_syndrome: return "unit_syndrome";
		case DF_Type::unit_syndrome__T_flags: return "unit_syndrome__T_flags";
		case DF_Type::unit_syndrome__T_symptoms: return "unit_syndrome__T_symptoms";
		case DF_Type::unit_syndrome__T_symptoms__T_flags: return "unit_syndrome__T_symptoms__T_flags";
		case DF_Type::unit_thought_type: return "unit_thought_type";
		case DF_Type::unit_unk_138: return "unit_unk_138";
		case DF_Type::unit_wound: return "unit_wound";
		case DF_Type::unit_wound__T_flags: return "unit_wound__T_flags";
		case DF_Type::unit_wound__T_parts: return "unit_wound__T_parts";
		case DF_Type::units_other_id: return "units_other_id";
		case DF_Type::vague_relationship_type: return "vague_relationship_type";
		case DF_Type::value_type: return "value_type";
		case DF_Type::vehicle: return "vehicle";
		case DF_Type::vermin: return "vermin";
		case DF_Type::vermin_flags: return "vermin_flags";
		case DF_Type::viewscreen: return "viewscreen";
		case DF_Type::viewscreen_adopt_regionst: return "viewscreen_adopt_regionst";
		case DF_Type::viewscreen_adventure_logst: return "viewscreen_adventure_logst";
		case DF_Type::viewscreen_adventure_logst__T_info_mode: return "viewscreen_adventure_logst__T_info_mode";
		case DF_Type::viewscreen_adventure_logst__T_mode: return "viewscreen_adventure_logst__T_mode";
		case DF_Type::viewscreen_adventure_logst__T_unk_68: return "viewscreen_adventure_logst__T_unk_68";
		case DF_Type::viewscreen_announcelistst: return "viewscreen_announcelistst";
		case DF_Type::viewscreen_assign_display_itemst: return "viewscreen_assign_display_itemst";
		case DF_Type::viewscreen_assign_display_itemst__T_sel_column: return "viewscreen_assign_display_itemst__T_sel_column";
		case DF_Type::viewscreen_barterst: return "viewscreen_barterst";
		case DF_Type::viewscreen_buildinglistst: return "viewscreen_buildinglistst";
		case DF_Type::viewscreen_buildingst: return "viewscreen_buildingst";
		case DF_Type::viewscreen_choose_start_sitest: return "viewscreen_choose_start_sitest";
		case DF_Type::viewscreen_choose_start_sitest__T_finder: return "viewscreen_choose_start_sitest__T_finder";
		case DF_Type::viewscreen_choose_start_sitest__T_finder__T_finder_state: return "viewscreen_choose_start_sitest__T_finder__T_finder_state";
		case DF_Type::viewscreen_choose_start_sitest__T_page: return "viewscreen_choose_start_sitest__T_page";
		case DF_Type::viewscreen_civlistst: return "viewscreen_civlistst";
		case DF_Type::viewscreen_civlistst__T_artifact_details: return "viewscreen_civlistst__T_artifact_details";
		case DF_Type::viewscreen_civlistst__T_page: return "viewscreen_civlistst__T_page";
		case DF_Type::viewscreen_civlistst__T_rumors: return "viewscreen_civlistst__T_rumors";
		case DF_Type::viewscreen_civlistst__T_rumors__T_type: return "viewscreen_civlistst__T_rumors__T_type";
		case DF_Type::viewscreen_civlistst__T_unk_cache: return "viewscreen_civlistst__T_unk_cache";
		case DF_Type::viewscreen_civlistst__T_unk_cache__T_tmp1: return "viewscreen_civlistst__T_unk_cache__T_tmp1";
		case DF_Type::viewscreen_civlistst__T_unk_cache__T_tmp2: return "viewscreen_civlistst__T_unk_cache__T_tmp2";
		case DF_Type::viewscreen_counterintelligencest: return "viewscreen_counterintelligencest";
		case DF_Type::viewscreen_createquotast: return "viewscreen_createquotast";
		case DF_Type::viewscreen_customize_unitst: return "viewscreen_customize_unitst";
		case DF_Type::viewscreen_dungeon_monsterstatusst: return "viewscreen_dungeon_monsterstatusst";
		case DF_Type::viewscreen_dungeon_wrestlest: return "viewscreen_dungeon_wrestlest";
		case DF_Type::viewscreen_dungeon_wrestlest__T_unk1: return "viewscreen_dungeon_wrestlest__T_unk1";
		case DF_Type::viewscreen_dungeonmodest: return "viewscreen_dungeonmodest";
		case DF_Type::viewscreen_dwarfmodest: return "viewscreen_dwarfmodest";
		case DF_Type::viewscreen_entityst: return "viewscreen_entityst";
		case DF_Type::viewscreen_export_graphical_mapst: return "viewscreen_export_graphical_mapst";
		case DF_Type::viewscreen_export_graphical_mapst__T_rgb_buffer: return "viewscreen_export_graphical_mapst__T_rgb_buffer";
		case DF_Type::viewscreen_export_regionst: return "viewscreen_export_regionst";
		case DF_Type::viewscreen_export_regionst__T_unk1: return "viewscreen_export_regionst__T_unk1";
		case DF_Type::viewscreen_game_cleanerst: return "viewscreen_game_cleanerst";
		case DF_Type::viewscreen_game_cleanerst__T_state: return "viewscreen_game_cleanerst__T_state";
		case DF_Type::viewscreen_image_creator_mode: return "viewscreen_image_creator_mode";
		case DF_Type::viewscreen_image_creatorst: return "viewscreen_image_creatorst";
		case DF_Type::viewscreen_image_creatorst__T_artifacts: return "viewscreen_image_creatorst__T_artifacts";
		case DF_Type::viewscreen_image_creatorst__T_entities: return "viewscreen_image_creatorst__T_entities";
		case DF_Type::viewscreen_image_creatorst__T_histfigs: return "viewscreen_image_creatorst__T_histfigs";
		case DF_Type::viewscreen_image_creatorst__T_objects: return "viewscreen_image_creatorst__T_objects";
		case DF_Type::viewscreen_image_creatorst__T_plants: return "viewscreen_image_creatorst__T_plants";
		case DF_Type::viewscreen_image_creatorst__T_relationships: return "viewscreen_image_creatorst__T_relationships";
		case DF_Type::viewscreen_image_creatorst__T_shapes: return "viewscreen_image_creatorst__T_shapes";
		case DF_Type::viewscreen_image_creatorst__T_sites: return "viewscreen_image_creatorst__T_sites";
		case DF_Type::viewscreen_image_creatorst__T_trees: return "viewscreen_image_creatorst__T_trees";
		case DF_Type::viewscreen_itemst: return "viewscreen_itemst";
		case DF_Type::viewscreen_joblistst: return "viewscreen_joblistst";
		case DF_Type::viewscreen_jobmanagementst: return "viewscreen_jobmanagementst";
		case DF_Type::viewscreen_jobst: return "viewscreen_jobst";
		case DF_Type::viewscreen_justicest: return "viewscreen_justicest";
		case DF_Type::viewscreen_justicest__T_cur_column: return "viewscreen_justicest__T_cur_column";
		case DF_Type::viewscreen_justicest__T_interrogate_status: return "viewscreen_justicest__T_interrogate_status";
		case DF_Type::viewscreen_kitchenpref_page: return "viewscreen_kitchenpref_page";
		case DF_Type::viewscreen_kitchenprefst: return "viewscreen_kitchenprefst";
		case DF_Type::viewscreen_layer: return "viewscreen_layer";
		case DF_Type::viewscreen_layer_arena_creaturest: return "viewscreen_layer_arena_creaturest";
		case DF_Type::viewscreen_layer_assigntradest: return "viewscreen_layer_assigntradest";
		case DF_Type::viewscreen_layer_choose_language_namest: return "viewscreen_layer_choose_language_namest";
		case DF_Type::viewscreen_layer_choose_language_namest__T_current_component: return "viewscreen_layer_choose_language_namest__T_current_component";
		case DF_Type::viewscreen_layer_currencyst: return "viewscreen_layer_currencyst";
		case DF_Type::viewscreen_layer_export_play_mapst: return "viewscreen_layer_export_play_mapst";
		case DF_Type::viewscreen_layer_militaryst: return "viewscreen_layer_militaryst";
		case DF_Type::viewscreen_layer_militaryst__T_ammo: return "viewscreen_layer_militaryst__T_ammo";
		case DF_Type::viewscreen_layer_militaryst__T_ammo__T_add_item: return "viewscreen_layer_militaryst__T_ammo__T_add_item";
		case DF_Type::viewscreen_layer_militaryst__T_ammo__T_material: return "viewscreen_layer_militaryst__T_ammo__T_material";
		case DF_Type::viewscreen_layer_militaryst__T_equip: return "viewscreen_layer_militaryst__T_equip";
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_add_item: return "viewscreen_layer_militaryst__T_equip__T_add_item";
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_assigned: return "viewscreen_layer_militaryst__T_equip__T_assigned";
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_color: return "viewscreen_layer_militaryst__T_equip__T_color";
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_edit_mode: return "viewscreen_layer_militaryst__T_equip__T_edit_mode";
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_material: return "viewscreen_layer_militaryst__T_equip__T_material";
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_mode: return "viewscreen_layer_militaryst__T_equip__T_mode";
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_uniform: return "viewscreen_layer_militaryst__T_equip__T_uniform";
		case DF_Type::viewscreen_layer_militaryst__T_page: return "viewscreen_layer_militaryst__T_page";
		case DF_Type::viewscreen_layer_militaryst__T_positions: return "viewscreen_layer_militaryst__T_positions";
		case DF_Type::viewscreen_layer_militaryst__T_squad_members: return "viewscreen_layer_militaryst__T_squad_members";
		case DF_Type::viewscreen_layer_militaryst__T_squads: return "viewscreen_layer_militaryst__T_squads";
		case DF_Type::viewscreen_layer_musicsoundst: return "viewscreen_layer_musicsoundst";
		case DF_Type::viewscreen_layer_noblelistst: return "viewscreen_layer_noblelistst";
		case DF_Type::viewscreen_layer_noblelistst__T_candidates: return "viewscreen_layer_noblelistst__T_candidates";
		case DF_Type::viewscreen_layer_noblelistst__T_info: return "viewscreen_layer_noblelistst__T_info";
		case DF_Type::viewscreen_layer_noblelistst__T_mode: return "viewscreen_layer_noblelistst__T_mode";
		case DF_Type::viewscreen_layer_overall_healthst: return "viewscreen_layer_overall_healthst";
		case DF_Type::viewscreen_layer_reactionst: return "viewscreen_layer_reactionst";
		case DF_Type::viewscreen_layer_squad_schedulest: return "viewscreen_layer_squad_schedulest";
		case DF_Type::viewscreen_layer_stockpilest: return "viewscreen_layer_stockpilest";
		case DF_Type::viewscreen_layer_stone_restrictionst: return "viewscreen_layer_stone_restrictionst";
		case DF_Type::viewscreen_layer_unit_actionst: return "viewscreen_layer_unit_actionst";
		case DF_Type::viewscreen_layer_unit_healthst: return "viewscreen_layer_unit_healthst";
		case DF_Type::viewscreen_layer_unit_relationshipst: return "viewscreen_layer_unit_relationshipst";
		case DF_Type::viewscreen_layer_world_gen_param_presetst: return "viewscreen_layer_world_gen_param_presetst";
		case DF_Type::viewscreen_layer_world_gen_paramst: return "viewscreen_layer_world_gen_paramst";
		case DF_Type::viewscreen_layer_world_gen_paramst__T_unk1: return "viewscreen_layer_world_gen_paramst__T_unk1";
		case DF_Type::viewscreen_legendsst: return "viewscreen_legendsst";
		case DF_Type::viewscreen_legendsst__T_anon_7: return "viewscreen_legendsst__T_anon_7";
		case DF_Type::viewscreen_legendsst__T_anon_7__T_anon_3: return "viewscreen_legendsst__T_anon_7__T_anon_3";
		case DF_Type::viewscreen_legendsst__T_cur_page: return "viewscreen_legendsst__T_cur_page";
		case DF_Type::viewscreen_loadgamest: return "viewscreen_loadgamest";
		case DF_Type::viewscreen_loadgamest__T_cur_step: return "viewscreen_loadgamest__T_cur_step";
		case DF_Type::viewscreen_locationsst: return "viewscreen_locationsst";
		case DF_Type::viewscreen_locationsst__T_in_edit: return "viewscreen_locationsst__T_in_edit";
		case DF_Type::viewscreen_locationsst__T_menu: return "viewscreen_locationsst__T_menu";
		case DF_Type::viewscreen_meetingst: return "viewscreen_meetingst";
		case DF_Type::viewscreen_movieplayerst: return "viewscreen_movieplayerst";
		case DF_Type::viewscreen_new_regionst: return "viewscreen_new_regionst";
		case DF_Type::viewscreen_new_regionst__T_worldgen_presets: return "viewscreen_new_regionst__T_worldgen_presets";
		case DF_Type::viewscreen_noblest: return "viewscreen_noblest";
		case DF_Type::viewscreen_optionst: return "viewscreen_optionst";
		case DF_Type::viewscreen_optionst__T_options: return "viewscreen_optionst__T_options";
		case DF_Type::viewscreen_overallstatusst: return "viewscreen_overallstatusst";
		case DF_Type::viewscreen_overallstatusst__T_visible_pages: return "viewscreen_overallstatusst__T_visible_pages";
		case DF_Type::viewscreen_petitionsst: return "viewscreen_petitionsst";
		case DF_Type::viewscreen_petst: return "viewscreen_petst";
		case DF_Type::viewscreen_petst__T_animal: return "viewscreen_petst__T_animal";
		case DF_Type::viewscreen_petst__T_mode: return "viewscreen_petst__T_mode";
		case DF_Type::viewscreen_petst__T_trainer_mode: return "viewscreen_petst__T_trainer_mode";
		case DF_Type::viewscreen_pricest: return "viewscreen_pricest";
		case DF_Type::viewscreen_reportlistst: return "viewscreen_reportlistst";
		case DF_Type::viewscreen_requestagreementst: return "viewscreen_requestagreementst";
		case DF_Type::viewscreen_savegamest: return "viewscreen_savegamest";
		case DF_Type::viewscreen_selectitemst: return "viewscreen_selectitemst";
		case DF_Type::viewscreen_setupadventurest: return "viewscreen_setupadventurest";
		case DF_Type::viewscreen_setupadventurest__T_page: return "viewscreen_setupadventurest__T_page";
		case DF_Type::viewscreen_setupadventurest__T_races_info: return "viewscreen_setupadventurest__T_races_info";
		case DF_Type::viewscreen_setupadventurest__T_status: return "viewscreen_setupadventurest__T_status";
		case DF_Type::viewscreen_setupdwarfgamest: return "viewscreen_setupdwarfgamest";
		case DF_Type::viewscreen_setupdwarfgamest__T_animals: return "viewscreen_setupdwarfgamest__T_animals";
		case DF_Type::viewscreen_setupdwarfgamest__T_choice_types: return "viewscreen_setupdwarfgamest__T_choice_types";
		case DF_Type::viewscreen_setupdwarfgamest__T_mode: return "viewscreen_setupdwarfgamest__T_mode";
		case DF_Type::viewscreen_setupdwarfgamest__T_unk_v43: return "viewscreen_setupdwarfgamest__T_unk_v43";
		case DF_Type::viewscreen_setupdwarfgamest__T_unk_v43__T_unk_v43_sub9: return "viewscreen_setupdwarfgamest__T_unk_v43__T_unk_v43_sub9";
		case DF_Type::viewscreen_storesst: return "viewscreen_storesst";
		case DF_Type::viewscreen_textviewerst: return "viewscreen_textviewerst";
		case DF_Type::viewscreen_textviewerst__T_formatted_text: return "viewscreen_textviewerst__T_formatted_text";
		case DF_Type::viewscreen_textviewerst__T_formatted_text__T_flags: return "viewscreen_textviewerst__T_formatted_text__T_flags";
		case DF_Type::viewscreen_titlest: return "viewscreen_titlest";
		case DF_Type::viewscreen_titlest__T_menu_line_id: return "viewscreen_titlest__T_menu_line_id";
		case DF_Type::viewscreen_titlest__T_sel_subpage: return "viewscreen_titlest__T_sel_subpage";
		case DF_Type::viewscreen_titlest__T_start_savegames: return "viewscreen_titlest__T_start_savegames";
		case DF_Type::viewscreen_topicmeeting_fill_land_holder_positionsst: return "viewscreen_topicmeeting_fill_land_holder_positionsst";
		case DF_Type::viewscreen_topicmeeting_takerequestsst: return "viewscreen_topicmeeting_takerequestsst";
		case DF_Type::viewscreen_topicmeetingst: return "viewscreen_topicmeetingst";
		case DF_Type::viewscreen_tradeagreementst: return "viewscreen_tradeagreementst";
		case DF_Type::viewscreen_tradegoodsst: return "viewscreen_tradegoodsst";
		case DF_Type::viewscreen_tradelistst: return "viewscreen_tradelistst";
		case DF_Type::viewscreen_treasurelistst: return "viewscreen_treasurelistst";
		case DF_Type::viewscreen_unitlist_page: return "viewscreen_unitlist_page";
		case DF_Type::viewscreen_unitlistst: return "viewscreen_unitlistst";
		case DF_Type::viewscreen_unitst: return "viewscreen_unitst";
		case DF_Type::viewscreen_update_regionst: return "viewscreen_update_regionst";
		case DF_Type::viewscreen_wagesst: return "viewscreen_wagesst";
		case DF_Type::viewscreen_workquota_conditionst: return "viewscreen_workquota_conditionst";
		case DF_Type::viewscreen_workquota_conditionst__T_mode: return "viewscreen_workquota_conditionst__T_mode";
		case DF_Type::viewscreen_workquota_conditionst__T_traits: return "viewscreen_workquota_conditionst__T_traits";
		case DF_Type::viewscreen_workquota_conditionst__T_traits__T_flags: return "viewscreen_workquota_conditionst__T_traits__T_flags";
		case DF_Type::viewscreen_workquota_detailsst: return "viewscreen_workquota_detailsst";
		case DF_Type::viewscreen_workshop_profilest: return "viewscreen_workshop_profilest";
		case DF_Type::viewscreen_workshop_profilest__T_tab: return "viewscreen_workshop_profilest__T_tab";
		case DF_Type::weapon_attack: return "weapon_attack";
		case DF_Type::weapon_attack__T_flags: return "weapon_attack__T_flags";
		case DF_Type::weapon_flags: return "weapon_flags";
		case DF_Type::weather_type: return "weather_type";
		case DF_Type::web_cluster: return "web_cluster";
		case DF_Type::whereabouts_type: return "whereabouts_type";
		case DF_Type::widget_menu: return "widget_menu";
		case DF_Type::widget_textbox: return "widget_textbox";
		case DF_Type::workshop_profile: return "workshop_profile";
		case DF_Type::workshop_type: return "workshop_type";
		case DF_Type::world: return "world";
		case DF_Type::world__T_activities: return "world__T_activities";
		case DF_Type::world__T_agreements: return "world__T_agreements";
		case DF_Type::world__T_area_grasses: return "world__T_area_grasses";
		case DF_Type::world__T_area_grasses__T_layer_grasses: return "world__T_area_grasses__T_layer_grasses";
		case DF_Type::world__T_arena_settings: return "world__T_arena_settings";
		case DF_Type::world__T_arena_spawn: return "world__T_arena_spawn";
		case DF_Type::world__T_arena_spawn__T_equipment: return "world__T_arena_spawn__T_equipment";
		case DF_Type::world__T_arena_spawn__T_item_types: return "world__T_arena_spawn__T_item_types";
		case DF_Type::world__T_arena_spawn__T_tame: return "world__T_arena_spawn__T_tame";
		case DF_Type::world__T_armies: return "world__T_armies";
		case DF_Type::world__T_army_controllers: return "world__T_army_controllers";
		case DF_Type::world__T_army_tracking_info: return "world__T_army_tracking_info";
		case DF_Type::world__T_artifacts: return "world__T_artifacts";
		case DF_Type::world__T_belief_systems: return "world__T_belief_systems";
		case DF_Type::world__T_crimes: return "world__T_crimes";
		case DF_Type::world__T_cultural_identities: return "world__T_cultural_identities";
		case DF_Type::world__T_cur_savegame: return "world__T_cur_savegame";
		case DF_Type::world__T_dance_forms: return "world__T_dance_forms";
		case DF_Type::world__T_divination_sets: return "world__T_divination_sets";
		case DF_Type::world__T_enemy_status_cache: return "world__T_enemy_status_cache";
		case DF_Type::world__T_entities: return "world__T_entities";
		case DF_Type::world__T_features: return "world__T_features";
		case DF_Type::world__T_flow_engine: return "world__T_flow_engine";
		case DF_Type::world__T_flow_guides: return "world__T_flow_guides";
		case DF_Type::world__T_formations: return "world__T_formations";
		case DF_Type::world__T_identities: return "world__T_identities";
		case DF_Type::world__T_image_sets: return "world__T_image_sets";
		case DF_Type::world__T_image_sets__T_all: return "world__T_image_sets__T_all";
		case DF_Type::world__T_image_sets__T_all__T_anon_3: return "world__T_image_sets__T_all__T_anon_3";
		case DF_Type::world__T_incidents: return "world__T_incidents";
		case DF_Type::world__T_interaction_instances: return "world__T_interaction_instances";
		case DF_Type::world__T_items: return "world__T_items";
		case DF_Type::world__T_languages: return "world__T_languages";
		case DF_Type::world__T_map: return "world__T_map";
		case DF_Type::world__T_map_extras: return "world__T_map_extras";
		case DF_Type::world__T_math: return "world__T_math";
		case DF_Type::world__T_math__T_approx: return "world__T_math__T_approx";
		case DF_Type::world__T_musical_forms: return "world__T_musical_forms";
		case DF_Type::world__T_nemesis: return "world__T_nemesis";
		case DF_Type::world__T_occupations: return "world__T_occupations";
		case DF_Type::world__T_pathfinder: return "world__T_pathfinder";
		case DF_Type::world__T_pathfinder__T_boundary_heap: return "world__T_pathfinder__T_boundary_heap";
		case DF_Type::world__T_plants: return "world__T_plants";
		case DF_Type::world__T_poetic_forms: return "world__T_poetic_forms";
		case DF_Type::world__T_profession_skills: return "world__T_profession_skills";
		case DF_Type::world__T_rhythms: return "world__T_rhythms";
		case DF_Type::world__T_scales: return "world__T_scales";
		case DF_Type::world__T_schedules: return "world__T_schedules";
		case DF_Type::world__T_squads: return "world__T_squads";
		case DF_Type::world__T_status: return "world__T_status";
		case DF_Type::world__T_status__T_flags: return "world__T_status__T_flags";
		case DF_Type::world__T_status__T_slots: return "world__T_status__T_slots";
		case DF_Type::world__T_status__T_slots__T_flags: return "world__T_status__T_slots__T_flags";
		case DF_Type::world__T_stockpile: return "world__T_stockpile";
		case DF_Type::world__T_stockpile__T_simple1: return "world__T_stockpile__T_simple1";
		case DF_Type::world__T_stockpile__T_simple2: return "world__T_stockpile__T_simple2";
		case DF_Type::world__T_stockpile__T_simple3: return "world__T_stockpile__T_simple3";
		case DF_Type::world__T_units: return "world__T_units";
		case DF_Type::world__T_unk_131ec0: return "world__T_unk_131ec0";
		case DF_Type::world__T_unk_131ef0: return "world__T_unk_131ef0";
		case DF_Type::world__T_unk_131ef0__T_claims: return "world__T_unk_131ef0__T_claims";
		case DF_Type::world__T_unk_19325c: return "world__T_unk_19325c";
		case DF_Type::world__T_unk_19325c__T_anon_1: return "world__T_unk_19325c__T_anon_1";
		case DF_Type::world__T_unk_19325c__T_anon_2: return "world__T_unk_19325c__T_anon_2";
		case DF_Type::world__T_unk_19325c__T_anon_3: return "world__T_unk_19325c__T_anon_3";
		case DF_Type::world__T_unk_26c678: return "world__T_unk_26c678";
		case DF_Type::world__T_unk_v40_6: return "world__T_unk_v40_6";
		case DF_Type::world__T_vehicles: return "world__T_vehicles";
		case DF_Type::world__T_vermin: return "world__T_vermin";
		case DF_Type::world__T_worldgen: return "world__T_worldgen";
		case DF_Type::world__T_worldgen__T_worldgen_parms: return "world__T_worldgen__T_worldgen_parms";
		case DF_Type::world__T_worldgen_coord_buf: return "world__T_worldgen_coord_buf";
		case DF_Type::world__T_worldgen_status: return "world__T_worldgen_status";
		case DF_Type::world__T_written_contents: return "world__T_written_contents";
		case DF_Type::world_construction: return "world_construction";
		case DF_Type::world_construction_bridgest: return "world_construction_bridgest";
		case DF_Type::world_construction_roadst: return "world_construction_roadst";
		case DF_Type::world_construction_square: return "world_construction_square";
		case DF_Type::world_construction_square_bridgest: return "world_construction_square_bridgest";
		case DF_Type::world_construction_square_roadst: return "world_construction_square_roadst";
		case DF_Type::world_construction_square_tunnelst: return "world_construction_square_tunnelst";
		case DF_Type::world_construction_square_wallst: return "world_construction_square_wallst";
		case DF_Type::world_construction_tunnelst: return "world_construction_tunnelst";
		case DF_Type::world_construction_type: return "world_construction_type";
		case DF_Type::world_construction_wallst: return "world_construction_wallst";
		case DF_Type::world_dat_summary: return "world_dat_summary";
		case DF_Type::world_data: return "world_data";
		case DF_Type::world_data__T_constructions: return "world_data__T_constructions";
		case DF_Type::world_data__T_feature_map: return "world_data__T_feature_map";
		case DF_Type::world_data__T_feature_map__T_features: return "world_data__T_feature_map__T_features";
		case DF_Type::world_data__T_field_battles: return "world_data__T_field_battles";
		case DF_Type::world_data__T_field_battles__T_sapient_deaths: return "world_data__T_field_battles__T_sapient_deaths";
		case DF_Type::world_data__T_flip_latitude: return "world_data__T_flip_latitude";
		case DF_Type::world_data__T_freakish_weather: return "world_data__T_freakish_weather";
		case DF_Type::world_data__T_mountain_peaks: return "world_data__T_mountain_peaks";
		case DF_Type::world_data__T_unk_150: return "world_data__T_unk_150";
		case DF_Type::world_data__T_unk_150__T_unk_18: return "world_data__T_unk_150__T_unk_18";
		case DF_Type::world_data__T_unk_150__T_unk_28: return "world_data__T_unk_150__T_unk_28";
		case DF_Type::world_data__T_unk_150__T_unk_8: return "world_data__T_unk_150__T_unk_8";
		case DF_Type::world_data__T_unk_274: return "world_data__T_unk_274";
		case DF_Type::world_data__T_unk_274__T_unk_10: return "world_data__T_unk_274__T_unk_10";
		case DF_Type::world_data__T_unk_482f8: return "world_data__T_unk_482f8";
		case DF_Type::world_data__T_unk_b4: return "world_data__T_unk_b4";
		case DF_Type::world_gen_param_basest: return "world_gen_param_basest";
		case DF_Type::world_gen_param_charst: return "world_gen_param_charst";
		case DF_Type::world_gen_param_memberst: return "world_gen_param_memberst";
		case DF_Type::world_gen_param_seedst: return "world_gen_param_seedst";
		case DF_Type::world_gen_param_valuest: return "world_gen_param_valuest";
		case DF_Type::world_geo_biome: return "world_geo_biome";
		case DF_Type::world_geo_layer: return "world_geo_layer";
		case DF_Type::world_history: return "world_history";
		case DF_Type::world_history__T_event_collections: return "world_history__T_event_collections";
		case DF_Type::world_history__T_intrigues: return "world_history__T_intrigues";
		case DF_Type::world_history__T_intrigues__T_anon_1: return "world_history__T_intrigues__T_anon_1";
		case DF_Type::world_landmass: return "world_landmass";
		case DF_Type::world_object_data: return "world_object_data";
		case DF_Type::world_object_data__T_offloaded_buildings: return "world_object_data__T_offloaded_buildings";
		case DF_Type::world_object_data__T_offloaded_items: return "world_object_data__T_offloaded_items";
		case DF_Type::world_object_data__T_unk_94: return "world_object_data__T_unk_94";
		case DF_Type::world_population: return "world_population";
		case DF_Type::world_population___union4: return "world_population___union4";
		case DF_Type::world_population_ref: return "world_population_ref";
		case DF_Type::world_population_type: return "world_population_type";
		case DF_Type::world_raws: return "world_raws";
		case DF_Type::world_raws__T_bodyglosses: return "world_raws__T_bodyglosses";
		case DF_Type::world_raws__T_buildings: return "world_raws__T_buildings";
		case DF_Type::world_raws__T_descriptors: return "world_raws__T_descriptors";
		case DF_Type::world_raws__T_effects: return "world_raws__T_effects";
		case DF_Type::world_raws__T_itemdefs: return "world_raws__T_itemdefs";
		case DF_Type::world_raws__T_language: return "world_raws__T_language";
		case DF_Type::world_raws__T_plants: return "world_raws__T_plants";
		case DF_Type::world_raws__T_reactions: return "world_raws__T_reactions";
		case DF_Type::world_raws__T_syndromes: return "world_raws__T_syndromes";
		case DF_Type::world_region: return "world_region";
		case DF_Type::world_region_details: return "world_region_details";
		case DF_Type::world_region_details__T_edges: return "world_region_details__T_edges";
		case DF_Type::world_region_details__T_other_features: return "world_region_details__T_other_features";
		case DF_Type::world_region_details__T_rivers_horizontal: return "world_region_details__T_rivers_horizontal";
		case DF_Type::world_region_details__T_rivers_vertical: return "world_region_details__T_rivers_vertical";
		case DF_Type::world_region_feature: return "world_region_feature";
		case DF_Type::world_region_type: return "world_region_type";
		case DF_Type::world_river: return "world_river";
		case DF_Type::world_site: return "world_site";
		case DF_Type::world_site__T_subtype_info: return "world_site__T_subtype_info";
		case DF_Type::world_site__T_unk_1: return "world_site__T_unk_1";
		case DF_Type::world_site__T_unk_118: return "world_site__T_unk_118";
		case DF_Type::world_site__T_unk_13c: return "world_site__T_unk_13c";
		case DF_Type::world_site__T_unk_188: return "world_site__T_unk_188";
		case DF_Type::world_site__T_unk_188__T_unk1: return "world_site__T_unk_188__T_unk1";
		case DF_Type::world_site__T_unk_1__T_units: return "world_site__T_unk_1__T_units";
		case DF_Type::world_site__T_unk_21c: return "world_site__T_unk_21c";
		case DF_Type::world_site__T_unk_v40_2: return "world_site__T_unk_v40_2";
		case DF_Type::world_site__T_unk_v40_4a: return "world_site__T_unk_v40_4a";
		case DF_Type::world_site__T_unk_v40_4b: return "world_site__T_unk_v40_4b";
		case DF_Type::world_site__T_unk_v40_4c: return "world_site__T_unk_v40_4c";
		case DF_Type::world_site__T_unk_v40_4d: return "world_site__T_unk_v40_4d";
		case DF_Type::world_site__T_unk_v40_4d__T_anon_1: return "world_site__T_unk_v40_4d__T_anon_1";
		case DF_Type::world_site__T_unk_v43_2: return "world_site__T_unk_v43_2";
		case DF_Type::world_site__T_unk_v47_1: return "world_site__T_unk_v47_1";
		case DF_Type::world_site__T_unk_v47_1__T_unk_1: return "world_site__T_unk_v47_1__T_unk_1";
		case DF_Type::world_site_flags: return "world_site_flags";
		case DF_Type::world_site_inhabitant: return "world_site_inhabitant";
		case DF_Type::world_site_realization: return "world_site_realization";
		case DF_Type::world_site_realization__T_areas: return "world_site_realization__T_areas";
		case DF_Type::world_site_realization__T_areas__T_type: return "world_site_realization__T_areas__T_type";
		case DF_Type::world_site_realization__T_building_map: return "world_site_realization__T_building_map";
		case DF_Type::world_site_realization__T_river_map: return "world_site_realization__T_river_map";
		case DF_Type::world_site_realization__T_unk_193bc: return "world_site_realization__T_unk_193bc";
		case DF_Type::world_site_realization__T_unk_193bc__T_unk_8: return "world_site_realization__T_unk_193bc__T_unk_8";
		case DF_Type::world_site_realization__T_unk_55e8: return "world_site_realization__T_unk_55e8";
		case DF_Type::world_site_realization__T_unk_55e8__T_unk_v40_2: return "world_site_realization__T_unk_55e8__T_unk_v40_2";
		case DF_Type::world_site_type: return "world_site_type";
		case DF_Type::world_site_unk130: return "world_site_unk130";
		case DF_Type::world_site_unk130__T_unk_4: return "world_site_unk130__T_unk_4";
		case DF_Type::world_underground_region: return "world_underground_region";
		case DF_Type::world_underground_region__T_type: return "world_underground_region__T_type";
		case DF_Type::world_unk26c678_unk38: return "world_unk26c678_unk38";
		case DF_Type::world_unk_20: return "world_unk_20";
		case DF_Type::world_unk_20__T_anon_7: return "world_unk_20__T_anon_7";
		case DF_Type::world_unk_6c: return "world_unk_6c";
		case DF_Type::world_unk_a8: return "world_unk_a8";
		case DF_Type::world_unk_b4: return "world_unk_b4";
		case DF_Type::world_unk_c0: return "world_unk_c0";
		case DF_Type::world_unk_c0__T_anon_7: return "world_unk_c0__T_anon_7";
		case DF_Type::worldgen_range_type: return "worldgen_range_type";
		case DF_Type::worldgen_region_type: return "worldgen_region_type";
		case DF_Type::wound_curse_info: return "wound_curse_info";
		case DF_Type::wound_damage_flags1: return "wound_damage_flags1";
		case DF_Type::wound_damage_flags2: return "wound_damage_flags2";
		case DF_Type::wound_effect_type: return "wound_effect_type";
		case DF_Type::written_content: return "written_content";
		case DF_Type::written_content_style: return "written_content_style";
		case DF_Type::written_content_type: return "written_content_type";
		case DF_Type::z_level_flags: return "z_level_flags";
		case DF_Type::zoom_commands: return "zoom_commands";
	}
	return "";
}

static std::map<std::string,DF_Type> translation_table =
{
    { "None"         , DF_Type::None          },
    { "int64_t"      , DF_Type::int64_t       },
    { "uint64_t"     , DF_Type::uint64_t      },
    { "int32_t"      , DF_Type::int32_t       },
    { "int16_t"      , DF_Type::int16_t       },
    { "uint32_t"     , DF_Type::uint32_t      },
    { "uint16_t"     , DF_Type::uint16_t      },
    { "uint8_t"      , DF_Type::uint8_t       },
    { "int8_t"       , DF_Type::int8_t        },
    { "Void"         , DF_Type::Void          },
    { "void"         , DF_Type::Void          },
    { "Char"         , DF_Type::Char          },
    { "char"         , DF_Type::Char          },
    { "Long"         , DF_Type::Long          },
    { "long"         , DF_Type::Long          },
    { "Bool"         , DF_Type::Bool          },
    { "bool"         , DF_Type::Bool          },
    { "Stl_string"   , DF_Type::Stl_string    },
    { "stl_string"   , DF_Type::Stl_string    },
    { "Static_string", DF_Type::Static_string },
    { "static_string", DF_Type::Static_string },
    { "Ptr_string"   , DF_Type::Ptr_string    },
    { "ptr_string"   , DF_Type::Ptr_string    },
    { "S_float"      , DF_Type::S_float       },
    { "s_float"      , DF_Type::S_float       },
    { "D_float"      , DF_Type::D_float       },
    { "d_float"      , DF_Type::D_float       },
    { "S_double"     , DF_Type::S_double      },
    { "s_double"     , DF_Type::S_double      },
    { "Padding"      , DF_Type::Padding       },
    { "padding"      , DF_Type::Padding       },
    { "Stl_fstream"  , DF_Type::Stl_fstream   },
    { "stl_fstream"  , DF_Type::Stl_fstream   },
	{ "abstract_building", DF_Type::abstract_building },
	{ "abstract_building__T_inhabitants", DF_Type::abstract_building__T_inhabitants },
	{ "abstract_building__T_unk1", DF_Type::abstract_building__T_unk1 },
	{ "abstract_building_contents", DF_Type::abstract_building_contents },
	{ "abstract_building_counting_housest", DF_Type::abstract_building_counting_housest },
	{ "abstract_building_dark_towerst", DF_Type::abstract_building_dark_towerst },
	{ "abstract_building_dungeonst", DF_Type::abstract_building_dungeonst },
	{ "abstract_building_dungeonst__T_dungeon_type", DF_Type::abstract_building_dungeonst__T_dungeon_type },
	{ "abstract_building_flags", DF_Type::abstract_building_flags },
	{ "abstract_building_guildhallst", DF_Type::abstract_building_guildhallst },
	{ "abstract_building_inn_tavernst", DF_Type::abstract_building_inn_tavernst },
	{ "abstract_building_inn_tavernst__T_room_info", DF_Type::abstract_building_inn_tavernst__T_room_info },
	{ "abstract_building_keepst", DF_Type::abstract_building_keepst },
	{ "abstract_building_libraryst", DF_Type::abstract_building_libraryst },
	{ "abstract_building_marketst", DF_Type::abstract_building_marketst },
	{ "abstract_building_mead_hallst", DF_Type::abstract_building_mead_hallst },
	{ "abstract_building_templest", DF_Type::abstract_building_templest },
	{ "abstract_building_tombst", DF_Type::abstract_building_tombst },
	{ "abstract_building_towerst", DF_Type::abstract_building_towerst },
	{ "abstract_building_type", DF_Type::abstract_building_type },
	{ "abstract_building_underworld_spirest", DF_Type::abstract_building_underworld_spirest },
	{ "abstract_building_unk", DF_Type::abstract_building_unk },
	{ "abstract_building_unk__T_anon_1", DF_Type::abstract_building_unk__T_anon_1 },
	{ "active_script_var_longst", DF_Type::active_script_var_longst },
	{ "active_script_var_unitst", DF_Type::active_script_var_unitst },
	{ "active_script_varst", DF_Type::active_script_varst },
	{ "activity_entry", DF_Type::activity_entry },
	{ "activity_entry_type", DF_Type::activity_entry_type },
	{ "activity_event", DF_Type::activity_event },
	{ "activity_event__T_flags", DF_Type::activity_event__T_flags },
	{ "activity_event__T_unk_v42_1", DF_Type::activity_event__T_unk_v42_1 },
	{ "activity_event__T_unk_v42_2", DF_Type::activity_event__T_unk_v42_2 },
	{ "activity_event_combat_trainingst", DF_Type::activity_event_combat_trainingst },
	{ "activity_event_conflictst", DF_Type::activity_event_conflictst },
	{ "activity_event_conflictst__T_sides", DF_Type::activity_event_conflictst__T_sides },
	{ "activity_event_conflictst__T_sides__T_enemies", DF_Type::activity_event_conflictst__T_sides__T_enemies },
	{ "activity_event_conversationst", DF_Type::activity_event_conversationst },
	{ "activity_event_conversationst__T_anon_6", DF_Type::activity_event_conversationst__T_anon_6 },
	{ "activity_event_conversationst__T_flags2", DF_Type::activity_event_conversationst__T_flags2 },
	{ "activity_event_conversationst__T_participants", DF_Type::activity_event_conversationst__T_participants },
	{ "activity_event_conversationst__T_turns", DF_Type::activity_event_conversationst__T_turns },
	{ "activity_event_conversationst__T_unk2", DF_Type::activity_event_conversationst__T_unk2 },
	{ "activity_event_conversationst__T_unk_b4", DF_Type::activity_event_conversationst__T_unk_b4 },
	{ "activity_event_copy_written_contentst", DF_Type::activity_event_copy_written_contentst },
	{ "activity_event_copy_written_contentst__T_flagsmaybe", DF_Type::activity_event_copy_written_contentst__T_flagsmaybe },
	{ "activity_event_discuss_topicst", DF_Type::activity_event_discuss_topicst },
	{ "activity_event_encounterst", DF_Type::activity_event_encounterst },
	{ "activity_event_encounterst__T_anon_1", DF_Type::activity_event_encounterst__T_anon_1 },
	{ "activity_event_encounterst__T_anon_2", DF_Type::activity_event_encounterst__T_anon_2 },
	{ "activity_event_fill_service_orderst", DF_Type::activity_event_fill_service_orderst },
	{ "activity_event_guardst", DF_Type::activity_event_guardst },
	{ "activity_event_harassmentst", DF_Type::activity_event_harassmentst },
	{ "activity_event_harassmentst__T_anon_2", DF_Type::activity_event_harassmentst__T_anon_2 },
	{ "activity_event_individual_skill_drillst", DF_Type::activity_event_individual_skill_drillst },
	{ "activity_event_make_believest", DF_Type::activity_event_make_believest },
	{ "activity_event_participants", DF_Type::activity_event_participants },
	{ "activity_event_performancest", DF_Type::activity_event_performancest },
	{ "activity_event_performancest__T_participant_actions", DF_Type::activity_event_performancest__T_participant_actions },
	{ "activity_event_play_with_toyst", DF_Type::activity_event_play_with_toyst },
	{ "activity_event_play_with_toyst__T_unk", DF_Type::activity_event_play_with_toyst__T_unk },
	{ "activity_event_playst", DF_Type::activity_event_playst },
	{ "activity_event_ponder_topicst", DF_Type::activity_event_ponder_topicst },
	{ "activity_event_prayerst", DF_Type::activity_event_prayerst },
	{ "activity_event_ranged_practicest", DF_Type::activity_event_ranged_practicest },
	{ "activity_event_readst", DF_Type::activity_event_readst },
	{ "activity_event_researchst", DF_Type::activity_event_researchst },
	{ "activity_event_reunionst", DF_Type::activity_event_reunionst },
	{ "activity_event_skill_demonstrationst", DF_Type::activity_event_skill_demonstrationst },
	{ "activity_event_socializest", DF_Type::activity_event_socializest },
	{ "activity_event_sparringst", DF_Type::activity_event_sparringst },
	{ "activity_event_sparringst__T_groups", DF_Type::activity_event_sparringst__T_groups },
	{ "activity_event_store_objectst", DF_Type::activity_event_store_objectst },
	{ "activity_event_teach_topicst", DF_Type::activity_event_teach_topicst },
	{ "activity_event_training_sessionst", DF_Type::activity_event_training_sessionst },
	{ "activity_event_type", DF_Type::activity_event_type },
	{ "activity_event_worshipst", DF_Type::activity_event_worshipst },
	{ "activity_event_writest", DF_Type::activity_event_writest },
	{ "activity_info", DF_Type::activity_info },
	{ "activity_info__T_flags", DF_Type::activity_info__T_flags },
	{ "adventure_environment_ingest_from_containerst", DF_Type::adventure_environment_ingest_from_containerst },
	{ "adventure_environment_ingest_materialst", DF_Type::adventure_environment_ingest_materialst },
	{ "adventure_environment_optionst", DF_Type::adventure_environment_optionst },
	{ "adventure_environment_pickup_chop_treest", DF_Type::adventure_environment_pickup_chop_treest },
	{ "adventure_environment_pickup_ignite_vegst", DF_Type::adventure_environment_pickup_ignite_vegst },
	{ "adventure_environment_pickup_make_campfirest", DF_Type::adventure_environment_pickup_make_campfirest },
	{ "adventure_environment_pickup_vermin_eventst", DF_Type::adventure_environment_pickup_vermin_eventst },
	{ "adventure_environment_place_in_bld_containerst", DF_Type::adventure_environment_place_in_bld_containerst },
	{ "adventure_environment_place_in_it_containerst", DF_Type::adventure_environment_place_in_it_containerst },
	{ "adventure_environment_unit_suck_bloodst", DF_Type::adventure_environment_unit_suck_bloodst },
	{ "adventure_item_interact_choicest", DF_Type::adventure_item_interact_choicest },
	{ "adventure_item_interact_fill_from_containerst", DF_Type::adventure_item_interact_fill_from_containerst },
	{ "adventure_item_interact_fill_with_materialst", DF_Type::adventure_item_interact_fill_with_materialst },
	{ "adventure_item_interact_give_namest", DF_Type::adventure_item_interact_give_namest },
	{ "adventure_item_interact_heat_from_tilest", DF_Type::adventure_item_interact_heat_from_tilest },
	{ "adventure_item_interact_pull_outst", DF_Type::adventure_item_interact_pull_outst },
	{ "adventure_item_interact_readst", DF_Type::adventure_item_interact_readst },
	{ "adventure_item_interact_strugglest", DF_Type::adventure_item_interact_strugglest },
	{ "adventure_log_item", DF_Type::adventure_log_item },
	{ "adventure_movement_attack_creaturest", DF_Type::adventure_movement_attack_creaturest },
	{ "adventure_movement_building_interactst", DF_Type::adventure_movement_building_interactst },
	{ "adventure_movement_climbst", DF_Type::adventure_movement_climbst },
	{ "adventure_movement_hold_itemst", DF_Type::adventure_movement_hold_itemst },
	{ "adventure_movement_hold_tilest", DF_Type::adventure_movement_hold_tilest },
	{ "adventure_movement_item_interact_guidest", DF_Type::adventure_movement_item_interact_guidest },
	{ "adventure_movement_item_interact_pushst", DF_Type::adventure_movement_item_interact_pushst },
	{ "adventure_movement_item_interact_ridest", DF_Type::adventure_movement_item_interact_ridest },
	{ "adventure_movement_item_interactst", DF_Type::adventure_movement_item_interactst },
	{ "adventure_movement_movest", DF_Type::adventure_movement_movest },
	{ "adventure_movement_optionst", DF_Type::adventure_movement_optionst },
	{ "adventure_movement_release_hold_itemst", DF_Type::adventure_movement_release_hold_itemst },
	{ "adventure_movement_release_hold_tilest", DF_Type::adventure_movement_release_hold_tilest },
	{ "adventure_option_eat_item_contaminantst", DF_Type::adventure_option_eat_item_contaminantst },
	{ "adventure_option_eat_unit_contaminantst", DF_Type::adventure_option_eat_unit_contaminantst },
	{ "adventure_option_view_contaminantst", DF_Type::adventure_option_view_contaminantst },
	{ "adventure_optionst", DF_Type::adventure_optionst },
	{ "adventurer_attribute_level", DF_Type::adventurer_attribute_level },
	{ "agreement", DF_Type::agreement },
	{ "agreement__T_anon_3", DF_Type::agreement__T_anon_3 },
	{ "agreement_details", DF_Type::agreement_details },
	{ "agreement_details__T_data", DF_Type::agreement_details__T_data },
	{ "agreement_details_data_citizenship", DF_Type::agreement_details_data_citizenship },
	{ "agreement_details_data_demonic_binding", DF_Type::agreement_details_data_demonic_binding },
	{ "agreement_details_data_join_party", DF_Type::agreement_details_data_join_party },
	{ "agreement_details_data_location", DF_Type::agreement_details_data_location },
	{ "agreement_details_data_parley", DF_Type::agreement_details_data_parley },
	{ "agreement_details_data_plot_abduct", DF_Type::agreement_details_data_plot_abduct },
	{ "agreement_details_data_plot_assassination", DF_Type::agreement_details_data_plot_assassination },
	{ "agreement_details_data_plot_conviction", DF_Type::agreement_details_data_plot_conviction },
	{ "agreement_details_data_plot_frame_treason", DF_Type::agreement_details_data_plot_frame_treason },
	{ "agreement_details_data_plot_induce_war", DF_Type::agreement_details_data_plot_induce_war },
	{ "agreement_details_data_plot_infiltration_coup", DF_Type::agreement_details_data_plot_infiltration_coup },
	{ "agreement_details_data_plot_steal_artifact", DF_Type::agreement_details_data_plot_steal_artifact },
	{ "agreement_details_data_position_corruption", DF_Type::agreement_details_data_position_corruption },
	{ "agreement_details_data_promise_position", DF_Type::agreement_details_data_promise_position },
	{ "agreement_details_data_residency", DF_Type::agreement_details_data_residency },
	{ "agreement_details_data_unk10", DF_Type::agreement_details_data_unk10 },
	{ "agreement_details_type", DF_Type::agreement_details_type },
	{ "agreement_party", DF_Type::agreement_party },
	{ "agreement_party__T_anon_1", DF_Type::agreement_party__T_anon_1 },
	{ "ammo_flags", DF_Type::ammo_flags },
	{ "animal_training_level", DF_Type::animal_training_level },
	{ "announcement_flags", DF_Type::announcement_flags },
	{ "announcement_type", DF_Type::announcement_type },
	{ "announcements", DF_Type::announcements },
	{ "appearance_modifier_growth_interval", DF_Type::appearance_modifier_growth_interval },
	{ "appearance_modifier_type", DF_Type::appearance_modifier_type },
	{ "armor_flags", DF_Type::armor_flags },
	{ "armor_general_flags", DF_Type::armor_general_flags },
	{ "armor_properties", DF_Type::armor_properties },
	{ "army", DF_Type::army },
	{ "army__T_members", DF_Type::army__T_members },
	{ "army__T_unk_2c", DF_Type::army__T_unk_2c },
	{ "army_controller", DF_Type::army_controller },
	{ "army_controller__T_type", DF_Type::army_controller__T_type },
	{ "army_controller__T_unk_64", DF_Type::army_controller__T_unk_64 },
	{ "army_controller_sub1", DF_Type::army_controller_sub1 },
	{ "army_controller_sub11", DF_Type::army_controller_sub11 },
	{ "army_controller_sub11__T_anon_3", DF_Type::army_controller_sub11__T_anon_3 },
	{ "army_controller_sub12", DF_Type::army_controller_sub12 },
	{ "army_controller_sub12__T_anon_4", DF_Type::army_controller_sub12__T_anon_4 },
	{ "army_controller_sub13", DF_Type::army_controller_sub13 },
	{ "army_controller_sub13__T_anon_4", DF_Type::army_controller_sub13__T_anon_4 },
	{ "army_controller_sub14", DF_Type::army_controller_sub14 },
	{ "army_controller_sub14__T_anon_4", DF_Type::army_controller_sub14__T_anon_4 },
	{ "army_controller_sub15", DF_Type::army_controller_sub15 },
	{ "army_controller_sub15__T_anon_3", DF_Type::army_controller_sub15__T_anon_3 },
	{ "army_controller_sub16", DF_Type::army_controller_sub16 },
	{ "army_controller_sub17", DF_Type::army_controller_sub17 },
	{ "army_controller_sub18", DF_Type::army_controller_sub18 },
	{ "army_controller_sub2", DF_Type::army_controller_sub2 },
	{ "army_controller_sub24", DF_Type::army_controller_sub24 },
	{ "army_controller_sub2__T_anon_5", DF_Type::army_controller_sub2__T_anon_5 },
	{ "army_controller_sub4", DF_Type::army_controller_sub4 },
	{ "army_controller_sub4__T_unk_2", DF_Type::army_controller_sub4__T_unk_2 },
	{ "army_controller_sub5", DF_Type::army_controller_sub5 },
	{ "army_controller_sub6", DF_Type::army_controller_sub6 },
	{ "army_controller_sub7", DF_Type::army_controller_sub7 },
	{ "army_controller_sub7__T_anon_3", DF_Type::army_controller_sub7__T_anon_3 },
	{ "army_flags", DF_Type::army_flags },
	{ "art_facet_type", DF_Type::art_facet_type },
	{ "art_image", DF_Type::art_image },
	{ "art_image_chunk", DF_Type::art_image_chunk },
	{ "art_image_element", DF_Type::art_image_element },
	{ "art_image_element_creaturest", DF_Type::art_image_element_creaturest },
	{ "art_image_element_itemst", DF_Type::art_image_element_itemst },
	{ "art_image_element_plantst", DF_Type::art_image_element_plantst },
	{ "art_image_element_shapest", DF_Type::art_image_element_shapest },
	{ "art_image_element_treest", DF_Type::art_image_element_treest },
	{ "art_image_element_type", DF_Type::art_image_element_type },
	{ "art_image_property", DF_Type::art_image_property },
	{ "art_image_property_intransitive_verbst", DF_Type::art_image_property_intransitive_verbst },
	{ "art_image_property_transitive_verbst", DF_Type::art_image_property_transitive_verbst },
	{ "art_image_property_type", DF_Type::art_image_property_type },
	{ "art_image_property_verb", DF_Type::art_image_property_verb },
	{ "art_image_ref", DF_Type::art_image_ref },
	{ "artifact_claim", DF_Type::artifact_claim },
	{ "artifact_claim_type", DF_Type::artifact_claim_type },
	{ "artifact_record", DF_Type::artifact_record },
	{ "assign_trade_status", DF_Type::assign_trade_status },
	{ "assign_trade_status__T_status", DF_Type::assign_trade_status__T_status },
	{ "assume_identity_mode", DF_Type::assume_identity_mode },
	{ "barrack_preference_category", DF_Type::barrack_preference_category },
	{ "belief_system", DF_Type::belief_system },
	{ "biome_type", DF_Type::biome_type },
	{ "block_burrow", DF_Type::block_burrow },
	{ "block_burrow_link", DF_Type::block_burrow_link },
	{ "block_flags", DF_Type::block_flags },
	{ "block_square_event", DF_Type::block_square_event },
	{ "block_square_event_designation_priorityst", DF_Type::block_square_event_designation_priorityst },
	{ "block_square_event_frozen_liquidst", DF_Type::block_square_event_frozen_liquidst },
	{ "block_square_event_grassst", DF_Type::block_square_event_grassst },
	{ "block_square_event_item_spatterst", DF_Type::block_square_event_item_spatterst },
	{ "block_square_event_material_spatterst", DF_Type::block_square_event_material_spatterst },
	{ "block_square_event_mineralst", DF_Type::block_square_event_mineralst },
	{ "block_square_event_mineralst__T_flags", DF_Type::block_square_event_mineralst__T_flags },
	{ "block_square_event_spoorst", DF_Type::block_square_event_spoorst },
	{ "block_square_event_type", DF_Type::block_square_event_type },
	{ "block_square_event_world_constructionst", DF_Type::block_square_event_world_constructionst },
	{ "body_appearance_modifier", DF_Type::body_appearance_modifier },
	{ "body_component_info", DF_Type::body_component_info },
	{ "body_detail_plan", DF_Type::body_detail_plan },
	{ "body_layer_status", DF_Type::body_layer_status },
	{ "body_part_layer_flags", DF_Type::body_part_layer_flags },
	{ "body_part_layer_raw", DF_Type::body_part_layer_raw },
	{ "body_part_raw", DF_Type::body_part_raw },
	{ "body_part_raw_flags", DF_Type::body_part_raw_flags },
	{ "body_part_status", DF_Type::body_part_status },
	{ "body_part_template", DF_Type::body_part_template },
	{ "body_part_template_contype", DF_Type::body_part_template_contype },
	{ "body_part_template_flags", DF_Type::body_part_template_flags },
	{ "body_size_info", DF_Type::body_size_info },
	{ "body_template", DF_Type::body_template },
	{ "bp_appearance_modifier", DF_Type::bp_appearance_modifier },
	{ "breath_attack_type", DF_Type::breath_attack_type },
	{ "build_req_choice_genst", DF_Type::build_req_choice_genst },
	{ "build_req_choice_specst", DF_Type::build_req_choice_specst },
	{ "build_req_choice_type", DF_Type::build_req_choice_type },
	{ "build_req_choicest", DF_Type::build_req_choicest },
	{ "building", DF_Type::building },
	{ "building__T_activities", DF_Type::building__T_activities },
	{ "building__T_job_claim_suppress", DF_Type::building__T_job_claim_suppress },
	{ "building_actual", DF_Type::building_actual },
	{ "building_actual__T_contained_items", DF_Type::building_actual__T_contained_items },
	{ "building_animaltrapst", DF_Type::building_animaltrapst },
	{ "building_archerytargetst", DF_Type::building_archerytargetst },
	{ "building_archerytargetst__T_archery_direction", DF_Type::building_archerytargetst__T_archery_direction },
	{ "building_armorstandst", DF_Type::building_armorstandst },
	{ "building_axle_horizontalst", DF_Type::building_axle_horizontalst },
	{ "building_axle_verticalst", DF_Type::building_axle_verticalst },
	{ "building_bars_floorst", DF_Type::building_bars_floorst },
	{ "building_bars_verticalst", DF_Type::building_bars_verticalst },
	{ "building_bedst", DF_Type::building_bedst },
	{ "building_bedst__T_bed_flags", DF_Type::building_bedst__T_bed_flags },
	{ "building_bookcasest", DF_Type::building_bookcasest },
	{ "building_boxst", DF_Type::building_boxst },
	{ "building_bridgest", DF_Type::building_bridgest },
	{ "building_bridgest__T_direction", DF_Type::building_bridgest__T_direction },
	{ "building_cabinetst", DF_Type::building_cabinetst },
	{ "building_cagest", DF_Type::building_cagest },
	{ "building_cagest__T_cage_flags", DF_Type::building_cagest__T_cage_flags },
	{ "building_chainst", DF_Type::building_chainst },
	{ "building_chainst__T_chain_flags", DF_Type::building_chainst__T_chain_flags },
	{ "building_chairst", DF_Type::building_chairst },
	{ "building_civzonest", DF_Type::building_civzonest },
	{ "building_civzonest__T_gather_flags", DF_Type::building_civzonest__T_gather_flags },
	{ "building_civzonest__T_pit_flags", DF_Type::building_civzonest__T_pit_flags },
	{ "building_civzonest__T_zone_flags", DF_Type::building_civzonest__T_zone_flags },
	{ "building_coffinst", DF_Type::building_coffinst },
	{ "building_coffinst__T_burial_mode", DF_Type::building_coffinst__T_burial_mode },
	{ "building_constructionst", DF_Type::building_constructionst },
	{ "building_def", DF_Type::building_def },
	{ "building_def_furnacest", DF_Type::building_def_furnacest },
	{ "building_def_item", DF_Type::building_def_item },
	{ "building_def_workshopst", DF_Type::building_def_workshopst },
	{ "building_design", DF_Type::building_design },
	{ "building_design__T_flags", DF_Type::building_design__T_flags },
	{ "building_display_furniturest", DF_Type::building_display_furniturest },
	{ "building_doorst", DF_Type::building_doorst },
	{ "building_drawbuffer", DF_Type::building_drawbuffer },
	{ "building_extents", DF_Type::building_extents },
	{ "building_farmplotst", DF_Type::building_farmplotst },
	{ "building_flags", DF_Type::building_flags },
	{ "building_floodgatest", DF_Type::building_floodgatest },
	{ "building_furnacest", DF_Type::building_furnacest },
	{ "building_gear_assemblyst", DF_Type::building_gear_assemblyst },
	{ "building_gear_assemblyst__T_gear_flags", DF_Type::building_gear_assemblyst__T_gear_flags },
	{ "building_grate_floorst", DF_Type::building_grate_floorst },
	{ "building_grate_wallst", DF_Type::building_grate_wallst },
	{ "building_handler", DF_Type::building_handler },
	{ "building_hatchst", DF_Type::building_hatchst },
	{ "building_hivest", DF_Type::building_hivest },
	{ "building_instrumentst", DF_Type::building_instrumentst },
	{ "building_nest_boxst", DF_Type::building_nest_boxst },
	{ "building_nestst", DF_Type::building_nestst },
	{ "building_offering_placest", DF_Type::building_offering_placest },
	{ "building_road_dirtst", DF_Type::building_road_dirtst },
	{ "building_road_pavedst", DF_Type::building_road_pavedst },
	{ "building_roadst", DF_Type::building_roadst },
	{ "building_rollersst", DF_Type::building_rollersst },
	{ "building_screw_pumpst", DF_Type::building_screw_pumpst },
	{ "building_shopst", DF_Type::building_shopst },
	{ "building_shopst__T_shop_flags", DF_Type::building_shopst__T_shop_flags },
	{ "building_siegeenginest", DF_Type::building_siegeenginest },
	{ "building_siegeenginest__T_action", DF_Type::building_siegeenginest__T_action },
	{ "building_siegeenginest__T_facing", DF_Type::building_siegeenginest__T_facing },
	{ "building_slabst", DF_Type::building_slabst },
	{ "building_squad_use", DF_Type::building_squad_use },
	{ "building_statuest", DF_Type::building_statuest },
	{ "building_stockpilest", DF_Type::building_stockpilest },
	{ "building_supportst", DF_Type::building_supportst },
	{ "building_supportst__T_support_flags", DF_Type::building_supportst__T_support_flags },
	{ "building_tablest", DF_Type::building_tablest },
	{ "building_tablest__T_table_flags", DF_Type::building_tablest__T_table_flags },
	{ "building_traction_benchst", DF_Type::building_traction_benchst },
	{ "building_tradedepotst", DF_Type::building_tradedepotst },
	{ "building_tradedepotst__T_trade_flags", DF_Type::building_tradedepotst__T_trade_flags },
	{ "building_trapst", DF_Type::building_trapst },
	{ "building_trapst__T_stop_flags", DF_Type::building_trapst__T_stop_flags },
	{ "building_type", DF_Type::building_type },
	{ "building_users", DF_Type::building_users },
	{ "building_wagonst", DF_Type::building_wagonst },
	{ "building_water_wheelst", DF_Type::building_water_wheelst },
	{ "building_weaponrackst", DF_Type::building_weaponrackst },
	{ "building_weaponst", DF_Type::building_weaponst },
	{ "building_wellst", DF_Type::building_wellst },
	{ "building_wellst__T_well_flags", DF_Type::building_wellst__T_well_flags },
	{ "building_windmillst", DF_Type::building_windmillst },
	{ "building_window_gemst", DF_Type::building_window_gemst },
	{ "building_window_glassst", DF_Type::building_window_glassst },
	{ "building_windowst", DF_Type::building_windowst },
	{ "building_workshopst", DF_Type::building_workshopst },
	{ "buildings_other_id", DF_Type::buildings_other_id },
	{ "builtin_mats", DF_Type::builtin_mats },
	{ "burrow", DF_Type::burrow },
	{ "campfire", DF_Type::campfire },
	{ "caravan_state", DF_Type::caravan_state },
	{ "caravan_state__T_flags", DF_Type::caravan_state__T_flags },
	{ "caravan_state__T_trade_state", DF_Type::caravan_state__T_trade_state },
	{ "caste_attack", DF_Type::caste_attack },
	{ "caste_attack__T_flags", DF_Type::caste_attack__T_flags },
	{ "caste_body_info", DF_Type::caste_body_info },
	{ "caste_body_info__T_extra_butcher_objects", DF_Type::caste_body_info__T_extra_butcher_objects },
	{ "caste_body_info__T_flags", DF_Type::caste_body_info__T_flags },
	{ "caste_body_info__T_interactions", DF_Type::caste_body_info__T_interactions },
	{ "caste_body_info__T_interactions__T_type", DF_Type::caste_body_info__T_interactions__T_type },
	{ "caste_clothing_item", DF_Type::caste_clothing_item },
	{ "caste_raw", DF_Type::caste_raw },
	{ "caste_raw__T_anon_1", DF_Type::caste_raw__T_anon_1 },
	{ "caste_raw__T_attributes", DF_Type::caste_raw__T_attributes },
	{ "caste_raw__T_bp_appearance", DF_Type::caste_raw__T_bp_appearance },
	{ "caste_raw__T_caste_profession_name", DF_Type::caste_raw__T_caste_profession_name },
	{ "caste_raw__T_extracts", DF_Type::caste_raw__T_extracts },
	{ "caste_raw__T_lair_hunter_speech", DF_Type::caste_raw__T_lair_hunter_speech },
	{ "caste_raw__T_misc", DF_Type::caste_raw__T_misc },
	{ "caste_raw__T_personality", DF_Type::caste_raw__T_personality },
	{ "caste_raw__T_secretion", DF_Type::caste_raw__T_secretion },
	{ "caste_raw__T_shearable_tissue_layer", DF_Type::caste_raw__T_shearable_tissue_layer },
	{ "caste_raw__T_sound", DF_Type::caste_raw__T_sound },
	{ "caste_raw__T_unk29", DF_Type::caste_raw__T_unk29 },
	{ "caste_raw__T_unknown2", DF_Type::caste_raw__T_unknown2 },
	{ "caste_raw_flags", DF_Type::caste_raw_flags },
	{ "cave_column", DF_Type::cave_column },
	{ "cave_column_link", DF_Type::cave_column_link },
	{ "cave_column_rectangle", DF_Type::cave_column_rectangle },
	{ "cie_add_tag_mask1", DF_Type::cie_add_tag_mask1 },
	{ "cie_add_tag_mask2", DF_Type::cie_add_tag_mask2 },
	{ "civzone_type", DF_Type::civzone_type },
	{ "coin_batch", DF_Type::coin_batch },
	{ "coin_batch__T_image_back", DF_Type::coin_batch__T_image_back },
	{ "coin_batch__T_image_front", DF_Type::coin_batch__T_image_front },
	{ "color_modifier_raw", DF_Type::color_modifier_raw },
	{ "combat_report_event_type", DF_Type::combat_report_event_type },
	{ "conflict_level", DF_Type::conflict_level },
	{ "construction", DF_Type::construction },
	{ "construction_flags", DF_Type::construction_flags },
	{ "construction_type", DF_Type::construction_type },
	{ "conversation", DF_Type::conversation },
	{ "conversation__T_speech", DF_Type::conversation__T_speech },
	{ "conversation__T_state", DF_Type::conversation__T_state },
	{ "conversation_menu", DF_Type::conversation_menu },
	{ "coord", DF_Type::coord },
	{ "coord2d", DF_Type::coord2d },
	{ "coord2d_path", DF_Type::coord2d_path },
	{ "coord_path", DF_Type::coord_path },
	{ "coord_rect", DF_Type::coord_rect },
	{ "corpse_material_type", DF_Type::corpse_material_type },
	{ "craft_material_class", DF_Type::craft_material_class },
	{ "creation_zone_pwg_alteration_campst", DF_Type::creation_zone_pwg_alteration_campst },
	{ "creation_zone_pwg_alteration_location_deathst", DF_Type::creation_zone_pwg_alteration_location_deathst },
	{ "creation_zone_pwg_alteration_location_deathst__T_unk_1", DF_Type::creation_zone_pwg_alteration_location_deathst__T_unk_1 },
	{ "creation_zone_pwg_alteration_location_deathst__T_unk_1__T_anon_1", DF_Type::creation_zone_pwg_alteration_location_deathst__T_unk_1__T_anon_1 },
	{ "creation_zone_pwg_alteration_srb_ruinedst", DF_Type::creation_zone_pwg_alteration_srb_ruinedst },
	{ "creation_zone_pwg_alteration_srp_ruinedst", DF_Type::creation_zone_pwg_alteration_srp_ruinedst },
	{ "creation_zone_pwg_alteration_type", DF_Type::creation_zone_pwg_alteration_type },
	{ "creation_zone_pwg_alterationst", DF_Type::creation_zone_pwg_alterationst },
	{ "creature_graphics_appointment", DF_Type::creature_graphics_appointment },
	{ "creature_graphics_role", DF_Type::creature_graphics_role },
	{ "creature_handler", DF_Type::creature_handler },
	{ "creature_interaction", DF_Type::creature_interaction },
	{ "creature_interaction__T_flags", DF_Type::creature_interaction__T_flags },
	{ "creature_interaction_effect", DF_Type::creature_interaction_effect },
	{ "creature_interaction_effect__T_counter_trigger", DF_Type::creature_interaction_effect__T_counter_trigger },
	{ "creature_interaction_effect_add_simple_flagst", DF_Type::creature_interaction_effect_add_simple_flagst },
	{ "creature_interaction_effect_bleedingst", DF_Type::creature_interaction_effect_bleedingst },
	{ "creature_interaction_effect_blistersst", DF_Type::creature_interaction_effect_blistersst },
	{ "creature_interaction_effect_body_appearance_modifierst", DF_Type::creature_interaction_effect_body_appearance_modifierst },
	{ "creature_interaction_effect_body_mat_interactionst", DF_Type::creature_interaction_effect_body_mat_interactionst },
	{ "creature_interaction_effect_body_transformationst", DF_Type::creature_interaction_effect_body_transformationst },
	{ "creature_interaction_effect_bp_appearance_modifierst", DF_Type::creature_interaction_effect_bp_appearance_modifierst },
	{ "creature_interaction_effect_bruisingst", DF_Type::creature_interaction_effect_bruisingst },
	{ "creature_interaction_effect_can_do_interactionst", DF_Type::creature_interaction_effect_can_do_interactionst },
	{ "creature_interaction_effect_change_personalityst", DF_Type::creature_interaction_effect_change_personalityst },
	{ "creature_interaction_effect_close_open_woundsst", DF_Type::creature_interaction_effect_close_open_woundsst },
	{ "creature_interaction_effect_cough_bloodst", DF_Type::creature_interaction_effect_cough_bloodst },
	{ "creature_interaction_effect_cure_infectionsst", DF_Type::creature_interaction_effect_cure_infectionsst },
	{ "creature_interaction_effect_cure_infectionst", DF_Type::creature_interaction_effect_cure_infectionst },
	{ "creature_interaction_effect_display_namest", DF_Type::creature_interaction_effect_display_namest },
	{ "creature_interaction_effect_display_symbolst", DF_Type::creature_interaction_effect_display_symbolst },
	{ "creature_interaction_effect_dizzinessst", DF_Type::creature_interaction_effect_dizzinessst },
	{ "creature_interaction_effect_drowsinessst", DF_Type::creature_interaction_effect_drowsinessst },
	{ "creature_interaction_effect_erratic_behaviorst", DF_Type::creature_interaction_effect_erratic_behaviorst },
	{ "creature_interaction_effect_feel_emotionst", DF_Type::creature_interaction_effect_feel_emotionst },
	{ "creature_interaction_effect_feverst", DF_Type::creature_interaction_effect_feverst },
	{ "creature_interaction_effect_flags", DF_Type::creature_interaction_effect_flags },
	{ "creature_interaction_effect_flash_symbolst", DF_Type::creature_interaction_effect_flash_symbolst },
	{ "creature_interaction_effect_heal_nervesst", DF_Type::creature_interaction_effect_heal_nervesst },
	{ "creature_interaction_effect_heal_tissuesst", DF_Type::creature_interaction_effect_heal_tissuesst },
	{ "creature_interaction_effect_impair_functionst", DF_Type::creature_interaction_effect_impair_functionst },
	{ "creature_interaction_effect_material_force_adjustst", DF_Type::creature_interaction_effect_material_force_adjustst },
	{ "creature_interaction_effect_ment_att_changest", DF_Type::creature_interaction_effect_ment_att_changest },
	{ "creature_interaction_effect_nauseast", DF_Type::creature_interaction_effect_nauseast },
	{ "creature_interaction_effect_necrosisst", DF_Type::creature_interaction_effect_necrosisst },
	{ "creature_interaction_effect_numbnessst", DF_Type::creature_interaction_effect_numbnessst },
	{ "creature_interaction_effect_oozingst", DF_Type::creature_interaction_effect_oozingst },
	{ "creature_interaction_effect_painst", DF_Type::creature_interaction_effect_painst },
	{ "creature_interaction_effect_paralysisst", DF_Type::creature_interaction_effect_paralysisst },
	{ "creature_interaction_effect_phys_att_changest", DF_Type::creature_interaction_effect_phys_att_changest },
	{ "creature_interaction_effect_reduce_dizzinessst", DF_Type::creature_interaction_effect_reduce_dizzinessst },
	{ "creature_interaction_effect_reduce_feverst", DF_Type::creature_interaction_effect_reduce_feverst },
	{ "creature_interaction_effect_reduce_nauseast", DF_Type::creature_interaction_effect_reduce_nauseast },
	{ "creature_interaction_effect_reduce_painst", DF_Type::creature_interaction_effect_reduce_painst },
	{ "creature_interaction_effect_reduce_paralysisst", DF_Type::creature_interaction_effect_reduce_paralysisst },
	{ "creature_interaction_effect_reduce_swellingst", DF_Type::creature_interaction_effect_reduce_swellingst },
	{ "creature_interaction_effect_regrow_partsst", DF_Type::creature_interaction_effect_regrow_partsst },
	{ "creature_interaction_effect_remove_simple_flagst", DF_Type::creature_interaction_effect_remove_simple_flagst },
	{ "creature_interaction_effect_sense_creature_classst", DF_Type::creature_interaction_effect_sense_creature_classst },
	{ "creature_interaction_effect_skill_roll_adjustst", DF_Type::creature_interaction_effect_skill_roll_adjustst },
	{ "creature_interaction_effect_special_attack_interactionst", DF_Type::creature_interaction_effect_special_attack_interactionst },
	{ "creature_interaction_effect_speed_changest", DF_Type::creature_interaction_effect_speed_changest },
	{ "creature_interaction_effect_stop_bleedingst", DF_Type::creature_interaction_effect_stop_bleedingst },
	{ "creature_interaction_effect_swellingst", DF_Type::creature_interaction_effect_swellingst },
	{ "creature_interaction_effect_target", DF_Type::creature_interaction_effect_target },
	{ "creature_interaction_effect_target_mode", DF_Type::creature_interaction_effect_target_mode },
	{ "creature_interaction_effect_type", DF_Type::creature_interaction_effect_type },
	{ "creature_interaction_effect_unconsciousnessst", DF_Type::creature_interaction_effect_unconsciousnessst },
	{ "creature_interaction_effect_vomit_bloodst", DF_Type::creature_interaction_effect_vomit_bloodst },
	{ "creature_interaction_target_flags", DF_Type::creature_interaction_target_flags },
	{ "creature_raw", DF_Type::creature_raw },
	{ "creature_raw__T_graphics", DF_Type::creature_raw__T_graphics },
	{ "creature_raw__T_hive_product", DF_Type::creature_raw__T_hive_product },
	{ "creature_raw__T_profession_name", DF_Type::creature_raw__T_profession_name },
	{ "creature_raw_flags", DF_Type::creature_raw_flags },
	{ "creature_variation", DF_Type::creature_variation },
	{ "creature_variation_convert_tag", DF_Type::creature_variation_convert_tag },
	{ "crime", DF_Type::crime },
	{ "crime__T_counterintelligence", DF_Type::crime__T_counterintelligence },
	{ "crime__T_flags", DF_Type::crime__T_flags },
	{ "crime__T_mode", DF_Type::crime__T_mode },
	{ "crime__T_punishment", DF_Type::crime__T_punishment },
	{ "crime__T_reports", DF_Type::crime__T_reports },
	{ "crime_type", DF_Type::crime_type },
	{ "cultural_identity", DF_Type::cultural_identity },
	{ "cultural_identity__T_anon_1", DF_Type::cultural_identity__T_anon_1 },
	{ "cultural_identity__T_anon_2", DF_Type::cultural_identity__T_anon_2 },
	{ "cultural_identity__T_group_log", DF_Type::cultural_identity__T_group_log },
	{ "cultural_identity__T_group_log__T_join_type", DF_Type::cultural_identity__T_group_log__T_join_type },
	{ "cumulus_type", DF_Type::cumulus_type },
	{ "curse_attr_change", DF_Type::curse_attr_change },
	{ "d_init", DF_Type::d_init },
	{ "d_init__T_store_dist", DF_Type::d_init__T_store_dist },
	{ "d_init__T_wound_color", DF_Type::d_init__T_wound_color },
	{ "d_init_embark_confirm", DF_Type::d_init_embark_confirm },
	{ "d_init_flags1", DF_Type::d_init_flags1 },
	{ "d_init_flags2", DF_Type::d_init_flags2 },
	{ "d_init_flags3", DF_Type::d_init_flags3 },
	{ "d_init_flags4", DF_Type::d_init_flags4 },
	{ "d_init_idlers", DF_Type::d_init_idlers },
	{ "d_init_nickname", DF_Type::d_init_nickname },
	{ "d_init_tunnel", DF_Type::d_init_tunnel },
	{ "d_init_z_view", DF_Type::d_init_z_view },
	{ "dance_form", DF_Type::dance_form },
	{ "dance_form_sub1", DF_Type::dance_form_sub1 },
	{ "dance_form_sub2", DF_Type::dance_form_sub2 },
	{ "death_condition_type", DF_Type::death_condition_type },
	{ "death_type", DF_Type::death_type },
	{ "deep_vein_hollow", DF_Type::deep_vein_hollow },
	{ "descriptor_color", DF_Type::descriptor_color },
	{ "descriptor_pattern", DF_Type::descriptor_pattern },
	{ "descriptor_shape", DF_Type::descriptor_shape },
	{ "descriptor_shape__T_gems_use", DF_Type::descriptor_shape__T_gems_use },
	{ "dfhack_knowledge_scholar_flag", DF_Type::dfhack_knowledge_scholar_flag },
	{ "dfhack_material_category", DF_Type::dfhack_material_category },
	{ "dfhack_room_quality_level", DF_Type::dfhack_room_quality_level },
	{ "dipscript_info", DF_Type::dipscript_info },
	{ "dipscript_popup", DF_Type::dipscript_popup },
	{ "dipscript_popup__T_flags", DF_Type::dipscript_popup__T_flags },
	{ "divination_set", DF_Type::divination_set },
	{ "divination_set_roll", DF_Type::divination_set_roll },
	{ "door_flags", DF_Type::door_flags },
	{ "dye_info", DF_Type::dye_info },
	{ "effect_info", DF_Type::effect_info },
	{ "embark_feature", DF_Type::embark_feature },
	{ "embark_finder_option", DF_Type::embark_finder_option },
	{ "embark_item_choice", DF_Type::embark_item_choice },
	{ "embark_item_choice__T_list", DF_Type::embark_item_choice__T_list },
	{ "embark_location", DF_Type::embark_location },
	{ "embark_note", DF_Type::embark_note },
	{ "embark_profile", DF_Type::embark_profile },
	{ "emotion_type", DF_Type::emotion_type },
	{ "enabler", DF_Type::enabler },
	{ "enabler__T_async_frombox", DF_Type::enabler__T_async_frombox },
	{ "enabler__T_async_frombox__T_queue", DF_Type::enabler__T_async_frombox__T_queue },
	{ "enabler__T_async_frombox__T_queue___union0", DF_Type::enabler__T_async_frombox__T_queue___union0 },
	{ "enabler__T_async_frombox__T_queue___union0___struct1", DF_Type::enabler__T_async_frombox__T_queue___union0___struct1 },
	{ "enabler__T_async_frombox__T_queue__T_msg", DF_Type::enabler__T_async_frombox__T_queue__T_msg },
	{ "enabler__T_async_tobox", DF_Type::enabler__T_async_tobox },
	{ "enabler__T_async_tobox__T_queue", DF_Type::enabler__T_async_tobox__T_queue },
	{ "enabler__T_async_tobox__T_queue__T_cmd", DF_Type::enabler__T_async_tobox__T_queue__T_cmd },
	{ "enabler__T_async_zoom", DF_Type::enabler__T_async_zoom },
	{ "enabler__T_flag", DF_Type::enabler__T_flag },
	{ "enabler__T_gputicks", DF_Type::enabler__T_gputicks },
	{ "enabler__T_overridden_grid_sizes", DF_Type::enabler__T_overridden_grid_sizes },
	{ "enabler__T_simticks", DF_Type::enabler__T_simticks },
	{ "enabler__T_text_system", DF_Type::enabler__T_text_system },
	{ "enabler__T_text_system__T_file_info", DF_Type::enabler__T_text_system__T_file_info },
	{ "enabler__T_textures", DF_Type::enabler__T_textures },
	{ "engraving", DF_Type::engraving },
	{ "engraving_flags", DF_Type::engraving_flags },
	{ "entity_action_type", DF_Type::entity_action_type },
	{ "entity_activity_statistics", DF_Type::entity_activity_statistics },
	{ "entity_activity_statistics__T_food", DF_Type::entity_activity_statistics__T_food },
	{ "entity_activity_statistics__T_found_misc", DF_Type::entity_activity_statistics__T_found_misc },
	{ "entity_activity_statistics__T_wealth", DF_Type::entity_activity_statistics__T_wealth },
	{ "entity_animal_raw", DF_Type::entity_animal_raw },
	{ "entity_animal_raw__T_flags", DF_Type::entity_animal_raw__T_flags },
	{ "entity_buy_prices", DF_Type::entity_buy_prices },
	{ "entity_buy_requests", DF_Type::entity_buy_requests },
	{ "entity_claim_mask", DF_Type::entity_claim_mask },
	{ "entity_claim_mask__T_map", DF_Type::entity_claim_mask__T_map },
	{ "entity_entity_link", DF_Type::entity_entity_link },
	{ "entity_entity_link_type", DF_Type::entity_entity_link_type },
	{ "entity_event", DF_Type::entity_event },
	{ "entity_event__T_data", DF_Type::entity_event__T_data },
	{ "entity_event__T_data__T_abandon", DF_Type::entity_event__T_data__T_abandon },
	{ "entity_event__T_data__T_abduction", DF_Type::entity_event__T_data__T_abduction },
	{ "entity_event__T_data__T_accept_peace_offer", DF_Type::entity_event__T_data__T_accept_peace_offer },
	{ "entity_event__T_data__T_accept_tribute_demand", DF_Type::entity_event__T_data__T_accept_tribute_demand },
	{ "entity_event__T_data__T_accept_tribute_offer", DF_Type::entity_event__T_data__T_accept_tribute_offer },
	{ "entity_event__T_data__T_artifact_destroyed", DF_Type::entity_event__T_data__T_artifact_destroyed },
	{ "entity_event__T_data__T_artifact_in_feature_layer", DF_Type::entity_event__T_data__T_artifact_in_feature_layer },
	{ "entity_event__T_data__T_artifact_in_inventory", DF_Type::entity_event__T_data__T_artifact_in_inventory },
	{ "entity_event__T_data__T_artifact_in_site", DF_Type::entity_event__T_data__T_artifact_in_site },
	{ "entity_event__T_data__T_artifact_in_subregion", DF_Type::entity_event__T_data__T_artifact_in_subregion },
	{ "entity_event__T_data__T_artifact_not_in_feature_layer", DF_Type::entity_event__T_data__T_artifact_not_in_feature_layer },
	{ "entity_event__T_data__T_artifact_not_in_inventory", DF_Type::entity_event__T_data__T_artifact_not_in_inventory },
	{ "entity_event__T_data__T_artifact_not_in_site", DF_Type::entity_event__T_data__T_artifact_not_in_site },
	{ "entity_event__T_data__T_artifact_not_in_subregion", DF_Type::entity_event__T_data__T_artifact_not_in_subregion },
	{ "entity_event__T_data__T_beast", DF_Type::entity_event__T_data__T_beast },
	{ "entity_event__T_data__T_cease_tribute_offer", DF_Type::entity_event__T_data__T_cease_tribute_offer },
	{ "entity_event__T_data__T_claim", DF_Type::entity_event__T_data__T_claim },
	{ "entity_event__T_data__T_flee", DF_Type::entity_event__T_data__T_flee },
	{ "entity_event__T_data__T_founded", DF_Type::entity_event__T_data__T_founded },
	{ "entity_event__T_data__T_founding", DF_Type::entity_event__T_data__T_founding },
	{ "entity_event__T_data__T_group", DF_Type::entity_event__T_data__T_group },
	{ "entity_event__T_data__T_harass", DF_Type::entity_event__T_data__T_harass },
	{ "entity_event__T_data__T_incident", DF_Type::entity_event__T_data__T_incident },
	{ "entity_event__T_data__T_insurrection", DF_Type::entity_event__T_data__T_insurrection },
	{ "entity_event__T_data__T_insurrection_end", DF_Type::entity_event__T_data__T_insurrection_end },
	{ "entity_event__T_data__T_insurrection_end__T_result", DF_Type::entity_event__T_data__T_insurrection_end__T_result },
	{ "entity_event__T_data__T_invasion", DF_Type::entity_event__T_data__T_invasion },
	{ "entity_event__T_data__T_leave", DF_Type::entity_event__T_data__T_leave },
	{ "entity_event__T_data__T_occupation", DF_Type::entity_event__T_data__T_occupation },
	{ "entity_event__T_data__T_reclaimed", DF_Type::entity_event__T_data__T_reclaimed },
	{ "entity_event__T_data__T_reclaiming", DF_Type::entity_event__T_data__T_reclaiming },
	{ "entity_event__T_data__T_refuse_peace_offer", DF_Type::entity_event__T_data__T_refuse_peace_offer },
	{ "entity_event__T_data__T_refuse_tribute_demand", DF_Type::entity_event__T_data__T_refuse_tribute_demand },
	{ "entity_event__T_data__T_refuse_tribute_offer", DF_Type::entity_event__T_data__T_refuse_tribute_offer },
	{ "entity_event__T_data__T_succession", DF_Type::entity_event__T_data__T_succession },
	{ "entity_event_type", DF_Type::entity_event_type },
	{ "entity_material_category", DF_Type::entity_material_category },
	{ "entity_name_type", DF_Type::entity_name_type },
	{ "entity_occasion", DF_Type::entity_occasion },
	{ "entity_occasion_info", DF_Type::entity_occasion_info },
	{ "entity_occasion_schedule", DF_Type::entity_occasion_schedule },
	{ "entity_occasion_schedule_feature", DF_Type::entity_occasion_schedule_feature },
	{ "entity_population", DF_Type::entity_population },
	{ "entity_population_unk4", DF_Type::entity_population_unk4 },
	{ "entity_population_unk4__T_anon_1", DF_Type::entity_population_unk4__T_anon_1 },
	{ "entity_population_unk4__T_anon_2", DF_Type::entity_population_unk4__T_anon_2 },
	{ "entity_population_unk4__T_anon_3", DF_Type::entity_population_unk4__T_anon_3 },
	{ "entity_position", DF_Type::entity_position },
	{ "entity_position_assignment", DF_Type::entity_position_assignment },
	{ "entity_position_flags", DF_Type::entity_position_flags },
	{ "entity_position_raw", DF_Type::entity_position_raw },
	{ "entity_position_raw_flags", DF_Type::entity_position_raw_flags },
	{ "entity_position_responsibility", DF_Type::entity_position_responsibility },
	{ "entity_raw", DF_Type::entity_raw },
	{ "entity_raw__T_equipment", DF_Type::entity_raw__T_equipment },
	{ "entity_raw__T_jobs", DF_Type::entity_raw__T_jobs },
	{ "entity_raw__T_land_holder_trigger", DF_Type::entity_raw__T_land_holder_trigger },
	{ "entity_raw__T_progress_trigger", DF_Type::entity_raw__T_progress_trigger },
	{ "entity_raw__T_scholar", DF_Type::entity_raw__T_scholar },
	{ "entity_raw__T_symbols", DF_Type::entity_raw__T_symbols },
	{ "entity_raw__T_tissue_styles", DF_Type::entity_raw__T_tissue_styles },
	{ "entity_raw__T_workshops", DF_Type::entity_raw__T_workshops },
	{ "entity_raw_flags", DF_Type::entity_raw_flags },
	{ "entity_recipe", DF_Type::entity_recipe },
	{ "entity_sell_category", DF_Type::entity_sell_category },
	{ "entity_sell_prices", DF_Type::entity_sell_prices },
	{ "entity_sell_requests", DF_Type::entity_sell_requests },
	{ "entity_site_link", DF_Type::entity_site_link },
	{ "entity_site_link__T_unk_7", DF_Type::entity_site_link__T_unk_7 },
	{ "entity_site_link_flags", DF_Type::entity_site_link_flags },
	{ "entity_site_link_status_flags", DF_Type::entity_site_link_status_flags },
	{ "entity_site_link_type", DF_Type::entity_site_link_type },
	{ "entity_tissue_style", DF_Type::entity_tissue_style },
	{ "entity_uniform", DF_Type::entity_uniform },
	{ "entity_uniform_item", DF_Type::entity_uniform_item },
	{ "entity_unk_v47_1", DF_Type::entity_unk_v47_1 },
	{ "environment_type", DF_Type::environment_type },
	{ "era_type", DF_Type::era_type },
	{ "ethic_response", DF_Type::ethic_response },
	{ "ethic_type", DF_Type::ethic_type },
	{ "export_map_type", DF_Type::export_map_type },
	{ "feature", DF_Type::feature },
	{ "feature_alteration", DF_Type::feature_alteration },
	{ "feature_alteration_new_lava_fill_zst", DF_Type::feature_alteration_new_lava_fill_zst },
	{ "feature_alteration_new_pop_maxst", DF_Type::feature_alteration_new_pop_maxst },
	{ "feature_alteration_type", DF_Type::feature_alteration_type },
	{ "feature_cavest", DF_Type::feature_cavest },
	{ "feature_deep_special_tubest", DF_Type::feature_deep_special_tubest },
	{ "feature_deep_surface_portalst", DF_Type::feature_deep_surface_portalst },
	{ "feature_init", DF_Type::feature_init },
	{ "feature_init_cavest", DF_Type::feature_init_cavest },
	{ "feature_init_deep_special_tubest", DF_Type::feature_init_deep_special_tubest },
	{ "feature_init_deep_surface_portalst", DF_Type::feature_init_deep_surface_portalst },
	{ "feature_init_flags", DF_Type::feature_init_flags },
	{ "feature_init_magma_core_from_layerst", DF_Type::feature_init_magma_core_from_layerst },
	{ "feature_init_magma_poolst", DF_Type::feature_init_magma_poolst },
	{ "feature_init_outdoor_riverst", DF_Type::feature_init_outdoor_riverst },
	{ "feature_init_pitst", DF_Type::feature_init_pitst },
	{ "feature_init_subterranean_from_layerst", DF_Type::feature_init_subterranean_from_layerst },
	{ "feature_init_underworld_from_layerst", DF_Type::feature_init_underworld_from_layerst },
	{ "feature_init_volcanost", DF_Type::feature_init_volcanost },
	{ "feature_magma_core_from_layerst", DF_Type::feature_magma_core_from_layerst },
	{ "feature_magma_poolst", DF_Type::feature_magma_poolst },
	{ "feature_outdoor_riverst", DF_Type::feature_outdoor_riverst },
	{ "feature_pitst", DF_Type::feature_pitst },
	{ "feature_subterranean_from_layerst", DF_Type::feature_subterranean_from_layerst },
	{ "feature_type", DF_Type::feature_type },
	{ "feature_underworld_from_layerst", DF_Type::feature_underworld_from_layerst },
	{ "feature_volcanost", DF_Type::feature_volcanost },
	{ "file_compressorst", DF_Type::file_compressorst },
	{ "fire", DF_Type::fire },
	{ "flow_guide", DF_Type::flow_guide },
	{ "flow_guide_item_cloudst", DF_Type::flow_guide_item_cloudst },
	{ "flow_guide_trailing_flowst", DF_Type::flow_guide_trailing_flowst },
	{ "flow_guide_type", DF_Type::flow_guide_type },
	{ "flow_info", DF_Type::flow_info },
	{ "flow_reuse_pool", DF_Type::flow_reuse_pool },
	{ "flow_reuse_pool__T_flags", DF_Type::flow_reuse_pool__T_flags },
	{ "flow_type", DF_Type::flow_type },
	{ "fog_type", DF_Type::fog_type },
	{ "fortress_type", DF_Type::fortress_type },
	{ "front_type", DF_Type::front_type },
	{ "furnace_type", DF_Type::furnace_type },
	{ "furniture_type", DF_Type::furniture_type },
	{ "gait_info", DF_Type::gait_info },
	{ "gait_info__T_flags", DF_Type::gait_info__T_flags },
	{ "gait_type", DF_Type::gait_type },
	{ "game_mode", DF_Type::game_mode },
	{ "game_type", DF_Type::game_type },
	{ "gate_flags", DF_Type::gate_flags },
	{ "general_ref", DF_Type::general_ref },
	{ "general_ref_abstract_buildingst", DF_Type::general_ref_abstract_buildingst },
	{ "general_ref_activity_eventst", DF_Type::general_ref_activity_eventst },
	{ "general_ref_artifact", DF_Type::general_ref_artifact },
	{ "general_ref_building", DF_Type::general_ref_building },
	{ "general_ref_building_cagedst", DF_Type::general_ref_building_cagedst },
	{ "general_ref_building_chainst", DF_Type::general_ref_building_chainst },
	{ "general_ref_building_civzone_assignedst", DF_Type::general_ref_building_civzone_assignedst },
	{ "general_ref_building_destinationst", DF_Type::general_ref_building_destinationst },
	{ "general_ref_building_display_furniturest", DF_Type::general_ref_building_display_furniturest },
	{ "general_ref_building_holderst", DF_Type::general_ref_building_holderst },
	{ "general_ref_building_nest_boxst", DF_Type::general_ref_building_nest_boxst },
	{ "general_ref_building_triggerst", DF_Type::general_ref_building_triggerst },
	{ "general_ref_building_triggertargetst", DF_Type::general_ref_building_triggertargetst },
	{ "general_ref_building_use_target_1st", DF_Type::general_ref_building_use_target_1st },
	{ "general_ref_building_use_target_2st", DF_Type::general_ref_building_use_target_2st },
	{ "general_ref_building_well_tag", DF_Type::general_ref_building_well_tag },
	{ "general_ref_coinbatch", DF_Type::general_ref_coinbatch },
	{ "general_ref_contained_in_itemst", DF_Type::general_ref_contained_in_itemst },
	{ "general_ref_contains_itemst", DF_Type::general_ref_contains_itemst },
	{ "general_ref_contains_unitst", DF_Type::general_ref_contains_unitst },
	{ "general_ref_creaturest", DF_Type::general_ref_creaturest },
	{ "general_ref_creaturest__T_flags", DF_Type::general_ref_creaturest__T_flags },
	{ "general_ref_dance_formst", DF_Type::general_ref_dance_formst },
	{ "general_ref_entity", DF_Type::general_ref_entity },
	{ "general_ref_entity_art_image", DF_Type::general_ref_entity_art_image },
	{ "general_ref_entity_itemownerst", DF_Type::general_ref_entity_itemownerst },
	{ "general_ref_entity_offeredst", DF_Type::general_ref_entity_offeredst },
	{ "general_ref_entity_popst", DF_Type::general_ref_entity_popst },
	{ "general_ref_entity_popst__T_flags", DF_Type::general_ref_entity_popst__T_flags },
	{ "general_ref_entity_stolenst", DF_Type::general_ref_entity_stolenst },
	{ "general_ref_feature_layerst", DF_Type::general_ref_feature_layerst },
	{ "general_ref_historical_eventst", DF_Type::general_ref_historical_eventst },
	{ "general_ref_historical_figurest", DF_Type::general_ref_historical_figurest },
	{ "general_ref_interactionst", DF_Type::general_ref_interactionst },
	{ "general_ref_is_artifactst", DF_Type::general_ref_is_artifactst },
	{ "general_ref_is_nemesisst", DF_Type::general_ref_is_nemesisst },
	{ "general_ref_item", DF_Type::general_ref_item },
	{ "general_ref_item_type", DF_Type::general_ref_item_type },
	{ "general_ref_knowledge_scholar_flagst", DF_Type::general_ref_knowledge_scholar_flagst },
	{ "general_ref_languagest", DF_Type::general_ref_languagest },
	{ "general_ref_locationst", DF_Type::general_ref_locationst },
	{ "general_ref_mapsquare", DF_Type::general_ref_mapsquare },
	{ "general_ref_musical_formst", DF_Type::general_ref_musical_formst },
	{ "general_ref_nemesis", DF_Type::general_ref_nemesis },
	{ "general_ref_poetic_formst", DF_Type::general_ref_poetic_formst },
	{ "general_ref_projectile", DF_Type::general_ref_projectile },
	{ "general_ref_sitest", DF_Type::general_ref_sitest },
	{ "general_ref_spherest", DF_Type::general_ref_spherest },
	{ "general_ref_subregionst", DF_Type::general_ref_subregionst },
	{ "general_ref_type", DF_Type::general_ref_type },
	{ "general_ref_unit", DF_Type::general_ref_unit },
	{ "general_ref_unit_beateest", DF_Type::general_ref_unit_beateest },
	{ "general_ref_unit_cageest", DF_Type::general_ref_unit_cageest },
	{ "general_ref_unit_climberst", DF_Type::general_ref_unit_climberst },
	{ "general_ref_unit_foodreceiverst", DF_Type::general_ref_unit_foodreceiverst },
	{ "general_ref_unit_geldeest", DF_Type::general_ref_unit_geldeest },
	{ "general_ref_unit_holderst", DF_Type::general_ref_unit_holderst },
	{ "general_ref_unit_infantst", DF_Type::general_ref_unit_infantst },
	{ "general_ref_unit_interrogateest", DF_Type::general_ref_unit_interrogateest },
	{ "general_ref_unit_itemownerst", DF_Type::general_ref_unit_itemownerst },
	{ "general_ref_unit_itemownerst__T_flags", DF_Type::general_ref_unit_itemownerst__T_flags },
	{ "general_ref_unit_kidnapeest", DF_Type::general_ref_unit_kidnapeest },
	{ "general_ref_unit_milkeest", DF_Type::general_ref_unit_milkeest },
	{ "general_ref_unit_patientst", DF_Type::general_ref_unit_patientst },
	{ "general_ref_unit_reporteest", DF_Type::general_ref_unit_reporteest },
	{ "general_ref_unit_riderst", DF_Type::general_ref_unit_riderst },
	{ "general_ref_unit_sheareest", DF_Type::general_ref_unit_sheareest },
	{ "general_ref_unit_slaughtereest", DF_Type::general_ref_unit_slaughtereest },
	{ "general_ref_unit_suckeest", DF_Type::general_ref_unit_suckeest },
	{ "general_ref_unit_tradebringerst", DF_Type::general_ref_unit_tradebringerst },
	{ "general_ref_unit_traineest", DF_Type::general_ref_unit_traineest },
	{ "general_ref_unit_workerst", DF_Type::general_ref_unit_workerst },
	{ "general_ref_value_levelst", DF_Type::general_ref_value_levelst },
	{ "general_ref_written_contentst", DF_Type::general_ref_written_contentst },
	{ "geo_layer_type", DF_Type::geo_layer_type },
	{ "ghost_goal", DF_Type::ghost_goal },
	{ "ghost_type", DF_Type::ghost_type },
	{ "gloves_flags", DF_Type::gloves_flags },
	{ "glowing_barrier", DF_Type::glowing_barrier },
	{ "goal_type", DF_Type::goal_type },
	{ "graphic", DF_Type::graphic },
	{ "guild_id", DF_Type::guild_id },
	{ "hauler_type", DF_Type::hauler_type },
	{ "hauling_route", DF_Type::hauling_route },
	{ "hauling_stop", DF_Type::hauling_stop },
	{ "health_view_bits1", DF_Type::health_view_bits1 },
	{ "health_view_bits2", DF_Type::health_view_bits2 },
	{ "health_view_bits3", DF_Type::health_view_bits3 },
	{ "helm_flags", DF_Type::helm_flags },
	{ "hillock_house_type", DF_Type::hillock_house_type },
	{ "histfig_body_state", DF_Type::histfig_body_state },
	{ "histfig_entity_link", DF_Type::histfig_entity_link },
	{ "histfig_entity_link_criminalst", DF_Type::histfig_entity_link_criminalst },
	{ "histfig_entity_link_enemyst", DF_Type::histfig_entity_link_enemyst },
	{ "histfig_entity_link_former_memberst", DF_Type::histfig_entity_link_former_memberst },
	{ "histfig_entity_link_former_mercenaryst", DF_Type::histfig_entity_link_former_mercenaryst },
	{ "histfig_entity_link_former_occupationst", DF_Type::histfig_entity_link_former_occupationst },
	{ "histfig_entity_link_former_positionst", DF_Type::histfig_entity_link_former_positionst },
	{ "histfig_entity_link_former_prisonerst", DF_Type::histfig_entity_link_former_prisonerst },
	{ "histfig_entity_link_former_slavest", DF_Type::histfig_entity_link_former_slavest },
	{ "histfig_entity_link_former_squadst", DF_Type::histfig_entity_link_former_squadst },
	{ "histfig_entity_link_memberst", DF_Type::histfig_entity_link_memberst },
	{ "histfig_entity_link_mercenaryst", DF_Type::histfig_entity_link_mercenaryst },
	{ "histfig_entity_link_occupationst", DF_Type::histfig_entity_link_occupationst },
	{ "histfig_entity_link_position_claimst", DF_Type::histfig_entity_link_position_claimst },
	{ "histfig_entity_link_positionst", DF_Type::histfig_entity_link_positionst },
	{ "histfig_entity_link_prisonerst", DF_Type::histfig_entity_link_prisonerst },
	{ "histfig_entity_link_slavest", DF_Type::histfig_entity_link_slavest },
	{ "histfig_entity_link_squadst", DF_Type::histfig_entity_link_squadst },
	{ "histfig_entity_link_type", DF_Type::histfig_entity_link_type },
	{ "histfig_flags", DF_Type::histfig_flags },
	{ "histfig_hf_link", DF_Type::histfig_hf_link },
	{ "histfig_hf_link_apprenticest", DF_Type::histfig_hf_link_apprenticest },
	{ "histfig_hf_link_childst", DF_Type::histfig_hf_link_childst },
	{ "histfig_hf_link_companionst", DF_Type::histfig_hf_link_companionst },
	{ "histfig_hf_link_deceased_spousest", DF_Type::histfig_hf_link_deceased_spousest },
	{ "histfig_hf_link_deityst", DF_Type::histfig_hf_link_deityst },
	{ "histfig_hf_link_fatherst", DF_Type::histfig_hf_link_fatherst },
	{ "histfig_hf_link_former_apprenticest", DF_Type::histfig_hf_link_former_apprenticest },
	{ "histfig_hf_link_former_masterst", DF_Type::histfig_hf_link_former_masterst },
	{ "histfig_hf_link_former_spousest", DF_Type::histfig_hf_link_former_spousest },
	{ "histfig_hf_link_imprisonerst", DF_Type::histfig_hf_link_imprisonerst },
	{ "histfig_hf_link_loverst", DF_Type::histfig_hf_link_loverst },
	{ "histfig_hf_link_masterst", DF_Type::histfig_hf_link_masterst },
	{ "histfig_hf_link_motherst", DF_Type::histfig_hf_link_motherst },
	{ "histfig_hf_link_pet_ownerst", DF_Type::histfig_hf_link_pet_ownerst },
	{ "histfig_hf_link_prisonerst", DF_Type::histfig_hf_link_prisonerst },
	{ "histfig_hf_link_spousest", DF_Type::histfig_hf_link_spousest },
	{ "histfig_hf_link_type", DF_Type::histfig_hf_link_type },
	{ "histfig_relationship_type", DF_Type::histfig_relationship_type },
	{ "histfig_site_link", DF_Type::histfig_site_link },
	{ "histfig_site_link_hangoutst", DF_Type::histfig_site_link_hangoutst },
	{ "histfig_site_link_home_site_abstract_buildingst", DF_Type::histfig_site_link_home_site_abstract_buildingst },
	{ "histfig_site_link_home_site_realization_buildingst", DF_Type::histfig_site_link_home_site_realization_buildingst },
	{ "histfig_site_link_home_site_realization_sulst", DF_Type::histfig_site_link_home_site_realization_sulst },
	{ "histfig_site_link_home_site_saved_civzonest", DF_Type::histfig_site_link_home_site_saved_civzonest },
	{ "histfig_site_link_lairst", DF_Type::histfig_site_link_lairst },
	{ "histfig_site_link_occupationst", DF_Type::histfig_site_link_occupationst },
	{ "histfig_site_link_prison_abstract_buildingst", DF_Type::histfig_site_link_prison_abstract_buildingst },
	{ "histfig_site_link_prison_site_building_profilest", DF_Type::histfig_site_link_prison_site_building_profilest },
	{ "histfig_site_link_seat_of_powerst", DF_Type::histfig_site_link_seat_of_powerst },
	{ "histfig_site_link_type", DF_Type::histfig_site_link_type },
	{ "historical_entity", DF_Type::historical_entity },
	{ "historical_entity__T_claims", DF_Type::historical_entity__T_claims },
	{ "historical_entity__T_derived_resources", DF_Type::historical_entity__T_derived_resources },
	{ "historical_entity__T_flags", DF_Type::historical_entity__T_flags },
	{ "historical_entity__T_guild_professions", DF_Type::historical_entity__T_guild_professions },
	{ "historical_entity__T_positions", DF_Type::historical_entity__T_positions },
	{ "historical_entity__T_relations", DF_Type::historical_entity__T_relations },
	{ "historical_entity__T_relations__T_constructions", DF_Type::historical_entity__T_relations__T_constructions },
	{ "historical_entity__T_relations__T_diplomacy", DF_Type::historical_entity__T_relations__T_diplomacy },
	{ "historical_entity__T_resources", DF_Type::historical_entity__T_resources },
	{ "historical_entity__T_resources__T_animals", DF_Type::historical_entity__T_resources__T_animals },
	{ "historical_entity__T_resources__T_metal", DF_Type::historical_entity__T_resources__T_metal },
	{ "historical_entity__T_resources__T_misc_mat", DF_Type::historical_entity__T_resources__T_misc_mat },
	{ "historical_entity__T_resources__T_organic", DF_Type::historical_entity__T_resources__T_organic },
	{ "historical_entity__T_resources__T_refuse", DF_Type::historical_entity__T_resources__T_refuse },
	{ "historical_entity__T_resources__T_unk13", DF_Type::historical_entity__T_resources__T_unk13 },
	{ "historical_entity__T_resources__T_wood_products", DF_Type::historical_entity__T_resources__T_wood_products },
	{ "historical_entity__T_tissue_styles", DF_Type::historical_entity__T_tissue_styles },
	{ "historical_entity__T_training_knowledge", DF_Type::historical_entity__T_training_knowledge },
	{ "historical_entity__T_unk_v47_1", DF_Type::historical_entity__T_unk_v47_1 },
	{ "historical_entity__T_unknown1d", DF_Type::historical_entity__T_unknown1d },
	{ "historical_entity__T_unknown1e", DF_Type::historical_entity__T_unknown1e },
	{ "historical_entity__T_unknown2", DF_Type::historical_entity__T_unknown2 },
	{ "historical_entity_type", DF_Type::historical_entity_type },
	{ "historical_figure", DF_Type::historical_figure },
	{ "historical_figure__T_unk_fc", DF_Type::historical_figure__T_unk_fc },
	{ "historical_figure__T_vague_relationships", DF_Type::historical_figure__T_vague_relationships },
	{ "historical_figure_info", DF_Type::historical_figure_info },
	{ "historical_figure_info__T_books", DF_Type::historical_figure_info__T_books },
	{ "historical_figure_info__T_books__T_flags", DF_Type::historical_figure_info__T_books__T_flags },
	{ "historical_figure_info__T_curse", DF_Type::historical_figure_info__T_curse },
	{ "historical_figure_info__T_curse__T_anon_1", DF_Type::historical_figure_info__T_curse__T_anon_1 },
	{ "historical_figure_info__T_curse__T_experiments", DF_Type::historical_figure_info__T_curse__T_experiments },
	{ "historical_figure_info__T_known_info", DF_Type::historical_figure_info__T_known_info },
	{ "historical_figure_info__T_known_info__T_anon_1", DF_Type::historical_figure_info__T_known_info__T_anon_1 },
	{ "historical_figure_info__T_known_info__T_anon_6", DF_Type::historical_figure_info__T_known_info__T_anon_6 },
	{ "historical_figure_info__T_known_info__T_knowledge", DF_Type::historical_figure_info__T_known_info__T_knowledge },
	{ "historical_figure_info__T_known_info__T_knowledge__T_knowledge_goal", DF_Type::historical_figure_info__T_known_info__T_knowledge__T_knowledge_goal },
	{ "historical_figure_info__T_known_info__T_unk_a8", DF_Type::historical_figure_info__T_known_info__T_unk_a8 },
	{ "historical_figure_info__T_masterpieces", DF_Type::historical_figure_info__T_masterpieces },
	{ "historical_figure_info__T_personality", DF_Type::historical_figure_info__T_personality },
	{ "historical_figure_info__T_relationships", DF_Type::historical_figure_info__T_relationships },
	{ "historical_figure_info__T_relationships__T_anon_1", DF_Type::historical_figure_info__T_relationships__T_anon_1 },
	{ "historical_figure_info__T_relationships__T_artifact_claims", DF_Type::historical_figure_info__T_relationships__T_artifact_claims },
	{ "historical_figure_info__T_relationships__T_hf_historical", DF_Type::historical_figure_info__T_relationships__T_hf_historical },
	{ "historical_figure_info__T_relationships__T_hf_visual", DF_Type::historical_figure_info__T_relationships__T_hf_visual },
	{ "historical_figure_info__T_relationships__T_intrigues", DF_Type::historical_figure_info__T_relationships__T_intrigues },
	{ "historical_figure_info__T_relationships__T_intrigues__T_intrigue", DF_Type::historical_figure_info__T_relationships__T_intrigues__T_intrigue },
	{ "historical_figure_info__T_relationships__T_intrigues__T_plots", DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots },
	{ "historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data", DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data },
	{ "historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data__T_Infiltrate_Society", DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data__T_Infiltrate_Society },
	{ "historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data__T_Sabotage_Actor", DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data__T_Sabotage_Actor },
	{ "historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_type", DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_type },
	{ "historical_figure_info__T_reputation", DF_Type::historical_figure_info__T_reputation },
	{ "historical_figure_info__T_reputation__T_anon_1", DF_Type::historical_figure_info__T_reputation__T_anon_1 },
	{ "historical_figure_info__T_reputation__T_unk_2c", DF_Type::historical_figure_info__T_reputation__T_unk_2c },
	{ "historical_figure_info__T_reputation__T_unk_2c__T_anon_12", DF_Type::historical_figure_info__T_reputation__T_unk_2c__T_anon_12 },
	{ "historical_figure_info__T_reputation__T_wanted", DF_Type::historical_figure_info__T_reputation__T_wanted },
	{ "historical_figure_info__T_reputation__T_wanted__T_unk", DF_Type::historical_figure_info__T_reputation__T_wanted__T_unk },
	{ "historical_figure_info__T_skills", DF_Type::historical_figure_info__T_skills },
	{ "historical_figure_info__T_skills__T_employment_held", DF_Type::historical_figure_info__T_skills__T_employment_held },
	{ "historical_figure_info__T_skills__T_employment_held__T_employment", DF_Type::historical_figure_info__T_skills__T_employment_held__T_employment },
	{ "historical_figure_info__T_whereabouts", DF_Type::historical_figure_info__T_whereabouts },
	{ "historical_figure_info__T_wounds", DF_Type::historical_figure_info__T_wounds },
	{ "historical_kills", DF_Type::historical_kills },
	{ "historical_kills__T_killed_undead", DF_Type::historical_kills__T_killed_undead },
	{ "history_era", DF_Type::history_era },
	{ "history_era__T_details", DF_Type::history_era__T_details },
	{ "history_era__T_title", DF_Type::history_era__T_title },
	{ "history_event", DF_Type::history_event },
	{ "history_event_add_entity_site_profile_flagst", DF_Type::history_event_add_entity_site_profile_flagst },
	{ "history_event_add_hf_entity_honorst", DF_Type::history_event_add_hf_entity_honorst },
	{ "history_event_add_hf_entity_linkst", DF_Type::history_event_add_hf_entity_linkst },
	{ "history_event_add_hf_hf_linkst", DF_Type::history_event_add_hf_hf_linkst },
	{ "history_event_add_hf_site_linkst", DF_Type::history_event_add_hf_site_linkst },
	{ "history_event_agreement_concludedst", DF_Type::history_event_agreement_concludedst },
	{ "history_event_agreement_formedst", DF_Type::history_event_agreement_formedst },
	{ "history_event_agreements_voidedst", DF_Type::history_event_agreements_voidedst },
	{ "history_event_artifact_claim_formedst", DF_Type::history_event_artifact_claim_formedst },
	{ "history_event_artifact_copiedst", DF_Type::history_event_artifact_copiedst },
	{ "history_event_artifact_copiedst__T_flags2", DF_Type::history_event_artifact_copiedst__T_flags2 },
	{ "history_event_artifact_createdst", DF_Type::history_event_artifact_createdst },
	{ "history_event_artifact_createdst__T_flags2", DF_Type::history_event_artifact_createdst__T_flags2 },
	{ "history_event_artifact_destroyedst", DF_Type::history_event_artifact_destroyedst },
	{ "history_event_artifact_droppedst", DF_Type::history_event_artifact_droppedst },
	{ "history_event_artifact_foundst", DF_Type::history_event_artifact_foundst },
	{ "history_event_artifact_givenst", DF_Type::history_event_artifact_givenst },
	{ "history_event_artifact_hiddenst", DF_Type::history_event_artifact_hiddenst },
	{ "history_event_artifact_lostst", DF_Type::history_event_artifact_lostst },
	{ "history_event_artifact_possessedst", DF_Type::history_event_artifact_possessedst },
	{ "history_event_artifact_recoveredst", DF_Type::history_event_artifact_recoveredst },
	{ "history_event_artifact_storedst", DF_Type::history_event_artifact_storedst },
	{ "history_event_artifact_transformedst", DF_Type::history_event_artifact_transformedst },
	{ "history_event_assume_identityst", DF_Type::history_event_assume_identityst },
	{ "history_event_body_abusedst", DF_Type::history_event_body_abusedst },
	{ "history_event_body_abusedst__T_abuse_data", DF_Type::history_event_body_abusedst__T_abuse_data },
	{ "history_event_body_abusedst__T_abuse_data__T_Animated", DF_Type::history_event_body_abusedst__T_abuse_data__T_Animated },
	{ "history_event_body_abusedst__T_abuse_data__T_Flayed", DF_Type::history_event_body_abusedst__T_abuse_data__T_Flayed },
	{ "history_event_body_abusedst__T_abuse_data__T_Hung", DF_Type::history_event_body_abusedst__T_abuse_data__T_Hung },
	{ "history_event_body_abusedst__T_abuse_data__T_Impaled", DF_Type::history_event_body_abusedst__T_abuse_data__T_Impaled },
	{ "history_event_body_abusedst__T_abuse_data__T_Piled", DF_Type::history_event_body_abusedst__T_abuse_data__T_Piled },
	{ "history_event_body_abusedst__T_abuse_data__T_Piled__T_pile_type", DF_Type::history_event_body_abusedst__T_abuse_data__T_Piled__T_pile_type },
	{ "history_event_body_abusedst__T_abuse_type", DF_Type::history_event_body_abusedst__T_abuse_type },
	{ "history_event_building_profile_acquiredst", DF_Type::history_event_building_profile_acquiredst },
	{ "history_event_ceremonyst", DF_Type::history_event_ceremonyst },
	{ "history_event_change_creature_typest", DF_Type::history_event_change_creature_typest },
	{ "history_event_change_hf_body_statest", DF_Type::history_event_change_hf_body_statest },
	{ "history_event_change_hf_jobst", DF_Type::history_event_change_hf_jobst },
	{ "history_event_change_hf_moodst", DF_Type::history_event_change_hf_moodst },
	{ "history_event_change_hf_statest", DF_Type::history_event_change_hf_statest },
	{ "history_event_change_hf_statest__T_state", DF_Type::history_event_change_hf_statest__T_state },
	{ "history_event_circumstance_info", DF_Type::history_event_circumstance_info },
	{ "history_event_circumstance_info__T_data", DF_Type::history_event_circumstance_info__T_data },
	{ "history_event_collection", DF_Type::history_event_collection },
	{ "history_event_collection_abductionst", DF_Type::history_event_collection_abductionst },
	{ "history_event_collection_battlest", DF_Type::history_event_collection_battlest },
	{ "history_event_collection_beast_attackst", DF_Type::history_event_collection_beast_attackst },
	{ "history_event_collection_ceremonyst", DF_Type::history_event_collection_ceremonyst },
	{ "history_event_collection_competitionst", DF_Type::history_event_collection_competitionst },
	{ "history_event_collection_duelst", DF_Type::history_event_collection_duelst },
	{ "history_event_collection_entity_overthrownst", DF_Type::history_event_collection_entity_overthrownst },
	{ "history_event_collection_insurrectionst", DF_Type::history_event_collection_insurrectionst },
	{ "history_event_collection_journeyst", DF_Type::history_event_collection_journeyst },
	{ "history_event_collection_occasionst", DF_Type::history_event_collection_occasionst },
	{ "history_event_collection_performancest", DF_Type::history_event_collection_performancest },
	{ "history_event_collection_persecutionst", DF_Type::history_event_collection_persecutionst },
	{ "history_event_collection_processionst", DF_Type::history_event_collection_processionst },
	{ "history_event_collection_purgest", DF_Type::history_event_collection_purgest },
	{ "history_event_collection_raidst", DF_Type::history_event_collection_raidst },
	{ "history_event_collection_site_conqueredst", DF_Type::history_event_collection_site_conqueredst },
	{ "history_event_collection_theftst", DF_Type::history_event_collection_theftst },
	{ "history_event_collection_type", DF_Type::history_event_collection_type },
	{ "history_event_collection_warst", DF_Type::history_event_collection_warst },
	{ "history_event_collection_warst__T_unk", DF_Type::history_event_collection_warst__T_unk },
	{ "history_event_competitionst", DF_Type::history_event_competitionst },
	{ "history_event_context", DF_Type::history_event_context },
	{ "history_event_context__T_unk_10", DF_Type::history_event_context__T_unk_10 },
	{ "history_event_create_entity_positionst", DF_Type::history_event_create_entity_positionst },
	{ "history_event_created_buildingst", DF_Type::history_event_created_buildingst },
	{ "history_event_created_sitest", DF_Type::history_event_created_sitest },
	{ "history_event_created_world_constructionst", DF_Type::history_event_created_world_constructionst },
	{ "history_event_creature_devouredst", DF_Type::history_event_creature_devouredst },
	{ "history_event_dance_form_createdst", DF_Type::history_event_dance_form_createdst },
	{ "history_event_diplomat_lostst", DF_Type::history_event_diplomat_lostst },
	{ "history_event_entity_actionst", DF_Type::history_event_entity_actionst },
	{ "history_event_entity_alliance_formedst", DF_Type::history_event_entity_alliance_formedst },
	{ "history_event_entity_breach_feature_layerst", DF_Type::history_event_entity_breach_feature_layerst },
	{ "history_event_entity_createdst", DF_Type::history_event_entity_createdst },
	{ "history_event_entity_dissolvedst", DF_Type::history_event_entity_dissolvedst },
	{ "history_event_entity_equipment_purchasest", DF_Type::history_event_entity_equipment_purchasest },
	{ "history_event_entity_expels_hfst", DF_Type::history_event_entity_expels_hfst },
	{ "history_event_entity_fled_sitest", DF_Type::history_event_entity_fled_sitest },
	{ "history_event_entity_incorporatedst", DF_Type::history_event_entity_incorporatedst },
	{ "history_event_entity_lawst", DF_Type::history_event_entity_lawst },
	{ "history_event_entity_lawst__T_add_flags", DF_Type::history_event_entity_lawst__T_add_flags },
	{ "history_event_entity_lawst__T_remove_flags", DF_Type::history_event_entity_lawst__T_remove_flags },
	{ "history_event_entity_overthrownst", DF_Type::history_event_entity_overthrownst },
	{ "history_event_entity_persecutedst", DF_Type::history_event_entity_persecutedst },
	{ "history_event_entity_rampaged_in_sitest", DF_Type::history_event_entity_rampaged_in_sitest },
	{ "history_event_entity_razed_buildingst", DF_Type::history_event_entity_razed_buildingst },
	{ "history_event_entity_searched_sitest", DF_Type::history_event_entity_searched_sitest },
	{ "history_event_failed_frame_attemptst", DF_Type::history_event_failed_frame_attemptst },
	{ "history_event_failed_intrigue_corruptionst", DF_Type::history_event_failed_intrigue_corruptionst },
	{ "history_event_first_contact_failedst", DF_Type::history_event_first_contact_failedst },
	{ "history_event_first_contactst", DF_Type::history_event_first_contactst },
	{ "history_event_flags", DF_Type::history_event_flags },
	{ "history_event_gamblest", DF_Type::history_event_gamblest },
	{ "history_event_hf_act_on_artifactst", DF_Type::history_event_hf_act_on_artifactst },
	{ "history_event_hf_act_on_artifactst__T_action", DF_Type::history_event_hf_act_on_artifactst__T_action },
	{ "history_event_hf_act_on_buildingst", DF_Type::history_event_hf_act_on_buildingst },
	{ "history_event_hf_act_on_buildingst__T_action", DF_Type::history_event_hf_act_on_buildingst__T_action },
	{ "history_event_hf_attacked_sitest", DF_Type::history_event_hf_attacked_sitest },
	{ "history_event_hf_confrontedst", DF_Type::history_event_hf_confrontedst },
	{ "history_event_hf_convictedst", DF_Type::history_event_hf_convictedst },
	{ "history_event_hf_convictedst__T_plot_flags", DF_Type::history_event_hf_convictedst__T_plot_flags },
	{ "history_event_hf_convictedst__T_punishment_flags", DF_Type::history_event_hf_convictedst__T_punishment_flags },
	{ "history_event_hf_destroyed_sitest", DF_Type::history_event_hf_destroyed_sitest },
	{ "history_event_hf_does_interactionst", DF_Type::history_event_hf_does_interactionst },
	{ "history_event_hf_enslavedst", DF_Type::history_event_hf_enslavedst },
	{ "history_event_hf_freedst", DF_Type::history_event_hf_freedst },
	{ "history_event_hf_gains_secret_goalst", DF_Type::history_event_hf_gains_secret_goalst },
	{ "history_event_hf_interrogatedst", DF_Type::history_event_hf_interrogatedst },
	{ "history_event_hf_interrogatedst__T_interrogation_flags", DF_Type::history_event_hf_interrogatedst__T_interrogation_flags },
	{ "history_event_hf_learns_secretst", DF_Type::history_event_hf_learns_secretst },
	{ "history_event_hf_preachst", DF_Type::history_event_hf_preachst },
	{ "history_event_hf_ransomedst", DF_Type::history_event_hf_ransomedst },
	{ "history_event_hf_razed_buildingst", DF_Type::history_event_hf_razed_buildingst },
	{ "history_event_hf_recruited_unit_type_for_entityst", DF_Type::history_event_hf_recruited_unit_type_for_entityst },
	{ "history_event_hf_relationship_deniedst", DF_Type::history_event_hf_relationship_deniedst },
	{ "history_event_hfs_formed_intrigue_relationshipst", DF_Type::history_event_hfs_formed_intrigue_relationshipst },
	{ "history_event_hfs_formed_reputation_relationshipst", DF_Type::history_event_hfs_formed_reputation_relationshipst },
	{ "history_event_hist_figure_abductedst", DF_Type::history_event_hist_figure_abductedst },
	{ "history_event_hist_figure_diedst", DF_Type::history_event_hist_figure_diedst },
	{ "history_event_hist_figure_new_petst", DF_Type::history_event_hist_figure_new_petst },
	{ "history_event_hist_figure_reach_summitst", DF_Type::history_event_hist_figure_reach_summitst },
	{ "history_event_hist_figure_reunionst", DF_Type::history_event_hist_figure_reunionst },
	{ "history_event_hist_figure_revivedst", DF_Type::history_event_hist_figure_revivedst },
	{ "history_event_hist_figure_revivedst__T_flags2", DF_Type::history_event_hist_figure_revivedst__T_flags2 },
	{ "history_event_hist_figure_simple_actionst", DF_Type::history_event_hist_figure_simple_actionst },
	{ "history_event_hist_figure_simple_battle_eventst", DF_Type::history_event_hist_figure_simple_battle_eventst },
	{ "history_event_hist_figure_travelst", DF_Type::history_event_hist_figure_travelst },
	{ "history_event_hist_figure_travelst__T_reason", DF_Type::history_event_hist_figure_travelst__T_reason },
	{ "history_event_hist_figure_woundedst", DF_Type::history_event_hist_figure_woundedst },
	{ "history_event_hist_figure_woundedst__T_flags2", DF_Type::history_event_hist_figure_woundedst__T_flags2 },
	{ "history_event_hist_figure_woundedst__T_injury_type", DF_Type::history_event_hist_figure_woundedst__T_injury_type },
	{ "history_event_insurrection_endedst", DF_Type::history_event_insurrection_endedst },
	{ "history_event_insurrection_startedst", DF_Type::history_event_insurrection_startedst },
	{ "history_event_item_stolenst", DF_Type::history_event_item_stolenst },
	{ "history_event_knowledge_discoveredst", DF_Type::history_event_knowledge_discoveredst },
	{ "history_event_masterpiece_created_arch_constructst", DF_Type::history_event_masterpiece_created_arch_constructst },
	{ "history_event_masterpiece_created_arch_designst", DF_Type::history_event_masterpiece_created_arch_designst },
	{ "history_event_masterpiece_created_dye_itemst", DF_Type::history_event_masterpiece_created_dye_itemst },
	{ "history_event_masterpiece_created_engravingst", DF_Type::history_event_masterpiece_created_engravingst },
	{ "history_event_masterpiece_created_foodst", DF_Type::history_event_masterpiece_created_foodst },
	{ "history_event_masterpiece_created_item_improvementst", DF_Type::history_event_masterpiece_created_item_improvementst },
	{ "history_event_masterpiece_created_itemst", DF_Type::history_event_masterpiece_created_itemst },
	{ "history_event_masterpiece_createdst", DF_Type::history_event_masterpiece_createdst },
	{ "history_event_masterpiece_lostst", DF_Type::history_event_masterpiece_lostst },
	{ "history_event_merchantst", DF_Type::history_event_merchantst },
	{ "history_event_modified_buildingst", DF_Type::history_event_modified_buildingst },
	{ "history_event_modified_buildingst__T_modification", DF_Type::history_event_modified_buildingst__T_modification },
	{ "history_event_musical_form_createdst", DF_Type::history_event_musical_form_createdst },
	{ "history_event_performancest", DF_Type::history_event_performancest },
	{ "history_event_poetic_form_createdst", DF_Type::history_event_poetic_form_createdst },
	{ "history_event_processionst", DF_Type::history_event_processionst },
	{ "history_event_reason", DF_Type::history_event_reason },
	{ "history_event_reason_info", DF_Type::history_event_reason_info },
	{ "history_event_reason_info__T_data", DF_Type::history_event_reason_info__T_data },
	{ "history_event_reclaim_sitest", DF_Type::history_event_reclaim_sitest },
	{ "history_event_reclaim_sitest__T_flags2", DF_Type::history_event_reclaim_sitest__T_flags2 },
	{ "history_event_regionpop_incorporated_into_entityst", DF_Type::history_event_regionpop_incorporated_into_entityst },
	{ "history_event_remove_hf_entity_linkst", DF_Type::history_event_remove_hf_entity_linkst },
	{ "history_event_remove_hf_hf_linkst", DF_Type::history_event_remove_hf_hf_linkst },
	{ "history_event_remove_hf_site_linkst", DF_Type::history_event_remove_hf_site_linkst },
	{ "history_event_replaced_buildingst", DF_Type::history_event_replaced_buildingst },
	{ "history_event_sabotagest", DF_Type::history_event_sabotagest },
	{ "history_event_simple_battle_subtype", DF_Type::history_event_simple_battle_subtype },
	{ "history_event_site_diedst", DF_Type::history_event_site_diedst },
	{ "history_event_site_diedst__T_flags2", DF_Type::history_event_site_diedst__T_flags2 },
	{ "history_event_site_disputest", DF_Type::history_event_site_disputest },
	{ "history_event_site_retiredst", DF_Type::history_event_site_retiredst },
	{ "history_event_site_retiredst__T_flags2", DF_Type::history_event_site_retiredst__T_flags2 },
	{ "history_event_site_surrenderedst", DF_Type::history_event_site_surrenderedst },
	{ "history_event_sneak_into_sitest", DF_Type::history_event_sneak_into_sitest },
	{ "history_event_spotted_leaving_sitest", DF_Type::history_event_spotted_leaving_sitest },
	{ "history_event_squad_vs_squadst", DF_Type::history_event_squad_vs_squadst },
	{ "history_event_tactical_situationst", DF_Type::history_event_tactical_situationst },
	{ "history_event_tactical_situationst__T_tactics_flags", DF_Type::history_event_tactical_situationst__T_tactics_flags },
	{ "history_event_topicagreement_concludedst", DF_Type::history_event_topicagreement_concludedst },
	{ "history_event_topicagreement_madest", DF_Type::history_event_topicagreement_madest },
	{ "history_event_topicagreement_rejectedst", DF_Type::history_event_topicagreement_rejectedst },
	{ "history_event_tradest", DF_Type::history_event_tradest },
	{ "history_event_type", DF_Type::history_event_type },
	{ "history_event_war_attacked_sitest", DF_Type::history_event_war_attacked_sitest },
	{ "history_event_war_destroyed_sitest", DF_Type::history_event_war_destroyed_sitest },
	{ "history_event_war_field_battlest", DF_Type::history_event_war_field_battlest },
	{ "history_event_war_peace_acceptedst", DF_Type::history_event_war_peace_acceptedst },
	{ "history_event_war_peace_rejectedst", DF_Type::history_event_war_peace_rejectedst },
	{ "history_event_war_plundered_sitest", DF_Type::history_event_war_plundered_sitest },
	{ "history_event_war_site_new_leaderst", DF_Type::history_event_war_site_new_leaderst },
	{ "history_event_war_site_taken_overst", DF_Type::history_event_war_site_taken_overst },
	{ "history_event_war_site_tribute_forcedst", DF_Type::history_event_war_site_tribute_forcedst },
	{ "history_event_war_site_tribute_forcedst__T_tribute_flags", DF_Type::history_event_war_site_tribute_forcedst__T_tribute_flags },
	{ "history_event_written_content_composedst", DF_Type::history_event_written_content_composedst },
	{ "history_hit_item", DF_Type::history_hit_item },
	{ "hive_flags", DF_Type::hive_flags },
	{ "honors_type", DF_Type::honors_type },
	{ "honors_type__T_flags", DF_Type::honors_type__T_flags },
	{ "honors_type__T_required_skill_type", DF_Type::honors_type__T_required_skill_type },
	{ "hospital_supplies", DF_Type::hospital_supplies },
	{ "hospital_supplies__T_supplies_needed", DF_Type::hospital_supplies__T_supplies_needed },
	{ "identity", DF_Type::identity },
	{ "identity_unk_94", DF_Type::identity_unk_94 },
	{ "improvement_type", DF_Type::improvement_type },
	{ "incident", DF_Type::incident },
	{ "incident__T_data", DF_Type::incident__T_data },
	{ "incident__T_flags", DF_Type::incident__T_flags },
	{ "incident__T_type", DF_Type::incident__T_type },
	{ "incident_hfid", DF_Type::incident_hfid },
	{ "incident_sub10", DF_Type::incident_sub10 },
	{ "incident_sub6_performance", DF_Type::incident_sub6_performance },
	{ "incident_sub6_performance__T_participants", DF_Type::incident_sub6_performance__T_participants },
	{ "incident_sub7", DF_Type::incident_sub7 },
	{ "incident_sub8", DF_Type::incident_sub8 },
	{ "incident_sub9", DF_Type::incident_sub9 },
	{ "inclusion_type", DF_Type::inclusion_type },
	{ "init", DF_Type::init },
	{ "init_display", DF_Type::init_display },
	{ "init_display__T_windowed", DF_Type::init_display__T_windowed },
	{ "init_display_flags", DF_Type::init_display_flags },
	{ "init_font", DF_Type::init_font },
	{ "init_font__T_use_ttf", DF_Type::init_font__T_use_ttf },
	{ "init_input", DF_Type::init_input },
	{ "init_input_flags", DF_Type::init_input_flags },
	{ "init_media", DF_Type::init_media },
	{ "init_media_flags", DF_Type::init_media_flags },
	{ "init_window", DF_Type::init_window },
	{ "init_window_flags", DF_Type::init_window_flags },
	{ "inorganic_flags", DF_Type::inorganic_flags },
	{ "inorganic_raw", DF_Type::inorganic_raw },
	{ "inorganic_raw__T_environment", DF_Type::inorganic_raw__T_environment },
	{ "inorganic_raw__T_environment_spec", DF_Type::inorganic_raw__T_environment_spec },
	{ "inorganic_raw__T_metal_ore", DF_Type::inorganic_raw__T_metal_ore },
	{ "inorganic_raw__T_thread_metal", DF_Type::inorganic_raw__T_thread_metal },
	{ "instrument_flags", DF_Type::instrument_flags },
	{ "instrument_piece", DF_Type::instrument_piece },
	{ "instrument_piece__T_flags", DF_Type::instrument_piece__T_flags },
	{ "instrument_register", DF_Type::instrument_register },
	{ "insurrection_outcome", DF_Type::insurrection_outcome },
	{ "interaction", DF_Type::interaction },
	{ "interaction_effect", DF_Type::interaction_effect },
	{ "interaction_effect__T_flags", DF_Type::interaction_effect__T_flags },
	{ "interaction_effect_add_syndromest", DF_Type::interaction_effect_add_syndromest },
	{ "interaction_effect_animatest", DF_Type::interaction_effect_animatest },
	{ "interaction_effect_change_item_qualityst", DF_Type::interaction_effect_change_item_qualityst },
	{ "interaction_effect_change_weatherst", DF_Type::interaction_effect_change_weatherst },
	{ "interaction_effect_cleanst", DF_Type::interaction_effect_cleanst },
	{ "interaction_effect_contactst", DF_Type::interaction_effect_contactst },
	{ "interaction_effect_create_itemst", DF_Type::interaction_effect_create_itemst },
	{ "interaction_effect_hidest", DF_Type::interaction_effect_hidest },
	{ "interaction_effect_location_hint", DF_Type::interaction_effect_location_hint },
	{ "interaction_effect_material_emissionst", DF_Type::interaction_effect_material_emissionst },
	{ "interaction_effect_propel_unitst", DF_Type::interaction_effect_propel_unitst },
	{ "interaction_effect_resurrectst", DF_Type::interaction_effect_resurrectst },
	{ "interaction_effect_summon_unitst", DF_Type::interaction_effect_summon_unitst },
	{ "interaction_effect_type", DF_Type::interaction_effect_type },
	{ "interaction_flags", DF_Type::interaction_flags },
	{ "interaction_instance", DF_Type::interaction_instance },
	{ "interaction_source", DF_Type::interaction_source },
	{ "interaction_source_attackst", DF_Type::interaction_source_attackst },
	{ "interaction_source_creature_actionst", DF_Type::interaction_source_creature_actionst },
	{ "interaction_source_deityst", DF_Type::interaction_source_deityst },
	{ "interaction_source_disturbancest", DF_Type::interaction_source_disturbancest },
	{ "interaction_source_experimentst", DF_Type::interaction_source_experimentst },
	{ "interaction_source_ingestionst", DF_Type::interaction_source_ingestionst },
	{ "interaction_source_regionst", DF_Type::interaction_source_regionst },
	{ "interaction_source_regionst__T_region_flags", DF_Type::interaction_source_regionst__T_region_flags },
	{ "interaction_source_secretst", DF_Type::interaction_source_secretst },
	{ "interaction_source_secretst__T_learn_flags", DF_Type::interaction_source_secretst__T_learn_flags },
	{ "interaction_source_type", DF_Type::interaction_source_type },
	{ "interaction_source_underground_specialst", DF_Type::interaction_source_underground_specialst },
	{ "interaction_source_usage_hint", DF_Type::interaction_source_usage_hint },
	{ "interaction_target", DF_Type::interaction_target },
	{ "interaction_target_corpsest", DF_Type::interaction_target_corpsest },
	{ "interaction_target_creaturest", DF_Type::interaction_target_creaturest },
	{ "interaction_target_info", DF_Type::interaction_target_info },
	{ "interaction_target_info__T_restrictions", DF_Type::interaction_target_info__T_restrictions },
	{ "interaction_target_location_type", DF_Type::interaction_target_location_type },
	{ "interaction_target_locationst", DF_Type::interaction_target_locationst },
	{ "interaction_target_materialst", DF_Type::interaction_target_materialst },
	{ "interaction_target_materialst__T_restrictions", DF_Type::interaction_target_materialst__T_restrictions },
	{ "interaction_target_type", DF_Type::interaction_target_type },
	{ "interface_breakdown_types", DF_Type::interface_breakdown_types },
	{ "interface_button", DF_Type::interface_button },
	{ "interface_button_building_category_selectorst", DF_Type::interface_button_building_category_selectorst },
	{ "interface_button_building_custom_category_selectorst", DF_Type::interface_button_building_custom_category_selectorst },
	{ "interface_button_building_material_selectorst", DF_Type::interface_button_building_material_selectorst },
	{ "interface_button_building_new_jobst", DF_Type::interface_button_building_new_jobst },
	{ "interface_button_buildingst", DF_Type::interface_button_buildingst },
	{ "interface_button_construction_building_selectorst", DF_Type::interface_button_construction_building_selectorst },
	{ "interface_button_construction_category_selectorst", DF_Type::interface_button_construction_category_selectorst },
	{ "interface_button_construction_category_selectorst__T_category_id", DF_Type::interface_button_construction_category_selectorst__T_category_id },
	{ "interface_button_construction_donest", DF_Type::interface_button_construction_donest },
	{ "interface_button_constructionst", DF_Type::interface_button_constructionst },
	{ "interface_key", DF_Type::interface_key },
	{ "interfacest", DF_Type::interfacest },
	{ "invasion_info", DF_Type::invasion_info },
	{ "invasion_info__T_flags", DF_Type::invasion_info__T_flags },
	{ "item", DF_Type::item },
	{ "item_actual", DF_Type::item_actual },
	{ "item_ammost", DF_Type::item_ammost },
	{ "item_amuletst", DF_Type::item_amuletst },
	{ "item_animaltrapst", DF_Type::item_animaltrapst },
	{ "item_anvilst", DF_Type::item_anvilst },
	{ "item_armorst", DF_Type::item_armorst },
	{ "item_armorstandst", DF_Type::item_armorstandst },
	{ "item_backpackst", DF_Type::item_backpackst },
	{ "item_ballistaarrowheadst", DF_Type::item_ballistaarrowheadst },
	{ "item_ballistapartsst", DF_Type::item_ballistapartsst },
	{ "item_barrelst", DF_Type::item_barrelst },
	{ "item_barst", DF_Type::item_barst },
	{ "item_bedst", DF_Type::item_bedst },
	{ "item_binst", DF_Type::item_binst },
	{ "item_blocksst", DF_Type::item_blocksst },
	{ "item_body_component", DF_Type::item_body_component },
	{ "item_body_component__T_appearance", DF_Type::item_body_component__T_appearance },
	{ "item_body_component__T_body", DF_Type::item_body_component__T_body },
	{ "item_body_component__T_bone1", DF_Type::item_body_component__T_bone1 },
	{ "item_body_component__T_bone2", DF_Type::item_body_component__T_bone2 },
	{ "item_body_component__T_corpse_flags", DF_Type::item_body_component__T_corpse_flags },
	{ "item_bookst", DF_Type::item_bookst },
	{ "item_boulderst", DF_Type::item_boulderst },
	{ "item_boxst", DF_Type::item_boxst },
	{ "item_braceletst", DF_Type::item_braceletst },
	{ "item_branchst", DF_Type::item_branchst },
	{ "item_bucketst", DF_Type::item_bucketst },
	{ "item_cabinetst", DF_Type::item_cabinetst },
	{ "item_cagest", DF_Type::item_cagest },
	{ "item_catapultpartsst", DF_Type::item_catapultpartsst },
	{ "item_chainst", DF_Type::item_chainst },
	{ "item_chairst", DF_Type::item_chairst },
	{ "item_cheesest", DF_Type::item_cheesest },
	{ "item_clothst", DF_Type::item_clothst },
	{ "item_coffinst", DF_Type::item_coffinst },
	{ "item_coinst", DF_Type::item_coinst },
	{ "item_constructed", DF_Type::item_constructed },
	{ "item_corpsepiecest", DF_Type::item_corpsepiecest },
	{ "item_corpsest", DF_Type::item_corpsest },
	{ "item_crafted", DF_Type::item_crafted },
	{ "item_critter", DF_Type::item_critter },
	{ "item_crownst", DF_Type::item_crownst },
	{ "item_crutchst", DF_Type::item_crutchst },
	{ "item_doorst", DF_Type::item_doorst },
	{ "item_drinkst", DF_Type::item_drinkst },
	{ "item_earringst", DF_Type::item_earringst },
	{ "item_eggst", DF_Type::item_eggst },
	{ "item_eggst__T_egg_flags", DF_Type::item_eggst__T_egg_flags },
	{ "item_figurinest", DF_Type::item_figurinest },
	{ "item_filter_spec", DF_Type::item_filter_spec },
	{ "item_fish_rawst", DF_Type::item_fish_rawst },
	{ "item_fishst", DF_Type::item_fishst },
	{ "item_flags", DF_Type::item_flags },
	{ "item_flags2", DF_Type::item_flags2 },
	{ "item_flaskst", DF_Type::item_flaskst },
	{ "item_floodgatest", DF_Type::item_floodgatest },
	{ "item_foodst", DF_Type::item_foodst },
	{ "item_foodst__T_ingredients", DF_Type::item_foodst__T_ingredients },
	{ "item_gemst", DF_Type::item_gemst },
	{ "item_globst", DF_Type::item_globst },
	{ "item_glovesst", DF_Type::item_glovesst },
	{ "item_gobletst", DF_Type::item_gobletst },
	{ "item_gratest", DF_Type::item_gratest },
	{ "item_hatch_coverst", DF_Type::item_hatch_coverst },
	{ "item_helmst", DF_Type::item_helmst },
	{ "item_history_info", DF_Type::item_history_info },
	{ "item_instrumentst", DF_Type::item_instrumentst },
	{ "item_kill_info", DF_Type::item_kill_info },
	{ "item_liquid", DF_Type::item_liquid },
	{ "item_liquid_miscst", DF_Type::item_liquid_miscst },
	{ "item_liquipowder", DF_Type::item_liquipowder },
	{ "item_magicness", DF_Type::item_magicness },
	{ "item_magicness_type", DF_Type::item_magicness_type },
	{ "item_matstate", DF_Type::item_matstate },
	{ "item_meatst", DF_Type::item_meatst },
	{ "item_millstonest", DF_Type::item_millstonest },
	{ "item_orthopedic_castst", DF_Type::item_orthopedic_castst },
	{ "item_pantsst", DF_Type::item_pantsst },
	{ "item_petst", DF_Type::item_petst },
	{ "item_petst__T_pet_flags", DF_Type::item_petst__T_pet_flags },
	{ "item_pipe_sectionst", DF_Type::item_pipe_sectionst },
	{ "item_plant_growthst", DF_Type::item_plant_growthst },
	{ "item_plantst", DF_Type::item_plantst },
	{ "item_powder", DF_Type::item_powder },
	{ "item_powder_miscst", DF_Type::item_powder_miscst },
	{ "item_quality", DF_Type::item_quality },
	{ "item_quernst", DF_Type::item_quernst },
	{ "item_quiverst", DF_Type::item_quiverst },
	{ "item_remainsst", DF_Type::item_remainsst },
	{ "item_ringst", DF_Type::item_ringst },
	{ "item_rockst", DF_Type::item_rockst },
	{ "item_roughst", DF_Type::item_roughst },
	{ "item_scepterst", DF_Type::item_scepterst },
	{ "item_seedsst", DF_Type::item_seedsst },
	{ "item_sheetst", DF_Type::item_sheetst },
	{ "item_shieldst", DF_Type::item_shieldst },
	{ "item_shoesst", DF_Type::item_shoesst },
	{ "item_siegeammost", DF_Type::item_siegeammost },
	{ "item_skin_tannedst", DF_Type::item_skin_tannedst },
	{ "item_slabst", DF_Type::item_slabst },
	{ "item_smallgemst", DF_Type::item_smallgemst },
	{ "item_splintst", DF_Type::item_splintst },
	{ "item_statuest", DF_Type::item_statuest },
	{ "item_stockpile_ref", DF_Type::item_stockpile_ref },
	{ "item_tablest", DF_Type::item_tablest },
	{ "item_threadst", DF_Type::item_threadst },
	{ "item_toolst", DF_Type::item_toolst },
	{ "item_totemst", DF_Type::item_totemst },
	{ "item_toyst", DF_Type::item_toyst },
	{ "item_traction_benchst", DF_Type::item_traction_benchst },
	{ "item_trapcompst", DF_Type::item_trapcompst },
	{ "item_trappartsst", DF_Type::item_trappartsst },
	{ "item_type", DF_Type::item_type },
	{ "item_verminst", DF_Type::item_verminst },
	{ "item_weaponrackst", DF_Type::item_weaponrackst },
	{ "item_weaponst", DF_Type::item_weaponst },
	{ "item_windowst", DF_Type::item_windowst },
	{ "item_woodst", DF_Type::item_woodst },
	{ "itemdef", DF_Type::itemdef },
	{ "itemdef_ammost", DF_Type::itemdef_ammost },
	{ "itemdef_armorst", DF_Type::itemdef_armorst },
	{ "itemdef_foodst", DF_Type::itemdef_foodst },
	{ "itemdef_glovesst", DF_Type::itemdef_glovesst },
	{ "itemdef_helmst", DF_Type::itemdef_helmst },
	{ "itemdef_instrumentst", DF_Type::itemdef_instrumentst },
	{ "itemdef_pantsst", DF_Type::itemdef_pantsst },
	{ "itemdef_shieldst", DF_Type::itemdef_shieldst },
	{ "itemdef_shoesst", DF_Type::itemdef_shoesst },
	{ "itemdef_siegeammost", DF_Type::itemdef_siegeammost },
	{ "itemdef_toolst", DF_Type::itemdef_toolst },
	{ "itemdef_toolst__T_default_improvements", DF_Type::itemdef_toolst__T_default_improvements },
	{ "itemdef_toyst", DF_Type::itemdef_toyst },
	{ "itemdef_trapcompst", DF_Type::itemdef_trapcompst },
	{ "itemdef_weaponst", DF_Type::itemdef_weaponst },
	{ "itemimprovement", DF_Type::itemimprovement },
	{ "itemimprovement_art_imagest", DF_Type::itemimprovement_art_imagest },
	{ "itemimprovement_bandsst", DF_Type::itemimprovement_bandsst },
	{ "itemimprovement_clothst", DF_Type::itemimprovement_clothst },
	{ "itemimprovement_coveredst", DF_Type::itemimprovement_coveredst },
	{ "itemimprovement_coveredst__T_cover_flags", DF_Type::itemimprovement_coveredst__T_cover_flags },
	{ "itemimprovement_illustrationst", DF_Type::itemimprovement_illustrationst },
	{ "itemimprovement_instrument_piecest", DF_Type::itemimprovement_instrument_piecest },
	{ "itemimprovement_itemspecificst", DF_Type::itemimprovement_itemspecificst },
	{ "itemimprovement_pagesst", DF_Type::itemimprovement_pagesst },
	{ "itemimprovement_rings_hangingst", DF_Type::itemimprovement_rings_hangingst },
	{ "itemimprovement_sewn_imagest", DF_Type::itemimprovement_sewn_imagest },
	{ "itemimprovement_sewn_imagest__T_cloth", DF_Type::itemimprovement_sewn_imagest__T_cloth },
	{ "itemimprovement_specific_type", DF_Type::itemimprovement_specific_type },
	{ "itemimprovement_spikesst", DF_Type::itemimprovement_spikesst },
	{ "itemimprovement_threadst", DF_Type::itemimprovement_threadst },
	{ "itemimprovement_writingst", DF_Type::itemimprovement_writingst },
	{ "items_other_id", DF_Type::items_other_id },
	{ "job", DF_Type::job },
	{ "job_art_specification", DF_Type::job_art_specification },
	{ "job_art_specification__T_type", DF_Type::job_art_specification__T_type },
	{ "job_flags", DF_Type::job_flags },
	{ "job_handler", DF_Type::job_handler },
	{ "job_handler__T_anon_1", DF_Type::job_handler__T_anon_1 },
	{ "job_handler__T_postings", DF_Type::job_handler__T_postings },
	{ "job_handler__T_postings__T_flags", DF_Type::job_handler__T_postings__T_flags },
	{ "job_item", DF_Type::job_item },
	{ "job_item_filter", DF_Type::job_item_filter },
	{ "job_item_flags1", DF_Type::job_item_flags1 },
	{ "job_item_flags2", DF_Type::job_item_flags2 },
	{ "job_item_flags3", DF_Type::job_item_flags3 },
	{ "job_item_ref", DF_Type::job_item_ref },
	{ "job_item_ref__T_role", DF_Type::job_item_ref__T_role },
	{ "job_item_vector_id", DF_Type::job_item_vector_id },
	{ "job_list_link", DF_Type::job_list_link },
	{ "job_material_category", DF_Type::job_material_category },
	{ "job_skill", DF_Type::job_skill },
	{ "job_skill_class", DF_Type::job_skill_class },
	{ "job_subtype_surgery", DF_Type::job_subtype_surgery },
	{ "job_type", DF_Type::job_type },
	{ "job_type_class", DF_Type::job_type_class },
	{ "KeybindingScreen", DF_Type::KeybindingScreen },
	{ "KeybindingScreen__T_mode", DF_Type::KeybindingScreen__T_mode },
	{ "kitchen_exc_type", DF_Type::kitchen_exc_type },
	{ "kitchen_pref_flag", DF_Type::kitchen_pref_flag },
	{ "knowledge_scholar_category_flag", DF_Type::knowledge_scholar_category_flag },
	{ "knowledge_scholar_category_flag__T_flag_data", DF_Type::knowledge_scholar_category_flag__T_flag_data },
	{ "knowledge_scholar_category_flag__T_flag_type", DF_Type::knowledge_scholar_category_flag__T_flag_type },
	{ "knowledge_scholar_flags_0", DF_Type::knowledge_scholar_flags_0 },
	{ "knowledge_scholar_flags_1", DF_Type::knowledge_scholar_flags_1 },
	{ "knowledge_scholar_flags_10", DF_Type::knowledge_scholar_flags_10 },
	{ "knowledge_scholar_flags_11", DF_Type::knowledge_scholar_flags_11 },
	{ "knowledge_scholar_flags_12", DF_Type::knowledge_scholar_flags_12 },
	{ "knowledge_scholar_flags_13", DF_Type::knowledge_scholar_flags_13 },
	{ "knowledge_scholar_flags_2", DF_Type::knowledge_scholar_flags_2 },
	{ "knowledge_scholar_flags_3", DF_Type::knowledge_scholar_flags_3 },
	{ "knowledge_scholar_flags_4", DF_Type::knowledge_scholar_flags_4 },
	{ "knowledge_scholar_flags_5", DF_Type::knowledge_scholar_flags_5 },
	{ "knowledge_scholar_flags_6", DF_Type::knowledge_scholar_flags_6 },
	{ "knowledge_scholar_flags_7", DF_Type::knowledge_scholar_flags_7 },
	{ "knowledge_scholar_flags_8", DF_Type::knowledge_scholar_flags_8 },
	{ "knowledge_scholar_flags_9", DF_Type::knowledge_scholar_flags_9 },
	{ "lair_type", DF_Type::lair_type },
	{ "language_name", DF_Type::language_name },
	{ "language_name_category", DF_Type::language_name_category },
	{ "language_symbol", DF_Type::language_symbol },
	{ "language_translation", DF_Type::language_translation },
	{ "language_word", DF_Type::language_word },
	{ "language_word_flags", DF_Type::language_word_flags },
	{ "language_word_table", DF_Type::language_word_table },
	{ "large_integer", DF_Type::large_integer },
	{ "large_integer___struct0", DF_Type::large_integer___struct0 },
	{ "large_integer__T_u", DF_Type::large_integer__T_u },
	{ "layer_object", DF_Type::layer_object },
	{ "layer_object_buttonst", DF_Type::layer_object_buttonst },
	{ "layer_object_listst", DF_Type::layer_object_listst },
	{ "layer_type", DF_Type::layer_type },
	{ "lever_target_type", DF_Type::lever_target_type },
	{ "loadgame_save_info", DF_Type::loadgame_save_info },
	{ "local_population", DF_Type::local_population },
	{ "local_population___union3", DF_Type::local_population___union3 },
	{ "local_population__T_flags", DF_Type::local_population__T_flags },
	{ "location_scribe_jobs", DF_Type::location_scribe_jobs },
	{ "machine", DF_Type::machine },
	{ "machine__T_components", DF_Type::machine__T_components },
	{ "machine__T_flags", DF_Type::machine__T_flags },
	{ "machine_conn_modes", DF_Type::machine_conn_modes },
	{ "machine_handler", DF_Type::machine_handler },
	{ "machine_info", DF_Type::machine_info },
	{ "machine_info__T_flags", DF_Type::machine_info__T_flags },
	{ "machine_standardst", DF_Type::machine_standardst },
	{ "machine_tile_set", DF_Type::machine_tile_set },
	{ "machine_type", DF_Type::machine_type },
	{ "MacroScreenLoad", DF_Type::MacroScreenLoad },
	{ "MacroScreenSave", DF_Type::MacroScreenSave },
	{ "manager_order", DF_Type::manager_order },
	{ "manager_order__T_frequency", DF_Type::manager_order__T_frequency },
	{ "manager_order_condition_item", DF_Type::manager_order_condition_item },
	{ "manager_order_condition_item__T_compare_type", DF_Type::manager_order_condition_item__T_compare_type },
	{ "manager_order_condition_order", DF_Type::manager_order_condition_order },
	{ "manager_order_condition_order__T_condition", DF_Type::manager_order_condition_order__T_condition },
	{ "manager_order_status", DF_Type::manager_order_status },
	{ "manager_order_template", DF_Type::manager_order_template },
	{ "mandate", DF_Type::mandate },
	{ "mandate__T_mode", DF_Type::mandate__T_mode },
	{ "mandate__T_punishment", DF_Type::mandate__T_punishment },
	{ "map_block", DF_Type::map_block },
	{ "map_block_column", DF_Type::map_block_column },
	{ "map_block_column__T_unmined_glyphs", DF_Type::map_block_column__T_unmined_glyphs },
	{ "map_renderer", DF_Type::map_renderer },
	{ "map_renderer__T_anon_4", DF_Type::map_renderer__T_anon_4 },
	{ "map_viewport", DF_Type::map_viewport },
	{ "masterpiece_loss_type", DF_Type::masterpiece_loss_type },
	{ "material", DF_Type::material },
	{ "material_common", DF_Type::material_common },
	{ "material_common__T_hardens_with_water", DF_Type::material_common__T_hardens_with_water },
	{ "material_common__T_heat", DF_Type::material_common__T_heat },
	{ "material_common__T_reaction_product", DF_Type::material_common__T_reaction_product },
	{ "material_common__T_strength", DF_Type::material_common__T_strength },
	{ "material_flags", DF_Type::material_flags },
	{ "material_template", DF_Type::material_template },
	{ "material_vec_ref", DF_Type::material_vec_ref },
	{ "matgloss_list", DF_Type::matgloss_list },
	{ "matgloss_list__T_unk_0", DF_Type::matgloss_list__T_unk_0 },
	{ "matter_state", DF_Type::matter_state },
	{ "meeting_context", DF_Type::meeting_context },
	{ "meeting_diplomat_info", DF_Type::meeting_diplomat_info },
	{ "meeting_diplomat_info__T_flags", DF_Type::meeting_diplomat_info__T_flags },
	{ "meeting_event", DF_Type::meeting_event },
	{ "meeting_event_type", DF_Type::meeting_event_type },
	{ "meeting_topic", DF_Type::meeting_topic },
	{ "meeting_variable", DF_Type::meeting_variable },
	{ "mental_attribute_type", DF_Type::mental_attribute_type },
	{ "mental_picture", DF_Type::mental_picture },
	{ "mental_picture__T_unk", DF_Type::mental_picture__T_unk },
	{ "mental_picture_element_hfst", DF_Type::mental_picture_element_hfst },
	{ "mental_picture_element_regionst", DF_Type::mental_picture_element_regionst },
	{ "mental_picture_element_sitest", DF_Type::mental_picture_element_sitest },
	{ "mental_picture_element_type", DF_Type::mental_picture_element_type },
	{ "mental_picture_elementst", DF_Type::mental_picture_elementst },
	{ "mental_picture_property_actionst", DF_Type::mental_picture_property_actionst },
	{ "mental_picture_property_adjectivest", DF_Type::mental_picture_property_adjectivest },
	{ "mental_picture_property_color_patternst", DF_Type::mental_picture_property_color_patternst },
	{ "mental_picture_property_datest", DF_Type::mental_picture_property_datest },
	{ "mental_picture_property_emotionst", DF_Type::mental_picture_property_emotionst },
	{ "mental_picture_property_positionst", DF_Type::mental_picture_property_positionst },
	{ "mental_picture_property_shapest", DF_Type::mental_picture_property_shapest },
	{ "mental_picture_property_timest", DF_Type::mental_picture_property_timest },
	{ "mental_picture_property_toolst", DF_Type::mental_picture_property_toolst },
	{ "mental_picture_property_type", DF_Type::mental_picture_property_type },
	{ "mental_picture_propertyst", DF_Type::mental_picture_propertyst },
	{ "misc_trait_type", DF_Type::misc_trait_type },
	{ "mission", DF_Type::mission },
	{ "mission__T_details", DF_Type::mission__T_details },
	{ "mission__T_details__T_raid", DF_Type::mission__T_details__T_raid },
	{ "mission__T_details__T_raid__T_raid_flags", DF_Type::mission__T_details__T_raid__T_raid_flags },
	{ "mission__T_details__T_raid__T_raid_type", DF_Type::mission__T_details__T_raid__T_raid_type },
	{ "mission__T_details__T_recovery", DF_Type::mission__T_details__T_recovery },
	{ "mission__T_details__T_request", DF_Type::mission__T_details__T_request },
	{ "mission__T_details__T_rescue", DF_Type::mission__T_details__T_rescue },
	{ "mission__T_type", DF_Type::mission__T_type },
	{ "mission_campaign_report", DF_Type::mission_campaign_report },
	{ "mission_report", DF_Type::mission_report },
	{ "monument_type", DF_Type::monument_type },
	{ "mood_type", DF_Type::mood_type },
	{ "mountain_peak_flags", DF_Type::mountain_peak_flags },
	{ "moving_party", DF_Type::moving_party },
	{ "moving_party__T_members", DF_Type::moving_party__T_members },
	{ "musical_form", DF_Type::musical_form },
	{ "musical_form__T_flags", DF_Type::musical_form__T_flags },
	{ "musical_form_feature", DF_Type::musical_form_feature },
	{ "musical_form_instruments", DF_Type::musical_form_instruments },
	{ "musical_form_instruments__T_substitutions", DF_Type::musical_form_instruments__T_substitutions },
	{ "musical_form_interval", DF_Type::musical_form_interval },
	{ "musical_form_interval__T_flags", DF_Type::musical_form_interval__T_flags },
	{ "musical_form_melodies", DF_Type::musical_form_melodies },
	{ "musical_form_pitch_style", DF_Type::musical_form_pitch_style },
	{ "musical_form_purpose", DF_Type::musical_form_purpose },
	{ "musical_form_style", DF_Type::musical_form_style },
	{ "musical_form_sub4", DF_Type::musical_form_sub4 },
	{ "musical_form_vocals", DF_Type::musical_form_vocals },
	{ "need_type", DF_Type::need_type },
	{ "nemesis_flags", DF_Type::nemesis_flags },
	{ "nemesis_offload", DF_Type::nemesis_offload },
	{ "nemesis_record", DF_Type::nemesis_record },
	{ "next_global_id", DF_Type::next_global_id },
	{ "occasion_schedule_feature", DF_Type::occasion_schedule_feature },
	{ "occasion_schedule_type", DF_Type::occasion_schedule_type },
	{ "occupation", DF_Type::occupation },
	{ "occupation_sub1", DF_Type::occupation_sub1 },
	{ "occupation_type", DF_Type::occupation_type },
	{ "ocean_wave", DF_Type::ocean_wave },
	{ "organic_mat_category", DF_Type::organic_mat_category },
	{ "orientation_flags", DF_Type::orientation_flags },
	{ "pants_flags", DF_Type::pants_flags },
	{ "part_of_speech", DF_Type::part_of_speech },
	{ "party_info", DF_Type::party_info },
	{ "pattern_type", DF_Type::pattern_type },
	{ "performance_event_type", DF_Type::performance_event_type },
	{ "performance_participant_type", DF_Type::performance_participant_type },
	{ "performance_play_orderst", DF_Type::performance_play_orderst },
	{ "performance_play_orderst__T_anon_4", DF_Type::performance_play_orderst__T_anon_4 },
	{ "personality_facet_type", DF_Type::personality_facet_type },
	{ "physical_attribute_type", DF_Type::physical_attribute_type },
	{ "pitch_choice_type", DF_Type::pitch_choice_type },
	{ "plant", DF_Type::plant },
	{ "plant__T_damage_flags", DF_Type::plant__T_damage_flags },
	{ "plant_flags", DF_Type::plant_flags },
	{ "plant_growth", DF_Type::plant_growth },
	{ "plant_growth__T_behavior", DF_Type::plant_growth__T_behavior },
	{ "plant_growth__T_locations", DF_Type::plant_growth__T_locations },
	{ "plant_growth_print", DF_Type::plant_growth_print },
	{ "plant_raw", DF_Type::plant_raw },
	{ "plant_raw__T_colors", DF_Type::plant_raw__T_colors },
	{ "plant_raw__T_material_defs", DF_Type::plant_raw__T_material_defs },
	{ "plant_raw__T_stockpile_growth_flags", DF_Type::plant_raw__T_stockpile_growth_flags },
	{ "plant_raw__T_tiles", DF_Type::plant_raw__T_tiles },
	{ "plant_raw_flags", DF_Type::plant_raw_flags },
	{ "plant_tree_info", DF_Type::plant_tree_info },
	{ "plant_tree_tile", DF_Type::plant_tree_tile },
	{ "plot_agreement", DF_Type::plot_agreement },
	{ "plot_role_type", DF_Type::plot_role_type },
	{ "plot_strategy_type", DF_Type::plot_strategy_type },
	{ "poetic_form", DF_Type::poetic_form },
	{ "poetic_form__T_flags", DF_Type::poetic_form__T_flags },
	{ "poetic_form_action", DF_Type::poetic_form_action },
	{ "poetic_form_additional_feature", DF_Type::poetic_form_additional_feature },
	{ "poetic_form_caesura_position", DF_Type::poetic_form_caesura_position },
	{ "poetic_form_feature", DF_Type::poetic_form_feature },
	{ "poetic_form_mood", DF_Type::poetic_form_mood },
	{ "poetic_form_part", DF_Type::poetic_form_part },
	{ "poetic_form_part__T_flags", DF_Type::poetic_form_part__T_flags },
	{ "poetic_form_pattern", DF_Type::poetic_form_pattern },
	{ "poetic_form_perspective", DF_Type::poetic_form_perspective },
	{ "poetic_form_perspective__T_type", DF_Type::poetic_form_perspective__T_type },
	{ "poetic_form_subject", DF_Type::poetic_form_subject },
	{ "poetic_form_subject_target", DF_Type::poetic_form_subject_target },
	{ "poetic_form_subject_target__T_Concept", DF_Type::poetic_form_subject_target__T_Concept },
	{ "poetic_form_subject_target__T_Histfig", DF_Type::poetic_form_subject_target__T_Histfig },
	{ "popup_message", DF_Type::popup_message },
	{ "power_info", DF_Type::power_info },
	{ "pressure_plate_info", DF_Type::pressure_plate_info },
	{ "pressure_plate_info__T_flags", DF_Type::pressure_plate_info__T_flags },
	{ "profession", DF_Type::profession },
	{ "proj_itemst", DF_Type::proj_itemst },
	{ "proj_list_link", DF_Type::proj_list_link },
	{ "proj_magicst", DF_Type::proj_magicst },
	{ "proj_unitst", DF_Type::proj_unitst },
	{ "projectile", DF_Type::projectile },
	{ "projectile_flags", DF_Type::projectile_flags },
	{ "projectile_type", DF_Type::projectile_type },
	{ "property_ownership", DF_Type::property_ownership },
	{ "punishment", DF_Type::punishment },
	{ "reaction", DF_Type::reaction },
	{ "reaction__T_building", DF_Type::reaction__T_building },
	{ "reaction_category", DF_Type::reaction_category },
	{ "reaction_description", DF_Type::reaction_description },
	{ "reaction_flags", DF_Type::reaction_flags },
	{ "reaction_product", DF_Type::reaction_product },
	{ "reaction_product_improvement_flags", DF_Type::reaction_product_improvement_flags },
	{ "reaction_product_item_flags", DF_Type::reaction_product_item_flags },
	{ "reaction_product_item_improvementst", DF_Type::reaction_product_item_improvementst },
	{ "reaction_product_item_improvementst__T_get_material", DF_Type::reaction_product_item_improvementst__T_get_material },
	{ "reaction_product_itemst", DF_Type::reaction_product_itemst },
	{ "reaction_product_itemst__T_get_material", DF_Type::reaction_product_itemst__T_get_material },
	{ "reaction_product_type", DF_Type::reaction_product_type },
	{ "reaction_reagent", DF_Type::reaction_reagent },
	{ "reaction_reagent_flags", DF_Type::reaction_reagent_flags },
	{ "reaction_reagent_itemst", DF_Type::reaction_reagent_itemst },
	{ "reaction_reagent_type", DF_Type::reaction_reagent_type },
	{ "region_block_event_sphere_fieldst", DF_Type::region_block_event_sphere_fieldst },
	{ "region_block_event_type", DF_Type::region_block_event_type },
	{ "region_block_eventst", DF_Type::region_block_eventst },
	{ "region_map_entry", DF_Type::region_map_entry },
	{ "region_map_entry__T_clouds", DF_Type::region_map_entry__T_clouds },
	{ "region_map_entry__T_wind", DF_Type::region_map_entry__T_wind },
	{ "region_map_entry_flags", DF_Type::region_map_entry_flags },
	{ "relationship_event", DF_Type::relationship_event },
	{ "relationship_event_supplement", DF_Type::relationship_event_supplement },
	{ "renderer", DF_Type::renderer },
	{ "report", DF_Type::report },
	{ "report__T_flags", DF_Type::report__T_flags },
	{ "reputation_type", DF_Type::reputation_type },
	{ "resource_allotment_data", DF_Type::resource_allotment_data },
	{ "resource_allotment_data__T_unk_654", DF_Type::resource_allotment_data__T_unk_654 },
	{ "resource_allotment_specifier", DF_Type::resource_allotment_specifier },
	{ "resource_allotment_specifier_ammost", DF_Type::resource_allotment_specifier_ammost },
	{ "resource_allotment_specifier_anvilst", DF_Type::resource_allotment_specifier_anvilst },
	{ "resource_allotment_specifier_armor_bodyst", DF_Type::resource_allotment_specifier_armor_bodyst },
	{ "resource_allotment_specifier_armor_bootsst", DF_Type::resource_allotment_specifier_armor_bootsst },
	{ "resource_allotment_specifier_armor_glovesst", DF_Type::resource_allotment_specifier_armor_glovesst },
	{ "resource_allotment_specifier_armor_helmst", DF_Type::resource_allotment_specifier_armor_helmst },
	{ "resource_allotment_specifier_armor_pantsst", DF_Type::resource_allotment_specifier_armor_pantsst },
	{ "resource_allotment_specifier_backpackst", DF_Type::resource_allotment_specifier_backpackst },
	{ "resource_allotment_specifier_bagst", DF_Type::resource_allotment_specifier_bagst },
	{ "resource_allotment_specifier_bedst", DF_Type::resource_allotment_specifier_bedst },
	{ "resource_allotment_specifier_bonest", DF_Type::resource_allotment_specifier_bonest },
	{ "resource_allotment_specifier_boxst", DF_Type::resource_allotment_specifier_boxst },
	{ "resource_allotment_specifier_cabinetst", DF_Type::resource_allotment_specifier_cabinetst },
	{ "resource_allotment_specifier_chairst", DF_Type::resource_allotment_specifier_chairst },
	{ "resource_allotment_specifier_cheesest", DF_Type::resource_allotment_specifier_cheesest },
	{ "resource_allotment_specifier_clothing_bodyst", DF_Type::resource_allotment_specifier_clothing_bodyst },
	{ "resource_allotment_specifier_clothing_bootsst", DF_Type::resource_allotment_specifier_clothing_bootsst },
	{ "resource_allotment_specifier_clothing_glovesst", DF_Type::resource_allotment_specifier_clothing_glovesst },
	{ "resource_allotment_specifier_clothing_helmst", DF_Type::resource_allotment_specifier_clothing_helmst },
	{ "resource_allotment_specifier_clothing_pantsst", DF_Type::resource_allotment_specifier_clothing_pantsst },
	{ "resource_allotment_specifier_clothst", DF_Type::resource_allotment_specifier_clothst },
	{ "resource_allotment_specifier_craftsst", DF_Type::resource_allotment_specifier_craftsst },
	{ "resource_allotment_specifier_cropst", DF_Type::resource_allotment_specifier_cropst },
	{ "resource_allotment_specifier_extractst", DF_Type::resource_allotment_specifier_extractst },
	{ "resource_allotment_specifier_flaskst", DF_Type::resource_allotment_specifier_flaskst },
	{ "resource_allotment_specifier_gemsst", DF_Type::resource_allotment_specifier_gemsst },
	{ "resource_allotment_specifier_hornst", DF_Type::resource_allotment_specifier_hornst },
	{ "resource_allotment_specifier_leatherst", DF_Type::resource_allotment_specifier_leatherst },
	{ "resource_allotment_specifier_meatst", DF_Type::resource_allotment_specifier_meatst },
	{ "resource_allotment_specifier_metalst", DF_Type::resource_allotment_specifier_metalst },
	{ "resource_allotment_specifier_pearlst", DF_Type::resource_allotment_specifier_pearlst },
	{ "resource_allotment_specifier_powderst", DF_Type::resource_allotment_specifier_powderst },
	{ "resource_allotment_specifier_quiverst", DF_Type::resource_allotment_specifier_quiverst },
	{ "resource_allotment_specifier_shellst", DF_Type::resource_allotment_specifier_shellst },
	{ "resource_allotment_specifier_skinst", DF_Type::resource_allotment_specifier_skinst },
	{ "resource_allotment_specifier_soapst", DF_Type::resource_allotment_specifier_soapst },
	{ "resource_allotment_specifier_stonest", DF_Type::resource_allotment_specifier_stonest },
	{ "resource_allotment_specifier_tablest", DF_Type::resource_allotment_specifier_tablest },
	{ "resource_allotment_specifier_tallowst", DF_Type::resource_allotment_specifier_tallowst },
	{ "resource_allotment_specifier_threadst", DF_Type::resource_allotment_specifier_threadst },
	{ "resource_allotment_specifier_toothst", DF_Type::resource_allotment_specifier_toothst },
	{ "resource_allotment_specifier_type", DF_Type::resource_allotment_specifier_type },
	{ "resource_allotment_specifier_weapon_meleest", DF_Type::resource_allotment_specifier_weapon_meleest },
	{ "resource_allotment_specifier_weapon_rangedst", DF_Type::resource_allotment_specifier_weapon_rangedst },
	{ "resource_allotment_specifier_woodst", DF_Type::resource_allotment_specifier_woodst },
	{ "rhythm", DF_Type::rhythm },
	{ "rhythm_sub1", DF_Type::rhythm_sub1 },
	{ "rhythm_sub1__T_anon_1", DF_Type::rhythm_sub1__T_anon_1 },
	{ "rhythm_sub2", DF_Type::rhythm_sub2 },
	{ "room_rent_info", DF_Type::room_rent_info },
	{ "room_rent_info__T_flags", DF_Type::room_rent_info__T_flags },
	{ "route_stockpile_link", DF_Type::route_stockpile_link },
	{ "route_stockpile_link__T_mode", DF_Type::route_stockpile_link__T_mode },
	{ "scale", DF_Type::scale },
	{ "scale__T_unk1", DF_Type::scale__T_unk1 },
	{ "scale_sub1", DF_Type::scale_sub1 },
	{ "scale_sub2", DF_Type::scale_sub2 },
	{ "schedule_info", DF_Type::schedule_info },
	{ "schedule_slot", DF_Type::schedule_slot },
	{ "screw_pump_direction", DF_Type::screw_pump_direction },
	{ "scribejob", DF_Type::scribejob },
	{ "script_step_conditionalst", DF_Type::script_step_conditionalst },
	{ "script_step_conditionalst__T_condition", DF_Type::script_step_conditionalst__T_condition },
	{ "script_step_constructtopiclistst", DF_Type::script_step_constructtopiclistst },
	{ "script_step_dipeventst", DF_Type::script_step_dipeventst },
	{ "script_step_diphistoryst", DF_Type::script_step_diphistoryst },
	{ "script_step_discussst", DF_Type::script_step_discussst },
	{ "script_step_eventst", DF_Type::script_step_eventst },
	{ "script_step_invasionst", DF_Type::script_step_invasionst },
	{ "script_step_setvarst", DF_Type::script_step_setvarst },
	{ "script_step_simpleactionst", DF_Type::script_step_simpleactionst },
	{ "script_step_textviewerst", DF_Type::script_step_textviewerst },
	{ "script_step_topicdiscussionst", DF_Type::script_step_topicdiscussionst },
	{ "script_stepst", DF_Type::script_stepst },
	{ "script_var_longst", DF_Type::script_var_longst },
	{ "script_var_unitst", DF_Type::script_var_unitst },
	{ "script_varst", DF_Type::script_varst },
	{ "setup_character_info", DF_Type::setup_character_info },
	{ "setup_character_info__T_available_embark_items", DF_Type::setup_character_info__T_available_embark_items },
	{ "setup_character_info__T_page", DF_Type::setup_character_info__T_page },
	{ "setup_character_info__T_sel_trait_column", DF_Type::setup_character_info__T_sel_trait_column },
	{ "setup_character_info__T_status", DF_Type::setup_character_info__T_status },
	{ "shoes_flags", DF_Type::shoes_flags },
	{ "shop_type", DF_Type::shop_type },
	{ "siegeengine_type", DF_Type::siegeengine_type },
	{ "site_building_item", DF_Type::site_building_item },
	{ "site_dispute_type", DF_Type::site_dispute_type },
	{ "site_realization_building", DF_Type::site_realization_building },
	{ "site_realization_building__T_unk_4c", DF_Type::site_realization_building__T_unk_4c },
	{ "site_realization_building_info_castle_courtyardst", DF_Type::site_realization_building_info_castle_courtyardst },
	{ "site_realization_building_info_castle_towerst", DF_Type::site_realization_building_info_castle_towerst },
	{ "site_realization_building_info_castle_wallst", DF_Type::site_realization_building_info_castle_wallst },
	{ "site_realization_building_info_hillock_housest", DF_Type::site_realization_building_info_hillock_housest },
	{ "site_realization_building_info_market_squarest", DF_Type::site_realization_building_info_market_squarest },
	{ "site_realization_building_info_shop_housest", DF_Type::site_realization_building_info_shop_housest },
	{ "site_realization_building_info_tree_housest", DF_Type::site_realization_building_info_tree_housest },
	{ "site_realization_building_info_trenchesst", DF_Type::site_realization_building_info_trenchesst },
	{ "site_realization_building_info_trenchesst__T_spokes", DF_Type::site_realization_building_info_trenchesst__T_spokes },
	{ "site_realization_building_infost", DF_Type::site_realization_building_infost },
	{ "site_realization_building_type", DF_Type::site_realization_building_type },
	{ "site_realization_crossroads", DF_Type::site_realization_crossroads },
	{ "site_reputation_info", DF_Type::site_reputation_info },
	{ "site_reputation_report", DF_Type::site_reputation_report },
	{ "site_shop_type", DF_Type::site_shop_type },
	{ "site_type", DF_Type::site_type },
	{ "skill_rating", DF_Type::skill_rating },
	{ "slab_engraving_type", DF_Type::slab_engraving_type },
	{ "sound_production_type", DF_Type::sound_production_type },
	{ "spatter", DF_Type::spatter },
	{ "spatter__T_flags", DF_Type::spatter__T_flags },
	{ "spatter_common", DF_Type::spatter_common },
	{ "spatter_common__T_base_flags", DF_Type::spatter_common__T_base_flags },
	{ "special_mat_table", DF_Type::special_mat_table },
	{ "specific_ref", DF_Type::specific_ref },
	{ "specific_ref__T_data", DF_Type::specific_ref__T_data },
	{ "specific_ref__T_data__T_UNIT_ITEM_WRESTLE", DF_Type::specific_ref__T_data__T_UNIT_ITEM_WRESTLE },
	{ "specific_ref_type", DF_Type::specific_ref_type },
	{ "sphere_type", DF_Type::sphere_type },
	{ "spoils_report", DF_Type::spoils_report },
	{ "squad", DF_Type::squad },
	{ "squad__T_rooms", DF_Type::squad__T_rooms },
	{ "squad_ammo_spec", DF_Type::squad_ammo_spec },
	{ "squad_ammo_spec__T_flags", DF_Type::squad_ammo_spec__T_flags },
	{ "squad_event_type", DF_Type::squad_event_type },
	{ "squad_order", DF_Type::squad_order },
	{ "squad_order_cannot_reason", DF_Type::squad_order_cannot_reason },
	{ "squad_order_cause_trouble_for_entityst", DF_Type::squad_order_cause_trouble_for_entityst },
	{ "squad_order_defend_burrowsst", DF_Type::squad_order_defend_burrowsst },
	{ "squad_order_drive_armies_from_sitest", DF_Type::squad_order_drive_armies_from_sitest },
	{ "squad_order_drive_entity_off_sitest", DF_Type::squad_order_drive_entity_off_sitest },
	{ "squad_order_kill_hfst", DF_Type::squad_order_kill_hfst },
	{ "squad_order_kill_listst", DF_Type::squad_order_kill_listst },
	{ "squad_order_movest", DF_Type::squad_order_movest },
	{ "squad_order_patrol_routest", DF_Type::squad_order_patrol_routest },
	{ "squad_order_raid_sitest", DF_Type::squad_order_raid_sitest },
	{ "squad_order_rescue_hfst", DF_Type::squad_order_rescue_hfst },
	{ "squad_order_retrieve_artifactst", DF_Type::squad_order_retrieve_artifactst },
	{ "squad_order_trainst", DF_Type::squad_order_trainst },
	{ "squad_order_type", DF_Type::squad_order_type },
	{ "squad_position", DF_Type::squad_position },
	{ "squad_schedule_entry", DF_Type::squad_schedule_entry },
	{ "squad_schedule_order", DF_Type::squad_schedule_order },
	{ "squad_uniform_spec", DF_Type::squad_uniform_spec },
	{ "squad_use_flags", DF_Type::squad_use_flags },
	{ "stockpile_category", DF_Type::stockpile_category },
	{ "stockpile_group_set", DF_Type::stockpile_group_set },
	{ "stockpile_links", DF_Type::stockpile_links },
	{ "stockpile_list", DF_Type::stockpile_list },
	{ "stockpile_settings", DF_Type::stockpile_settings },
	{ "stockpile_settings__T_ammo", DF_Type::stockpile_settings__T_ammo },
	{ "stockpile_settings__T_animals", DF_Type::stockpile_settings__T_animals },
	{ "stockpile_settings__T_armor", DF_Type::stockpile_settings__T_armor },
	{ "stockpile_settings__T_bars_blocks", DF_Type::stockpile_settings__T_bars_blocks },
	{ "stockpile_settings__T_cloth", DF_Type::stockpile_settings__T_cloth },
	{ "stockpile_settings__T_coins", DF_Type::stockpile_settings__T_coins },
	{ "stockpile_settings__T_finished_goods", DF_Type::stockpile_settings__T_finished_goods },
	{ "stockpile_settings__T_food", DF_Type::stockpile_settings__T_food },
	{ "stockpile_settings__T_furniture", DF_Type::stockpile_settings__T_furniture },
	{ "stockpile_settings__T_gems", DF_Type::stockpile_settings__T_gems },
	{ "stockpile_settings__T_leather", DF_Type::stockpile_settings__T_leather },
	{ "stockpile_settings__T_ore", DF_Type::stockpile_settings__T_ore },
	{ "stockpile_settings__T_refuse", DF_Type::stockpile_settings__T_refuse },
	{ "stockpile_settings__T_sheet", DF_Type::stockpile_settings__T_sheet },
	{ "stockpile_settings__T_stone", DF_Type::stockpile_settings__T_stone },
	{ "stockpile_settings__T_weapons", DF_Type::stockpile_settings__T_weapons },
	{ "stockpile_settings__T_wood", DF_Type::stockpile_settings__T_wood },
	{ "stop_depart_condition", DF_Type::stop_depart_condition },
	{ "stop_depart_condition__T_direction", DF_Type::stop_depart_condition__T_direction },
	{ "stop_depart_condition__T_flags", DF_Type::stop_depart_condition__T_flags },
	{ "stop_depart_condition__T_mode", DF_Type::stop_depart_condition__T_mode },
	{ "strain_type", DF_Type::strain_type },
	{ "stratus_type", DF_Type::stratus_type },
	{ "syndrome", DF_Type::syndrome },
	{ "syndrome_flags", DF_Type::syndrome_flags },
	{ "T_cursor", DF_Type::T_cursor },
	{ "T_selection_rect", DF_Type::T_selection_rect },
	{ "tactical_situation", DF_Type::tactical_situation },
	{ "talk_choice", DF_Type::talk_choice },
	{ "talk_choice__T_unk", DF_Type::talk_choice__T_unk },
	{ "talk_choice_type", DF_Type::talk_choice_type },
	{ "temperaturest", DF_Type::temperaturest },
	{ "temple_deity_data", DF_Type::temple_deity_data },
	{ "temple_deity_type", DF_Type::temple_deity_type },
	{ "text_info_element_longst", DF_Type::text_info_element_longst },
	{ "text_info_element_stringst", DF_Type::text_info_element_stringst },
	{ "text_info_elementst", DF_Type::text_info_elementst },
	{ "texture_handler", DF_Type::texture_handler },
	{ "tile_bitmask", DF_Type::tile_bitmask },
	{ "tile_building_occ", DF_Type::tile_building_occ },
	{ "tile_designation", DF_Type::tile_designation },
	{ "tile_dig_designation", DF_Type::tile_dig_designation },
	{ "tile_liquid", DF_Type::tile_liquid },
	{ "tile_liquid_flow", DF_Type::tile_liquid_flow },
	{ "tile_liquid_flow_dir", DF_Type::tile_liquid_flow_dir },
	{ "tile_occupancy", DF_Type::tile_occupancy },
	{ "tile_page", DF_Type::tile_page },
	{ "tile_traffic", DF_Type::tile_traffic },
	{ "tiletype", DF_Type::tiletype },
	{ "tiletype_material", DF_Type::tiletype_material },
	{ "tiletype_shape", DF_Type::tiletype_shape },
	{ "tiletype_shape_basic", DF_Type::tiletype_shape_basic },
	{ "tiletype_special", DF_Type::tiletype_special },
	{ "tiletype_variant", DF_Type::tiletype_variant },
	{ "timbre_type", DF_Type::timbre_type },
	{ "timed_event", DF_Type::timed_event },
	{ "timed_event_type", DF_Type::timed_event_type },
	{ "tissue", DF_Type::tissue },
	{ "tissue_flags", DF_Type::tissue_flags },
	{ "tissue_style_raw", DF_Type::tissue_style_raw },
	{ "tissue_style_type", DF_Type::tissue_style_type },
	{ "tissue_template", DF_Type::tissue_template },
	{ "tool_flags", DF_Type::tool_flags },
	{ "tool_uses", DF_Type::tool_uses },
	{ "tower_shape", DF_Type::tower_shape },
	{ "toy_flags", DF_Type::toy_flags },
	{ "training_assignment", DF_Type::training_assignment },
	{ "training_assignment__T_flags", DF_Type::training_assignment__T_flags },
	{ "training_knowledge_level", DF_Type::training_knowledge_level },
	{ "trap_type", DF_Type::trap_type },
	{ "trapcomp_flags", DF_Type::trapcomp_flags },
	{ "tree_house_type", DF_Type::tree_house_type },
	{ "tuning_type", DF_Type::tuning_type },
	{ "ui", DF_Type::ui },
	{ "ui__T_alerts", DF_Type::ui__T_alerts },
	{ "ui__T_alerts__T_list", DF_Type::ui__T_alerts__T_list },
	{ "ui__T_becoming_capital", DF_Type::ui__T_becoming_capital },
	{ "ui__T_burrows", DF_Type::ui__T_burrows },
	{ "ui__T_economy_prices", DF_Type::ui__T_economy_prices },
	{ "ui__T_economy_prices__T_price_adjustment", DF_Type::ui__T_economy_prices__T_price_adjustment },
	{ "ui__T_economy_prices__T_price_setter", DF_Type::ui__T_economy_prices__T_price_setter },
	{ "ui__T_equipment", DF_Type::ui__T_equipment },
	{ "ui__T_equipment__T_update", DF_Type::ui__T_equipment__T_update },
	{ "ui__T_hauling", DF_Type::ui__T_hauling },
	{ "ui__T_invasions", DF_Type::ui__T_invasions },
	{ "ui__T_kitchen", DF_Type::ui__T_kitchen },
	{ "ui__T_main", DF_Type::ui__T_main },
	{ "ui__T_main__T_dead_citizens", DF_Type::ui__T_main__T_dead_citizens },
	{ "ui__T_map_edge", DF_Type::ui__T_map_edge },
	{ "ui__T_squads", DF_Type::ui__T_squads },
	{ "ui__T_stockpile", DF_Type::ui__T_stockpile },
	{ "ui__T_tax_collection", DF_Type::ui__T_tax_collection },
	{ "ui__T_unk23c8_flags", DF_Type::ui__T_unk23c8_flags },
	{ "ui__T_unk2a8c", DF_Type::ui__T_unk2a8c },
	{ "ui__T_waypoints", DF_Type::ui__T_waypoints },
	{ "ui__T_waypoints__T_points", DF_Type::ui__T_waypoints__T_points },
	{ "ui__T_waypoints__T_routes", DF_Type::ui__T_waypoints__T_routes },
	{ "ui_advmode", DF_Type::ui_advmode },
	{ "ui_advmode__T_assume_identity", DF_Type::ui_advmode__T_assume_identity },
	{ "ui_advmode__T_companions", DF_Type::ui_advmode__T_companions },
	{ "ui_advmode__T_conversation", DF_Type::ui_advmode__T_conversation },
	{ "ui_advmode__T_conversation__T_choices", DF_Type::ui_advmode__T_conversation__T_choices },
	{ "ui_advmode__T_conversation__T_targets", DF_Type::ui_advmode__T_conversation__T_targets },
	{ "ui_advmode__T_conversation__T_targets__T_type", DF_Type::ui_advmode__T_conversation__T_targets__T_type },
	{ "ui_advmode__T_interactions", DF_Type::ui_advmode__T_interactions },
	{ "ui_advmode__T_show_menu", DF_Type::ui_advmode__T_show_menu },
	{ "ui_advmode__T_travel_right_map", DF_Type::ui_advmode__T_travel_right_map },
	{ "ui_advmode__T_unk_3124", DF_Type::ui_advmode__T_unk_3124 },
	{ "ui_advmode__T_unk_3170", DF_Type::ui_advmode__T_unk_3170 },
	{ "ui_advmode__T_unk_3170__T_unk_2", DF_Type::ui_advmode__T_unk_3170__T_unk_2 },
	{ "ui_advmode__T_unk_v40_1", DF_Type::ui_advmode__T_unk_v40_1 },
	{ "ui_advmode__T_unk_v40_2", DF_Type::ui_advmode__T_unk_v40_2 },
	{ "ui_advmode__T_unk_v40_3", DF_Type::ui_advmode__T_unk_v40_3 },
	{ "ui_advmode__T_unk_v40_4", DF_Type::ui_advmode__T_unk_v40_4 },
	{ "ui_advmode__T_unk_v40_4__T_unk_v40_4a", DF_Type::ui_advmode__T_unk_v40_4__T_unk_v40_4a },
	{ "ui_advmode__T_unk_v40_5", DF_Type::ui_advmode__T_unk_v40_5 },
	{ "ui_advmode__T_unk_v42_1", DF_Type::ui_advmode__T_unk_v42_1 },
	{ "ui_advmode_menu", DF_Type::ui_advmode_menu },
	{ "ui_build_item_req", DF_Type::ui_build_item_req },
	{ "ui_build_selector", DF_Type::ui_build_selector },
	{ "ui_hotkey", DF_Type::ui_hotkey },
	{ "ui_hotkey___union1", DF_Type::ui_hotkey___union1 },
	{ "ui_hotkey__T_cmd", DF_Type::ui_hotkey__T_cmd },
	{ "ui_look_list", DF_Type::ui_look_list },
	{ "ui_look_list__T_items", DF_Type::ui_look_list__T_items },
	{ "ui_look_list__T_items__T_data", DF_Type::ui_look_list__T_items__T_data },
	{ "ui_look_list__T_items__T_data__T_Magma", DF_Type::ui_look_list__T_items__T_data__T_Magma },
	{ "ui_look_list__T_items__T_data__T_Spatter", DF_Type::ui_look_list__T_items__T_data__T_Spatter },
	{ "ui_look_list__T_items__T_data__T_Water", DF_Type::ui_look_list__T_items__T_data__T_Water },
	{ "ui_look_list__T_items__T_type", DF_Type::ui_look_list__T_items__T_type },
	{ "ui_sidebar_menus", DF_Type::ui_sidebar_menus },
	{ "ui_sidebar_menus__T_barracks", DF_Type::ui_sidebar_menus__T_barracks },
	{ "ui_sidebar_menus__T_building", DF_Type::ui_sidebar_menus__T_building },
	{ "ui_sidebar_menus__T_command_line", DF_Type::ui_sidebar_menus__T_command_line },
	{ "ui_sidebar_menus__T_designation", DF_Type::ui_sidebar_menus__T_designation },
	{ "ui_sidebar_menus__T_designation__T_mine_mode", DF_Type::ui_sidebar_menus__T_designation__T_mine_mode },
	{ "ui_sidebar_menus__T_hospital", DF_Type::ui_sidebar_menus__T_hospital },
	{ "ui_sidebar_menus__T_job_details", DF_Type::ui_sidebar_menus__T_job_details },
	{ "ui_sidebar_menus__T_location", DF_Type::ui_sidebar_menus__T_location },
	{ "ui_sidebar_menus__T_minimap", DF_Type::ui_sidebar_menus__T_minimap },
	{ "ui_sidebar_menus__T_unit", DF_Type::ui_sidebar_menus__T_unit },
	{ "ui_sidebar_menus__T_unit__T_expel_error", DF_Type::ui_sidebar_menus__T_unit__T_expel_error },
	{ "ui_sidebar_menus__T_unit_cursor", DF_Type::ui_sidebar_menus__T_unit_cursor },
	{ "ui_sidebar_menus__T_unit_skills", DF_Type::ui_sidebar_menus__T_unit_skills },
	{ "ui_sidebar_menus__T_workshop_job", DF_Type::ui_sidebar_menus__T_workshop_job },
	{ "ui_sidebar_menus__T_zone", DF_Type::ui_sidebar_menus__T_zone },
	{ "ui_sidebar_menus__T_zone__T_mode", DF_Type::ui_sidebar_menus__T_zone__T_mode },
	{ "ui_sidebar_mode", DF_Type::ui_sidebar_mode },
	{ "ui_unit_view_mode", DF_Type::ui_unit_view_mode },
	{ "ui_unit_view_mode__T_value", DF_Type::ui_unit_view_mode__T_value },
	{ "uniform_category", DF_Type::uniform_category },
	{ "uniform_flags", DF_Type::uniform_flags },
	{ "uniform_indiv_choice", DF_Type::uniform_indiv_choice },
	{ "unit", DF_Type::unit },
	{ "unit__T_animal", DF_Type::unit__T_animal },
	{ "unit__T_appearance", DF_Type::unit__T_appearance },
	{ "unit__T_body", DF_Type::unit__T_body },
	{ "unit__T_counters", DF_Type::unit__T_counters },
	{ "unit__T_counters2", DF_Type::unit__T_counters2 },
	{ "unit__T_counters__T_soldier_mood", DF_Type::unit__T_counters__T_soldier_mood },
	{ "unit__T_curse", DF_Type::unit__T_curse },
	{ "unit__T_enemy", DF_Type::unit__T_enemy },
	{ "unit__T_enemy__T_undead", DF_Type::unit__T_enemy__T_undead },
	{ "unit__T_enemy__T_unk_448", DF_Type::unit__T_enemy__T_unk_448 },
	{ "unit__T_enemy__T_unk_448__T_unk", DF_Type::unit__T_enemy__T_unk_448__T_unk },
	{ "unit__T_enemy__T_unk_44c", DF_Type::unit__T_enemy__T_unk_44c },
	{ "unit__T_enemy__T_unk_v40_sub3", DF_Type::unit__T_enemy__T_unk_v40_sub3 },
	{ "unit__T_enemy__T_unk_v40_sub3__T_unk_2", DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_2 },
	{ "unit__T_enemy__T_unk_v40_sub3__T_unk_6", DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_6 },
	{ "unit__T_enemy__T_unk_v40_sub3__T_unk_7", DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_7 },
	{ "unit__T_enemy__T_unk_v40_sub3__T_unk_7__T_unk_sub1", DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_7__T_unk_sub1 },
	{ "unit__T_enemy__T_witness_reports", DF_Type::unit__T_enemy__T_witness_reports },
	{ "unit__T_job", DF_Type::unit__T_job },
	{ "unit__T_meeting", DF_Type::unit__T_meeting },
	{ "unit__T_meeting__T_state", DF_Type::unit__T_meeting__T_state },
	{ "unit__T_military", DF_Type::unit__T_military },
	{ "unit__T_military__T_pickup_flags", DF_Type::unit__T_military__T_pickup_flags },
	{ "unit__T_opponent", DF_Type::unit__T_opponent },
	{ "unit__T_path", DF_Type::unit__T_path },
	{ "unit__T_reports", DF_Type::unit__T_reports },
	{ "unit__T_status", DF_Type::unit__T_status },
	{ "unit__T_status2", DF_Type::unit__T_status2 },
	{ "unit__T_status__T_eat_history", DF_Type::unit__T_status__T_eat_history },
	{ "unit__T_status__T_eat_history__T_drink", DF_Type::unit__T_status__T_eat_history__T_drink },
	{ "unit__T_status__T_eat_history__T_food", DF_Type::unit__T_status__T_eat_history__T_food },
	{ "unit__T_syndromes", DF_Type::unit__T_syndromes },
	{ "unit__T_unknown7", DF_Type::unit__T_unknown7 },
	{ "unit_action", DF_Type::unit_action },
	{ "unit_action__T_data", DF_Type::unit_action__T_data },
	{ "unit_action_data_attack", DF_Type::unit_action_data_attack },
	{ "unit_action_data_attack__T_flags", DF_Type::unit_action_data_attack__T_flags },
	{ "unit_action_data_attack__T_unk_4", DF_Type::unit_action_data_attack__T_unk_4 },
	{ "unit_action_data_attack__T_unk_4__T_wrestle_type", DF_Type::unit_action_data_attack__T_unk_4__T_wrestle_type },
	{ "unit_action_data_block", DF_Type::unit_action_data_block },
	{ "unit_action_data_climb", DF_Type::unit_action_data_climb },
	{ "unit_action_data_dodge", DF_Type::unit_action_data_dodge },
	{ "unit_action_data_hold_item", DF_Type::unit_action_data_hold_item },
	{ "unit_action_data_hold_terrain", DF_Type::unit_action_data_hold_terrain },
	{ "unit_action_data_job", DF_Type::unit_action_data_job },
	{ "unit_action_data_job2", DF_Type::unit_action_data_job2 },
	{ "unit_action_data_jump", DF_Type::unit_action_data_jump },
	{ "unit_action_data_lie_down", DF_Type::unit_action_data_lie_down },
	{ "unit_action_data_move", DF_Type::unit_action_data_move },
	{ "unit_action_data_move__T_flags", DF_Type::unit_action_data_move__T_flags },
	{ "unit_action_data_parry", DF_Type::unit_action_data_parry },
	{ "unit_action_data_push_object", DF_Type::unit_action_data_push_object },
	{ "unit_action_data_recover", DF_Type::unit_action_data_recover },
	{ "unit_action_data_release_item", DF_Type::unit_action_data_release_item },
	{ "unit_action_data_release_terrain", DF_Type::unit_action_data_release_terrain },
	{ "unit_action_data_stand_up", DF_Type::unit_action_data_stand_up },
	{ "unit_action_data_suck_blood", DF_Type::unit_action_data_suck_blood },
	{ "unit_action_data_talk", DF_Type::unit_action_data_talk },
	{ "unit_action_data_unsteady", DF_Type::unit_action_data_unsteady },
	{ "unit_action_type", DF_Type::unit_action_type },
	{ "unit_appearance", DF_Type::unit_appearance },
	{ "unit_attribute", DF_Type::unit_attribute },
	{ "unit_bp_health_flags", DF_Type::unit_bp_health_flags },
	{ "unit_chunk", DF_Type::unit_chunk },
	{ "unit_chunk__T_units", DF_Type::unit_chunk__T_units },
	{ "unit_coin_debt", DF_Type::unit_coin_debt },
	{ "unit_complaint", DF_Type::unit_complaint },
	{ "unit_complaint__T_type", DF_Type::unit_complaint__T_type },
	{ "unit_dance_skill", DF_Type::unit_dance_skill },
	{ "unit_demand", DF_Type::unit_demand },
	{ "unit_demand__T_place", DF_Type::unit_demand__T_place },
	{ "unit_emotion_memory", DF_Type::unit_emotion_memory },
	{ "unit_flags1", DF_Type::unit_flags1 },
	{ "unit_flags2", DF_Type::unit_flags2 },
	{ "unit_flags3", DF_Type::unit_flags3 },
	{ "unit_flags4", DF_Type::unit_flags4 },
	{ "unit_genes", DF_Type::unit_genes },
	{ "unit_ghost_info", DF_Type::unit_ghost_info },
	{ "unit_ghost_info__T_flags", DF_Type::unit_ghost_info__T_flags },
	{ "unit_ghost_info__T_target", DF_Type::unit_ghost_info__T_target },
	{ "unit_health_flags", DF_Type::unit_health_flags },
	{ "unit_health_info", DF_Type::unit_health_info },
	{ "unit_health_info__T_op_history", DF_Type::unit_health_info__T_op_history },
	{ "unit_health_info__T_op_history__T_info", DF_Type::unit_health_info__T_op_history__T_info },
	{ "unit_health_info__T_op_history__T_info__T_bandage", DF_Type::unit_health_info__T_op_history__T_info__T_bandage },
	{ "unit_health_info__T_op_history__T_info__T_crutch", DF_Type::unit_health_info__T_op_history__T_info__T_crutch },
	{ "unit_instrument_skill", DF_Type::unit_instrument_skill },
	{ "unit_inventory_item", DF_Type::unit_inventory_item },
	{ "unit_inventory_item__T_mode", DF_Type::unit_inventory_item__T_mode },
	{ "unit_item_use", DF_Type::unit_item_use },
	{ "unit_item_wrestle", DF_Type::unit_item_wrestle },
	{ "unit_labor", DF_Type::unit_labor },
	{ "unit_labor_category", DF_Type::unit_labor_category },
	{ "unit_misc_trait", DF_Type::unit_misc_trait },
	{ "unit_musical_skill", DF_Type::unit_musical_skill },
	{ "unit_path_goal", DF_Type::unit_path_goal },
	{ "unit_personality", DF_Type::unit_personality },
	{ "unit_personality__T_dreams", DF_Type::unit_personality__T_dreams },
	{ "unit_personality__T_emotions", DF_Type::unit_personality__T_emotions },
	{ "unit_personality__T_emotions__T_flags", DF_Type::unit_personality__T_emotions__T_flags },
	{ "unit_personality__T_flags", DF_Type::unit_personality__T_flags },
	{ "unit_personality__T_memories", DF_Type::unit_personality__T_memories },
	{ "unit_personality__T_memories__T_reflected_on", DF_Type::unit_personality__T_memories__T_reflected_on },
	{ "unit_personality__T_needs", DF_Type::unit_personality__T_needs },
	{ "unit_personality__T_unk5", DF_Type::unit_personality__T_unk5 },
	{ "unit_personality__T_unk_v40_2", DF_Type::unit_personality__T_unk_v40_2 },
	{ "unit_personality__T_unk_v40_6", DF_Type::unit_personality__T_unk_v40_6 },
	{ "unit_personality__T_values", DF_Type::unit_personality__T_values },
	{ "unit_poetic_skill", DF_Type::unit_poetic_skill },
	{ "unit_preference", DF_Type::unit_preference },
	{ "unit_preference___union2", DF_Type::unit_preference___union2 },
	{ "unit_preference__T_type", DF_Type::unit_preference__T_type },
	{ "unit_relationship_type", DF_Type::unit_relationship_type },
	{ "unit_report_type", DF_Type::unit_report_type },
	{ "unit_request", DF_Type::unit_request },
	{ "unit_request__T_type", DF_Type::unit_request__T_type },
	{ "unit_skill", DF_Type::unit_skill },
	{ "unit_soul", DF_Type::unit_soul },
	{ "unit_soul__T_performance_skills", DF_Type::unit_soul__T_performance_skills },
	{ "unit_station_type", DF_Type::unit_station_type },
	{ "unit_storage_status", DF_Type::unit_storage_status },
	{ "unit_syndrome", DF_Type::unit_syndrome },
	{ "unit_syndrome__T_flags", DF_Type::unit_syndrome__T_flags },
	{ "unit_syndrome__T_symptoms", DF_Type::unit_syndrome__T_symptoms },
	{ "unit_syndrome__T_symptoms__T_flags", DF_Type::unit_syndrome__T_symptoms__T_flags },
	{ "unit_thought_type", DF_Type::unit_thought_type },
	{ "unit_unk_138", DF_Type::unit_unk_138 },
	{ "unit_wound", DF_Type::unit_wound },
	{ "unit_wound__T_flags", DF_Type::unit_wound__T_flags },
	{ "unit_wound__T_parts", DF_Type::unit_wound__T_parts },
	{ "units_other_id", DF_Type::units_other_id },
	{ "vague_relationship_type", DF_Type::vague_relationship_type },
	{ "value_type", DF_Type::value_type },
	{ "vehicle", DF_Type::vehicle },
	{ "vermin", DF_Type::vermin },
	{ "vermin_flags", DF_Type::vermin_flags },
	{ "viewscreen", DF_Type::viewscreen },
	{ "viewscreen_adopt_regionst", DF_Type::viewscreen_adopt_regionst },
	{ "viewscreen_adventure_logst", DF_Type::viewscreen_adventure_logst },
	{ "viewscreen_adventure_logst__T_info_mode", DF_Type::viewscreen_adventure_logst__T_info_mode },
	{ "viewscreen_adventure_logst__T_mode", DF_Type::viewscreen_adventure_logst__T_mode },
	{ "viewscreen_adventure_logst__T_unk_68", DF_Type::viewscreen_adventure_logst__T_unk_68 },
	{ "viewscreen_announcelistst", DF_Type::viewscreen_announcelistst },
	{ "viewscreen_assign_display_itemst", DF_Type::viewscreen_assign_display_itemst },
	{ "viewscreen_assign_display_itemst__T_sel_column", DF_Type::viewscreen_assign_display_itemst__T_sel_column },
	{ "viewscreen_barterst", DF_Type::viewscreen_barterst },
	{ "viewscreen_buildinglistst", DF_Type::viewscreen_buildinglistst },
	{ "viewscreen_buildingst", DF_Type::viewscreen_buildingst },
	{ "viewscreen_choose_start_sitest", DF_Type::viewscreen_choose_start_sitest },
	{ "viewscreen_choose_start_sitest__T_finder", DF_Type::viewscreen_choose_start_sitest__T_finder },
	{ "viewscreen_choose_start_sitest__T_finder__T_finder_state", DF_Type::viewscreen_choose_start_sitest__T_finder__T_finder_state },
	{ "viewscreen_choose_start_sitest__T_page", DF_Type::viewscreen_choose_start_sitest__T_page },
	{ "viewscreen_civlistst", DF_Type::viewscreen_civlistst },
	{ "viewscreen_civlistst__T_artifact_details", DF_Type::viewscreen_civlistst__T_artifact_details },
	{ "viewscreen_civlistst__T_page", DF_Type::viewscreen_civlistst__T_page },
	{ "viewscreen_civlistst__T_rumors", DF_Type::viewscreen_civlistst__T_rumors },
	{ "viewscreen_civlistst__T_rumors__T_type", DF_Type::viewscreen_civlistst__T_rumors__T_type },
	{ "viewscreen_civlistst__T_unk_cache", DF_Type::viewscreen_civlistst__T_unk_cache },
	{ "viewscreen_civlistst__T_unk_cache__T_tmp1", DF_Type::viewscreen_civlistst__T_unk_cache__T_tmp1 },
	{ "viewscreen_civlistst__T_unk_cache__T_tmp2", DF_Type::viewscreen_civlistst__T_unk_cache__T_tmp2 },
	{ "viewscreen_counterintelligencest", DF_Type::viewscreen_counterintelligencest },
	{ "viewscreen_createquotast", DF_Type::viewscreen_createquotast },
	{ "viewscreen_customize_unitst", DF_Type::viewscreen_customize_unitst },
	{ "viewscreen_dungeon_monsterstatusst", DF_Type::viewscreen_dungeon_monsterstatusst },
	{ "viewscreen_dungeon_wrestlest", DF_Type::viewscreen_dungeon_wrestlest },
	{ "viewscreen_dungeon_wrestlest__T_unk1", DF_Type::viewscreen_dungeon_wrestlest__T_unk1 },
	{ "viewscreen_dungeonmodest", DF_Type::viewscreen_dungeonmodest },
	{ "viewscreen_dwarfmodest", DF_Type::viewscreen_dwarfmodest },
	{ "viewscreen_entityst", DF_Type::viewscreen_entityst },
	{ "viewscreen_export_graphical_mapst", DF_Type::viewscreen_export_graphical_mapst },
	{ "viewscreen_export_graphical_mapst__T_rgb_buffer", DF_Type::viewscreen_export_graphical_mapst__T_rgb_buffer },
	{ "viewscreen_export_regionst", DF_Type::viewscreen_export_regionst },
	{ "viewscreen_export_regionst__T_unk1", DF_Type::viewscreen_export_regionst__T_unk1 },
	{ "viewscreen_game_cleanerst", DF_Type::viewscreen_game_cleanerst },
	{ "viewscreen_game_cleanerst__T_state", DF_Type::viewscreen_game_cleanerst__T_state },
	{ "viewscreen_image_creator_mode", DF_Type::viewscreen_image_creator_mode },
	{ "viewscreen_image_creatorst", DF_Type::viewscreen_image_creatorst },
	{ "viewscreen_image_creatorst__T_artifacts", DF_Type::viewscreen_image_creatorst__T_artifacts },
	{ "viewscreen_image_creatorst__T_entities", DF_Type::viewscreen_image_creatorst__T_entities },
	{ "viewscreen_image_creatorst__T_histfigs", DF_Type::viewscreen_image_creatorst__T_histfigs },
	{ "viewscreen_image_creatorst__T_objects", DF_Type::viewscreen_image_creatorst__T_objects },
	{ "viewscreen_image_creatorst__T_plants", DF_Type::viewscreen_image_creatorst__T_plants },
	{ "viewscreen_image_creatorst__T_relationships", DF_Type::viewscreen_image_creatorst__T_relationships },
	{ "viewscreen_image_creatorst__T_shapes", DF_Type::viewscreen_image_creatorst__T_shapes },
	{ "viewscreen_image_creatorst__T_sites", DF_Type::viewscreen_image_creatorst__T_sites },
	{ "viewscreen_image_creatorst__T_trees", DF_Type::viewscreen_image_creatorst__T_trees },
	{ "viewscreen_itemst", DF_Type::viewscreen_itemst },
	{ "viewscreen_joblistst", DF_Type::viewscreen_joblistst },
	{ "viewscreen_jobmanagementst", DF_Type::viewscreen_jobmanagementst },
	{ "viewscreen_jobst", DF_Type::viewscreen_jobst },
	{ "viewscreen_justicest", DF_Type::viewscreen_justicest },
	{ "viewscreen_justicest__T_cur_column", DF_Type::viewscreen_justicest__T_cur_column },
	{ "viewscreen_justicest__T_interrogate_status", DF_Type::viewscreen_justicest__T_interrogate_status },
	{ "viewscreen_kitchenpref_page", DF_Type::viewscreen_kitchenpref_page },
	{ "viewscreen_kitchenprefst", DF_Type::viewscreen_kitchenprefst },
	{ "viewscreen_layer", DF_Type::viewscreen_layer },
	{ "viewscreen_layer_arena_creaturest", DF_Type::viewscreen_layer_arena_creaturest },
	{ "viewscreen_layer_assigntradest", DF_Type::viewscreen_layer_assigntradest },
	{ "viewscreen_layer_choose_language_namest", DF_Type::viewscreen_layer_choose_language_namest },
	{ "viewscreen_layer_choose_language_namest__T_current_component", DF_Type::viewscreen_layer_choose_language_namest__T_current_component },
	{ "viewscreen_layer_currencyst", DF_Type::viewscreen_layer_currencyst },
	{ "viewscreen_layer_export_play_mapst", DF_Type::viewscreen_layer_export_play_mapst },
	{ "viewscreen_layer_militaryst", DF_Type::viewscreen_layer_militaryst },
	{ "viewscreen_layer_militaryst__T_ammo", DF_Type::viewscreen_layer_militaryst__T_ammo },
	{ "viewscreen_layer_militaryst__T_ammo__T_add_item", DF_Type::viewscreen_layer_militaryst__T_ammo__T_add_item },
	{ "viewscreen_layer_militaryst__T_ammo__T_material", DF_Type::viewscreen_layer_militaryst__T_ammo__T_material },
	{ "viewscreen_layer_militaryst__T_equip", DF_Type::viewscreen_layer_militaryst__T_equip },
	{ "viewscreen_layer_militaryst__T_equip__T_add_item", DF_Type::viewscreen_layer_militaryst__T_equip__T_add_item },
	{ "viewscreen_layer_militaryst__T_equip__T_assigned", DF_Type::viewscreen_layer_militaryst__T_equip__T_assigned },
	{ "viewscreen_layer_militaryst__T_equip__T_color", DF_Type::viewscreen_layer_militaryst__T_equip__T_color },
	{ "viewscreen_layer_militaryst__T_equip__T_edit_mode", DF_Type::viewscreen_layer_militaryst__T_equip__T_edit_mode },
	{ "viewscreen_layer_militaryst__T_equip__T_material", DF_Type::viewscreen_layer_militaryst__T_equip__T_material },
	{ "viewscreen_layer_militaryst__T_equip__T_mode", DF_Type::viewscreen_layer_militaryst__T_equip__T_mode },
	{ "viewscreen_layer_militaryst__T_equip__T_uniform", DF_Type::viewscreen_layer_militaryst__T_equip__T_uniform },
	{ "viewscreen_layer_militaryst__T_page", DF_Type::viewscreen_layer_militaryst__T_page },
	{ "viewscreen_layer_militaryst__T_positions", DF_Type::viewscreen_layer_militaryst__T_positions },
	{ "viewscreen_layer_militaryst__T_squad_members", DF_Type::viewscreen_layer_militaryst__T_squad_members },
	{ "viewscreen_layer_militaryst__T_squads", DF_Type::viewscreen_layer_militaryst__T_squads },
	{ "viewscreen_layer_musicsoundst", DF_Type::viewscreen_layer_musicsoundst },
	{ "viewscreen_layer_noblelistst", DF_Type::viewscreen_layer_noblelistst },
	{ "viewscreen_layer_noblelistst__T_candidates", DF_Type::viewscreen_layer_noblelistst__T_candidates },
	{ "viewscreen_layer_noblelistst__T_info", DF_Type::viewscreen_layer_noblelistst__T_info },
	{ "viewscreen_layer_noblelistst__T_mode", DF_Type::viewscreen_layer_noblelistst__T_mode },
	{ "viewscreen_layer_overall_healthst", DF_Type::viewscreen_layer_overall_healthst },
	{ "viewscreen_layer_reactionst", DF_Type::viewscreen_layer_reactionst },
	{ "viewscreen_layer_squad_schedulest", DF_Type::viewscreen_layer_squad_schedulest },
	{ "viewscreen_layer_stockpilest", DF_Type::viewscreen_layer_stockpilest },
	{ "viewscreen_layer_stone_restrictionst", DF_Type::viewscreen_layer_stone_restrictionst },
	{ "viewscreen_layer_unit_actionst", DF_Type::viewscreen_layer_unit_actionst },
	{ "viewscreen_layer_unit_healthst", DF_Type::viewscreen_layer_unit_healthst },
	{ "viewscreen_layer_unit_relationshipst", DF_Type::viewscreen_layer_unit_relationshipst },
	{ "viewscreen_layer_world_gen_param_presetst", DF_Type::viewscreen_layer_world_gen_param_presetst },
	{ "viewscreen_layer_world_gen_paramst", DF_Type::viewscreen_layer_world_gen_paramst },
	{ "viewscreen_layer_world_gen_paramst__T_unk1", DF_Type::viewscreen_layer_world_gen_paramst__T_unk1 },
	{ "viewscreen_legendsst", DF_Type::viewscreen_legendsst },
	{ "viewscreen_legendsst__T_anon_7", DF_Type::viewscreen_legendsst__T_anon_7 },
	{ "viewscreen_legendsst__T_anon_7__T_anon_3", DF_Type::viewscreen_legendsst__T_anon_7__T_anon_3 },
	{ "viewscreen_legendsst__T_cur_page", DF_Type::viewscreen_legendsst__T_cur_page },
	{ "viewscreen_loadgamest", DF_Type::viewscreen_loadgamest },
	{ "viewscreen_loadgamest__T_cur_step", DF_Type::viewscreen_loadgamest__T_cur_step },
	{ "viewscreen_locationsst", DF_Type::viewscreen_locationsst },
	{ "viewscreen_locationsst__T_in_edit", DF_Type::viewscreen_locationsst__T_in_edit },
	{ "viewscreen_locationsst__T_menu", DF_Type::viewscreen_locationsst__T_menu },
	{ "viewscreen_meetingst", DF_Type::viewscreen_meetingst },
	{ "viewscreen_movieplayerst", DF_Type::viewscreen_movieplayerst },
	{ "viewscreen_new_regionst", DF_Type::viewscreen_new_regionst },
	{ "viewscreen_new_regionst__T_worldgen_presets", DF_Type::viewscreen_new_regionst__T_worldgen_presets },
	{ "viewscreen_noblest", DF_Type::viewscreen_noblest },
	{ "viewscreen_optionst", DF_Type::viewscreen_optionst },
	{ "viewscreen_optionst__T_options", DF_Type::viewscreen_optionst__T_options },
	{ "viewscreen_overallstatusst", DF_Type::viewscreen_overallstatusst },
	{ "viewscreen_overallstatusst__T_visible_pages", DF_Type::viewscreen_overallstatusst__T_visible_pages },
	{ "viewscreen_petitionsst", DF_Type::viewscreen_petitionsst },
	{ "viewscreen_petst", DF_Type::viewscreen_petst },
	{ "viewscreen_petst__T_animal", DF_Type::viewscreen_petst__T_animal },
	{ "viewscreen_petst__T_mode", DF_Type::viewscreen_petst__T_mode },
	{ "viewscreen_petst__T_trainer_mode", DF_Type::viewscreen_petst__T_trainer_mode },
	{ "viewscreen_pricest", DF_Type::viewscreen_pricest },
	{ "viewscreen_reportlistst", DF_Type::viewscreen_reportlistst },
	{ "viewscreen_requestagreementst", DF_Type::viewscreen_requestagreementst },
	{ "viewscreen_savegamest", DF_Type::viewscreen_savegamest },
	{ "viewscreen_selectitemst", DF_Type::viewscreen_selectitemst },
	{ "viewscreen_setupadventurest", DF_Type::viewscreen_setupadventurest },
	{ "viewscreen_setupadventurest__T_page", DF_Type::viewscreen_setupadventurest__T_page },
	{ "viewscreen_setupadventurest__T_races_info", DF_Type::viewscreen_setupadventurest__T_races_info },
	{ "viewscreen_setupadventurest__T_status", DF_Type::viewscreen_setupadventurest__T_status },
	{ "viewscreen_setupdwarfgamest", DF_Type::viewscreen_setupdwarfgamest },
	{ "viewscreen_setupdwarfgamest__T_animals", DF_Type::viewscreen_setupdwarfgamest__T_animals },
	{ "viewscreen_setupdwarfgamest__T_choice_types", DF_Type::viewscreen_setupdwarfgamest__T_choice_types },
	{ "viewscreen_setupdwarfgamest__T_mode", DF_Type::viewscreen_setupdwarfgamest__T_mode },
	{ "viewscreen_setupdwarfgamest__T_unk_v43", DF_Type::viewscreen_setupdwarfgamest__T_unk_v43 },
	{ "viewscreen_setupdwarfgamest__T_unk_v43__T_unk_v43_sub9", DF_Type::viewscreen_setupdwarfgamest__T_unk_v43__T_unk_v43_sub9 },
	{ "viewscreen_storesst", DF_Type::viewscreen_storesst },
	{ "viewscreen_textviewerst", DF_Type::viewscreen_textviewerst },
	{ "viewscreen_textviewerst__T_formatted_text", DF_Type::viewscreen_textviewerst__T_formatted_text },
	{ "viewscreen_textviewerst__T_formatted_text__T_flags", DF_Type::viewscreen_textviewerst__T_formatted_text__T_flags },
	{ "viewscreen_titlest", DF_Type::viewscreen_titlest },
	{ "viewscreen_titlest__T_menu_line_id", DF_Type::viewscreen_titlest__T_menu_line_id },
	{ "viewscreen_titlest__T_sel_subpage", DF_Type::viewscreen_titlest__T_sel_subpage },
	{ "viewscreen_titlest__T_start_savegames", DF_Type::viewscreen_titlest__T_start_savegames },
	{ "viewscreen_topicmeeting_fill_land_holder_positionsst", DF_Type::viewscreen_topicmeeting_fill_land_holder_positionsst },
	{ "viewscreen_topicmeeting_takerequestsst", DF_Type::viewscreen_topicmeeting_takerequestsst },
	{ "viewscreen_topicmeetingst", DF_Type::viewscreen_topicmeetingst },
	{ "viewscreen_tradeagreementst", DF_Type::viewscreen_tradeagreementst },
	{ "viewscreen_tradegoodsst", DF_Type::viewscreen_tradegoodsst },
	{ "viewscreen_tradelistst", DF_Type::viewscreen_tradelistst },
	{ "viewscreen_treasurelistst", DF_Type::viewscreen_treasurelistst },
	{ "viewscreen_unitlist_page", DF_Type::viewscreen_unitlist_page },
	{ "viewscreen_unitlistst", DF_Type::viewscreen_unitlistst },
	{ "viewscreen_unitst", DF_Type::viewscreen_unitst },
	{ "viewscreen_update_regionst", DF_Type::viewscreen_update_regionst },
	{ "viewscreen_wagesst", DF_Type::viewscreen_wagesst },
	{ "viewscreen_workquota_conditionst", DF_Type::viewscreen_workquota_conditionst },
	{ "viewscreen_workquota_conditionst__T_mode", DF_Type::viewscreen_workquota_conditionst__T_mode },
	{ "viewscreen_workquota_conditionst__T_traits", DF_Type::viewscreen_workquota_conditionst__T_traits },
	{ "viewscreen_workquota_conditionst__T_traits__T_flags", DF_Type::viewscreen_workquota_conditionst__T_traits__T_flags },
	{ "viewscreen_workquota_detailsst", DF_Type::viewscreen_workquota_detailsst },
	{ "viewscreen_workshop_profilest", DF_Type::viewscreen_workshop_profilest },
	{ "viewscreen_workshop_profilest__T_tab", DF_Type::viewscreen_workshop_profilest__T_tab },
	{ "weapon_attack", DF_Type::weapon_attack },
	{ "weapon_attack__T_flags", DF_Type::weapon_attack__T_flags },
	{ "weapon_flags", DF_Type::weapon_flags },
	{ "weather_type", DF_Type::weather_type },
	{ "web_cluster", DF_Type::web_cluster },
	{ "whereabouts_type", DF_Type::whereabouts_type },
	{ "widget_menu", DF_Type::widget_menu },
	{ "widget_textbox", DF_Type::widget_textbox },
	{ "workshop_profile", DF_Type::workshop_profile },
	{ "workshop_type", DF_Type::workshop_type },
	{ "world", DF_Type::world },
	{ "world__T_activities", DF_Type::world__T_activities },
	{ "world__T_agreements", DF_Type::world__T_agreements },
	{ "world__T_area_grasses", DF_Type::world__T_area_grasses },
	{ "world__T_area_grasses__T_layer_grasses", DF_Type::world__T_area_grasses__T_layer_grasses },
	{ "world__T_arena_settings", DF_Type::world__T_arena_settings },
	{ "world__T_arena_spawn", DF_Type::world__T_arena_spawn },
	{ "world__T_arena_spawn__T_equipment", DF_Type::world__T_arena_spawn__T_equipment },
	{ "world__T_arena_spawn__T_item_types", DF_Type::world__T_arena_spawn__T_item_types },
	{ "world__T_arena_spawn__T_tame", DF_Type::world__T_arena_spawn__T_tame },
	{ "world__T_armies", DF_Type::world__T_armies },
	{ "world__T_army_controllers", DF_Type::world__T_army_controllers },
	{ "world__T_army_tracking_info", DF_Type::world__T_army_tracking_info },
	{ "world__T_artifacts", DF_Type::world__T_artifacts },
	{ "world__T_belief_systems", DF_Type::world__T_belief_systems },
	{ "world__T_crimes", DF_Type::world__T_crimes },
	{ "world__T_cultural_identities", DF_Type::world__T_cultural_identities },
	{ "world__T_cur_savegame", DF_Type::world__T_cur_savegame },
	{ "world__T_dance_forms", DF_Type::world__T_dance_forms },
	{ "world__T_divination_sets", DF_Type::world__T_divination_sets },
	{ "world__T_enemy_status_cache", DF_Type::world__T_enemy_status_cache },
	{ "world__T_entities", DF_Type::world__T_entities },
	{ "world__T_features", DF_Type::world__T_features },
	{ "world__T_flow_engine", DF_Type::world__T_flow_engine },
	{ "world__T_flow_guides", DF_Type::world__T_flow_guides },
	{ "world__T_formations", DF_Type::world__T_formations },
	{ "world__T_identities", DF_Type::world__T_identities },
	{ "world__T_image_sets", DF_Type::world__T_image_sets },
	{ "world__T_image_sets__T_all", DF_Type::world__T_image_sets__T_all },
	{ "world__T_image_sets__T_all__T_anon_3", DF_Type::world__T_image_sets__T_all__T_anon_3 },
	{ "world__T_incidents", DF_Type::world__T_incidents },
	{ "world__T_interaction_instances", DF_Type::world__T_interaction_instances },
	{ "world__T_items", DF_Type::world__T_items },
	{ "world__T_languages", DF_Type::world__T_languages },
	{ "world__T_map", DF_Type::world__T_map },
	{ "world__T_map_extras", DF_Type::world__T_map_extras },
	{ "world__T_math", DF_Type::world__T_math },
	{ "world__T_math__T_approx", DF_Type::world__T_math__T_approx },
	{ "world__T_musical_forms", DF_Type::world__T_musical_forms },
	{ "world__T_nemesis", DF_Type::world__T_nemesis },
	{ "world__T_occupations", DF_Type::world__T_occupations },
	{ "world__T_pathfinder", DF_Type::world__T_pathfinder },
	{ "world__T_pathfinder__T_boundary_heap", DF_Type::world__T_pathfinder__T_boundary_heap },
	{ "world__T_plants", DF_Type::world__T_plants },
	{ "world__T_poetic_forms", DF_Type::world__T_poetic_forms },
	{ "world__T_profession_skills", DF_Type::world__T_profession_skills },
	{ "world__T_rhythms", DF_Type::world__T_rhythms },
	{ "world__T_scales", DF_Type::world__T_scales },
	{ "world__T_schedules", DF_Type::world__T_schedules },
	{ "world__T_squads", DF_Type::world__T_squads },
	{ "world__T_status", DF_Type::world__T_status },
	{ "world__T_status__T_flags", DF_Type::world__T_status__T_flags },
	{ "world__T_status__T_slots", DF_Type::world__T_status__T_slots },
	{ "world__T_status__T_slots__T_flags", DF_Type::world__T_status__T_slots__T_flags },
	{ "world__T_stockpile", DF_Type::world__T_stockpile },
	{ "world__T_stockpile__T_simple1", DF_Type::world__T_stockpile__T_simple1 },
	{ "world__T_stockpile__T_simple2", DF_Type::world__T_stockpile__T_simple2 },
	{ "world__T_stockpile__T_simple3", DF_Type::world__T_stockpile__T_simple3 },
	{ "world__T_units", DF_Type::world__T_units },
	{ "world__T_unk_131ec0", DF_Type::world__T_unk_131ec0 },
	{ "world__T_unk_131ef0", DF_Type::world__T_unk_131ef0 },
	{ "world__T_unk_131ef0__T_claims", DF_Type::world__T_unk_131ef0__T_claims },
	{ "world__T_unk_19325c", DF_Type::world__T_unk_19325c },
	{ "world__T_unk_19325c__T_anon_1", DF_Type::world__T_unk_19325c__T_anon_1 },
	{ "world__T_unk_19325c__T_anon_2", DF_Type::world__T_unk_19325c__T_anon_2 },
	{ "world__T_unk_19325c__T_anon_3", DF_Type::world__T_unk_19325c__T_anon_3 },
	{ "world__T_unk_26c678", DF_Type::world__T_unk_26c678 },
	{ "world__T_unk_v40_6", DF_Type::world__T_unk_v40_6 },
	{ "world__T_vehicles", DF_Type::world__T_vehicles },
	{ "world__T_vermin", DF_Type::world__T_vermin },
	{ "world__T_worldgen", DF_Type::world__T_worldgen },
	{ "world__T_worldgen__T_worldgen_parms", DF_Type::world__T_worldgen__T_worldgen_parms },
	{ "world__T_worldgen_coord_buf", DF_Type::world__T_worldgen_coord_buf },
	{ "world__T_worldgen_status", DF_Type::world__T_worldgen_status },
	{ "world__T_written_contents", DF_Type::world__T_written_contents },
	{ "world_construction", DF_Type::world_construction },
	{ "world_construction_bridgest", DF_Type::world_construction_bridgest },
	{ "world_construction_roadst", DF_Type::world_construction_roadst },
	{ "world_construction_square", DF_Type::world_construction_square },
	{ "world_construction_square_bridgest", DF_Type::world_construction_square_bridgest },
	{ "world_construction_square_roadst", DF_Type::world_construction_square_roadst },
	{ "world_construction_square_tunnelst", DF_Type::world_construction_square_tunnelst },
	{ "world_construction_square_wallst", DF_Type::world_construction_square_wallst },
	{ "world_construction_tunnelst", DF_Type::world_construction_tunnelst },
	{ "world_construction_type", DF_Type::world_construction_type },
	{ "world_construction_wallst", DF_Type::world_construction_wallst },
	{ "world_dat_summary", DF_Type::world_dat_summary },
	{ "world_data", DF_Type::world_data },
	{ "world_data__T_constructions", DF_Type::world_data__T_constructions },
	{ "world_data__T_feature_map", DF_Type::world_data__T_feature_map },
	{ "world_data__T_feature_map__T_features", DF_Type::world_data__T_feature_map__T_features },
	{ "world_data__T_field_battles", DF_Type::world_data__T_field_battles },
	{ "world_data__T_field_battles__T_sapient_deaths", DF_Type::world_data__T_field_battles__T_sapient_deaths },
	{ "world_data__T_flip_latitude", DF_Type::world_data__T_flip_latitude },
	{ "world_data__T_freakish_weather", DF_Type::world_data__T_freakish_weather },
	{ "world_data__T_mountain_peaks", DF_Type::world_data__T_mountain_peaks },
	{ "world_data__T_unk_150", DF_Type::world_data__T_unk_150 },
	{ "world_data__T_unk_150__T_unk_18", DF_Type::world_data__T_unk_150__T_unk_18 },
	{ "world_data__T_unk_150__T_unk_28", DF_Type::world_data__T_unk_150__T_unk_28 },
	{ "world_data__T_unk_150__T_unk_8", DF_Type::world_data__T_unk_150__T_unk_8 },
	{ "world_data__T_unk_274", DF_Type::world_data__T_unk_274 },
	{ "world_data__T_unk_274__T_unk_10", DF_Type::world_data__T_unk_274__T_unk_10 },
	{ "world_data__T_unk_482f8", DF_Type::world_data__T_unk_482f8 },
	{ "world_data__T_unk_b4", DF_Type::world_data__T_unk_b4 },
	{ "world_gen_param_basest", DF_Type::world_gen_param_basest },
	{ "world_gen_param_charst", DF_Type::world_gen_param_charst },
	{ "world_gen_param_memberst", DF_Type::world_gen_param_memberst },
	{ "world_gen_param_seedst", DF_Type::world_gen_param_seedst },
	{ "world_gen_param_valuest", DF_Type::world_gen_param_valuest },
	{ "world_geo_biome", DF_Type::world_geo_biome },
	{ "world_geo_layer", DF_Type::world_geo_layer },
	{ "world_history", DF_Type::world_history },
	{ "world_history__T_event_collections", DF_Type::world_history__T_event_collections },
	{ "world_history__T_intrigues", DF_Type::world_history__T_intrigues },
	{ "world_history__T_intrigues__T_anon_1", DF_Type::world_history__T_intrigues__T_anon_1 },
	{ "world_landmass", DF_Type::world_landmass },
	{ "world_object_data", DF_Type::world_object_data },
	{ "world_object_data__T_offloaded_buildings", DF_Type::world_object_data__T_offloaded_buildings },
	{ "world_object_data__T_offloaded_items", DF_Type::world_object_data__T_offloaded_items },
	{ "world_object_data__T_unk_94", DF_Type::world_object_data__T_unk_94 },
	{ "world_population", DF_Type::world_population },
	{ "world_population___union4", DF_Type::world_population___union4 },
	{ "world_population_ref", DF_Type::world_population_ref },
	{ "world_population_type", DF_Type::world_population_type },
	{ "world_raws", DF_Type::world_raws },
	{ "world_raws__T_bodyglosses", DF_Type::world_raws__T_bodyglosses },
	{ "world_raws__T_buildings", DF_Type::world_raws__T_buildings },
	{ "world_raws__T_descriptors", DF_Type::world_raws__T_descriptors },
	{ "world_raws__T_effects", DF_Type::world_raws__T_effects },
	{ "world_raws__T_itemdefs", DF_Type::world_raws__T_itemdefs },
	{ "world_raws__T_language", DF_Type::world_raws__T_language },
	{ "world_raws__T_plants", DF_Type::world_raws__T_plants },
	{ "world_raws__T_reactions", DF_Type::world_raws__T_reactions },
	{ "world_raws__T_syndromes", DF_Type::world_raws__T_syndromes },
	{ "world_region", DF_Type::world_region },
	{ "world_region_details", DF_Type::world_region_details },
	{ "world_region_details__T_edges", DF_Type::world_region_details__T_edges },
	{ "world_region_details__T_other_features", DF_Type::world_region_details__T_other_features },
	{ "world_region_details__T_rivers_horizontal", DF_Type::world_region_details__T_rivers_horizontal },
	{ "world_region_details__T_rivers_vertical", DF_Type::world_region_details__T_rivers_vertical },
	{ "world_region_feature", DF_Type::world_region_feature },
	{ "world_region_type", DF_Type::world_region_type },
	{ "world_river", DF_Type::world_river },
	{ "world_site", DF_Type::world_site },
	{ "world_site__T_subtype_info", DF_Type::world_site__T_subtype_info },
	{ "world_site__T_unk_1", DF_Type::world_site__T_unk_1 },
	{ "world_site__T_unk_118", DF_Type::world_site__T_unk_118 },
	{ "world_site__T_unk_13c", DF_Type::world_site__T_unk_13c },
	{ "world_site__T_unk_188", DF_Type::world_site__T_unk_188 },
	{ "world_site__T_unk_188__T_unk1", DF_Type::world_site__T_unk_188__T_unk1 },
	{ "world_site__T_unk_1__T_units", DF_Type::world_site__T_unk_1__T_units },
	{ "world_site__T_unk_21c", DF_Type::world_site__T_unk_21c },
	{ "world_site__T_unk_v40_2", DF_Type::world_site__T_unk_v40_2 },
	{ "world_site__T_unk_v40_4a", DF_Type::world_site__T_unk_v40_4a },
	{ "world_site__T_unk_v40_4b", DF_Type::world_site__T_unk_v40_4b },
	{ "world_site__T_unk_v40_4c", DF_Type::world_site__T_unk_v40_4c },
	{ "world_site__T_unk_v40_4d", DF_Type::world_site__T_unk_v40_4d },
	{ "world_site__T_unk_v40_4d__T_anon_1", DF_Type::world_site__T_unk_v40_4d__T_anon_1 },
	{ "world_site__T_unk_v43_2", DF_Type::world_site__T_unk_v43_2 },
	{ "world_site__T_unk_v47_1", DF_Type::world_site__T_unk_v47_1 },
	{ "world_site__T_unk_v47_1__T_unk_1", DF_Type::world_site__T_unk_v47_1__T_unk_1 },
	{ "world_site_flags", DF_Type::world_site_flags },
	{ "world_site_inhabitant", DF_Type::world_site_inhabitant },
	{ "world_site_realization", DF_Type::world_site_realization },
	{ "world_site_realization__T_areas", DF_Type::world_site_realization__T_areas },
	{ "world_site_realization__T_areas__T_type", DF_Type::world_site_realization__T_areas__T_type },
	{ "world_site_realization__T_building_map", DF_Type::world_site_realization__T_building_map },
	{ "world_site_realization__T_river_map", DF_Type::world_site_realization__T_river_map },
	{ "world_site_realization__T_unk_193bc", DF_Type::world_site_realization__T_unk_193bc },
	{ "world_site_realization__T_unk_193bc__T_unk_8", DF_Type::world_site_realization__T_unk_193bc__T_unk_8 },
	{ "world_site_realization__T_unk_55e8", DF_Type::world_site_realization__T_unk_55e8 },
	{ "world_site_realization__T_unk_55e8__T_unk_v40_2", DF_Type::world_site_realization__T_unk_55e8__T_unk_v40_2 },
	{ "world_site_type", DF_Type::world_site_type },
	{ "world_site_unk130", DF_Type::world_site_unk130 },
	{ "world_site_unk130__T_unk_4", DF_Type::world_site_unk130__T_unk_4 },
	{ "world_underground_region", DF_Type::world_underground_region },
	{ "world_underground_region__T_type", DF_Type::world_underground_region__T_type },
	{ "world_unk26c678_unk38", DF_Type::world_unk26c678_unk38 },
	{ "world_unk_20", DF_Type::world_unk_20 },
	{ "world_unk_20__T_anon_7", DF_Type::world_unk_20__T_anon_7 },
	{ "world_unk_6c", DF_Type::world_unk_6c },
	{ "world_unk_a8", DF_Type::world_unk_a8 },
	{ "world_unk_b4", DF_Type::world_unk_b4 },
	{ "world_unk_c0", DF_Type::world_unk_c0 },
	{ "world_unk_c0__T_anon_7", DF_Type::world_unk_c0__T_anon_7 },
	{ "worldgen_range_type", DF_Type::worldgen_range_type },
	{ "worldgen_region_type", DF_Type::worldgen_region_type },
	{ "wound_curse_info", DF_Type::wound_curse_info },
	{ "wound_damage_flags1", DF_Type::wound_damage_flags1 },
	{ "wound_damage_flags2", DF_Type::wound_damage_flags2 },
	{ "wound_effect_type", DF_Type::wound_effect_type },
	{ "written_content", DF_Type::written_content },
	{ "written_content_style", DF_Type::written_content_style },
	{ "written_content_type", DF_Type::written_content_type },
	{ "z_level_flags", DF_Type::z_level_flags },
	{ "zoom_commands", DF_Type::zoom_commands }
};

DF_Type DF_Type_from_string(std::string& p_string)
{
    auto l_data = translation_table.find(p_string);
    if (l_data != translation_table.end())
        return l_data->second;
    return DF_Type::None;
}

DF_Type DF_Type_from_string(const char* p_char)
{
    std::string l_s = std::string(p_char);
    auto l_data = translation_table.find(l_s);
    if (l_data != translation_table.end())
        return l_data->second;
    return DF_Type::None;
}


int32_t DF_Type_to_int(rdf::DF_Type p_df_type)
{
    switch(p_df_type)
    {
        case DF_Type::None: return 0;
        case DF_Type::int64_t: return 1;
        case DF_Type::uint64_t: return 2;
        case DF_Type::int32_t: return 3;
        case DF_Type::int16_t: return 4;
        case DF_Type::uint32_t: return 5;
        case DF_Type::uint16_t: return 6;
        case DF_Type::uint8_t: return 7;
        case DF_Type::int8_t: return 8;
        case DF_Type::Void: return 9;
        case DF_Type::Char: return 10;
        case DF_Type::Long: return 11;
        case DF_Type::Bool: return 12;
        case DF_Type::Stl_string: return 13;
        case DF_Type::Static_string: return 14;
        case DF_Type::Ptr_string: return 15;
        case DF_Type::S_float: return 16;
        case DF_Type::D_float: return 17;
        case DF_Type::S_double: return 18;
        case DF_Type::Padding: return 19;
        case DF_Type::Stl_fstream: return 20;
	case DF_Type::abstract_building: return 21;
	case DF_Type::abstract_building__T_inhabitants: return 22;
	case DF_Type::abstract_building__T_unk1: return 23;
	case DF_Type::abstract_building_contents: return 24;
	case DF_Type::abstract_building_counting_housest: return 25;
	case DF_Type::abstract_building_dark_towerst: return 26;
	case DF_Type::abstract_building_dungeonst: return 27;
	case DF_Type::abstract_building_dungeonst__T_dungeon_type: return 28;
	case DF_Type::abstract_building_flags: return 29;
	case DF_Type::abstract_building_guildhallst: return 30;
	case DF_Type::abstract_building_inn_tavernst: return 31;
	case DF_Type::abstract_building_inn_tavernst__T_room_info: return 32;
	case DF_Type::abstract_building_keepst: return 33;
	case DF_Type::abstract_building_libraryst: return 34;
	case DF_Type::abstract_building_marketst: return 35;
	case DF_Type::abstract_building_mead_hallst: return 36;
	case DF_Type::abstract_building_templest: return 37;
	case DF_Type::abstract_building_tombst: return 38;
	case DF_Type::abstract_building_towerst: return 39;
	case DF_Type::abstract_building_type: return 40;
	case DF_Type::abstract_building_underworld_spirest: return 41;
	case DF_Type::abstract_building_unk: return 42;
	case DF_Type::abstract_building_unk__T_anon_1: return 43;
	case DF_Type::active_script_var_longst: return 44;
	case DF_Type::active_script_var_unitst: return 45;
	case DF_Type::active_script_varst: return 46;
	case DF_Type::activity_entry: return 47;
	case DF_Type::activity_entry_type: return 48;
	case DF_Type::activity_event: return 49;
	case DF_Type::activity_event__T_flags: return 50;
	case DF_Type::activity_event__T_unk_v42_1: return 51;
	case DF_Type::activity_event__T_unk_v42_2: return 52;
	case DF_Type::activity_event_combat_trainingst: return 53;
	case DF_Type::activity_event_conflictst: return 54;
	case DF_Type::activity_event_conflictst__T_sides: return 55;
	case DF_Type::activity_event_conflictst__T_sides__T_enemies: return 56;
	case DF_Type::activity_event_conversationst: return 57;
	case DF_Type::activity_event_conversationst__T_anon_6: return 58;
	case DF_Type::activity_event_conversationst__T_flags2: return 59;
	case DF_Type::activity_event_conversationst__T_participants: return 60;
	case DF_Type::activity_event_conversationst__T_turns: return 61;
	case DF_Type::activity_event_conversationst__T_unk2: return 62;
	case DF_Type::activity_event_conversationst__T_unk_b4: return 63;
	case DF_Type::activity_event_copy_written_contentst: return 64;
	case DF_Type::activity_event_copy_written_contentst__T_flagsmaybe: return 65;
	case DF_Type::activity_event_discuss_topicst: return 66;
	case DF_Type::activity_event_encounterst: return 67;
	case DF_Type::activity_event_encounterst__T_anon_1: return 68;
	case DF_Type::activity_event_encounterst__T_anon_2: return 69;
	case DF_Type::activity_event_fill_service_orderst: return 70;
	case DF_Type::activity_event_guardst: return 71;
	case DF_Type::activity_event_harassmentst: return 72;
	case DF_Type::activity_event_harassmentst__T_anon_2: return 73;
	case DF_Type::activity_event_individual_skill_drillst: return 74;
	case DF_Type::activity_event_make_believest: return 75;
	case DF_Type::activity_event_participants: return 76;
	case DF_Type::activity_event_performancest: return 77;
	case DF_Type::activity_event_performancest__T_participant_actions: return 78;
	case DF_Type::activity_event_play_with_toyst: return 79;
	case DF_Type::activity_event_play_with_toyst__T_unk: return 80;
	case DF_Type::activity_event_playst: return 81;
	case DF_Type::activity_event_ponder_topicst: return 82;
	case DF_Type::activity_event_prayerst: return 83;
	case DF_Type::activity_event_ranged_practicest: return 84;
	case DF_Type::activity_event_readst: return 85;
	case DF_Type::activity_event_researchst: return 86;
	case DF_Type::activity_event_reunionst: return 87;
	case DF_Type::activity_event_skill_demonstrationst: return 88;
	case DF_Type::activity_event_socializest: return 89;
	case DF_Type::activity_event_sparringst: return 90;
	case DF_Type::activity_event_sparringst__T_groups: return 91;
	case DF_Type::activity_event_store_objectst: return 92;
	case DF_Type::activity_event_teach_topicst: return 93;
	case DF_Type::activity_event_training_sessionst: return 94;
	case DF_Type::activity_event_type: return 95;
	case DF_Type::activity_event_worshipst: return 96;
	case DF_Type::activity_event_writest: return 97;
	case DF_Type::activity_info: return 98;
	case DF_Type::activity_info__T_flags: return 99;
	case DF_Type::adventure_environment_ingest_from_containerst: return 100;
	case DF_Type::adventure_environment_ingest_materialst: return 101;
	case DF_Type::adventure_environment_optionst: return 102;
	case DF_Type::adventure_environment_pickup_chop_treest: return 103;
	case DF_Type::adventure_environment_pickup_ignite_vegst: return 104;
	case DF_Type::adventure_environment_pickup_make_campfirest: return 105;
	case DF_Type::adventure_environment_pickup_vermin_eventst: return 106;
	case DF_Type::adventure_environment_place_in_bld_containerst: return 107;
	case DF_Type::adventure_environment_place_in_it_containerst: return 108;
	case DF_Type::adventure_environment_unit_suck_bloodst: return 109;
	case DF_Type::adventure_item_interact_choicest: return 110;
	case DF_Type::adventure_item_interact_fill_from_containerst: return 111;
	case DF_Type::adventure_item_interact_fill_with_materialst: return 112;
	case DF_Type::adventure_item_interact_give_namest: return 113;
	case DF_Type::adventure_item_interact_heat_from_tilest: return 114;
	case DF_Type::adventure_item_interact_pull_outst: return 115;
	case DF_Type::adventure_item_interact_readst: return 116;
	case DF_Type::adventure_item_interact_strugglest: return 117;
	case DF_Type::adventure_log_item: return 118;
	case DF_Type::adventure_movement_attack_creaturest: return 119;
	case DF_Type::adventure_movement_building_interactst: return 120;
	case DF_Type::adventure_movement_climbst: return 121;
	case DF_Type::adventure_movement_hold_itemst: return 122;
	case DF_Type::adventure_movement_hold_tilest: return 123;
	case DF_Type::adventure_movement_item_interact_guidest: return 124;
	case DF_Type::adventure_movement_item_interact_pushst: return 125;
	case DF_Type::adventure_movement_item_interact_ridest: return 126;
	case DF_Type::adventure_movement_item_interactst: return 127;
	case DF_Type::adventure_movement_movest: return 128;
	case DF_Type::adventure_movement_optionst: return 129;
	case DF_Type::adventure_movement_release_hold_itemst: return 130;
	case DF_Type::adventure_movement_release_hold_tilest: return 131;
	case DF_Type::adventure_option_eat_item_contaminantst: return 132;
	case DF_Type::adventure_option_eat_unit_contaminantst: return 133;
	case DF_Type::adventure_option_view_contaminantst: return 134;
	case DF_Type::adventure_optionst: return 135;
	case DF_Type::adventurer_attribute_level: return 136;
	case DF_Type::agreement: return 137;
	case DF_Type::agreement__T_anon_3: return 138;
	case DF_Type::agreement_details: return 139;
	case DF_Type::agreement_details__T_data: return 140;
	case DF_Type::agreement_details_data_citizenship: return 141;
	case DF_Type::agreement_details_data_demonic_binding: return 142;
	case DF_Type::agreement_details_data_join_party: return 143;
	case DF_Type::agreement_details_data_location: return 144;
	case DF_Type::agreement_details_data_parley: return 145;
	case DF_Type::agreement_details_data_plot_abduct: return 146;
	case DF_Type::agreement_details_data_plot_assassination: return 147;
	case DF_Type::agreement_details_data_plot_conviction: return 148;
	case DF_Type::agreement_details_data_plot_frame_treason: return 149;
	case DF_Type::agreement_details_data_plot_induce_war: return 150;
	case DF_Type::agreement_details_data_plot_infiltration_coup: return 151;
	case DF_Type::agreement_details_data_plot_steal_artifact: return 152;
	case DF_Type::agreement_details_data_position_corruption: return 153;
	case DF_Type::agreement_details_data_promise_position: return 154;
	case DF_Type::agreement_details_data_residency: return 155;
	case DF_Type::agreement_details_data_unk10: return 156;
	case DF_Type::agreement_details_type: return 157;
	case DF_Type::agreement_party: return 158;
	case DF_Type::agreement_party__T_anon_1: return 159;
	case DF_Type::ammo_flags: return 160;
	case DF_Type::animal_training_level: return 161;
	case DF_Type::announcement_flags: return 162;
	case DF_Type::announcement_type: return 163;
	case DF_Type::announcements: return 164;
	case DF_Type::appearance_modifier_growth_interval: return 165;
	case DF_Type::appearance_modifier_type: return 166;
	case DF_Type::armor_flags: return 167;
	case DF_Type::armor_general_flags: return 168;
	case DF_Type::armor_properties: return 169;
	case DF_Type::army: return 170;
	case DF_Type::army__T_members: return 171;
	case DF_Type::army__T_unk_2c: return 172;
	case DF_Type::army_controller: return 173;
	case DF_Type::army_controller__T_type: return 174;
	case DF_Type::army_controller__T_unk_64: return 175;
	case DF_Type::army_controller_sub1: return 176;
	case DF_Type::army_controller_sub11: return 177;
	case DF_Type::army_controller_sub11__T_anon_3: return 178;
	case DF_Type::army_controller_sub12: return 179;
	case DF_Type::army_controller_sub12__T_anon_4: return 180;
	case DF_Type::army_controller_sub13: return 181;
	case DF_Type::army_controller_sub13__T_anon_4: return 182;
	case DF_Type::army_controller_sub14: return 183;
	case DF_Type::army_controller_sub14__T_anon_4: return 184;
	case DF_Type::army_controller_sub15: return 185;
	case DF_Type::army_controller_sub15__T_anon_3: return 186;
	case DF_Type::army_controller_sub16: return 187;
	case DF_Type::army_controller_sub17: return 188;
	case DF_Type::army_controller_sub18: return 189;
	case DF_Type::army_controller_sub2: return 190;
	case DF_Type::army_controller_sub24: return 191;
	case DF_Type::army_controller_sub2__T_anon_5: return 192;
	case DF_Type::army_controller_sub4: return 193;
	case DF_Type::army_controller_sub4__T_unk_2: return 194;
	case DF_Type::army_controller_sub5: return 195;
	case DF_Type::army_controller_sub6: return 196;
	case DF_Type::army_controller_sub7: return 197;
	case DF_Type::army_controller_sub7__T_anon_3: return 198;
	case DF_Type::army_flags: return 199;
	case DF_Type::art_facet_type: return 200;
	case DF_Type::art_image: return 201;
	case DF_Type::art_image_chunk: return 202;
	case DF_Type::art_image_element: return 203;
	case DF_Type::art_image_element_creaturest: return 204;
	case DF_Type::art_image_element_itemst: return 205;
	case DF_Type::art_image_element_plantst: return 206;
	case DF_Type::art_image_element_shapest: return 207;
	case DF_Type::art_image_element_treest: return 208;
	case DF_Type::art_image_element_type: return 209;
	case DF_Type::art_image_property: return 210;
	case DF_Type::art_image_property_intransitive_verbst: return 211;
	case DF_Type::art_image_property_transitive_verbst: return 212;
	case DF_Type::art_image_property_type: return 213;
	case DF_Type::art_image_property_verb: return 214;
	case DF_Type::art_image_ref: return 215;
	case DF_Type::artifact_claim: return 216;
	case DF_Type::artifact_claim_type: return 217;
	case DF_Type::artifact_record: return 218;
	case DF_Type::assign_trade_status: return 219;
	case DF_Type::assign_trade_status__T_status: return 220;
	case DF_Type::assume_identity_mode: return 221;
	case DF_Type::barrack_preference_category: return 222;
	case DF_Type::belief_system: return 223;
	case DF_Type::biome_type: return 224;
	case DF_Type::block_burrow: return 225;
	case DF_Type::block_burrow_link: return 226;
	case DF_Type::block_flags: return 227;
	case DF_Type::block_square_event: return 228;
	case DF_Type::block_square_event_designation_priorityst: return 229;
	case DF_Type::block_square_event_frozen_liquidst: return 230;
	case DF_Type::block_square_event_grassst: return 231;
	case DF_Type::block_square_event_item_spatterst: return 232;
	case DF_Type::block_square_event_material_spatterst: return 233;
	case DF_Type::block_square_event_mineralst: return 234;
	case DF_Type::block_square_event_mineralst__T_flags: return 235;
	case DF_Type::block_square_event_spoorst: return 236;
	case DF_Type::block_square_event_type: return 237;
	case DF_Type::block_square_event_world_constructionst: return 238;
	case DF_Type::body_appearance_modifier: return 239;
	case DF_Type::body_component_info: return 240;
	case DF_Type::body_detail_plan: return 241;
	case DF_Type::body_layer_status: return 242;
	case DF_Type::body_part_layer_flags: return 243;
	case DF_Type::body_part_layer_raw: return 244;
	case DF_Type::body_part_raw: return 245;
	case DF_Type::body_part_raw_flags: return 246;
	case DF_Type::body_part_status: return 247;
	case DF_Type::body_part_template: return 248;
	case DF_Type::body_part_template_contype: return 249;
	case DF_Type::body_part_template_flags: return 250;
	case DF_Type::body_size_info: return 251;
	case DF_Type::body_template: return 252;
	case DF_Type::bp_appearance_modifier: return 253;
	case DF_Type::breath_attack_type: return 254;
	case DF_Type::build_req_choice_genst: return 255;
	case DF_Type::build_req_choice_specst: return 256;
	case DF_Type::build_req_choice_type: return 257;
	case DF_Type::build_req_choicest: return 258;
	case DF_Type::building: return 259;
	case DF_Type::building__T_activities: return 260;
	case DF_Type::building__T_job_claim_suppress: return 261;
	case DF_Type::building_actual: return 262;
	case DF_Type::building_actual__T_contained_items: return 263;
	case DF_Type::building_animaltrapst: return 264;
	case DF_Type::building_archerytargetst: return 265;
	case DF_Type::building_archerytargetst__T_archery_direction: return 266;
	case DF_Type::building_armorstandst: return 267;
	case DF_Type::building_axle_horizontalst: return 268;
	case DF_Type::building_axle_verticalst: return 269;
	case DF_Type::building_bars_floorst: return 270;
	case DF_Type::building_bars_verticalst: return 271;
	case DF_Type::building_bedst: return 272;
	case DF_Type::building_bedst__T_bed_flags: return 273;
	case DF_Type::building_bookcasest: return 274;
	case DF_Type::building_boxst: return 275;
	case DF_Type::building_bridgest: return 276;
	case DF_Type::building_bridgest__T_direction: return 277;
	case DF_Type::building_cabinetst: return 278;
	case DF_Type::building_cagest: return 279;
	case DF_Type::building_cagest__T_cage_flags: return 280;
	case DF_Type::building_chainst: return 281;
	case DF_Type::building_chainst__T_chain_flags: return 282;
	case DF_Type::building_chairst: return 283;
	case DF_Type::building_civzonest: return 284;
	case DF_Type::building_civzonest__T_gather_flags: return 285;
	case DF_Type::building_civzonest__T_pit_flags: return 286;
	case DF_Type::building_civzonest__T_zone_flags: return 287;
	case DF_Type::building_coffinst: return 288;
	case DF_Type::building_coffinst__T_burial_mode: return 289;
	case DF_Type::building_constructionst: return 290;
	case DF_Type::building_def: return 291;
	case DF_Type::building_def_furnacest: return 292;
	case DF_Type::building_def_item: return 293;
	case DF_Type::building_def_workshopst: return 294;
	case DF_Type::building_design: return 295;
	case DF_Type::building_design__T_flags: return 296;
	case DF_Type::building_display_furniturest: return 297;
	case DF_Type::building_doorst: return 298;
	case DF_Type::building_drawbuffer: return 299;
	case DF_Type::building_extents: return 300;
	case DF_Type::building_farmplotst: return 301;
	case DF_Type::building_flags: return 302;
	case DF_Type::building_floodgatest: return 303;
	case DF_Type::building_furnacest: return 304;
	case DF_Type::building_gear_assemblyst: return 305;
	case DF_Type::building_gear_assemblyst__T_gear_flags: return 306;
	case DF_Type::building_grate_floorst: return 307;
	case DF_Type::building_grate_wallst: return 308;
	case DF_Type::building_handler: return 309;
	case DF_Type::building_hatchst: return 310;
	case DF_Type::building_hivest: return 311;
	case DF_Type::building_instrumentst: return 312;
	case DF_Type::building_nest_boxst: return 313;
	case DF_Type::building_nestst: return 314;
	case DF_Type::building_offering_placest: return 315;
	case DF_Type::building_road_dirtst: return 316;
	case DF_Type::building_road_pavedst: return 317;
	case DF_Type::building_roadst: return 318;
	case DF_Type::building_rollersst: return 319;
	case DF_Type::building_screw_pumpst: return 320;
	case DF_Type::building_shopst: return 321;
	case DF_Type::building_shopst__T_shop_flags: return 322;
	case DF_Type::building_siegeenginest: return 323;
	case DF_Type::building_siegeenginest__T_action: return 324;
	case DF_Type::building_siegeenginest__T_facing: return 325;
	case DF_Type::building_slabst: return 326;
	case DF_Type::building_squad_use: return 327;
	case DF_Type::building_statuest: return 328;
	case DF_Type::building_stockpilest: return 329;
	case DF_Type::building_supportst: return 330;
	case DF_Type::building_supportst__T_support_flags: return 331;
	case DF_Type::building_tablest: return 332;
	case DF_Type::building_tablest__T_table_flags: return 333;
	case DF_Type::building_traction_benchst: return 334;
	case DF_Type::building_tradedepotst: return 335;
	case DF_Type::building_tradedepotst__T_trade_flags: return 336;
	case DF_Type::building_trapst: return 337;
	case DF_Type::building_trapst__T_stop_flags: return 338;
	case DF_Type::building_type: return 339;
	case DF_Type::building_users: return 340;
	case DF_Type::building_wagonst: return 341;
	case DF_Type::building_water_wheelst: return 342;
	case DF_Type::building_weaponrackst: return 343;
	case DF_Type::building_weaponst: return 344;
	case DF_Type::building_wellst: return 345;
	case DF_Type::building_wellst__T_well_flags: return 346;
	case DF_Type::building_windmillst: return 347;
	case DF_Type::building_window_gemst: return 348;
	case DF_Type::building_window_glassst: return 349;
	case DF_Type::building_windowst: return 350;
	case DF_Type::building_workshopst: return 351;
	case DF_Type::buildings_other_id: return 352;
	case DF_Type::builtin_mats: return 353;
	case DF_Type::burrow: return 354;
	case DF_Type::campfire: return 355;
	case DF_Type::caravan_state: return 356;
	case DF_Type::caravan_state__T_flags: return 357;
	case DF_Type::caravan_state__T_trade_state: return 358;
	case DF_Type::caste_attack: return 359;
	case DF_Type::caste_attack__T_flags: return 360;
	case DF_Type::caste_body_info: return 361;
	case DF_Type::caste_body_info__T_extra_butcher_objects: return 362;
	case DF_Type::caste_body_info__T_flags: return 363;
	case DF_Type::caste_body_info__T_interactions: return 364;
	case DF_Type::caste_body_info__T_interactions__T_type: return 365;
	case DF_Type::caste_clothing_item: return 366;
	case DF_Type::caste_raw: return 367;
	case DF_Type::caste_raw__T_anon_1: return 368;
	case DF_Type::caste_raw__T_attributes: return 369;
	case DF_Type::caste_raw__T_bp_appearance: return 370;
	case DF_Type::caste_raw__T_caste_profession_name: return 371;
	case DF_Type::caste_raw__T_extracts: return 372;
	case DF_Type::caste_raw__T_lair_hunter_speech: return 373;
	case DF_Type::caste_raw__T_misc: return 374;
	case DF_Type::caste_raw__T_personality: return 375;
	case DF_Type::caste_raw__T_secretion: return 376;
	case DF_Type::caste_raw__T_shearable_tissue_layer: return 377;
	case DF_Type::caste_raw__T_sound: return 378;
	case DF_Type::caste_raw__T_unk29: return 379;
	case DF_Type::caste_raw__T_unknown2: return 380;
	case DF_Type::caste_raw_flags: return 381;
	case DF_Type::cave_column: return 382;
	case DF_Type::cave_column_link: return 383;
	case DF_Type::cave_column_rectangle: return 384;
	case DF_Type::cie_add_tag_mask1: return 385;
	case DF_Type::cie_add_tag_mask2: return 386;
	case DF_Type::civzone_type: return 387;
	case DF_Type::coin_batch: return 388;
	case DF_Type::coin_batch__T_image_back: return 389;
	case DF_Type::coin_batch__T_image_front: return 390;
	case DF_Type::color_modifier_raw: return 391;
	case DF_Type::combat_report_event_type: return 392;
	case DF_Type::conflict_level: return 393;
	case DF_Type::construction: return 394;
	case DF_Type::construction_flags: return 395;
	case DF_Type::construction_type: return 396;
	case DF_Type::conversation: return 397;
	case DF_Type::conversation__T_speech: return 398;
	case DF_Type::conversation__T_state: return 399;
	case DF_Type::conversation_menu: return 400;
	case DF_Type::coord: return 401;
	case DF_Type::coord2d: return 402;
	case DF_Type::coord2d_path: return 403;
	case DF_Type::coord_path: return 404;
	case DF_Type::coord_rect: return 405;
	case DF_Type::corpse_material_type: return 406;
	case DF_Type::craft_material_class: return 407;
	case DF_Type::creation_zone_pwg_alteration_campst: return 408;
	case DF_Type::creation_zone_pwg_alteration_location_deathst: return 409;
	case DF_Type::creation_zone_pwg_alteration_location_deathst__T_unk_1: return 410;
	case DF_Type::creation_zone_pwg_alteration_location_deathst__T_unk_1__T_anon_1: return 411;
	case DF_Type::creation_zone_pwg_alteration_srb_ruinedst: return 412;
	case DF_Type::creation_zone_pwg_alteration_srp_ruinedst: return 413;
	case DF_Type::creation_zone_pwg_alteration_type: return 414;
	case DF_Type::creation_zone_pwg_alterationst: return 415;
	case DF_Type::creature_graphics_appointment: return 416;
	case DF_Type::creature_graphics_role: return 417;
	case DF_Type::creature_handler: return 418;
	case DF_Type::creature_interaction: return 419;
	case DF_Type::creature_interaction__T_flags: return 420;
	case DF_Type::creature_interaction_effect: return 421;
	case DF_Type::creature_interaction_effect__T_counter_trigger: return 422;
	case DF_Type::creature_interaction_effect_add_simple_flagst: return 423;
	case DF_Type::creature_interaction_effect_bleedingst: return 424;
	case DF_Type::creature_interaction_effect_blistersst: return 425;
	case DF_Type::creature_interaction_effect_body_appearance_modifierst: return 426;
	case DF_Type::creature_interaction_effect_body_mat_interactionst: return 427;
	case DF_Type::creature_interaction_effect_body_transformationst: return 428;
	case DF_Type::creature_interaction_effect_bp_appearance_modifierst: return 429;
	case DF_Type::creature_interaction_effect_bruisingst: return 430;
	case DF_Type::creature_interaction_effect_can_do_interactionst: return 431;
	case DF_Type::creature_interaction_effect_change_personalityst: return 432;
	case DF_Type::creature_interaction_effect_close_open_woundsst: return 433;
	case DF_Type::creature_interaction_effect_cough_bloodst: return 434;
	case DF_Type::creature_interaction_effect_cure_infectionsst: return 435;
	case DF_Type::creature_interaction_effect_cure_infectionst: return 436;
	case DF_Type::creature_interaction_effect_display_namest: return 437;
	case DF_Type::creature_interaction_effect_display_symbolst: return 438;
	case DF_Type::creature_interaction_effect_dizzinessst: return 439;
	case DF_Type::creature_interaction_effect_drowsinessst: return 440;
	case DF_Type::creature_interaction_effect_erratic_behaviorst: return 441;
	case DF_Type::creature_interaction_effect_feel_emotionst: return 442;
	case DF_Type::creature_interaction_effect_feverst: return 443;
	case DF_Type::creature_interaction_effect_flags: return 444;
	case DF_Type::creature_interaction_effect_flash_symbolst: return 445;
	case DF_Type::creature_interaction_effect_heal_nervesst: return 446;
	case DF_Type::creature_interaction_effect_heal_tissuesst: return 447;
	case DF_Type::creature_interaction_effect_impair_functionst: return 448;
	case DF_Type::creature_interaction_effect_material_force_adjustst: return 449;
	case DF_Type::creature_interaction_effect_ment_att_changest: return 450;
	case DF_Type::creature_interaction_effect_nauseast: return 451;
	case DF_Type::creature_interaction_effect_necrosisst: return 452;
	case DF_Type::creature_interaction_effect_numbnessst: return 453;
	case DF_Type::creature_interaction_effect_oozingst: return 454;
	case DF_Type::creature_interaction_effect_painst: return 455;
	case DF_Type::creature_interaction_effect_paralysisst: return 456;
	case DF_Type::creature_interaction_effect_phys_att_changest: return 457;
	case DF_Type::creature_interaction_effect_reduce_dizzinessst: return 458;
	case DF_Type::creature_interaction_effect_reduce_feverst: return 459;
	case DF_Type::creature_interaction_effect_reduce_nauseast: return 460;
	case DF_Type::creature_interaction_effect_reduce_painst: return 461;
	case DF_Type::creature_interaction_effect_reduce_paralysisst: return 462;
	case DF_Type::creature_interaction_effect_reduce_swellingst: return 463;
	case DF_Type::creature_interaction_effect_regrow_partsst: return 464;
	case DF_Type::creature_interaction_effect_remove_simple_flagst: return 465;
	case DF_Type::creature_interaction_effect_sense_creature_classst: return 466;
	case DF_Type::creature_interaction_effect_skill_roll_adjustst: return 467;
	case DF_Type::creature_interaction_effect_special_attack_interactionst: return 468;
	case DF_Type::creature_interaction_effect_speed_changest: return 469;
	case DF_Type::creature_interaction_effect_stop_bleedingst: return 470;
	case DF_Type::creature_interaction_effect_swellingst: return 471;
	case DF_Type::creature_interaction_effect_target: return 472;
	case DF_Type::creature_interaction_effect_target_mode: return 473;
	case DF_Type::creature_interaction_effect_type: return 474;
	case DF_Type::creature_interaction_effect_unconsciousnessst: return 475;
	case DF_Type::creature_interaction_effect_vomit_bloodst: return 476;
	case DF_Type::creature_interaction_target_flags: return 477;
	case DF_Type::creature_raw: return 478;
	case DF_Type::creature_raw__T_graphics: return 479;
	case DF_Type::creature_raw__T_hive_product: return 480;
	case DF_Type::creature_raw__T_profession_name: return 481;
	case DF_Type::creature_raw_flags: return 482;
	case DF_Type::creature_variation: return 483;
	case DF_Type::creature_variation_convert_tag: return 484;
	case DF_Type::crime: return 485;
	case DF_Type::crime__T_counterintelligence: return 486;
	case DF_Type::crime__T_flags: return 487;
	case DF_Type::crime__T_mode: return 488;
	case DF_Type::crime__T_punishment: return 489;
	case DF_Type::crime__T_reports: return 490;
	case DF_Type::crime_type: return 491;
	case DF_Type::cultural_identity: return 492;
	case DF_Type::cultural_identity__T_anon_1: return 493;
	case DF_Type::cultural_identity__T_anon_2: return 494;
	case DF_Type::cultural_identity__T_group_log: return 495;
	case DF_Type::cultural_identity__T_group_log__T_join_type: return 496;
	case DF_Type::cumulus_type: return 497;
	case DF_Type::curse_attr_change: return 498;
	case DF_Type::d_init: return 499;
	case DF_Type::d_init__T_store_dist: return 500;
	case DF_Type::d_init__T_wound_color: return 501;
	case DF_Type::d_init_embark_confirm: return 502;
	case DF_Type::d_init_flags1: return 503;
	case DF_Type::d_init_flags2: return 504;
	case DF_Type::d_init_flags3: return 505;
	case DF_Type::d_init_flags4: return 506;
	case DF_Type::d_init_idlers: return 507;
	case DF_Type::d_init_nickname: return 508;
	case DF_Type::d_init_tunnel: return 509;
	case DF_Type::d_init_z_view: return 510;
	case DF_Type::dance_form: return 511;
	case DF_Type::dance_form_sub1: return 512;
	case DF_Type::dance_form_sub2: return 513;
	case DF_Type::death_condition_type: return 514;
	case DF_Type::death_type: return 515;
	case DF_Type::deep_vein_hollow: return 516;
	case DF_Type::descriptor_color: return 517;
	case DF_Type::descriptor_pattern: return 518;
	case DF_Type::descriptor_shape: return 519;
	case DF_Type::descriptor_shape__T_gems_use: return 520;
	case DF_Type::dfhack_knowledge_scholar_flag: return 521;
	case DF_Type::dfhack_material_category: return 522;
	case DF_Type::dfhack_room_quality_level: return 523;
	case DF_Type::dipscript_info: return 524;
	case DF_Type::dipscript_popup: return 525;
	case DF_Type::dipscript_popup__T_flags: return 526;
	case DF_Type::divination_set: return 527;
	case DF_Type::divination_set_roll: return 528;
	case DF_Type::door_flags: return 529;
	case DF_Type::dye_info: return 530;
	case DF_Type::effect_info: return 531;
	case DF_Type::embark_feature: return 532;
	case DF_Type::embark_finder_option: return 533;
	case DF_Type::embark_item_choice: return 534;
	case DF_Type::embark_item_choice__T_list: return 535;
	case DF_Type::embark_location: return 536;
	case DF_Type::embark_note: return 537;
	case DF_Type::embark_profile: return 538;
	case DF_Type::emotion_type: return 539;
	case DF_Type::enabler: return 540;
	case DF_Type::enabler__T_async_frombox: return 541;
	case DF_Type::enabler__T_async_frombox__T_queue: return 542;
	case DF_Type::enabler__T_async_frombox__T_queue___union0: return 543;
	case DF_Type::enabler__T_async_frombox__T_queue___union0___struct1: return 544;
	case DF_Type::enabler__T_async_frombox__T_queue__T_msg: return 545;
	case DF_Type::enabler__T_async_tobox: return 546;
	case DF_Type::enabler__T_async_tobox__T_queue: return 547;
	case DF_Type::enabler__T_async_tobox__T_queue__T_cmd: return 548;
	case DF_Type::enabler__T_async_zoom: return 549;
	case DF_Type::enabler__T_flag: return 550;
	case DF_Type::enabler__T_gputicks: return 551;
	case DF_Type::enabler__T_overridden_grid_sizes: return 552;
	case DF_Type::enabler__T_simticks: return 553;
	case DF_Type::enabler__T_text_system: return 554;
	case DF_Type::enabler__T_text_system__T_file_info: return 555;
	case DF_Type::enabler__T_textures: return 556;
	case DF_Type::engraving: return 557;
	case DF_Type::engraving_flags: return 558;
	case DF_Type::entity_action_type: return 559;
	case DF_Type::entity_activity_statistics: return 560;
	case DF_Type::entity_activity_statistics__T_food: return 561;
	case DF_Type::entity_activity_statistics__T_found_misc: return 562;
	case DF_Type::entity_activity_statistics__T_wealth: return 563;
	case DF_Type::entity_animal_raw: return 564;
	case DF_Type::entity_animal_raw__T_flags: return 565;
	case DF_Type::entity_buy_prices: return 566;
	case DF_Type::entity_buy_requests: return 567;
	case DF_Type::entity_claim_mask: return 568;
	case DF_Type::entity_claim_mask__T_map: return 569;
	case DF_Type::entity_entity_link: return 570;
	case DF_Type::entity_entity_link_type: return 571;
	case DF_Type::entity_event: return 572;
	case DF_Type::entity_event__T_data: return 573;
	case DF_Type::entity_event__T_data__T_abandon: return 574;
	case DF_Type::entity_event__T_data__T_abduction: return 575;
	case DF_Type::entity_event__T_data__T_accept_peace_offer: return 576;
	case DF_Type::entity_event__T_data__T_accept_tribute_demand: return 577;
	case DF_Type::entity_event__T_data__T_accept_tribute_offer: return 578;
	case DF_Type::entity_event__T_data__T_artifact_destroyed: return 579;
	case DF_Type::entity_event__T_data__T_artifact_in_feature_layer: return 580;
	case DF_Type::entity_event__T_data__T_artifact_in_inventory: return 581;
	case DF_Type::entity_event__T_data__T_artifact_in_site: return 582;
	case DF_Type::entity_event__T_data__T_artifact_in_subregion: return 583;
	case DF_Type::entity_event__T_data__T_artifact_not_in_feature_layer: return 584;
	case DF_Type::entity_event__T_data__T_artifact_not_in_inventory: return 585;
	case DF_Type::entity_event__T_data__T_artifact_not_in_site: return 586;
	case DF_Type::entity_event__T_data__T_artifact_not_in_subregion: return 587;
	case DF_Type::entity_event__T_data__T_beast: return 588;
	case DF_Type::entity_event__T_data__T_cease_tribute_offer: return 589;
	case DF_Type::entity_event__T_data__T_claim: return 590;
	case DF_Type::entity_event__T_data__T_flee: return 591;
	case DF_Type::entity_event__T_data__T_founded: return 592;
	case DF_Type::entity_event__T_data__T_founding: return 593;
	case DF_Type::entity_event__T_data__T_group: return 594;
	case DF_Type::entity_event__T_data__T_harass: return 595;
	case DF_Type::entity_event__T_data__T_incident: return 596;
	case DF_Type::entity_event__T_data__T_insurrection: return 597;
	case DF_Type::entity_event__T_data__T_insurrection_end: return 598;
	case DF_Type::entity_event__T_data__T_insurrection_end__T_result: return 599;
	case DF_Type::entity_event__T_data__T_invasion: return 600;
	case DF_Type::entity_event__T_data__T_leave: return 601;
	case DF_Type::entity_event__T_data__T_occupation: return 602;
	case DF_Type::entity_event__T_data__T_reclaimed: return 603;
	case DF_Type::entity_event__T_data__T_reclaiming: return 604;
	case DF_Type::entity_event__T_data__T_refuse_peace_offer: return 605;
	case DF_Type::entity_event__T_data__T_refuse_tribute_demand: return 606;
	case DF_Type::entity_event__T_data__T_refuse_tribute_offer: return 607;
	case DF_Type::entity_event__T_data__T_succession: return 608;
	case DF_Type::entity_event_type: return 609;
	case DF_Type::entity_material_category: return 610;
	case DF_Type::entity_name_type: return 611;
	case DF_Type::entity_occasion: return 612;
	case DF_Type::entity_occasion_info: return 613;
	case DF_Type::entity_occasion_schedule: return 614;
	case DF_Type::entity_occasion_schedule_feature: return 615;
	case DF_Type::entity_population: return 616;
	case DF_Type::entity_population_unk4: return 617;
	case DF_Type::entity_population_unk4__T_anon_1: return 618;
	case DF_Type::entity_population_unk4__T_anon_2: return 619;
	case DF_Type::entity_population_unk4__T_anon_3: return 620;
	case DF_Type::entity_position: return 621;
	case DF_Type::entity_position_assignment: return 622;
	case DF_Type::entity_position_flags: return 623;
	case DF_Type::entity_position_raw: return 624;
	case DF_Type::entity_position_raw_flags: return 625;
	case DF_Type::entity_position_responsibility: return 626;
	case DF_Type::entity_raw: return 627;
	case DF_Type::entity_raw__T_equipment: return 628;
	case DF_Type::entity_raw__T_jobs: return 629;
	case DF_Type::entity_raw__T_land_holder_trigger: return 630;
	case DF_Type::entity_raw__T_progress_trigger: return 631;
	case DF_Type::entity_raw__T_scholar: return 632;
	case DF_Type::entity_raw__T_symbols: return 633;
	case DF_Type::entity_raw__T_tissue_styles: return 634;
	case DF_Type::entity_raw__T_workshops: return 635;
	case DF_Type::entity_raw_flags: return 636;
	case DF_Type::entity_recipe: return 637;
	case DF_Type::entity_sell_category: return 638;
	case DF_Type::entity_sell_prices: return 639;
	case DF_Type::entity_sell_requests: return 640;
	case DF_Type::entity_site_link: return 641;
	case DF_Type::entity_site_link__T_unk_7: return 642;
	case DF_Type::entity_site_link_flags: return 643;
	case DF_Type::entity_site_link_status_flags: return 644;
	case DF_Type::entity_site_link_type: return 645;
	case DF_Type::entity_tissue_style: return 646;
	case DF_Type::entity_uniform: return 647;
	case DF_Type::entity_uniform_item: return 648;
	case DF_Type::entity_unk_v47_1: return 649;
	case DF_Type::environment_type: return 650;
	case DF_Type::era_type: return 651;
	case DF_Type::ethic_response: return 652;
	case DF_Type::ethic_type: return 653;
	case DF_Type::export_map_type: return 654;
	case DF_Type::feature: return 655;
	case DF_Type::feature_alteration: return 656;
	case DF_Type::feature_alteration_new_lava_fill_zst: return 657;
	case DF_Type::feature_alteration_new_pop_maxst: return 658;
	case DF_Type::feature_alteration_type: return 659;
	case DF_Type::feature_cavest: return 660;
	case DF_Type::feature_deep_special_tubest: return 661;
	case DF_Type::feature_deep_surface_portalst: return 662;
	case DF_Type::feature_init: return 663;
	case DF_Type::feature_init_cavest: return 664;
	case DF_Type::feature_init_deep_special_tubest: return 665;
	case DF_Type::feature_init_deep_surface_portalst: return 666;
	case DF_Type::feature_init_flags: return 667;
	case DF_Type::feature_init_magma_core_from_layerst: return 668;
	case DF_Type::feature_init_magma_poolst: return 669;
	case DF_Type::feature_init_outdoor_riverst: return 670;
	case DF_Type::feature_init_pitst: return 671;
	case DF_Type::feature_init_subterranean_from_layerst: return 672;
	case DF_Type::feature_init_underworld_from_layerst: return 673;
	case DF_Type::feature_init_volcanost: return 674;
	case DF_Type::feature_magma_core_from_layerst: return 675;
	case DF_Type::feature_magma_poolst: return 676;
	case DF_Type::feature_outdoor_riverst: return 677;
	case DF_Type::feature_pitst: return 678;
	case DF_Type::feature_subterranean_from_layerst: return 679;
	case DF_Type::feature_type: return 680;
	case DF_Type::feature_underworld_from_layerst: return 681;
	case DF_Type::feature_volcanost: return 682;
	case DF_Type::file_compressorst: return 683;
	case DF_Type::fire: return 684;
	case DF_Type::flow_guide: return 685;
	case DF_Type::flow_guide_item_cloudst: return 686;
	case DF_Type::flow_guide_trailing_flowst: return 687;
	case DF_Type::flow_guide_type: return 688;
	case DF_Type::flow_info: return 689;
	case DF_Type::flow_reuse_pool: return 690;
	case DF_Type::flow_reuse_pool__T_flags: return 691;
	case DF_Type::flow_type: return 692;
	case DF_Type::fog_type: return 693;
	case DF_Type::fortress_type: return 694;
	case DF_Type::front_type: return 695;
	case DF_Type::furnace_type: return 696;
	case DF_Type::furniture_type: return 697;
	case DF_Type::gait_info: return 698;
	case DF_Type::gait_info__T_flags: return 699;
	case DF_Type::gait_type: return 700;
	case DF_Type::game_mode: return 701;
	case DF_Type::game_type: return 702;
	case DF_Type::gate_flags: return 703;
	case DF_Type::general_ref: return 704;
	case DF_Type::general_ref_abstract_buildingst: return 705;
	case DF_Type::general_ref_activity_eventst: return 706;
	case DF_Type::general_ref_artifact: return 707;
	case DF_Type::general_ref_building: return 708;
	case DF_Type::general_ref_building_cagedst: return 709;
	case DF_Type::general_ref_building_chainst: return 710;
	case DF_Type::general_ref_building_civzone_assignedst: return 711;
	case DF_Type::general_ref_building_destinationst: return 712;
	case DF_Type::general_ref_building_display_furniturest: return 713;
	case DF_Type::general_ref_building_holderst: return 714;
	case DF_Type::general_ref_building_nest_boxst: return 715;
	case DF_Type::general_ref_building_triggerst: return 716;
	case DF_Type::general_ref_building_triggertargetst: return 717;
	case DF_Type::general_ref_building_use_target_1st: return 718;
	case DF_Type::general_ref_building_use_target_2st: return 719;
	case DF_Type::general_ref_building_well_tag: return 720;
	case DF_Type::general_ref_coinbatch: return 721;
	case DF_Type::general_ref_contained_in_itemst: return 722;
	case DF_Type::general_ref_contains_itemst: return 723;
	case DF_Type::general_ref_contains_unitst: return 724;
	case DF_Type::general_ref_creaturest: return 725;
	case DF_Type::general_ref_creaturest__T_flags: return 726;
	case DF_Type::general_ref_dance_formst: return 727;
	case DF_Type::general_ref_entity: return 728;
	case DF_Type::general_ref_entity_art_image: return 729;
	case DF_Type::general_ref_entity_itemownerst: return 730;
	case DF_Type::general_ref_entity_offeredst: return 731;
	case DF_Type::general_ref_entity_popst: return 732;
	case DF_Type::general_ref_entity_popst__T_flags: return 733;
	case DF_Type::general_ref_entity_stolenst: return 734;
	case DF_Type::general_ref_feature_layerst: return 735;
	case DF_Type::general_ref_historical_eventst: return 736;
	case DF_Type::general_ref_historical_figurest: return 737;
	case DF_Type::general_ref_interactionst: return 738;
	case DF_Type::general_ref_is_artifactst: return 739;
	case DF_Type::general_ref_is_nemesisst: return 740;
	case DF_Type::general_ref_item: return 741;
	case DF_Type::general_ref_item_type: return 742;
	case DF_Type::general_ref_knowledge_scholar_flagst: return 743;
	case DF_Type::general_ref_languagest: return 744;
	case DF_Type::general_ref_locationst: return 745;
	case DF_Type::general_ref_mapsquare: return 746;
	case DF_Type::general_ref_musical_formst: return 747;
	case DF_Type::general_ref_nemesis: return 748;
	case DF_Type::general_ref_poetic_formst: return 749;
	case DF_Type::general_ref_projectile: return 750;
	case DF_Type::general_ref_sitest: return 751;
	case DF_Type::general_ref_spherest: return 752;
	case DF_Type::general_ref_subregionst: return 753;
	case DF_Type::general_ref_type: return 754;
	case DF_Type::general_ref_unit: return 755;
	case DF_Type::general_ref_unit_beateest: return 756;
	case DF_Type::general_ref_unit_cageest: return 757;
	case DF_Type::general_ref_unit_climberst: return 758;
	case DF_Type::general_ref_unit_foodreceiverst: return 759;
	case DF_Type::general_ref_unit_geldeest: return 760;
	case DF_Type::general_ref_unit_holderst: return 761;
	case DF_Type::general_ref_unit_infantst: return 762;
	case DF_Type::general_ref_unit_interrogateest: return 763;
	case DF_Type::general_ref_unit_itemownerst: return 764;
	case DF_Type::general_ref_unit_itemownerst__T_flags: return 765;
	case DF_Type::general_ref_unit_kidnapeest: return 766;
	case DF_Type::general_ref_unit_milkeest: return 767;
	case DF_Type::general_ref_unit_patientst: return 768;
	case DF_Type::general_ref_unit_reporteest: return 769;
	case DF_Type::general_ref_unit_riderst: return 770;
	case DF_Type::general_ref_unit_sheareest: return 771;
	case DF_Type::general_ref_unit_slaughtereest: return 772;
	case DF_Type::general_ref_unit_suckeest: return 773;
	case DF_Type::general_ref_unit_tradebringerst: return 774;
	case DF_Type::general_ref_unit_traineest: return 775;
	case DF_Type::general_ref_unit_workerst: return 776;
	case DF_Type::general_ref_value_levelst: return 777;
	case DF_Type::general_ref_written_contentst: return 778;
	case DF_Type::geo_layer_type: return 779;
	case DF_Type::ghost_goal: return 780;
	case DF_Type::ghost_type: return 781;
	case DF_Type::gloves_flags: return 782;
	case DF_Type::glowing_barrier: return 783;
	case DF_Type::goal_type: return 784;
	case DF_Type::graphic: return 785;
	case DF_Type::guild_id: return 786;
	case DF_Type::hauler_type: return 787;
	case DF_Type::hauling_route: return 788;
	case DF_Type::hauling_stop: return 789;
	case DF_Type::health_view_bits1: return 790;
	case DF_Type::health_view_bits2: return 791;
	case DF_Type::health_view_bits3: return 792;
	case DF_Type::helm_flags: return 793;
	case DF_Type::hillock_house_type: return 794;
	case DF_Type::histfig_body_state: return 795;
	case DF_Type::histfig_entity_link: return 796;
	case DF_Type::histfig_entity_link_criminalst: return 797;
	case DF_Type::histfig_entity_link_enemyst: return 798;
	case DF_Type::histfig_entity_link_former_memberst: return 799;
	case DF_Type::histfig_entity_link_former_mercenaryst: return 800;
	case DF_Type::histfig_entity_link_former_occupationst: return 801;
	case DF_Type::histfig_entity_link_former_positionst: return 802;
	case DF_Type::histfig_entity_link_former_prisonerst: return 803;
	case DF_Type::histfig_entity_link_former_slavest: return 804;
	case DF_Type::histfig_entity_link_former_squadst: return 805;
	case DF_Type::histfig_entity_link_memberst: return 806;
	case DF_Type::histfig_entity_link_mercenaryst: return 807;
	case DF_Type::histfig_entity_link_occupationst: return 808;
	case DF_Type::histfig_entity_link_position_claimst: return 809;
	case DF_Type::histfig_entity_link_positionst: return 810;
	case DF_Type::histfig_entity_link_prisonerst: return 811;
	case DF_Type::histfig_entity_link_slavest: return 812;
	case DF_Type::histfig_entity_link_squadst: return 813;
	case DF_Type::histfig_entity_link_type: return 814;
	case DF_Type::histfig_flags: return 815;
	case DF_Type::histfig_hf_link: return 816;
	case DF_Type::histfig_hf_link_apprenticest: return 817;
	case DF_Type::histfig_hf_link_childst: return 818;
	case DF_Type::histfig_hf_link_companionst: return 819;
	case DF_Type::histfig_hf_link_deceased_spousest: return 820;
	case DF_Type::histfig_hf_link_deityst: return 821;
	case DF_Type::histfig_hf_link_fatherst: return 822;
	case DF_Type::histfig_hf_link_former_apprenticest: return 823;
	case DF_Type::histfig_hf_link_former_masterst: return 824;
	case DF_Type::histfig_hf_link_former_spousest: return 825;
	case DF_Type::histfig_hf_link_imprisonerst: return 826;
	case DF_Type::histfig_hf_link_loverst: return 827;
	case DF_Type::histfig_hf_link_masterst: return 828;
	case DF_Type::histfig_hf_link_motherst: return 829;
	case DF_Type::histfig_hf_link_pet_ownerst: return 830;
	case DF_Type::histfig_hf_link_prisonerst: return 831;
	case DF_Type::histfig_hf_link_spousest: return 832;
	case DF_Type::histfig_hf_link_type: return 833;
	case DF_Type::histfig_relationship_type: return 834;
	case DF_Type::histfig_site_link: return 835;
	case DF_Type::histfig_site_link_hangoutst: return 836;
	case DF_Type::histfig_site_link_home_site_abstract_buildingst: return 837;
	case DF_Type::histfig_site_link_home_site_realization_buildingst: return 838;
	case DF_Type::histfig_site_link_home_site_realization_sulst: return 839;
	case DF_Type::histfig_site_link_home_site_saved_civzonest: return 840;
	case DF_Type::histfig_site_link_lairst: return 841;
	case DF_Type::histfig_site_link_occupationst: return 842;
	case DF_Type::histfig_site_link_prison_abstract_buildingst: return 843;
	case DF_Type::histfig_site_link_prison_site_building_profilest: return 844;
	case DF_Type::histfig_site_link_seat_of_powerst: return 845;
	case DF_Type::histfig_site_link_type: return 846;
	case DF_Type::historical_entity: return 847;
	case DF_Type::historical_entity__T_claims: return 848;
	case DF_Type::historical_entity__T_derived_resources: return 849;
	case DF_Type::historical_entity__T_flags: return 850;
	case DF_Type::historical_entity__T_guild_professions: return 851;
	case DF_Type::historical_entity__T_positions: return 852;
	case DF_Type::historical_entity__T_relations: return 853;
	case DF_Type::historical_entity__T_relations__T_constructions: return 854;
	case DF_Type::historical_entity__T_relations__T_diplomacy: return 855;
	case DF_Type::historical_entity__T_resources: return 856;
	case DF_Type::historical_entity__T_resources__T_animals: return 857;
	case DF_Type::historical_entity__T_resources__T_metal: return 858;
	case DF_Type::historical_entity__T_resources__T_misc_mat: return 859;
	case DF_Type::historical_entity__T_resources__T_organic: return 860;
	case DF_Type::historical_entity__T_resources__T_refuse: return 861;
	case DF_Type::historical_entity__T_resources__T_unk13: return 862;
	case DF_Type::historical_entity__T_resources__T_wood_products: return 863;
	case DF_Type::historical_entity__T_tissue_styles: return 864;
	case DF_Type::historical_entity__T_training_knowledge: return 865;
	case DF_Type::historical_entity__T_unk_v47_1: return 866;
	case DF_Type::historical_entity__T_unknown1d: return 867;
	case DF_Type::historical_entity__T_unknown1e: return 868;
	case DF_Type::historical_entity__T_unknown2: return 869;
	case DF_Type::historical_entity_type: return 870;
	case DF_Type::historical_figure: return 871;
	case DF_Type::historical_figure__T_unk_fc: return 872;
	case DF_Type::historical_figure__T_vague_relationships: return 873;
	case DF_Type::historical_figure_info: return 874;
	case DF_Type::historical_figure_info__T_books: return 875;
	case DF_Type::historical_figure_info__T_books__T_flags: return 876;
	case DF_Type::historical_figure_info__T_curse: return 877;
	case DF_Type::historical_figure_info__T_curse__T_anon_1: return 878;
	case DF_Type::historical_figure_info__T_curse__T_experiments: return 879;
	case DF_Type::historical_figure_info__T_known_info: return 880;
	case DF_Type::historical_figure_info__T_known_info__T_anon_1: return 881;
	case DF_Type::historical_figure_info__T_known_info__T_anon_6: return 882;
	case DF_Type::historical_figure_info__T_known_info__T_knowledge: return 883;
	case DF_Type::historical_figure_info__T_known_info__T_knowledge__T_knowledge_goal: return 884;
	case DF_Type::historical_figure_info__T_known_info__T_unk_a8: return 885;
	case DF_Type::historical_figure_info__T_masterpieces: return 886;
	case DF_Type::historical_figure_info__T_personality: return 887;
	case DF_Type::historical_figure_info__T_relationships: return 888;
	case DF_Type::historical_figure_info__T_relationships__T_anon_1: return 889;
	case DF_Type::historical_figure_info__T_relationships__T_artifact_claims: return 890;
	case DF_Type::historical_figure_info__T_relationships__T_hf_historical: return 891;
	case DF_Type::historical_figure_info__T_relationships__T_hf_visual: return 892;
	case DF_Type::historical_figure_info__T_relationships__T_intrigues: return 893;
	case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_intrigue: return 894;
	case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots: return 895;
	case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data: return 896;
	case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data__T_Infiltrate_Society: return 897;
	case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data__T_Sabotage_Actor: return 898;
	case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_type: return 899;
	case DF_Type::historical_figure_info__T_reputation: return 900;
	case DF_Type::historical_figure_info__T_reputation__T_anon_1: return 901;
	case DF_Type::historical_figure_info__T_reputation__T_unk_2c: return 902;
	case DF_Type::historical_figure_info__T_reputation__T_unk_2c__T_anon_12: return 903;
	case DF_Type::historical_figure_info__T_reputation__T_wanted: return 904;
	case DF_Type::historical_figure_info__T_reputation__T_wanted__T_unk: return 905;
	case DF_Type::historical_figure_info__T_skills: return 906;
	case DF_Type::historical_figure_info__T_skills__T_employment_held: return 907;
	case DF_Type::historical_figure_info__T_skills__T_employment_held__T_employment: return 908;
	case DF_Type::historical_figure_info__T_whereabouts: return 909;
	case DF_Type::historical_figure_info__T_wounds: return 910;
	case DF_Type::historical_kills: return 911;
	case DF_Type::historical_kills__T_killed_undead: return 912;
	case DF_Type::history_era: return 913;
	case DF_Type::history_era__T_details: return 914;
	case DF_Type::history_era__T_title: return 915;
	case DF_Type::history_event: return 916;
	case DF_Type::history_event_add_entity_site_profile_flagst: return 917;
	case DF_Type::history_event_add_hf_entity_honorst: return 918;
	case DF_Type::history_event_add_hf_entity_linkst: return 919;
	case DF_Type::history_event_add_hf_hf_linkst: return 920;
	case DF_Type::history_event_add_hf_site_linkst: return 921;
	case DF_Type::history_event_agreement_concludedst: return 922;
	case DF_Type::history_event_agreement_formedst: return 923;
	case DF_Type::history_event_agreements_voidedst: return 924;
	case DF_Type::history_event_artifact_claim_formedst: return 925;
	case DF_Type::history_event_artifact_copiedst: return 926;
	case DF_Type::history_event_artifact_copiedst__T_flags2: return 927;
	case DF_Type::history_event_artifact_createdst: return 928;
	case DF_Type::history_event_artifact_createdst__T_flags2: return 929;
	case DF_Type::history_event_artifact_destroyedst: return 930;
	case DF_Type::history_event_artifact_droppedst: return 931;
	case DF_Type::history_event_artifact_foundst: return 932;
	case DF_Type::history_event_artifact_givenst: return 933;
	case DF_Type::history_event_artifact_hiddenst: return 934;
	case DF_Type::history_event_artifact_lostst: return 935;
	case DF_Type::history_event_artifact_possessedst: return 936;
	case DF_Type::history_event_artifact_recoveredst: return 937;
	case DF_Type::history_event_artifact_storedst: return 938;
	case DF_Type::history_event_artifact_transformedst: return 939;
	case DF_Type::history_event_assume_identityst: return 940;
	case DF_Type::history_event_body_abusedst: return 941;
	case DF_Type::history_event_body_abusedst__T_abuse_data: return 942;
	case DF_Type::history_event_body_abusedst__T_abuse_data__T_Animated: return 943;
	case DF_Type::history_event_body_abusedst__T_abuse_data__T_Flayed: return 944;
	case DF_Type::history_event_body_abusedst__T_abuse_data__T_Hung: return 945;
	case DF_Type::history_event_body_abusedst__T_abuse_data__T_Impaled: return 946;
	case DF_Type::history_event_body_abusedst__T_abuse_data__T_Piled: return 947;
	case DF_Type::history_event_body_abusedst__T_abuse_data__T_Piled__T_pile_type: return 948;
	case DF_Type::history_event_body_abusedst__T_abuse_type: return 949;
	case DF_Type::history_event_building_profile_acquiredst: return 950;
	case DF_Type::history_event_ceremonyst: return 951;
	case DF_Type::history_event_change_creature_typest: return 952;
	case DF_Type::history_event_change_hf_body_statest: return 953;
	case DF_Type::history_event_change_hf_jobst: return 954;
	case DF_Type::history_event_change_hf_moodst: return 955;
	case DF_Type::history_event_change_hf_statest: return 956;
	case DF_Type::history_event_change_hf_statest__T_state: return 957;
	case DF_Type::history_event_circumstance_info: return 958;
	case DF_Type::history_event_circumstance_info__T_data: return 959;
	case DF_Type::history_event_collection: return 960;
	case DF_Type::history_event_collection_abductionst: return 961;
	case DF_Type::history_event_collection_battlest: return 962;
	case DF_Type::history_event_collection_beast_attackst: return 963;
	case DF_Type::history_event_collection_ceremonyst: return 964;
	case DF_Type::history_event_collection_competitionst: return 965;
	case DF_Type::history_event_collection_duelst: return 966;
	case DF_Type::history_event_collection_entity_overthrownst: return 967;
	case DF_Type::history_event_collection_insurrectionst: return 968;
	case DF_Type::history_event_collection_journeyst: return 969;
	case DF_Type::history_event_collection_occasionst: return 970;
	case DF_Type::history_event_collection_performancest: return 971;
	case DF_Type::history_event_collection_persecutionst: return 972;
	case DF_Type::history_event_collection_processionst: return 973;
	case DF_Type::history_event_collection_purgest: return 974;
	case DF_Type::history_event_collection_raidst: return 975;
	case DF_Type::history_event_collection_site_conqueredst: return 976;
	case DF_Type::history_event_collection_theftst: return 977;
	case DF_Type::history_event_collection_type: return 978;
	case DF_Type::history_event_collection_warst: return 979;
	case DF_Type::history_event_collection_warst__T_unk: return 980;
	case DF_Type::history_event_competitionst: return 981;
	case DF_Type::history_event_context: return 982;
	case DF_Type::history_event_context__T_unk_10: return 983;
	case DF_Type::history_event_create_entity_positionst: return 984;
	case DF_Type::history_event_created_buildingst: return 985;
	case DF_Type::history_event_created_sitest: return 986;
	case DF_Type::history_event_created_world_constructionst: return 987;
	case DF_Type::history_event_creature_devouredst: return 988;
	case DF_Type::history_event_dance_form_createdst: return 989;
	case DF_Type::history_event_diplomat_lostst: return 990;
	case DF_Type::history_event_entity_actionst: return 991;
	case DF_Type::history_event_entity_alliance_formedst: return 992;
	case DF_Type::history_event_entity_breach_feature_layerst: return 993;
	case DF_Type::history_event_entity_createdst: return 994;
	case DF_Type::history_event_entity_dissolvedst: return 995;
	case DF_Type::history_event_entity_equipment_purchasest: return 996;
	case DF_Type::history_event_entity_expels_hfst: return 997;
	case DF_Type::history_event_entity_fled_sitest: return 998;
	case DF_Type::history_event_entity_incorporatedst: return 999;
	case DF_Type::history_event_entity_lawst: return 1000;
	case DF_Type::history_event_entity_lawst__T_add_flags: return 1001;
	case DF_Type::history_event_entity_lawst__T_remove_flags: return 1002;
	case DF_Type::history_event_entity_overthrownst: return 1003;
	case DF_Type::history_event_entity_persecutedst: return 1004;
	case DF_Type::history_event_entity_rampaged_in_sitest: return 1005;
	case DF_Type::history_event_entity_razed_buildingst: return 1006;
	case DF_Type::history_event_entity_searched_sitest: return 1007;
	case DF_Type::history_event_failed_frame_attemptst: return 1008;
	case DF_Type::history_event_failed_intrigue_corruptionst: return 1009;
	case DF_Type::history_event_first_contact_failedst: return 1010;
	case DF_Type::history_event_first_contactst: return 1011;
	case DF_Type::history_event_flags: return 1012;
	case DF_Type::history_event_gamblest: return 1013;
	case DF_Type::history_event_hf_act_on_artifactst: return 1014;
	case DF_Type::history_event_hf_act_on_artifactst__T_action: return 1015;
	case DF_Type::history_event_hf_act_on_buildingst: return 1016;
	case DF_Type::history_event_hf_act_on_buildingst__T_action: return 1017;
	case DF_Type::history_event_hf_attacked_sitest: return 1018;
	case DF_Type::history_event_hf_confrontedst: return 1019;
	case DF_Type::history_event_hf_convictedst: return 1020;
	case DF_Type::history_event_hf_convictedst__T_plot_flags: return 1021;
	case DF_Type::history_event_hf_convictedst__T_punishment_flags: return 1022;
	case DF_Type::history_event_hf_destroyed_sitest: return 1023;
	case DF_Type::history_event_hf_does_interactionst: return 1024;
	case DF_Type::history_event_hf_enslavedst: return 1025;
	case DF_Type::history_event_hf_freedst: return 1026;
	case DF_Type::history_event_hf_gains_secret_goalst: return 1027;
	case DF_Type::history_event_hf_interrogatedst: return 1028;
	case DF_Type::history_event_hf_interrogatedst__T_interrogation_flags: return 1029;
	case DF_Type::history_event_hf_learns_secretst: return 1030;
	case DF_Type::history_event_hf_preachst: return 1031;
	case DF_Type::history_event_hf_ransomedst: return 1032;
	case DF_Type::history_event_hf_razed_buildingst: return 1033;
	case DF_Type::history_event_hf_recruited_unit_type_for_entityst: return 1034;
	case DF_Type::history_event_hf_relationship_deniedst: return 1035;
	case DF_Type::history_event_hfs_formed_intrigue_relationshipst: return 1036;
	case DF_Type::history_event_hfs_formed_reputation_relationshipst: return 1037;
	case DF_Type::history_event_hist_figure_abductedst: return 1038;
	case DF_Type::history_event_hist_figure_diedst: return 1039;
	case DF_Type::history_event_hist_figure_new_petst: return 1040;
	case DF_Type::history_event_hist_figure_reach_summitst: return 1041;
	case DF_Type::history_event_hist_figure_reunionst: return 1042;
	case DF_Type::history_event_hist_figure_revivedst: return 1043;
	case DF_Type::history_event_hist_figure_revivedst__T_flags2: return 1044;
	case DF_Type::history_event_hist_figure_simple_actionst: return 1045;
	case DF_Type::history_event_hist_figure_simple_battle_eventst: return 1046;
	case DF_Type::history_event_hist_figure_travelst: return 1047;
	case DF_Type::history_event_hist_figure_travelst__T_reason: return 1048;
	case DF_Type::history_event_hist_figure_woundedst: return 1049;
	case DF_Type::history_event_hist_figure_woundedst__T_flags2: return 1050;
	case DF_Type::history_event_hist_figure_woundedst__T_injury_type: return 1051;
	case DF_Type::history_event_insurrection_endedst: return 1052;
	case DF_Type::history_event_insurrection_startedst: return 1053;
	case DF_Type::history_event_item_stolenst: return 1054;
	case DF_Type::history_event_knowledge_discoveredst: return 1055;
	case DF_Type::history_event_masterpiece_created_arch_constructst: return 1056;
	case DF_Type::history_event_masterpiece_created_arch_designst: return 1057;
	case DF_Type::history_event_masterpiece_created_dye_itemst: return 1058;
	case DF_Type::history_event_masterpiece_created_engravingst: return 1059;
	case DF_Type::history_event_masterpiece_created_foodst: return 1060;
	case DF_Type::history_event_masterpiece_created_item_improvementst: return 1061;
	case DF_Type::history_event_masterpiece_created_itemst: return 1062;
	case DF_Type::history_event_masterpiece_createdst: return 1063;
	case DF_Type::history_event_masterpiece_lostst: return 1064;
	case DF_Type::history_event_merchantst: return 1065;
	case DF_Type::history_event_modified_buildingst: return 1066;
	case DF_Type::history_event_modified_buildingst__T_modification: return 1067;
	case DF_Type::history_event_musical_form_createdst: return 1068;
	case DF_Type::history_event_performancest: return 1069;
	case DF_Type::history_event_poetic_form_createdst: return 1070;
	case DF_Type::history_event_processionst: return 1071;
	case DF_Type::history_event_reason: return 1072;
	case DF_Type::history_event_reason_info: return 1073;
	case DF_Type::history_event_reason_info__T_data: return 1074;
	case DF_Type::history_event_reclaim_sitest: return 1075;
	case DF_Type::history_event_reclaim_sitest__T_flags2: return 1076;
	case DF_Type::history_event_regionpop_incorporated_into_entityst: return 1077;
	case DF_Type::history_event_remove_hf_entity_linkst: return 1078;
	case DF_Type::history_event_remove_hf_hf_linkst: return 1079;
	case DF_Type::history_event_remove_hf_site_linkst: return 1080;
	case DF_Type::history_event_replaced_buildingst: return 1081;
	case DF_Type::history_event_sabotagest: return 1082;
	case DF_Type::history_event_simple_battle_subtype: return 1083;
	case DF_Type::history_event_site_diedst: return 1084;
	case DF_Type::history_event_site_diedst__T_flags2: return 1085;
	case DF_Type::history_event_site_disputest: return 1086;
	case DF_Type::history_event_site_retiredst: return 1087;
	case DF_Type::history_event_site_retiredst__T_flags2: return 1088;
	case DF_Type::history_event_site_surrenderedst: return 1089;
	case DF_Type::history_event_sneak_into_sitest: return 1090;
	case DF_Type::history_event_spotted_leaving_sitest: return 1091;
	case DF_Type::history_event_squad_vs_squadst: return 1092;
	case DF_Type::history_event_tactical_situationst: return 1093;
	case DF_Type::history_event_tactical_situationst__T_tactics_flags: return 1094;
	case DF_Type::history_event_topicagreement_concludedst: return 1095;
	case DF_Type::history_event_topicagreement_madest: return 1096;
	case DF_Type::history_event_topicagreement_rejectedst: return 1097;
	case DF_Type::history_event_tradest: return 1098;
	case DF_Type::history_event_type: return 1099;
	case DF_Type::history_event_war_attacked_sitest: return 1100;
	case DF_Type::history_event_war_destroyed_sitest: return 1101;
	case DF_Type::history_event_war_field_battlest: return 1102;
	case DF_Type::history_event_war_peace_acceptedst: return 1103;
	case DF_Type::history_event_war_peace_rejectedst: return 1104;
	case DF_Type::history_event_war_plundered_sitest: return 1105;
	case DF_Type::history_event_war_site_new_leaderst: return 1106;
	case DF_Type::history_event_war_site_taken_overst: return 1107;
	case DF_Type::history_event_war_site_tribute_forcedst: return 1108;
	case DF_Type::history_event_war_site_tribute_forcedst__T_tribute_flags: return 1109;
	case DF_Type::history_event_written_content_composedst: return 1110;
	case DF_Type::history_hit_item: return 1111;
	case DF_Type::hive_flags: return 1112;
	case DF_Type::honors_type: return 1113;
	case DF_Type::honors_type__T_flags: return 1114;
	case DF_Type::honors_type__T_required_skill_type: return 1115;
	case DF_Type::hospital_supplies: return 1116;
	case DF_Type::hospital_supplies__T_supplies_needed: return 1117;
	case DF_Type::identity: return 1118;
	case DF_Type::identity_unk_94: return 1119;
	case DF_Type::improvement_type: return 1120;
	case DF_Type::incident: return 1121;
	case DF_Type::incident__T_data: return 1122;
	case DF_Type::incident__T_flags: return 1123;
	case DF_Type::incident__T_type: return 1124;
	case DF_Type::incident_hfid: return 1125;
	case DF_Type::incident_sub10: return 1126;
	case DF_Type::incident_sub6_performance: return 1127;
	case DF_Type::incident_sub6_performance__T_participants: return 1128;
	case DF_Type::incident_sub7: return 1129;
	case DF_Type::incident_sub8: return 1130;
	case DF_Type::incident_sub9: return 1131;
	case DF_Type::inclusion_type: return 1132;
	case DF_Type::init: return 1133;
	case DF_Type::init_display: return 1134;
	case DF_Type::init_display__T_windowed: return 1135;
	case DF_Type::init_display_flags: return 1136;
	case DF_Type::init_font: return 1137;
	case DF_Type::init_font__T_use_ttf: return 1138;
	case DF_Type::init_input: return 1139;
	case DF_Type::init_input_flags: return 1140;
	case DF_Type::init_media: return 1141;
	case DF_Type::init_media_flags: return 1142;
	case DF_Type::init_window: return 1143;
	case DF_Type::init_window_flags: return 1144;
	case DF_Type::inorganic_flags: return 1145;
	case DF_Type::inorganic_raw: return 1146;
	case DF_Type::inorganic_raw__T_environment: return 1147;
	case DF_Type::inorganic_raw__T_environment_spec: return 1148;
	case DF_Type::inorganic_raw__T_metal_ore: return 1149;
	case DF_Type::inorganic_raw__T_thread_metal: return 1150;
	case DF_Type::instrument_flags: return 1151;
	case DF_Type::instrument_piece: return 1152;
	case DF_Type::instrument_piece__T_flags: return 1153;
	case DF_Type::instrument_register: return 1154;
	case DF_Type::insurrection_outcome: return 1155;
	case DF_Type::interaction: return 1156;
	case DF_Type::interaction_effect: return 1157;
	case DF_Type::interaction_effect__T_flags: return 1158;
	case DF_Type::interaction_effect_add_syndromest: return 1159;
	case DF_Type::interaction_effect_animatest: return 1160;
	case DF_Type::interaction_effect_change_item_qualityst: return 1161;
	case DF_Type::interaction_effect_change_weatherst: return 1162;
	case DF_Type::interaction_effect_cleanst: return 1163;
	case DF_Type::interaction_effect_contactst: return 1164;
	case DF_Type::interaction_effect_create_itemst: return 1165;
	case DF_Type::interaction_effect_hidest: return 1166;
	case DF_Type::interaction_effect_location_hint: return 1167;
	case DF_Type::interaction_effect_material_emissionst: return 1168;
	case DF_Type::interaction_effect_propel_unitst: return 1169;
	case DF_Type::interaction_effect_resurrectst: return 1170;
	case DF_Type::interaction_effect_summon_unitst: return 1171;
	case DF_Type::interaction_effect_type: return 1172;
	case DF_Type::interaction_flags: return 1173;
	case DF_Type::interaction_instance: return 1174;
	case DF_Type::interaction_source: return 1175;
	case DF_Type::interaction_source_attackst: return 1176;
	case DF_Type::interaction_source_creature_actionst: return 1177;
	case DF_Type::interaction_source_deityst: return 1178;
	case DF_Type::interaction_source_disturbancest: return 1179;
	case DF_Type::interaction_source_experimentst: return 1180;
	case DF_Type::interaction_source_ingestionst: return 1181;
	case DF_Type::interaction_source_regionst: return 1182;
	case DF_Type::interaction_source_regionst__T_region_flags: return 1183;
	case DF_Type::interaction_source_secretst: return 1184;
	case DF_Type::interaction_source_secretst__T_learn_flags: return 1185;
	case DF_Type::interaction_source_type: return 1186;
	case DF_Type::interaction_source_underground_specialst: return 1187;
	case DF_Type::interaction_source_usage_hint: return 1188;
	case DF_Type::interaction_target: return 1189;
	case DF_Type::interaction_target_corpsest: return 1190;
	case DF_Type::interaction_target_creaturest: return 1191;
	case DF_Type::interaction_target_info: return 1192;
	case DF_Type::interaction_target_info__T_restrictions: return 1193;
	case DF_Type::interaction_target_location_type: return 1194;
	case DF_Type::interaction_target_locationst: return 1195;
	case DF_Type::interaction_target_materialst: return 1196;
	case DF_Type::interaction_target_materialst__T_restrictions: return 1197;
	case DF_Type::interaction_target_type: return 1198;
	case DF_Type::interface_breakdown_types: return 1199;
	case DF_Type::interface_button: return 1200;
	case DF_Type::interface_button_building_category_selectorst: return 1201;
	case DF_Type::interface_button_building_custom_category_selectorst: return 1202;
	case DF_Type::interface_button_building_material_selectorst: return 1203;
	case DF_Type::interface_button_building_new_jobst: return 1204;
	case DF_Type::interface_button_buildingst: return 1205;
	case DF_Type::interface_button_construction_building_selectorst: return 1206;
	case DF_Type::interface_button_construction_category_selectorst: return 1207;
	case DF_Type::interface_button_construction_category_selectorst__T_category_id: return 1208;
	case DF_Type::interface_button_construction_donest: return 1209;
	case DF_Type::interface_button_constructionst: return 1210;
	case DF_Type::interface_key: return 1211;
	case DF_Type::interfacest: return 1212;
	case DF_Type::invasion_info: return 1213;
	case DF_Type::invasion_info__T_flags: return 1214;
	case DF_Type::item: return 1215;
	case DF_Type::item_actual: return 1216;
	case DF_Type::item_ammost: return 1217;
	case DF_Type::item_amuletst: return 1218;
	case DF_Type::item_animaltrapst: return 1219;
	case DF_Type::item_anvilst: return 1220;
	case DF_Type::item_armorst: return 1221;
	case DF_Type::item_armorstandst: return 1222;
	case DF_Type::item_backpackst: return 1223;
	case DF_Type::item_ballistaarrowheadst: return 1224;
	case DF_Type::item_ballistapartsst: return 1225;
	case DF_Type::item_barrelst: return 1226;
	case DF_Type::item_barst: return 1227;
	case DF_Type::item_bedst: return 1228;
	case DF_Type::item_binst: return 1229;
	case DF_Type::item_blocksst: return 1230;
	case DF_Type::item_body_component: return 1231;
	case DF_Type::item_body_component__T_appearance: return 1232;
	case DF_Type::item_body_component__T_body: return 1233;
	case DF_Type::item_body_component__T_bone1: return 1234;
	case DF_Type::item_body_component__T_bone2: return 1235;
	case DF_Type::item_body_component__T_corpse_flags: return 1236;
	case DF_Type::item_bookst: return 1237;
	case DF_Type::item_boulderst: return 1238;
	case DF_Type::item_boxst: return 1239;
	case DF_Type::item_braceletst: return 1240;
	case DF_Type::item_branchst: return 1241;
	case DF_Type::item_bucketst: return 1242;
	case DF_Type::item_cabinetst: return 1243;
	case DF_Type::item_cagest: return 1244;
	case DF_Type::item_catapultpartsst: return 1245;
	case DF_Type::item_chainst: return 1246;
	case DF_Type::item_chairst: return 1247;
	case DF_Type::item_cheesest: return 1248;
	case DF_Type::item_clothst: return 1249;
	case DF_Type::item_coffinst: return 1250;
	case DF_Type::item_coinst: return 1251;
	case DF_Type::item_constructed: return 1252;
	case DF_Type::item_corpsepiecest: return 1253;
	case DF_Type::item_corpsest: return 1254;
	case DF_Type::item_crafted: return 1255;
	case DF_Type::item_critter: return 1256;
	case DF_Type::item_crownst: return 1257;
	case DF_Type::item_crutchst: return 1258;
	case DF_Type::item_doorst: return 1259;
	case DF_Type::item_drinkst: return 1260;
	case DF_Type::item_earringst: return 1261;
	case DF_Type::item_eggst: return 1262;
	case DF_Type::item_eggst__T_egg_flags: return 1263;
	case DF_Type::item_figurinest: return 1264;
	case DF_Type::item_filter_spec: return 1265;
	case DF_Type::item_fish_rawst: return 1266;
	case DF_Type::item_fishst: return 1267;
	case DF_Type::item_flags: return 1268;
	case DF_Type::item_flags2: return 1269;
	case DF_Type::item_flaskst: return 1270;
	case DF_Type::item_floodgatest: return 1271;
	case DF_Type::item_foodst: return 1272;
	case DF_Type::item_foodst__T_ingredients: return 1273;
	case DF_Type::item_gemst: return 1274;
	case DF_Type::item_globst: return 1275;
	case DF_Type::item_glovesst: return 1276;
	case DF_Type::item_gobletst: return 1277;
	case DF_Type::item_gratest: return 1278;
	case DF_Type::item_hatch_coverst: return 1279;
	case DF_Type::item_helmst: return 1280;
	case DF_Type::item_history_info: return 1281;
	case DF_Type::item_instrumentst: return 1282;
	case DF_Type::item_kill_info: return 1283;
	case DF_Type::item_liquid: return 1284;
	case DF_Type::item_liquid_miscst: return 1285;
	case DF_Type::item_liquipowder: return 1286;
	case DF_Type::item_magicness: return 1287;
	case DF_Type::item_magicness_type: return 1288;
	case DF_Type::item_matstate: return 1289;
	case DF_Type::item_meatst: return 1290;
	case DF_Type::item_millstonest: return 1291;
	case DF_Type::item_orthopedic_castst: return 1292;
	case DF_Type::item_pantsst: return 1293;
	case DF_Type::item_petst: return 1294;
	case DF_Type::item_petst__T_pet_flags: return 1295;
	case DF_Type::item_pipe_sectionst: return 1296;
	case DF_Type::item_plant_growthst: return 1297;
	case DF_Type::item_plantst: return 1298;
	case DF_Type::item_powder: return 1299;
	case DF_Type::item_powder_miscst: return 1300;
	case DF_Type::item_quality: return 1301;
	case DF_Type::item_quernst: return 1302;
	case DF_Type::item_quiverst: return 1303;
	case DF_Type::item_remainsst: return 1304;
	case DF_Type::item_ringst: return 1305;
	case DF_Type::item_rockst: return 1306;
	case DF_Type::item_roughst: return 1307;
	case DF_Type::item_scepterst: return 1308;
	case DF_Type::item_seedsst: return 1309;
	case DF_Type::item_sheetst: return 1310;
	case DF_Type::item_shieldst: return 1311;
	case DF_Type::item_shoesst: return 1312;
	case DF_Type::item_siegeammost: return 1313;
	case DF_Type::item_skin_tannedst: return 1314;
	case DF_Type::item_slabst: return 1315;
	case DF_Type::item_smallgemst: return 1316;
	case DF_Type::item_splintst: return 1317;
	case DF_Type::item_statuest: return 1318;
	case DF_Type::item_stockpile_ref: return 1319;
	case DF_Type::item_tablest: return 1320;
	case DF_Type::item_threadst: return 1321;
	case DF_Type::item_toolst: return 1322;
	case DF_Type::item_totemst: return 1323;
	case DF_Type::item_toyst: return 1324;
	case DF_Type::item_traction_benchst: return 1325;
	case DF_Type::item_trapcompst: return 1326;
	case DF_Type::item_trappartsst: return 1327;
	case DF_Type::item_type: return 1328;
	case DF_Type::item_verminst: return 1329;
	case DF_Type::item_weaponrackst: return 1330;
	case DF_Type::item_weaponst: return 1331;
	case DF_Type::item_windowst: return 1332;
	case DF_Type::item_woodst: return 1333;
	case DF_Type::itemdef: return 1334;
	case DF_Type::itemdef_ammost: return 1335;
	case DF_Type::itemdef_armorst: return 1336;
	case DF_Type::itemdef_foodst: return 1337;
	case DF_Type::itemdef_glovesst: return 1338;
	case DF_Type::itemdef_helmst: return 1339;
	case DF_Type::itemdef_instrumentst: return 1340;
	case DF_Type::itemdef_pantsst: return 1341;
	case DF_Type::itemdef_shieldst: return 1342;
	case DF_Type::itemdef_shoesst: return 1343;
	case DF_Type::itemdef_siegeammost: return 1344;
	case DF_Type::itemdef_toolst: return 1345;
	case DF_Type::itemdef_toolst__T_default_improvements: return 1346;
	case DF_Type::itemdef_toyst: return 1347;
	case DF_Type::itemdef_trapcompst: return 1348;
	case DF_Type::itemdef_weaponst: return 1349;
	case DF_Type::itemimprovement: return 1350;
	case DF_Type::itemimprovement_art_imagest: return 1351;
	case DF_Type::itemimprovement_bandsst: return 1352;
	case DF_Type::itemimprovement_clothst: return 1353;
	case DF_Type::itemimprovement_coveredst: return 1354;
	case DF_Type::itemimprovement_coveredst__T_cover_flags: return 1355;
	case DF_Type::itemimprovement_illustrationst: return 1356;
	case DF_Type::itemimprovement_instrument_piecest: return 1357;
	case DF_Type::itemimprovement_itemspecificst: return 1358;
	case DF_Type::itemimprovement_pagesst: return 1359;
	case DF_Type::itemimprovement_rings_hangingst: return 1360;
	case DF_Type::itemimprovement_sewn_imagest: return 1361;
	case DF_Type::itemimprovement_sewn_imagest__T_cloth: return 1362;
	case DF_Type::itemimprovement_specific_type: return 1363;
	case DF_Type::itemimprovement_spikesst: return 1364;
	case DF_Type::itemimprovement_threadst: return 1365;
	case DF_Type::itemimprovement_writingst: return 1366;
	case DF_Type::items_other_id: return 1367;
	case DF_Type::job: return 1368;
	case DF_Type::job_art_specification: return 1369;
	case DF_Type::job_art_specification__T_type: return 1370;
	case DF_Type::job_flags: return 1371;
	case DF_Type::job_handler: return 1372;
	case DF_Type::job_handler__T_anon_1: return 1373;
	case DF_Type::job_handler__T_postings: return 1374;
	case DF_Type::job_handler__T_postings__T_flags: return 1375;
	case DF_Type::job_item: return 1376;
	case DF_Type::job_item_filter: return 1377;
	case DF_Type::job_item_flags1: return 1378;
	case DF_Type::job_item_flags2: return 1379;
	case DF_Type::job_item_flags3: return 1380;
	case DF_Type::job_item_ref: return 1381;
	case DF_Type::job_item_ref__T_role: return 1382;
	case DF_Type::job_item_vector_id: return 1383;
	case DF_Type::job_list_link: return 1384;
	case DF_Type::job_material_category: return 1385;
	case DF_Type::job_skill: return 1386;
	case DF_Type::job_skill_class: return 1387;
	case DF_Type::job_subtype_surgery: return 1388;
	case DF_Type::job_type: return 1389;
	case DF_Type::job_type_class: return 1390;
	case DF_Type::KeybindingScreen: return 1391;
	case DF_Type::KeybindingScreen__T_mode: return 1392;
	case DF_Type::kitchen_exc_type: return 1393;
	case DF_Type::kitchen_pref_flag: return 1394;
	case DF_Type::knowledge_scholar_category_flag: return 1395;
	case DF_Type::knowledge_scholar_category_flag__T_flag_data: return 1396;
	case DF_Type::knowledge_scholar_category_flag__T_flag_type: return 1397;
	case DF_Type::knowledge_scholar_flags_0: return 1398;
	case DF_Type::knowledge_scholar_flags_1: return 1399;
	case DF_Type::knowledge_scholar_flags_10: return 1400;
	case DF_Type::knowledge_scholar_flags_11: return 1401;
	case DF_Type::knowledge_scholar_flags_12: return 1402;
	case DF_Type::knowledge_scholar_flags_13: return 1403;
	case DF_Type::knowledge_scholar_flags_2: return 1404;
	case DF_Type::knowledge_scholar_flags_3: return 1405;
	case DF_Type::knowledge_scholar_flags_4: return 1406;
	case DF_Type::knowledge_scholar_flags_5: return 1407;
	case DF_Type::knowledge_scholar_flags_6: return 1408;
	case DF_Type::knowledge_scholar_flags_7: return 1409;
	case DF_Type::knowledge_scholar_flags_8: return 1410;
	case DF_Type::knowledge_scholar_flags_9: return 1411;
	case DF_Type::lair_type: return 1412;
	case DF_Type::language_name: return 1413;
	case DF_Type::language_name_category: return 1414;
	case DF_Type::language_symbol: return 1415;
	case DF_Type::language_translation: return 1416;
	case DF_Type::language_word: return 1417;
	case DF_Type::language_word_flags: return 1418;
	case DF_Type::language_word_table: return 1419;
	case DF_Type::large_integer: return 1420;
	case DF_Type::large_integer___struct0: return 1421;
	case DF_Type::large_integer__T_u: return 1422;
	case DF_Type::layer_object: return 1423;
	case DF_Type::layer_object_buttonst: return 1424;
	case DF_Type::layer_object_listst: return 1425;
	case DF_Type::layer_type: return 1426;
	case DF_Type::lever_target_type: return 1427;
	case DF_Type::loadgame_save_info: return 1428;
	case DF_Type::local_population: return 1429;
	case DF_Type::local_population___union3: return 1430;
	case DF_Type::local_population__T_flags: return 1431;
	case DF_Type::location_scribe_jobs: return 1432;
	case DF_Type::machine: return 1433;
	case DF_Type::machine__T_components: return 1434;
	case DF_Type::machine__T_flags: return 1435;
	case DF_Type::machine_conn_modes: return 1436;
	case DF_Type::machine_handler: return 1437;
	case DF_Type::machine_info: return 1438;
	case DF_Type::machine_info__T_flags: return 1439;
	case DF_Type::machine_standardst: return 1440;
	case DF_Type::machine_tile_set: return 1441;
	case DF_Type::machine_type: return 1442;
	case DF_Type::MacroScreenLoad: return 1443;
	case DF_Type::MacroScreenSave: return 1444;
	case DF_Type::manager_order: return 1445;
	case DF_Type::manager_order__T_frequency: return 1446;
	case DF_Type::manager_order_condition_item: return 1447;
	case DF_Type::manager_order_condition_item__T_compare_type: return 1448;
	case DF_Type::manager_order_condition_order: return 1449;
	case DF_Type::manager_order_condition_order__T_condition: return 1450;
	case DF_Type::manager_order_status: return 1451;
	case DF_Type::manager_order_template: return 1452;
	case DF_Type::mandate: return 1453;
	case DF_Type::mandate__T_mode: return 1454;
	case DF_Type::mandate__T_punishment: return 1455;
	case DF_Type::map_block: return 1456;
	case DF_Type::map_block_column: return 1457;
	case DF_Type::map_block_column__T_unmined_glyphs: return 1458;
	case DF_Type::map_renderer: return 1459;
	case DF_Type::map_renderer__T_anon_4: return 1460;
	case DF_Type::map_viewport: return 1461;
	case DF_Type::masterpiece_loss_type: return 1462;
	case DF_Type::material: return 1463;
	case DF_Type::material_common: return 1464;
	case DF_Type::material_common__T_hardens_with_water: return 1465;
	case DF_Type::material_common__T_heat: return 1466;
	case DF_Type::material_common__T_reaction_product: return 1467;
	case DF_Type::material_common__T_strength: return 1468;
	case DF_Type::material_flags: return 1469;
	case DF_Type::material_template: return 1470;
	case DF_Type::material_vec_ref: return 1471;
	case DF_Type::matgloss_list: return 1472;
	case DF_Type::matgloss_list__T_unk_0: return 1473;
	case DF_Type::matter_state: return 1474;
	case DF_Type::meeting_context: return 1475;
	case DF_Type::meeting_diplomat_info: return 1476;
	case DF_Type::meeting_diplomat_info__T_flags: return 1477;
	case DF_Type::meeting_event: return 1478;
	case DF_Type::meeting_event_type: return 1479;
	case DF_Type::meeting_topic: return 1480;
	case DF_Type::meeting_variable: return 1481;
	case DF_Type::mental_attribute_type: return 1482;
	case DF_Type::mental_picture: return 1483;
	case DF_Type::mental_picture__T_unk: return 1484;
	case DF_Type::mental_picture_element_hfst: return 1485;
	case DF_Type::mental_picture_element_regionst: return 1486;
	case DF_Type::mental_picture_element_sitest: return 1487;
	case DF_Type::mental_picture_element_type: return 1488;
	case DF_Type::mental_picture_elementst: return 1489;
	case DF_Type::mental_picture_property_actionst: return 1490;
	case DF_Type::mental_picture_property_adjectivest: return 1491;
	case DF_Type::mental_picture_property_color_patternst: return 1492;
	case DF_Type::mental_picture_property_datest: return 1493;
	case DF_Type::mental_picture_property_emotionst: return 1494;
	case DF_Type::mental_picture_property_positionst: return 1495;
	case DF_Type::mental_picture_property_shapest: return 1496;
	case DF_Type::mental_picture_property_timest: return 1497;
	case DF_Type::mental_picture_property_toolst: return 1498;
	case DF_Type::mental_picture_property_type: return 1499;
	case DF_Type::mental_picture_propertyst: return 1500;
	case DF_Type::misc_trait_type: return 1501;
	case DF_Type::mission: return 1502;
	case DF_Type::mission__T_details: return 1503;
	case DF_Type::mission__T_details__T_raid: return 1504;
	case DF_Type::mission__T_details__T_raid__T_raid_flags: return 1505;
	case DF_Type::mission__T_details__T_raid__T_raid_type: return 1506;
	case DF_Type::mission__T_details__T_recovery: return 1507;
	case DF_Type::mission__T_details__T_request: return 1508;
	case DF_Type::mission__T_details__T_rescue: return 1509;
	case DF_Type::mission__T_type: return 1510;
	case DF_Type::mission_campaign_report: return 1511;
	case DF_Type::mission_report: return 1512;
	case DF_Type::monument_type: return 1513;
	case DF_Type::mood_type: return 1514;
	case DF_Type::mountain_peak_flags: return 1515;
	case DF_Type::moving_party: return 1516;
	case DF_Type::moving_party__T_members: return 1517;
	case DF_Type::musical_form: return 1518;
	case DF_Type::musical_form__T_flags: return 1519;
	case DF_Type::musical_form_feature: return 1520;
	case DF_Type::musical_form_instruments: return 1521;
	case DF_Type::musical_form_instruments__T_substitutions: return 1522;
	case DF_Type::musical_form_interval: return 1523;
	case DF_Type::musical_form_interval__T_flags: return 1524;
	case DF_Type::musical_form_melodies: return 1525;
	case DF_Type::musical_form_pitch_style: return 1526;
	case DF_Type::musical_form_purpose: return 1527;
	case DF_Type::musical_form_style: return 1528;
	case DF_Type::musical_form_sub4: return 1529;
	case DF_Type::musical_form_vocals: return 1530;
	case DF_Type::need_type: return 1531;
	case DF_Type::nemesis_flags: return 1532;
	case DF_Type::nemesis_offload: return 1533;
	case DF_Type::nemesis_record: return 1534;
	case DF_Type::next_global_id: return 1535;
	case DF_Type::occasion_schedule_feature: return 1536;
	case DF_Type::occasion_schedule_type: return 1537;
	case DF_Type::occupation: return 1538;
	case DF_Type::occupation_sub1: return 1539;
	case DF_Type::occupation_type: return 1540;
	case DF_Type::ocean_wave: return 1541;
	case DF_Type::organic_mat_category: return 1542;
	case DF_Type::orientation_flags: return 1543;
	case DF_Type::pants_flags: return 1544;
	case DF_Type::part_of_speech: return 1545;
	case DF_Type::party_info: return 1546;
	case DF_Type::pattern_type: return 1547;
	case DF_Type::performance_event_type: return 1548;
	case DF_Type::performance_participant_type: return 1549;
	case DF_Type::performance_play_orderst: return 1550;
	case DF_Type::performance_play_orderst__T_anon_4: return 1551;
	case DF_Type::personality_facet_type: return 1552;
	case DF_Type::physical_attribute_type: return 1553;
	case DF_Type::pitch_choice_type: return 1554;
	case DF_Type::plant: return 1555;
	case DF_Type::plant__T_damage_flags: return 1556;
	case DF_Type::plant_flags: return 1557;
	case DF_Type::plant_growth: return 1558;
	case DF_Type::plant_growth__T_behavior: return 1559;
	case DF_Type::plant_growth__T_locations: return 1560;
	case DF_Type::plant_growth_print: return 1561;
	case DF_Type::plant_raw: return 1562;
	case DF_Type::plant_raw__T_colors: return 1563;
	case DF_Type::plant_raw__T_material_defs: return 1564;
	case DF_Type::plant_raw__T_stockpile_growth_flags: return 1565;
	case DF_Type::plant_raw__T_tiles: return 1566;
	case DF_Type::plant_raw_flags: return 1567;
	case DF_Type::plant_tree_info: return 1568;
	case DF_Type::plant_tree_tile: return 1569;
	case DF_Type::plot_agreement: return 1570;
	case DF_Type::plot_role_type: return 1571;
	case DF_Type::plot_strategy_type: return 1572;
	case DF_Type::poetic_form: return 1573;
	case DF_Type::poetic_form__T_flags: return 1574;
	case DF_Type::poetic_form_action: return 1575;
	case DF_Type::poetic_form_additional_feature: return 1576;
	case DF_Type::poetic_form_caesura_position: return 1577;
	case DF_Type::poetic_form_feature: return 1578;
	case DF_Type::poetic_form_mood: return 1579;
	case DF_Type::poetic_form_part: return 1580;
	case DF_Type::poetic_form_part__T_flags: return 1581;
	case DF_Type::poetic_form_pattern: return 1582;
	case DF_Type::poetic_form_perspective: return 1583;
	case DF_Type::poetic_form_perspective__T_type: return 1584;
	case DF_Type::poetic_form_subject: return 1585;
	case DF_Type::poetic_form_subject_target: return 1586;
	case DF_Type::poetic_form_subject_target__T_Concept: return 1587;
	case DF_Type::poetic_form_subject_target__T_Histfig: return 1588;
	case DF_Type::popup_message: return 1589;
	case DF_Type::power_info: return 1590;
	case DF_Type::pressure_plate_info: return 1591;
	case DF_Type::pressure_plate_info__T_flags: return 1592;
	case DF_Type::profession: return 1593;
	case DF_Type::proj_itemst: return 1594;
	case DF_Type::proj_list_link: return 1595;
	case DF_Type::proj_magicst: return 1596;
	case DF_Type::proj_unitst: return 1597;
	case DF_Type::projectile: return 1598;
	case DF_Type::projectile_flags: return 1599;
	case DF_Type::projectile_type: return 1600;
	case DF_Type::property_ownership: return 1601;
	case DF_Type::punishment: return 1602;
	case DF_Type::reaction: return 1603;
	case DF_Type::reaction__T_building: return 1604;
	case DF_Type::reaction_category: return 1605;
	case DF_Type::reaction_description: return 1606;
	case DF_Type::reaction_flags: return 1607;
	case DF_Type::reaction_product: return 1608;
	case DF_Type::reaction_product_improvement_flags: return 1609;
	case DF_Type::reaction_product_item_flags: return 1610;
	case DF_Type::reaction_product_item_improvementst: return 1611;
	case DF_Type::reaction_product_item_improvementst__T_get_material: return 1612;
	case DF_Type::reaction_product_itemst: return 1613;
	case DF_Type::reaction_product_itemst__T_get_material: return 1614;
	case DF_Type::reaction_product_type: return 1615;
	case DF_Type::reaction_reagent: return 1616;
	case DF_Type::reaction_reagent_flags: return 1617;
	case DF_Type::reaction_reagent_itemst: return 1618;
	case DF_Type::reaction_reagent_type: return 1619;
	case DF_Type::region_block_event_sphere_fieldst: return 1620;
	case DF_Type::region_block_event_type: return 1621;
	case DF_Type::region_block_eventst: return 1622;
	case DF_Type::region_map_entry: return 1623;
	case DF_Type::region_map_entry__T_clouds: return 1624;
	case DF_Type::region_map_entry__T_wind: return 1625;
	case DF_Type::region_map_entry_flags: return 1626;
	case DF_Type::relationship_event: return 1627;
	case DF_Type::relationship_event_supplement: return 1628;
	case DF_Type::renderer: return 1629;
	case DF_Type::report: return 1630;
	case DF_Type::report__T_flags: return 1631;
	case DF_Type::reputation_type: return 1632;
	case DF_Type::resource_allotment_data: return 1633;
	case DF_Type::resource_allotment_data__T_unk_654: return 1634;
	case DF_Type::resource_allotment_specifier: return 1635;
	case DF_Type::resource_allotment_specifier_ammost: return 1636;
	case DF_Type::resource_allotment_specifier_anvilst: return 1637;
	case DF_Type::resource_allotment_specifier_armor_bodyst: return 1638;
	case DF_Type::resource_allotment_specifier_armor_bootsst: return 1639;
	case DF_Type::resource_allotment_specifier_armor_glovesst: return 1640;
	case DF_Type::resource_allotment_specifier_armor_helmst: return 1641;
	case DF_Type::resource_allotment_specifier_armor_pantsst: return 1642;
	case DF_Type::resource_allotment_specifier_backpackst: return 1643;
	case DF_Type::resource_allotment_specifier_bagst: return 1644;
	case DF_Type::resource_allotment_specifier_bedst: return 1645;
	case DF_Type::resource_allotment_specifier_bonest: return 1646;
	case DF_Type::resource_allotment_specifier_boxst: return 1647;
	case DF_Type::resource_allotment_specifier_cabinetst: return 1648;
	case DF_Type::resource_allotment_specifier_chairst: return 1649;
	case DF_Type::resource_allotment_specifier_cheesest: return 1650;
	case DF_Type::resource_allotment_specifier_clothing_bodyst: return 1651;
	case DF_Type::resource_allotment_specifier_clothing_bootsst: return 1652;
	case DF_Type::resource_allotment_specifier_clothing_glovesst: return 1653;
	case DF_Type::resource_allotment_specifier_clothing_helmst: return 1654;
	case DF_Type::resource_allotment_specifier_clothing_pantsst: return 1655;
	case DF_Type::resource_allotment_specifier_clothst: return 1656;
	case DF_Type::resource_allotment_specifier_craftsst: return 1657;
	case DF_Type::resource_allotment_specifier_cropst: return 1658;
	case DF_Type::resource_allotment_specifier_extractst: return 1659;
	case DF_Type::resource_allotment_specifier_flaskst: return 1660;
	case DF_Type::resource_allotment_specifier_gemsst: return 1661;
	case DF_Type::resource_allotment_specifier_hornst: return 1662;
	case DF_Type::resource_allotment_specifier_leatherst: return 1663;
	case DF_Type::resource_allotment_specifier_meatst: return 1664;
	case DF_Type::resource_allotment_specifier_metalst: return 1665;
	case DF_Type::resource_allotment_specifier_pearlst: return 1666;
	case DF_Type::resource_allotment_specifier_powderst: return 1667;
	case DF_Type::resource_allotment_specifier_quiverst: return 1668;
	case DF_Type::resource_allotment_specifier_shellst: return 1669;
	case DF_Type::resource_allotment_specifier_skinst: return 1670;
	case DF_Type::resource_allotment_specifier_soapst: return 1671;
	case DF_Type::resource_allotment_specifier_stonest: return 1672;
	case DF_Type::resource_allotment_specifier_tablest: return 1673;
	case DF_Type::resource_allotment_specifier_tallowst: return 1674;
	case DF_Type::resource_allotment_specifier_threadst: return 1675;
	case DF_Type::resource_allotment_specifier_toothst: return 1676;
	case DF_Type::resource_allotment_specifier_type: return 1677;
	case DF_Type::resource_allotment_specifier_weapon_meleest: return 1678;
	case DF_Type::resource_allotment_specifier_weapon_rangedst: return 1679;
	case DF_Type::resource_allotment_specifier_woodst: return 1680;
	case DF_Type::rhythm: return 1681;
	case DF_Type::rhythm_sub1: return 1682;
	case DF_Type::rhythm_sub1__T_anon_1: return 1683;
	case DF_Type::rhythm_sub2: return 1684;
	case DF_Type::room_rent_info: return 1685;
	case DF_Type::room_rent_info__T_flags: return 1686;
	case DF_Type::route_stockpile_link: return 1687;
	case DF_Type::route_stockpile_link__T_mode: return 1688;
	case DF_Type::scale: return 1689;
	case DF_Type::scale__T_unk1: return 1690;
	case DF_Type::scale_sub1: return 1691;
	case DF_Type::scale_sub2: return 1692;
	case DF_Type::schedule_info: return 1693;
	case DF_Type::schedule_slot: return 1694;
	case DF_Type::screw_pump_direction: return 1695;
	case DF_Type::scribejob: return 1696;
	case DF_Type::script_step_conditionalst: return 1697;
	case DF_Type::script_step_conditionalst__T_condition: return 1698;
	case DF_Type::script_step_constructtopiclistst: return 1699;
	case DF_Type::script_step_dipeventst: return 1700;
	case DF_Type::script_step_diphistoryst: return 1701;
	case DF_Type::script_step_discussst: return 1702;
	case DF_Type::script_step_eventst: return 1703;
	case DF_Type::script_step_invasionst: return 1704;
	case DF_Type::script_step_setvarst: return 1705;
	case DF_Type::script_step_simpleactionst: return 1706;
	case DF_Type::script_step_textviewerst: return 1707;
	case DF_Type::script_step_topicdiscussionst: return 1708;
	case DF_Type::script_stepst: return 1709;
	case DF_Type::script_var_longst: return 1710;
	case DF_Type::script_var_unitst: return 1711;
	case DF_Type::script_varst: return 1712;
	case DF_Type::setup_character_info: return 1713;
	case DF_Type::setup_character_info__T_available_embark_items: return 1714;
	case DF_Type::setup_character_info__T_page: return 1715;
	case DF_Type::setup_character_info__T_sel_trait_column: return 1716;
	case DF_Type::setup_character_info__T_status: return 1717;
	case DF_Type::shoes_flags: return 1718;
	case DF_Type::shop_type: return 1719;
	case DF_Type::siegeengine_type: return 1720;
	case DF_Type::site_building_item: return 1721;
	case DF_Type::site_dispute_type: return 1722;
	case DF_Type::site_realization_building: return 1723;
	case DF_Type::site_realization_building__T_unk_4c: return 1724;
	case DF_Type::site_realization_building_info_castle_courtyardst: return 1725;
	case DF_Type::site_realization_building_info_castle_towerst: return 1726;
	case DF_Type::site_realization_building_info_castle_wallst: return 1727;
	case DF_Type::site_realization_building_info_hillock_housest: return 1728;
	case DF_Type::site_realization_building_info_market_squarest: return 1729;
	case DF_Type::site_realization_building_info_shop_housest: return 1730;
	case DF_Type::site_realization_building_info_tree_housest: return 1731;
	case DF_Type::site_realization_building_info_trenchesst: return 1732;
	case DF_Type::site_realization_building_info_trenchesst__T_spokes: return 1733;
	case DF_Type::site_realization_building_infost: return 1734;
	case DF_Type::site_realization_building_type: return 1735;
	case DF_Type::site_realization_crossroads: return 1736;
	case DF_Type::site_reputation_info: return 1737;
	case DF_Type::site_reputation_report: return 1738;
	case DF_Type::site_shop_type: return 1739;
	case DF_Type::site_type: return 1740;
	case DF_Type::skill_rating: return 1741;
	case DF_Type::slab_engraving_type: return 1742;
	case DF_Type::sound_production_type: return 1743;
	case DF_Type::spatter: return 1744;
	case DF_Type::spatter__T_flags: return 1745;
	case DF_Type::spatter_common: return 1746;
	case DF_Type::spatter_common__T_base_flags: return 1747;
	case DF_Type::special_mat_table: return 1748;
	case DF_Type::specific_ref: return 1749;
	case DF_Type::specific_ref__T_data: return 1750;
	case DF_Type::specific_ref__T_data__T_UNIT_ITEM_WRESTLE: return 1751;
	case DF_Type::specific_ref_type: return 1752;
	case DF_Type::sphere_type: return 1753;
	case DF_Type::spoils_report: return 1754;
	case DF_Type::squad: return 1755;
	case DF_Type::squad__T_rooms: return 1756;
	case DF_Type::squad_ammo_spec: return 1757;
	case DF_Type::squad_ammo_spec__T_flags: return 1758;
	case DF_Type::squad_event_type: return 1759;
	case DF_Type::squad_order: return 1760;
	case DF_Type::squad_order_cannot_reason: return 1761;
	case DF_Type::squad_order_cause_trouble_for_entityst: return 1762;
	case DF_Type::squad_order_defend_burrowsst: return 1763;
	case DF_Type::squad_order_drive_armies_from_sitest: return 1764;
	case DF_Type::squad_order_drive_entity_off_sitest: return 1765;
	case DF_Type::squad_order_kill_hfst: return 1766;
	case DF_Type::squad_order_kill_listst: return 1767;
	case DF_Type::squad_order_movest: return 1768;
	case DF_Type::squad_order_patrol_routest: return 1769;
	case DF_Type::squad_order_raid_sitest: return 1770;
	case DF_Type::squad_order_rescue_hfst: return 1771;
	case DF_Type::squad_order_retrieve_artifactst: return 1772;
	case DF_Type::squad_order_trainst: return 1773;
	case DF_Type::squad_order_type: return 1774;
	case DF_Type::squad_position: return 1775;
	case DF_Type::squad_schedule_entry: return 1776;
	case DF_Type::squad_schedule_order: return 1777;
	case DF_Type::squad_uniform_spec: return 1778;
	case DF_Type::squad_use_flags: return 1779;
	case DF_Type::stockpile_category: return 1780;
	case DF_Type::stockpile_group_set: return 1781;
	case DF_Type::stockpile_links: return 1782;
	case DF_Type::stockpile_list: return 1783;
	case DF_Type::stockpile_settings: return 1784;
	case DF_Type::stockpile_settings__T_ammo: return 1785;
	case DF_Type::stockpile_settings__T_animals: return 1786;
	case DF_Type::stockpile_settings__T_armor: return 1787;
	case DF_Type::stockpile_settings__T_bars_blocks: return 1788;
	case DF_Type::stockpile_settings__T_cloth: return 1789;
	case DF_Type::stockpile_settings__T_coins: return 1790;
	case DF_Type::stockpile_settings__T_finished_goods: return 1791;
	case DF_Type::stockpile_settings__T_food: return 1792;
	case DF_Type::stockpile_settings__T_furniture: return 1793;
	case DF_Type::stockpile_settings__T_gems: return 1794;
	case DF_Type::stockpile_settings__T_leather: return 1795;
	case DF_Type::stockpile_settings__T_ore: return 1796;
	case DF_Type::stockpile_settings__T_refuse: return 1797;
	case DF_Type::stockpile_settings__T_sheet: return 1798;
	case DF_Type::stockpile_settings__T_stone: return 1799;
	case DF_Type::stockpile_settings__T_weapons: return 1800;
	case DF_Type::stockpile_settings__T_wood: return 1801;
	case DF_Type::stop_depart_condition: return 1802;
	case DF_Type::stop_depart_condition__T_direction: return 1803;
	case DF_Type::stop_depart_condition__T_flags: return 1804;
	case DF_Type::stop_depart_condition__T_mode: return 1805;
	case DF_Type::strain_type: return 1806;
	case DF_Type::stratus_type: return 1807;
	case DF_Type::syndrome: return 1808;
	case DF_Type::syndrome_flags: return 1809;
	case DF_Type::T_cursor: return 1810;
	case DF_Type::T_selection_rect: return 1811;
	case DF_Type::tactical_situation: return 1812;
	case DF_Type::talk_choice: return 1813;
	case DF_Type::talk_choice__T_unk: return 1814;
	case DF_Type::talk_choice_type: return 1815;
	case DF_Type::temperaturest: return 1816;
	case DF_Type::temple_deity_data: return 1817;
	case DF_Type::temple_deity_type: return 1818;
	case DF_Type::text_info_element_longst: return 1819;
	case DF_Type::text_info_element_stringst: return 1820;
	case DF_Type::text_info_elementst: return 1821;
	case DF_Type::texture_handler: return 1822;
	case DF_Type::tile_bitmask: return 1823;
	case DF_Type::tile_building_occ: return 1824;
	case DF_Type::tile_designation: return 1825;
	case DF_Type::tile_dig_designation: return 1826;
	case DF_Type::tile_liquid: return 1827;
	case DF_Type::tile_liquid_flow: return 1828;
	case DF_Type::tile_liquid_flow_dir: return 1829;
	case DF_Type::tile_occupancy: return 1830;
	case DF_Type::tile_page: return 1831;
	case DF_Type::tile_traffic: return 1832;
	case DF_Type::tiletype: return 1833;
	case DF_Type::tiletype_material: return 1834;
	case DF_Type::tiletype_shape: return 1835;
	case DF_Type::tiletype_shape_basic: return 1836;
	case DF_Type::tiletype_special: return 1837;
	case DF_Type::tiletype_variant: return 1838;
	case DF_Type::timbre_type: return 1839;
	case DF_Type::timed_event: return 1840;
	case DF_Type::timed_event_type: return 1841;
	case DF_Type::tissue: return 1842;
	case DF_Type::tissue_flags: return 1843;
	case DF_Type::tissue_style_raw: return 1844;
	case DF_Type::tissue_style_type: return 1845;
	case DF_Type::tissue_template: return 1846;
	case DF_Type::tool_flags: return 1847;
	case DF_Type::tool_uses: return 1848;
	case DF_Type::tower_shape: return 1849;
	case DF_Type::toy_flags: return 1850;
	case DF_Type::training_assignment: return 1851;
	case DF_Type::training_assignment__T_flags: return 1852;
	case DF_Type::training_knowledge_level: return 1853;
	case DF_Type::trap_type: return 1854;
	case DF_Type::trapcomp_flags: return 1855;
	case DF_Type::tree_house_type: return 1856;
	case DF_Type::tuning_type: return 1857;
	case DF_Type::ui: return 1858;
	case DF_Type::ui__T_alerts: return 1859;
	case DF_Type::ui__T_alerts__T_list: return 1860;
	case DF_Type::ui__T_becoming_capital: return 1861;
	case DF_Type::ui__T_burrows: return 1862;
	case DF_Type::ui__T_economy_prices: return 1863;
	case DF_Type::ui__T_economy_prices__T_price_adjustment: return 1864;
	case DF_Type::ui__T_economy_prices__T_price_setter: return 1865;
	case DF_Type::ui__T_equipment: return 1866;
	case DF_Type::ui__T_equipment__T_update: return 1867;
	case DF_Type::ui__T_hauling: return 1868;
	case DF_Type::ui__T_invasions: return 1869;
	case DF_Type::ui__T_kitchen: return 1870;
	case DF_Type::ui__T_main: return 1871;
	case DF_Type::ui__T_main__T_dead_citizens: return 1872;
	case DF_Type::ui__T_map_edge: return 1873;
	case DF_Type::ui__T_squads: return 1874;
	case DF_Type::ui__T_stockpile: return 1875;
	case DF_Type::ui__T_tax_collection: return 1876;
	case DF_Type::ui__T_unk23c8_flags: return 1877;
	case DF_Type::ui__T_unk2a8c: return 1878;
	case DF_Type::ui__T_waypoints: return 1879;
	case DF_Type::ui__T_waypoints__T_points: return 1880;
	case DF_Type::ui__T_waypoints__T_routes: return 1881;
	case DF_Type::ui_advmode: return 1882;
	case DF_Type::ui_advmode__T_assume_identity: return 1883;
	case DF_Type::ui_advmode__T_companions: return 1884;
	case DF_Type::ui_advmode__T_conversation: return 1885;
	case DF_Type::ui_advmode__T_conversation__T_choices: return 1886;
	case DF_Type::ui_advmode__T_conversation__T_targets: return 1887;
	case DF_Type::ui_advmode__T_conversation__T_targets__T_type: return 1888;
	case DF_Type::ui_advmode__T_interactions: return 1889;
	case DF_Type::ui_advmode__T_show_menu: return 1890;
	case DF_Type::ui_advmode__T_travel_right_map: return 1891;
	case DF_Type::ui_advmode__T_unk_3124: return 1892;
	case DF_Type::ui_advmode__T_unk_3170: return 1893;
	case DF_Type::ui_advmode__T_unk_3170__T_unk_2: return 1894;
	case DF_Type::ui_advmode__T_unk_v40_1: return 1895;
	case DF_Type::ui_advmode__T_unk_v40_2: return 1896;
	case DF_Type::ui_advmode__T_unk_v40_3: return 1897;
	case DF_Type::ui_advmode__T_unk_v40_4: return 1898;
	case DF_Type::ui_advmode__T_unk_v40_4__T_unk_v40_4a: return 1899;
	case DF_Type::ui_advmode__T_unk_v40_5: return 1900;
	case DF_Type::ui_advmode__T_unk_v42_1: return 1901;
	case DF_Type::ui_advmode_menu: return 1902;
	case DF_Type::ui_build_item_req: return 1903;
	case DF_Type::ui_build_selector: return 1904;
	case DF_Type::ui_hotkey: return 1905;
	case DF_Type::ui_hotkey___union1: return 1906;
	case DF_Type::ui_hotkey__T_cmd: return 1907;
	case DF_Type::ui_look_list: return 1908;
	case DF_Type::ui_look_list__T_items: return 1909;
	case DF_Type::ui_look_list__T_items__T_data: return 1910;
	case DF_Type::ui_look_list__T_items__T_data__T_Magma: return 1911;
	case DF_Type::ui_look_list__T_items__T_data__T_Spatter: return 1912;
	case DF_Type::ui_look_list__T_items__T_data__T_Water: return 1913;
	case DF_Type::ui_look_list__T_items__T_type: return 1914;
	case DF_Type::ui_sidebar_menus: return 1915;
	case DF_Type::ui_sidebar_menus__T_barracks: return 1916;
	case DF_Type::ui_sidebar_menus__T_building: return 1917;
	case DF_Type::ui_sidebar_menus__T_command_line: return 1918;
	case DF_Type::ui_sidebar_menus__T_designation: return 1919;
	case DF_Type::ui_sidebar_menus__T_designation__T_mine_mode: return 1920;
	case DF_Type::ui_sidebar_menus__T_hospital: return 1921;
	case DF_Type::ui_sidebar_menus__T_job_details: return 1922;
	case DF_Type::ui_sidebar_menus__T_location: return 1923;
	case DF_Type::ui_sidebar_menus__T_minimap: return 1924;
	case DF_Type::ui_sidebar_menus__T_unit: return 1925;
	case DF_Type::ui_sidebar_menus__T_unit__T_expel_error: return 1926;
	case DF_Type::ui_sidebar_menus__T_unit_cursor: return 1927;
	case DF_Type::ui_sidebar_menus__T_unit_skills: return 1928;
	case DF_Type::ui_sidebar_menus__T_workshop_job: return 1929;
	case DF_Type::ui_sidebar_menus__T_zone: return 1930;
	case DF_Type::ui_sidebar_menus__T_zone__T_mode: return 1931;
	case DF_Type::ui_sidebar_mode: return 1932;
	case DF_Type::ui_unit_view_mode: return 1933;
	case DF_Type::ui_unit_view_mode__T_value: return 1934;
	case DF_Type::uniform_category: return 1935;
	case DF_Type::uniform_flags: return 1936;
	case DF_Type::uniform_indiv_choice: return 1937;
	case DF_Type::unit: return 1938;
	case DF_Type::unit__T_animal: return 1939;
	case DF_Type::unit__T_appearance: return 1940;
	case DF_Type::unit__T_body: return 1941;
	case DF_Type::unit__T_counters: return 1942;
	case DF_Type::unit__T_counters2: return 1943;
	case DF_Type::unit__T_counters__T_soldier_mood: return 1944;
	case DF_Type::unit__T_curse: return 1945;
	case DF_Type::unit__T_enemy: return 1946;
	case DF_Type::unit__T_enemy__T_undead: return 1947;
	case DF_Type::unit__T_enemy__T_unk_448: return 1948;
	case DF_Type::unit__T_enemy__T_unk_448__T_unk: return 1949;
	case DF_Type::unit__T_enemy__T_unk_44c: return 1950;
	case DF_Type::unit__T_enemy__T_unk_v40_sub3: return 1951;
	case DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_2: return 1952;
	case DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_6: return 1953;
	case DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_7: return 1954;
	case DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_7__T_unk_sub1: return 1955;
	case DF_Type::unit__T_enemy__T_witness_reports: return 1956;
	case DF_Type::unit__T_job: return 1957;
	case DF_Type::unit__T_meeting: return 1958;
	case DF_Type::unit__T_meeting__T_state: return 1959;
	case DF_Type::unit__T_military: return 1960;
	case DF_Type::unit__T_military__T_pickup_flags: return 1961;
	case DF_Type::unit__T_opponent: return 1962;
	case DF_Type::unit__T_path: return 1963;
	case DF_Type::unit__T_reports: return 1964;
	case DF_Type::unit__T_status: return 1965;
	case DF_Type::unit__T_status2: return 1966;
	case DF_Type::unit__T_status__T_eat_history: return 1967;
	case DF_Type::unit__T_status__T_eat_history__T_drink: return 1968;
	case DF_Type::unit__T_status__T_eat_history__T_food: return 1969;
	case DF_Type::unit__T_syndromes: return 1970;
	case DF_Type::unit__T_unknown7: return 1971;
	case DF_Type::unit_action: return 1972;
	case DF_Type::unit_action__T_data: return 1973;
	case DF_Type::unit_action_data_attack: return 1974;
	case DF_Type::unit_action_data_attack__T_flags: return 1975;
	case DF_Type::unit_action_data_attack__T_unk_4: return 1976;
	case DF_Type::unit_action_data_attack__T_unk_4__T_wrestle_type: return 1977;
	case DF_Type::unit_action_data_block: return 1978;
	case DF_Type::unit_action_data_climb: return 1979;
	case DF_Type::unit_action_data_dodge: return 1980;
	case DF_Type::unit_action_data_hold_item: return 1981;
	case DF_Type::unit_action_data_hold_terrain: return 1982;
	case DF_Type::unit_action_data_job: return 1983;
	case DF_Type::unit_action_data_job2: return 1984;
	case DF_Type::unit_action_data_jump: return 1985;
	case DF_Type::unit_action_data_lie_down: return 1986;
	case DF_Type::unit_action_data_move: return 1987;
	case DF_Type::unit_action_data_move__T_flags: return 1988;
	case DF_Type::unit_action_data_parry: return 1989;
	case DF_Type::unit_action_data_push_object: return 1990;
	case DF_Type::unit_action_data_recover: return 1991;
	case DF_Type::unit_action_data_release_item: return 1992;
	case DF_Type::unit_action_data_release_terrain: return 1993;
	case DF_Type::unit_action_data_stand_up: return 1994;
	case DF_Type::unit_action_data_suck_blood: return 1995;
	case DF_Type::unit_action_data_talk: return 1996;
	case DF_Type::unit_action_data_unsteady: return 1997;
	case DF_Type::unit_action_type: return 1998;
	case DF_Type::unit_appearance: return 1999;
	case DF_Type::unit_attribute: return 2000;
	case DF_Type::unit_bp_health_flags: return 2001;
	case DF_Type::unit_chunk: return 2002;
	case DF_Type::unit_chunk__T_units: return 2003;
	case DF_Type::unit_coin_debt: return 2004;
	case DF_Type::unit_complaint: return 2005;
	case DF_Type::unit_complaint__T_type: return 2006;
	case DF_Type::unit_dance_skill: return 2007;
	case DF_Type::unit_demand: return 2008;
	case DF_Type::unit_demand__T_place: return 2009;
	case DF_Type::unit_emotion_memory: return 2010;
	case DF_Type::unit_flags1: return 2011;
	case DF_Type::unit_flags2: return 2012;
	case DF_Type::unit_flags3: return 2013;
	case DF_Type::unit_flags4: return 2014;
	case DF_Type::unit_genes: return 2015;
	case DF_Type::unit_ghost_info: return 2016;
	case DF_Type::unit_ghost_info__T_flags: return 2017;
	case DF_Type::unit_ghost_info__T_target: return 2018;
	case DF_Type::unit_health_flags: return 2019;
	case DF_Type::unit_health_info: return 2020;
	case DF_Type::unit_health_info__T_op_history: return 2021;
	case DF_Type::unit_health_info__T_op_history__T_info: return 2022;
	case DF_Type::unit_health_info__T_op_history__T_info__T_bandage: return 2023;
	case DF_Type::unit_health_info__T_op_history__T_info__T_crutch: return 2024;
	case DF_Type::unit_instrument_skill: return 2025;
	case DF_Type::unit_inventory_item: return 2026;
	case DF_Type::unit_inventory_item__T_mode: return 2027;
	case DF_Type::unit_item_use: return 2028;
	case DF_Type::unit_item_wrestle: return 2029;
	case DF_Type::unit_labor: return 2030;
	case DF_Type::unit_labor_category: return 2031;
	case DF_Type::unit_misc_trait: return 2032;
	case DF_Type::unit_musical_skill: return 2033;
	case DF_Type::unit_path_goal: return 2034;
	case DF_Type::unit_personality: return 2035;
	case DF_Type::unit_personality__T_dreams: return 2036;
	case DF_Type::unit_personality__T_emotions: return 2037;
	case DF_Type::unit_personality__T_emotions__T_flags: return 2038;
	case DF_Type::unit_personality__T_flags: return 2039;
	case DF_Type::unit_personality__T_memories: return 2040;
	case DF_Type::unit_personality__T_memories__T_reflected_on: return 2041;
	case DF_Type::unit_personality__T_needs: return 2042;
	case DF_Type::unit_personality__T_unk5: return 2043;
	case DF_Type::unit_personality__T_unk_v40_2: return 2044;
	case DF_Type::unit_personality__T_unk_v40_6: return 2045;
	case DF_Type::unit_personality__T_values: return 2046;
	case DF_Type::unit_poetic_skill: return 2047;
	case DF_Type::unit_preference: return 2048;
	case DF_Type::unit_preference___union2: return 2049;
	case DF_Type::unit_preference__T_type: return 2050;
	case DF_Type::unit_relationship_type: return 2051;
	case DF_Type::unit_report_type: return 2052;
	case DF_Type::unit_request: return 2053;
	case DF_Type::unit_request__T_type: return 2054;
	case DF_Type::unit_skill: return 2055;
	case DF_Type::unit_soul: return 2056;
	case DF_Type::unit_soul__T_performance_skills: return 2057;
	case DF_Type::unit_station_type: return 2058;
	case DF_Type::unit_storage_status: return 2059;
	case DF_Type::unit_syndrome: return 2060;
	case DF_Type::unit_syndrome__T_flags: return 2061;
	case DF_Type::unit_syndrome__T_symptoms: return 2062;
	case DF_Type::unit_syndrome__T_symptoms__T_flags: return 2063;
	case DF_Type::unit_thought_type: return 2064;
	case DF_Type::unit_unk_138: return 2065;
	case DF_Type::unit_wound: return 2066;
	case DF_Type::unit_wound__T_flags: return 2067;
	case DF_Type::unit_wound__T_parts: return 2068;
	case DF_Type::units_other_id: return 2069;
	case DF_Type::vague_relationship_type: return 2070;
	case DF_Type::value_type: return 2071;
	case DF_Type::vehicle: return 2072;
	case DF_Type::vermin: return 2073;
	case DF_Type::vermin_flags: return 2074;
	case DF_Type::viewscreen: return 2075;
	case DF_Type::viewscreen_adopt_regionst: return 2076;
	case DF_Type::viewscreen_adventure_logst: return 2077;
	case DF_Type::viewscreen_adventure_logst__T_info_mode: return 2078;
	case DF_Type::viewscreen_adventure_logst__T_mode: return 2079;
	case DF_Type::viewscreen_adventure_logst__T_unk_68: return 2080;
	case DF_Type::viewscreen_announcelistst: return 2081;
	case DF_Type::viewscreen_assign_display_itemst: return 2082;
	case DF_Type::viewscreen_assign_display_itemst__T_sel_column: return 2083;
	case DF_Type::viewscreen_barterst: return 2084;
	case DF_Type::viewscreen_buildinglistst: return 2085;
	case DF_Type::viewscreen_buildingst: return 2086;
	case DF_Type::viewscreen_choose_start_sitest: return 2087;
	case DF_Type::viewscreen_choose_start_sitest__T_finder: return 2088;
	case DF_Type::viewscreen_choose_start_sitest__T_finder__T_finder_state: return 2089;
	case DF_Type::viewscreen_choose_start_sitest__T_page: return 2090;
	case DF_Type::viewscreen_civlistst: return 2091;
	case DF_Type::viewscreen_civlistst__T_artifact_details: return 2092;
	case DF_Type::viewscreen_civlistst__T_page: return 2093;
	case DF_Type::viewscreen_civlistst__T_rumors: return 2094;
	case DF_Type::viewscreen_civlistst__T_rumors__T_type: return 2095;
	case DF_Type::viewscreen_civlistst__T_unk_cache: return 2096;
	case DF_Type::viewscreen_civlistst__T_unk_cache__T_tmp1: return 2097;
	case DF_Type::viewscreen_civlistst__T_unk_cache__T_tmp2: return 2098;
	case DF_Type::viewscreen_counterintelligencest: return 2099;
	case DF_Type::viewscreen_createquotast: return 2100;
	case DF_Type::viewscreen_customize_unitst: return 2101;
	case DF_Type::viewscreen_dungeon_monsterstatusst: return 2102;
	case DF_Type::viewscreen_dungeon_wrestlest: return 2103;
	case DF_Type::viewscreen_dungeon_wrestlest__T_unk1: return 2104;
	case DF_Type::viewscreen_dungeonmodest: return 2105;
	case DF_Type::viewscreen_dwarfmodest: return 2106;
	case DF_Type::viewscreen_entityst: return 2107;
	case DF_Type::viewscreen_export_graphical_mapst: return 2108;
	case DF_Type::viewscreen_export_graphical_mapst__T_rgb_buffer: return 2109;
	case DF_Type::viewscreen_export_regionst: return 2110;
	case DF_Type::viewscreen_export_regionst__T_unk1: return 2111;
	case DF_Type::viewscreen_game_cleanerst: return 2112;
	case DF_Type::viewscreen_game_cleanerst__T_state: return 2113;
	case DF_Type::viewscreen_image_creator_mode: return 2114;
	case DF_Type::viewscreen_image_creatorst: return 2115;
	case DF_Type::viewscreen_image_creatorst__T_artifacts: return 2116;
	case DF_Type::viewscreen_image_creatorst__T_entities: return 2117;
	case DF_Type::viewscreen_image_creatorst__T_histfigs: return 2118;
	case DF_Type::viewscreen_image_creatorst__T_objects: return 2119;
	case DF_Type::viewscreen_image_creatorst__T_plants: return 2120;
	case DF_Type::viewscreen_image_creatorst__T_relationships: return 2121;
	case DF_Type::viewscreen_image_creatorst__T_shapes: return 2122;
	case DF_Type::viewscreen_image_creatorst__T_sites: return 2123;
	case DF_Type::viewscreen_image_creatorst__T_trees: return 2124;
	case DF_Type::viewscreen_itemst: return 2125;
	case DF_Type::viewscreen_joblistst: return 2126;
	case DF_Type::viewscreen_jobmanagementst: return 2127;
	case DF_Type::viewscreen_jobst: return 2128;
	case DF_Type::viewscreen_justicest: return 2129;
	case DF_Type::viewscreen_justicest__T_cur_column: return 2130;
	case DF_Type::viewscreen_justicest__T_interrogate_status: return 2131;
	case DF_Type::viewscreen_kitchenpref_page: return 2132;
	case DF_Type::viewscreen_kitchenprefst: return 2133;
	case DF_Type::viewscreen_layer: return 2134;
	case DF_Type::viewscreen_layer_arena_creaturest: return 2135;
	case DF_Type::viewscreen_layer_assigntradest: return 2136;
	case DF_Type::viewscreen_layer_choose_language_namest: return 2137;
	case DF_Type::viewscreen_layer_choose_language_namest__T_current_component: return 2138;
	case DF_Type::viewscreen_layer_currencyst: return 2139;
	case DF_Type::viewscreen_layer_export_play_mapst: return 2140;
	case DF_Type::viewscreen_layer_militaryst: return 2141;
	case DF_Type::viewscreen_layer_militaryst__T_ammo: return 2142;
	case DF_Type::viewscreen_layer_militaryst__T_ammo__T_add_item: return 2143;
	case DF_Type::viewscreen_layer_militaryst__T_ammo__T_material: return 2144;
	case DF_Type::viewscreen_layer_militaryst__T_equip: return 2145;
	case DF_Type::viewscreen_layer_militaryst__T_equip__T_add_item: return 2146;
	case DF_Type::viewscreen_layer_militaryst__T_equip__T_assigned: return 2147;
	case DF_Type::viewscreen_layer_militaryst__T_equip__T_color: return 2148;
	case DF_Type::viewscreen_layer_militaryst__T_equip__T_edit_mode: return 2149;
	case DF_Type::viewscreen_layer_militaryst__T_equip__T_material: return 2150;
	case DF_Type::viewscreen_layer_militaryst__T_equip__T_mode: return 2151;
	case DF_Type::viewscreen_layer_militaryst__T_equip__T_uniform: return 2152;
	case DF_Type::viewscreen_layer_militaryst__T_page: return 2153;
	case DF_Type::viewscreen_layer_militaryst__T_positions: return 2154;
	case DF_Type::viewscreen_layer_militaryst__T_squad_members: return 2155;
	case DF_Type::viewscreen_layer_militaryst__T_squads: return 2156;
	case DF_Type::viewscreen_layer_musicsoundst: return 2157;
	case DF_Type::viewscreen_layer_noblelistst: return 2158;
	case DF_Type::viewscreen_layer_noblelistst__T_candidates: return 2159;
	case DF_Type::viewscreen_layer_noblelistst__T_info: return 2160;
	case DF_Type::viewscreen_layer_noblelistst__T_mode: return 2161;
	case DF_Type::viewscreen_layer_overall_healthst: return 2162;
	case DF_Type::viewscreen_layer_reactionst: return 2163;
	case DF_Type::viewscreen_layer_squad_schedulest: return 2164;
	case DF_Type::viewscreen_layer_stockpilest: return 2165;
	case DF_Type::viewscreen_layer_stone_restrictionst: return 2166;
	case DF_Type::viewscreen_layer_unit_actionst: return 2167;
	case DF_Type::viewscreen_layer_unit_healthst: return 2168;
	case DF_Type::viewscreen_layer_unit_relationshipst: return 2169;
	case DF_Type::viewscreen_layer_world_gen_param_presetst: return 2170;
	case DF_Type::viewscreen_layer_world_gen_paramst: return 2171;
	case DF_Type::viewscreen_layer_world_gen_paramst__T_unk1: return 2172;
	case DF_Type::viewscreen_legendsst: return 2173;
	case DF_Type::viewscreen_legendsst__T_anon_7: return 2174;
	case DF_Type::viewscreen_legendsst__T_anon_7__T_anon_3: return 2175;
	case DF_Type::viewscreen_legendsst__T_cur_page: return 2176;
	case DF_Type::viewscreen_loadgamest: return 2177;
	case DF_Type::viewscreen_loadgamest__T_cur_step: return 2178;
	case DF_Type::viewscreen_locationsst: return 2179;
	case DF_Type::viewscreen_locationsst__T_in_edit: return 2180;
	case DF_Type::viewscreen_locationsst__T_menu: return 2181;
	case DF_Type::viewscreen_meetingst: return 2182;
	case DF_Type::viewscreen_movieplayerst: return 2183;
	case DF_Type::viewscreen_new_regionst: return 2184;
	case DF_Type::viewscreen_new_regionst__T_worldgen_presets: return 2185;
	case DF_Type::viewscreen_noblest: return 2186;
	case DF_Type::viewscreen_optionst: return 2187;
	case DF_Type::viewscreen_optionst__T_options: return 2188;
	case DF_Type::viewscreen_overallstatusst: return 2189;
	case DF_Type::viewscreen_overallstatusst__T_visible_pages: return 2190;
	case DF_Type::viewscreen_petitionsst: return 2191;
	case DF_Type::viewscreen_petst: return 2192;
	case DF_Type::viewscreen_petst__T_animal: return 2193;
	case DF_Type::viewscreen_petst__T_mode: return 2194;
	case DF_Type::viewscreen_petst__T_trainer_mode: return 2195;
	case DF_Type::viewscreen_pricest: return 2196;
	case DF_Type::viewscreen_reportlistst: return 2197;
	case DF_Type::viewscreen_requestagreementst: return 2198;
	case DF_Type::viewscreen_savegamest: return 2199;
	case DF_Type::viewscreen_selectitemst: return 2200;
	case DF_Type::viewscreen_setupadventurest: return 2201;
	case DF_Type::viewscreen_setupadventurest__T_page: return 2202;
	case DF_Type::viewscreen_setupadventurest__T_races_info: return 2203;
	case DF_Type::viewscreen_setupadventurest__T_status: return 2204;
	case DF_Type::viewscreen_setupdwarfgamest: return 2205;
	case DF_Type::viewscreen_setupdwarfgamest__T_animals: return 2206;
	case DF_Type::viewscreen_setupdwarfgamest__T_choice_types: return 2207;
	case DF_Type::viewscreen_setupdwarfgamest__T_mode: return 2208;
	case DF_Type::viewscreen_setupdwarfgamest__T_unk_v43: return 2209;
	case DF_Type::viewscreen_setupdwarfgamest__T_unk_v43__T_unk_v43_sub9: return 2210;
	case DF_Type::viewscreen_storesst: return 2211;
	case DF_Type::viewscreen_textviewerst: return 2212;
	case DF_Type::viewscreen_textviewerst__T_formatted_text: return 2213;
	case DF_Type::viewscreen_textviewerst__T_formatted_text__T_flags: return 2214;
	case DF_Type::viewscreen_titlest: return 2215;
	case DF_Type::viewscreen_titlest__T_menu_line_id: return 2216;
	case DF_Type::viewscreen_titlest__T_sel_subpage: return 2217;
	case DF_Type::viewscreen_titlest__T_start_savegames: return 2218;
	case DF_Type::viewscreen_topicmeeting_fill_land_holder_positionsst: return 2219;
	case DF_Type::viewscreen_topicmeeting_takerequestsst: return 2220;
	case DF_Type::viewscreen_topicmeetingst: return 2221;
	case DF_Type::viewscreen_tradeagreementst: return 2222;
	case DF_Type::viewscreen_tradegoodsst: return 2223;
	case DF_Type::viewscreen_tradelistst: return 2224;
	case DF_Type::viewscreen_treasurelistst: return 2225;
	case DF_Type::viewscreen_unitlist_page: return 2226;
	case DF_Type::viewscreen_unitlistst: return 2227;
	case DF_Type::viewscreen_unitst: return 2228;
	case DF_Type::viewscreen_update_regionst: return 2229;
	case DF_Type::viewscreen_wagesst: return 2230;
	case DF_Type::viewscreen_workquota_conditionst: return 2231;
	case DF_Type::viewscreen_workquota_conditionst__T_mode: return 2232;
	case DF_Type::viewscreen_workquota_conditionst__T_traits: return 2233;
	case DF_Type::viewscreen_workquota_conditionst__T_traits__T_flags: return 2234;
	case DF_Type::viewscreen_workquota_detailsst: return 2235;
	case DF_Type::viewscreen_workshop_profilest: return 2236;
	case DF_Type::viewscreen_workshop_profilest__T_tab: return 2237;
	case DF_Type::weapon_attack: return 2238;
	case DF_Type::weapon_attack__T_flags: return 2239;
	case DF_Type::weapon_flags: return 2240;
	case DF_Type::weather_type: return 2241;
	case DF_Type::web_cluster: return 2242;
	case DF_Type::whereabouts_type: return 2243;
	case DF_Type::widget_menu: return 2244;
	case DF_Type::widget_textbox: return 2245;
	case DF_Type::workshop_profile: return 2246;
	case DF_Type::workshop_type: return 2247;
	case DF_Type::world: return 2248;
	case DF_Type::world__T_activities: return 2249;
	case DF_Type::world__T_agreements: return 2250;
	case DF_Type::world__T_area_grasses: return 2251;
	case DF_Type::world__T_area_grasses__T_layer_grasses: return 2252;
	case DF_Type::world__T_arena_settings: return 2253;
	case DF_Type::world__T_arena_spawn: return 2254;
	case DF_Type::world__T_arena_spawn__T_equipment: return 2255;
	case DF_Type::world__T_arena_spawn__T_item_types: return 2256;
	case DF_Type::world__T_arena_spawn__T_tame: return 2257;
	case DF_Type::world__T_armies: return 2258;
	case DF_Type::world__T_army_controllers: return 2259;
	case DF_Type::world__T_army_tracking_info: return 2260;
	case DF_Type::world__T_artifacts: return 2261;
	case DF_Type::world__T_belief_systems: return 2262;
	case DF_Type::world__T_crimes: return 2263;
	case DF_Type::world__T_cultural_identities: return 2264;
	case DF_Type::world__T_cur_savegame: return 2265;
	case DF_Type::world__T_dance_forms: return 2266;
	case DF_Type::world__T_divination_sets: return 2267;
	case DF_Type::world__T_enemy_status_cache: return 2268;
	case DF_Type::world__T_entities: return 2269;
	case DF_Type::world__T_features: return 2270;
	case DF_Type::world__T_flow_engine: return 2271;
	case DF_Type::world__T_flow_guides: return 2272;
	case DF_Type::world__T_formations: return 2273;
	case DF_Type::world__T_identities: return 2274;
	case DF_Type::world__T_image_sets: return 2275;
	case DF_Type::world__T_image_sets__T_all: return 2276;
	case DF_Type::world__T_image_sets__T_all__T_anon_3: return 2277;
	case DF_Type::world__T_incidents: return 2278;
	case DF_Type::world__T_interaction_instances: return 2279;
	case DF_Type::world__T_items: return 2280;
	case DF_Type::world__T_languages: return 2281;
	case DF_Type::world__T_map: return 2282;
	case DF_Type::world__T_map_extras: return 2283;
	case DF_Type::world__T_math: return 2284;
	case DF_Type::world__T_math__T_approx: return 2285;
	case DF_Type::world__T_musical_forms: return 2286;
	case DF_Type::world__T_nemesis: return 2287;
	case DF_Type::world__T_occupations: return 2288;
	case DF_Type::world__T_pathfinder: return 2289;
	case DF_Type::world__T_pathfinder__T_boundary_heap: return 2290;
	case DF_Type::world__T_plants: return 2291;
	case DF_Type::world__T_poetic_forms: return 2292;
	case DF_Type::world__T_profession_skills: return 2293;
	case DF_Type::world__T_rhythms: return 2294;
	case DF_Type::world__T_scales: return 2295;
	case DF_Type::world__T_schedules: return 2296;
	case DF_Type::world__T_squads: return 2297;
	case DF_Type::world__T_status: return 2298;
	case DF_Type::world__T_status__T_flags: return 2299;
	case DF_Type::world__T_status__T_slots: return 2300;
	case DF_Type::world__T_status__T_slots__T_flags: return 2301;
	case DF_Type::world__T_stockpile: return 2302;
	case DF_Type::world__T_stockpile__T_simple1: return 2303;
	case DF_Type::world__T_stockpile__T_simple2: return 2304;
	case DF_Type::world__T_stockpile__T_simple3: return 2305;
	case DF_Type::world__T_units: return 2306;
	case DF_Type::world__T_unk_131ec0: return 2307;
	case DF_Type::world__T_unk_131ef0: return 2308;
	case DF_Type::world__T_unk_131ef0__T_claims: return 2309;
	case DF_Type::world__T_unk_19325c: return 2310;
	case DF_Type::world__T_unk_19325c__T_anon_1: return 2311;
	case DF_Type::world__T_unk_19325c__T_anon_2: return 2312;
	case DF_Type::world__T_unk_19325c__T_anon_3: return 2313;
	case DF_Type::world__T_unk_26c678: return 2314;
	case DF_Type::world__T_unk_v40_6: return 2315;
	case DF_Type::world__T_vehicles: return 2316;
	case DF_Type::world__T_vermin: return 2317;
	case DF_Type::world__T_worldgen: return 2318;
	case DF_Type::world__T_worldgen__T_worldgen_parms: return 2319;
	case DF_Type::world__T_worldgen_coord_buf: return 2320;
	case DF_Type::world__T_worldgen_status: return 2321;
	case DF_Type::world__T_written_contents: return 2322;
	case DF_Type::world_construction: return 2323;
	case DF_Type::world_construction_bridgest: return 2324;
	case DF_Type::world_construction_roadst: return 2325;
	case DF_Type::world_construction_square: return 2326;
	case DF_Type::world_construction_square_bridgest: return 2327;
	case DF_Type::world_construction_square_roadst: return 2328;
	case DF_Type::world_construction_square_tunnelst: return 2329;
	case DF_Type::world_construction_square_wallst: return 2330;
	case DF_Type::world_construction_tunnelst: return 2331;
	case DF_Type::world_construction_type: return 2332;
	case DF_Type::world_construction_wallst: return 2333;
	case DF_Type::world_dat_summary: return 2334;
	case DF_Type::world_data: return 2335;
	case DF_Type::world_data__T_constructions: return 2336;
	case DF_Type::world_data__T_feature_map: return 2337;
	case DF_Type::world_data__T_feature_map__T_features: return 2338;
	case DF_Type::world_data__T_field_battles: return 2339;
	case DF_Type::world_data__T_field_battles__T_sapient_deaths: return 2340;
	case DF_Type::world_data__T_flip_latitude: return 2341;
	case DF_Type::world_data__T_freakish_weather: return 2342;
	case DF_Type::world_data__T_mountain_peaks: return 2343;
	case DF_Type::world_data__T_unk_150: return 2344;
	case DF_Type::world_data__T_unk_150__T_unk_18: return 2345;
	case DF_Type::world_data__T_unk_150__T_unk_28: return 2346;
	case DF_Type::world_data__T_unk_150__T_unk_8: return 2347;
	case DF_Type::world_data__T_unk_274: return 2348;
	case DF_Type::world_data__T_unk_274__T_unk_10: return 2349;
	case DF_Type::world_data__T_unk_482f8: return 2350;
	case DF_Type::world_data__T_unk_b4: return 2351;
	case DF_Type::world_gen_param_basest: return 2352;
	case DF_Type::world_gen_param_charst: return 2353;
	case DF_Type::world_gen_param_memberst: return 2354;
	case DF_Type::world_gen_param_seedst: return 2355;
	case DF_Type::world_gen_param_valuest: return 2356;
	case DF_Type::world_geo_biome: return 2357;
	case DF_Type::world_geo_layer: return 2358;
	case DF_Type::world_history: return 2359;
	case DF_Type::world_history__T_event_collections: return 2360;
	case DF_Type::world_history__T_intrigues: return 2361;
	case DF_Type::world_history__T_intrigues__T_anon_1: return 2362;
	case DF_Type::world_landmass: return 2363;
	case DF_Type::world_object_data: return 2364;
	case DF_Type::world_object_data__T_offloaded_buildings: return 2365;
	case DF_Type::world_object_data__T_offloaded_items: return 2366;
	case DF_Type::world_object_data__T_unk_94: return 2367;
	case DF_Type::world_population: return 2368;
	case DF_Type::world_population___union4: return 2369;
	case DF_Type::world_population_ref: return 2370;
	case DF_Type::world_population_type: return 2371;
	case DF_Type::world_raws: return 2372;
	case DF_Type::world_raws__T_bodyglosses: return 2373;
	case DF_Type::world_raws__T_buildings: return 2374;
	case DF_Type::world_raws__T_descriptors: return 2375;
	case DF_Type::world_raws__T_effects: return 2376;
	case DF_Type::world_raws__T_itemdefs: return 2377;
	case DF_Type::world_raws__T_language: return 2378;
	case DF_Type::world_raws__T_plants: return 2379;
	case DF_Type::world_raws__T_reactions: return 2380;
	case DF_Type::world_raws__T_syndromes: return 2381;
	case DF_Type::world_region: return 2382;
	case DF_Type::world_region_details: return 2383;
	case DF_Type::world_region_details__T_edges: return 2384;
	case DF_Type::world_region_details__T_other_features: return 2385;
	case DF_Type::world_region_details__T_rivers_horizontal: return 2386;
	case DF_Type::world_region_details__T_rivers_vertical: return 2387;
	case DF_Type::world_region_feature: return 2388;
	case DF_Type::world_region_type: return 2389;
	case DF_Type::world_river: return 2390;
	case DF_Type::world_site: return 2391;
	case DF_Type::world_site__T_subtype_info: return 2392;
	case DF_Type::world_site__T_unk_1: return 2393;
	case DF_Type::world_site__T_unk_118: return 2394;
	case DF_Type::world_site__T_unk_13c: return 2395;
	case DF_Type::world_site__T_unk_188: return 2396;
	case DF_Type::world_site__T_unk_188__T_unk1: return 2397;
	case DF_Type::world_site__T_unk_1__T_units: return 2398;
	case DF_Type::world_site__T_unk_21c: return 2399;
	case DF_Type::world_site__T_unk_v40_2: return 2400;
	case DF_Type::world_site__T_unk_v40_4a: return 2401;
	case DF_Type::world_site__T_unk_v40_4b: return 2402;
	case DF_Type::world_site__T_unk_v40_4c: return 2403;
	case DF_Type::world_site__T_unk_v40_4d: return 2404;
	case DF_Type::world_site__T_unk_v40_4d__T_anon_1: return 2405;
	case DF_Type::world_site__T_unk_v43_2: return 2406;
	case DF_Type::world_site__T_unk_v47_1: return 2407;
	case DF_Type::world_site__T_unk_v47_1__T_unk_1: return 2408;
	case DF_Type::world_site_flags: return 2409;
	case DF_Type::world_site_inhabitant: return 2410;
	case DF_Type::world_site_realization: return 2411;
	case DF_Type::world_site_realization__T_areas: return 2412;
	case DF_Type::world_site_realization__T_areas__T_type: return 2413;
	case DF_Type::world_site_realization__T_building_map: return 2414;
	case DF_Type::world_site_realization__T_river_map: return 2415;
	case DF_Type::world_site_realization__T_unk_193bc: return 2416;
	case DF_Type::world_site_realization__T_unk_193bc__T_unk_8: return 2417;
	case DF_Type::world_site_realization__T_unk_55e8: return 2418;
	case DF_Type::world_site_realization__T_unk_55e8__T_unk_v40_2: return 2419;
	case DF_Type::world_site_type: return 2420;
	case DF_Type::world_site_unk130: return 2421;
	case DF_Type::world_site_unk130__T_unk_4: return 2422;
	case DF_Type::world_underground_region: return 2423;
	case DF_Type::world_underground_region__T_type: return 2424;
	case DF_Type::world_unk26c678_unk38: return 2425;
	case DF_Type::world_unk_20: return 2426;
	case DF_Type::world_unk_20__T_anon_7: return 2427;
	case DF_Type::world_unk_6c: return 2428;
	case DF_Type::world_unk_a8: return 2429;
	case DF_Type::world_unk_b4: return 2430;
	case DF_Type::world_unk_c0: return 2431;
	case DF_Type::world_unk_c0__T_anon_7: return 2432;
	case DF_Type::worldgen_range_type: return 2433;
	case DF_Type::worldgen_region_type: return 2434;
	case DF_Type::wound_curse_info: return 2435;
	case DF_Type::wound_damage_flags1: return 2436;
	case DF_Type::wound_damage_flags2: return 2437;
	case DF_Type::wound_effect_type: return 2438;
	case DF_Type::written_content: return 2439;
	case DF_Type::written_content_style: return 2440;
	case DF_Type::written_content_type: return 2441;
	case DF_Type::z_level_flags: return 2442;
	case DF_Type::zoom_commands: return 2443;
	}
	return -1;
}

DF_Type int_to_DF_Type(int32_t p_value)
{
    switch(p_value)
    {
        case 0: return DF_Type::None;
        case 1: return DF_Type::int64_t;
        case 2: return DF_Type::uint64_t;
        case 3: return DF_Type::int32_t;
        case 4: return DF_Type::int16_t;
        case 5: return DF_Type::uint32_t;
        case 6: return DF_Type::uint16_t;
        case 7: return DF_Type::uint8_t;
        case 8: return DF_Type::int8_t;
        case 9: return DF_Type::Void;
        case 10: return DF_Type::Char;
        case 11: return DF_Type::Long;
        case 12: return DF_Type::Bool;
        case 13: return DF_Type::Stl_string;
        case 14: return DF_Type::Static_string;
        case 15: return DF_Type::Ptr_string;
        case 16: return DF_Type::S_float;
        case 17: return DF_Type::D_float;
        case 18: return DF_Type::S_double;
        case 19: return DF_Type::Padding;
        case 20: return DF_Type::Stl_fstream;
		case 21: return DF_Type::abstract_building;
		case 22: return DF_Type::abstract_building__T_inhabitants;
		case 23: return DF_Type::abstract_building__T_unk1;
		case 24: return DF_Type::abstract_building_contents;
		case 25: return DF_Type::abstract_building_counting_housest;
		case 26: return DF_Type::abstract_building_dark_towerst;
		case 27: return DF_Type::abstract_building_dungeonst;
		case 28: return DF_Type::abstract_building_dungeonst__T_dungeon_type;
		case 29: return DF_Type::abstract_building_flags;
		case 30: return DF_Type::abstract_building_guildhallst;
		case 31: return DF_Type::abstract_building_inn_tavernst;
		case 32: return DF_Type::abstract_building_inn_tavernst__T_room_info;
		case 33: return DF_Type::abstract_building_keepst;
		case 34: return DF_Type::abstract_building_libraryst;
		case 35: return DF_Type::abstract_building_marketst;
		case 36: return DF_Type::abstract_building_mead_hallst;
		case 37: return DF_Type::abstract_building_templest;
		case 38: return DF_Type::abstract_building_tombst;
		case 39: return DF_Type::abstract_building_towerst;
		case 40: return DF_Type::abstract_building_type;
		case 41: return DF_Type::abstract_building_underworld_spirest;
		case 42: return DF_Type::abstract_building_unk;
		case 43: return DF_Type::abstract_building_unk__T_anon_1;
		case 44: return DF_Type::active_script_var_longst;
		case 45: return DF_Type::active_script_var_unitst;
		case 46: return DF_Type::active_script_varst;
		case 47: return DF_Type::activity_entry;
		case 48: return DF_Type::activity_entry_type;
		case 49: return DF_Type::activity_event;
		case 50: return DF_Type::activity_event__T_flags;
		case 51: return DF_Type::activity_event__T_unk_v42_1;
		case 52: return DF_Type::activity_event__T_unk_v42_2;
		case 53: return DF_Type::activity_event_combat_trainingst;
		case 54: return DF_Type::activity_event_conflictst;
		case 55: return DF_Type::activity_event_conflictst__T_sides;
		case 56: return DF_Type::activity_event_conflictst__T_sides__T_enemies;
		case 57: return DF_Type::activity_event_conversationst;
		case 58: return DF_Type::activity_event_conversationst__T_anon_6;
		case 59: return DF_Type::activity_event_conversationst__T_flags2;
		case 60: return DF_Type::activity_event_conversationst__T_participants;
		case 61: return DF_Type::activity_event_conversationst__T_turns;
		case 62: return DF_Type::activity_event_conversationst__T_unk2;
		case 63: return DF_Type::activity_event_conversationst__T_unk_b4;
		case 64: return DF_Type::activity_event_copy_written_contentst;
		case 65: return DF_Type::activity_event_copy_written_contentst__T_flagsmaybe;
		case 66: return DF_Type::activity_event_discuss_topicst;
		case 67: return DF_Type::activity_event_encounterst;
		case 68: return DF_Type::activity_event_encounterst__T_anon_1;
		case 69: return DF_Type::activity_event_encounterst__T_anon_2;
		case 70: return DF_Type::activity_event_fill_service_orderst;
		case 71: return DF_Type::activity_event_guardst;
		case 72: return DF_Type::activity_event_harassmentst;
		case 73: return DF_Type::activity_event_harassmentst__T_anon_2;
		case 74: return DF_Type::activity_event_individual_skill_drillst;
		case 75: return DF_Type::activity_event_make_believest;
		case 76: return DF_Type::activity_event_participants;
		case 77: return DF_Type::activity_event_performancest;
		case 78: return DF_Type::activity_event_performancest__T_participant_actions;
		case 79: return DF_Type::activity_event_play_with_toyst;
		case 80: return DF_Type::activity_event_play_with_toyst__T_unk;
		case 81: return DF_Type::activity_event_playst;
		case 82: return DF_Type::activity_event_ponder_topicst;
		case 83: return DF_Type::activity_event_prayerst;
		case 84: return DF_Type::activity_event_ranged_practicest;
		case 85: return DF_Type::activity_event_readst;
		case 86: return DF_Type::activity_event_researchst;
		case 87: return DF_Type::activity_event_reunionst;
		case 88: return DF_Type::activity_event_skill_demonstrationst;
		case 89: return DF_Type::activity_event_socializest;
		case 90: return DF_Type::activity_event_sparringst;
		case 91: return DF_Type::activity_event_sparringst__T_groups;
		case 92: return DF_Type::activity_event_store_objectst;
		case 93: return DF_Type::activity_event_teach_topicst;
		case 94: return DF_Type::activity_event_training_sessionst;
		case 95: return DF_Type::activity_event_type;
		case 96: return DF_Type::activity_event_worshipst;
		case 97: return DF_Type::activity_event_writest;
		case 98: return DF_Type::activity_info;
		case 99: return DF_Type::activity_info__T_flags;
		case 100: return DF_Type::adventure_environment_ingest_from_containerst;
		case 101: return DF_Type::adventure_environment_ingest_materialst;
		case 102: return DF_Type::adventure_environment_optionst;
		case 103: return DF_Type::adventure_environment_pickup_chop_treest;
		case 104: return DF_Type::adventure_environment_pickup_ignite_vegst;
		case 105: return DF_Type::adventure_environment_pickup_make_campfirest;
		case 106: return DF_Type::adventure_environment_pickup_vermin_eventst;
		case 107: return DF_Type::adventure_environment_place_in_bld_containerst;
		case 108: return DF_Type::adventure_environment_place_in_it_containerst;
		case 109: return DF_Type::adventure_environment_unit_suck_bloodst;
		case 110: return DF_Type::adventure_item_interact_choicest;
		case 111: return DF_Type::adventure_item_interact_fill_from_containerst;
		case 112: return DF_Type::adventure_item_interact_fill_with_materialst;
		case 113: return DF_Type::adventure_item_interact_give_namest;
		case 114: return DF_Type::adventure_item_interact_heat_from_tilest;
		case 115: return DF_Type::adventure_item_interact_pull_outst;
		case 116: return DF_Type::adventure_item_interact_readst;
		case 117: return DF_Type::adventure_item_interact_strugglest;
		case 118: return DF_Type::adventure_log_item;
		case 119: return DF_Type::adventure_movement_attack_creaturest;
		case 120: return DF_Type::adventure_movement_building_interactst;
		case 121: return DF_Type::adventure_movement_climbst;
		case 122: return DF_Type::adventure_movement_hold_itemst;
		case 123: return DF_Type::adventure_movement_hold_tilest;
		case 124: return DF_Type::adventure_movement_item_interact_guidest;
		case 125: return DF_Type::adventure_movement_item_interact_pushst;
		case 126: return DF_Type::adventure_movement_item_interact_ridest;
		case 127: return DF_Type::adventure_movement_item_interactst;
		case 128: return DF_Type::adventure_movement_movest;
		case 129: return DF_Type::adventure_movement_optionst;
		case 130: return DF_Type::adventure_movement_release_hold_itemst;
		case 131: return DF_Type::adventure_movement_release_hold_tilest;
		case 132: return DF_Type::adventure_option_eat_item_contaminantst;
		case 133: return DF_Type::adventure_option_eat_unit_contaminantst;
		case 134: return DF_Type::adventure_option_view_contaminantst;
		case 135: return DF_Type::adventure_optionst;
		case 136: return DF_Type::adventurer_attribute_level;
		case 137: return DF_Type::agreement;
		case 138: return DF_Type::agreement__T_anon_3;
		case 139: return DF_Type::agreement_details;
		case 140: return DF_Type::agreement_details__T_data;
		case 141: return DF_Type::agreement_details_data_citizenship;
		case 142: return DF_Type::agreement_details_data_demonic_binding;
		case 143: return DF_Type::agreement_details_data_join_party;
		case 144: return DF_Type::agreement_details_data_location;
		case 145: return DF_Type::agreement_details_data_parley;
		case 146: return DF_Type::agreement_details_data_plot_abduct;
		case 147: return DF_Type::agreement_details_data_plot_assassination;
		case 148: return DF_Type::agreement_details_data_plot_conviction;
		case 149: return DF_Type::agreement_details_data_plot_frame_treason;
		case 150: return DF_Type::agreement_details_data_plot_induce_war;
		case 151: return DF_Type::agreement_details_data_plot_infiltration_coup;
		case 152: return DF_Type::agreement_details_data_plot_steal_artifact;
		case 153: return DF_Type::agreement_details_data_position_corruption;
		case 154: return DF_Type::agreement_details_data_promise_position;
		case 155: return DF_Type::agreement_details_data_residency;
		case 156: return DF_Type::agreement_details_data_unk10;
		case 157: return DF_Type::agreement_details_type;
		case 158: return DF_Type::agreement_party;
		case 159: return DF_Type::agreement_party__T_anon_1;
		case 160: return DF_Type::ammo_flags;
		case 161: return DF_Type::animal_training_level;
		case 162: return DF_Type::announcement_flags;
		case 163: return DF_Type::announcement_type;
		case 164: return DF_Type::announcements;
		case 165: return DF_Type::appearance_modifier_growth_interval;
		case 166: return DF_Type::appearance_modifier_type;
		case 167: return DF_Type::armor_flags;
		case 168: return DF_Type::armor_general_flags;
		case 169: return DF_Type::armor_properties;
		case 170: return DF_Type::army;
		case 171: return DF_Type::army__T_members;
		case 172: return DF_Type::army__T_unk_2c;
		case 173: return DF_Type::army_controller;
		case 174: return DF_Type::army_controller__T_type;
		case 175: return DF_Type::army_controller__T_unk_64;
		case 176: return DF_Type::army_controller_sub1;
		case 177: return DF_Type::army_controller_sub11;
		case 178: return DF_Type::army_controller_sub11__T_anon_3;
		case 179: return DF_Type::army_controller_sub12;
		case 180: return DF_Type::army_controller_sub12__T_anon_4;
		case 181: return DF_Type::army_controller_sub13;
		case 182: return DF_Type::army_controller_sub13__T_anon_4;
		case 183: return DF_Type::army_controller_sub14;
		case 184: return DF_Type::army_controller_sub14__T_anon_4;
		case 185: return DF_Type::army_controller_sub15;
		case 186: return DF_Type::army_controller_sub15__T_anon_3;
		case 187: return DF_Type::army_controller_sub16;
		case 188: return DF_Type::army_controller_sub17;
		case 189: return DF_Type::army_controller_sub18;
		case 190: return DF_Type::army_controller_sub2;
		case 191: return DF_Type::army_controller_sub24;
		case 192: return DF_Type::army_controller_sub2__T_anon_5;
		case 193: return DF_Type::army_controller_sub4;
		case 194: return DF_Type::army_controller_sub4__T_unk_2;
		case 195: return DF_Type::army_controller_sub5;
		case 196: return DF_Type::army_controller_sub6;
		case 197: return DF_Type::army_controller_sub7;
		case 198: return DF_Type::army_controller_sub7__T_anon_3;
		case 199: return DF_Type::army_flags;
		case 200: return DF_Type::art_facet_type;
		case 201: return DF_Type::art_image;
		case 202: return DF_Type::art_image_chunk;
		case 203: return DF_Type::art_image_element;
		case 204: return DF_Type::art_image_element_creaturest;
		case 205: return DF_Type::art_image_element_itemst;
		case 206: return DF_Type::art_image_element_plantst;
		case 207: return DF_Type::art_image_element_shapest;
		case 208: return DF_Type::art_image_element_treest;
		case 209: return DF_Type::art_image_element_type;
		case 210: return DF_Type::art_image_property;
		case 211: return DF_Type::art_image_property_intransitive_verbst;
		case 212: return DF_Type::art_image_property_transitive_verbst;
		case 213: return DF_Type::art_image_property_type;
		case 214: return DF_Type::art_image_property_verb;
		case 215: return DF_Type::art_image_ref;
		case 216: return DF_Type::artifact_claim;
		case 217: return DF_Type::artifact_claim_type;
		case 218: return DF_Type::artifact_record;
		case 219: return DF_Type::assign_trade_status;
		case 220: return DF_Type::assign_trade_status__T_status;
		case 221: return DF_Type::assume_identity_mode;
		case 222: return DF_Type::barrack_preference_category;
		case 223: return DF_Type::belief_system;
		case 224: return DF_Type::biome_type;
		case 225: return DF_Type::block_burrow;
		case 226: return DF_Type::block_burrow_link;
		case 227: return DF_Type::block_flags;
		case 228: return DF_Type::block_square_event;
		case 229: return DF_Type::block_square_event_designation_priorityst;
		case 230: return DF_Type::block_square_event_frozen_liquidst;
		case 231: return DF_Type::block_square_event_grassst;
		case 232: return DF_Type::block_square_event_item_spatterst;
		case 233: return DF_Type::block_square_event_material_spatterst;
		case 234: return DF_Type::block_square_event_mineralst;
		case 235: return DF_Type::block_square_event_mineralst__T_flags;
		case 236: return DF_Type::block_square_event_spoorst;
		case 237: return DF_Type::block_square_event_type;
		case 238: return DF_Type::block_square_event_world_constructionst;
		case 239: return DF_Type::body_appearance_modifier;
		case 240: return DF_Type::body_component_info;
		case 241: return DF_Type::body_detail_plan;
		case 242: return DF_Type::body_layer_status;
		case 243: return DF_Type::body_part_layer_flags;
		case 244: return DF_Type::body_part_layer_raw;
		case 245: return DF_Type::body_part_raw;
		case 246: return DF_Type::body_part_raw_flags;
		case 247: return DF_Type::body_part_status;
		case 248: return DF_Type::body_part_template;
		case 249: return DF_Type::body_part_template_contype;
		case 250: return DF_Type::body_part_template_flags;
		case 251: return DF_Type::body_size_info;
		case 252: return DF_Type::body_template;
		case 253: return DF_Type::bp_appearance_modifier;
		case 254: return DF_Type::breath_attack_type;
		case 255: return DF_Type::build_req_choice_genst;
		case 256: return DF_Type::build_req_choice_specst;
		case 257: return DF_Type::build_req_choice_type;
		case 258: return DF_Type::build_req_choicest;
		case 259: return DF_Type::building;
		case 260: return DF_Type::building__T_activities;
		case 261: return DF_Type::building__T_job_claim_suppress;
		case 262: return DF_Type::building_actual;
		case 263: return DF_Type::building_actual__T_contained_items;
		case 264: return DF_Type::building_animaltrapst;
		case 265: return DF_Type::building_archerytargetst;
		case 266: return DF_Type::building_archerytargetst__T_archery_direction;
		case 267: return DF_Type::building_armorstandst;
		case 268: return DF_Type::building_axle_horizontalst;
		case 269: return DF_Type::building_axle_verticalst;
		case 270: return DF_Type::building_bars_floorst;
		case 271: return DF_Type::building_bars_verticalst;
		case 272: return DF_Type::building_bedst;
		case 273: return DF_Type::building_bedst__T_bed_flags;
		case 274: return DF_Type::building_bookcasest;
		case 275: return DF_Type::building_boxst;
		case 276: return DF_Type::building_bridgest;
		case 277: return DF_Type::building_bridgest__T_direction;
		case 278: return DF_Type::building_cabinetst;
		case 279: return DF_Type::building_cagest;
		case 280: return DF_Type::building_cagest__T_cage_flags;
		case 281: return DF_Type::building_chainst;
		case 282: return DF_Type::building_chainst__T_chain_flags;
		case 283: return DF_Type::building_chairst;
		case 284: return DF_Type::building_civzonest;
		case 285: return DF_Type::building_civzonest__T_gather_flags;
		case 286: return DF_Type::building_civzonest__T_pit_flags;
		case 287: return DF_Type::building_civzonest__T_zone_flags;
		case 288: return DF_Type::building_coffinst;
		case 289: return DF_Type::building_coffinst__T_burial_mode;
		case 290: return DF_Type::building_constructionst;
		case 291: return DF_Type::building_def;
		case 292: return DF_Type::building_def_furnacest;
		case 293: return DF_Type::building_def_item;
		case 294: return DF_Type::building_def_workshopst;
		case 295: return DF_Type::building_design;
		case 296: return DF_Type::building_design__T_flags;
		case 297: return DF_Type::building_display_furniturest;
		case 298: return DF_Type::building_doorst;
		case 299: return DF_Type::building_drawbuffer;
		case 300: return DF_Type::building_extents;
		case 301: return DF_Type::building_farmplotst;
		case 302: return DF_Type::building_flags;
		case 303: return DF_Type::building_floodgatest;
		case 304: return DF_Type::building_furnacest;
		case 305: return DF_Type::building_gear_assemblyst;
		case 306: return DF_Type::building_gear_assemblyst__T_gear_flags;
		case 307: return DF_Type::building_grate_floorst;
		case 308: return DF_Type::building_grate_wallst;
		case 309: return DF_Type::building_handler;
		case 310: return DF_Type::building_hatchst;
		case 311: return DF_Type::building_hivest;
		case 312: return DF_Type::building_instrumentst;
		case 313: return DF_Type::building_nest_boxst;
		case 314: return DF_Type::building_nestst;
		case 315: return DF_Type::building_offering_placest;
		case 316: return DF_Type::building_road_dirtst;
		case 317: return DF_Type::building_road_pavedst;
		case 318: return DF_Type::building_roadst;
		case 319: return DF_Type::building_rollersst;
		case 320: return DF_Type::building_screw_pumpst;
		case 321: return DF_Type::building_shopst;
		case 322: return DF_Type::building_shopst__T_shop_flags;
		case 323: return DF_Type::building_siegeenginest;
		case 324: return DF_Type::building_siegeenginest__T_action;
		case 325: return DF_Type::building_siegeenginest__T_facing;
		case 326: return DF_Type::building_slabst;
		case 327: return DF_Type::building_squad_use;
		case 328: return DF_Type::building_statuest;
		case 329: return DF_Type::building_stockpilest;
		case 330: return DF_Type::building_supportst;
		case 331: return DF_Type::building_supportst__T_support_flags;
		case 332: return DF_Type::building_tablest;
		case 333: return DF_Type::building_tablest__T_table_flags;
		case 334: return DF_Type::building_traction_benchst;
		case 335: return DF_Type::building_tradedepotst;
		case 336: return DF_Type::building_tradedepotst__T_trade_flags;
		case 337: return DF_Type::building_trapst;
		case 338: return DF_Type::building_trapst__T_stop_flags;
		case 339: return DF_Type::building_type;
		case 340: return DF_Type::building_users;
		case 341: return DF_Type::building_wagonst;
		case 342: return DF_Type::building_water_wheelst;
		case 343: return DF_Type::building_weaponrackst;
		case 344: return DF_Type::building_weaponst;
		case 345: return DF_Type::building_wellst;
		case 346: return DF_Type::building_wellst__T_well_flags;
		case 347: return DF_Type::building_windmillst;
		case 348: return DF_Type::building_window_gemst;
		case 349: return DF_Type::building_window_glassst;
		case 350: return DF_Type::building_windowst;
		case 351: return DF_Type::building_workshopst;
		case 352: return DF_Type::buildings_other_id;
		case 353: return DF_Type::builtin_mats;
		case 354: return DF_Type::burrow;
		case 355: return DF_Type::campfire;
		case 356: return DF_Type::caravan_state;
		case 357: return DF_Type::caravan_state__T_flags;
		case 358: return DF_Type::caravan_state__T_trade_state;
		case 359: return DF_Type::caste_attack;
		case 360: return DF_Type::caste_attack__T_flags;
		case 361: return DF_Type::caste_body_info;
		case 362: return DF_Type::caste_body_info__T_extra_butcher_objects;
		case 363: return DF_Type::caste_body_info__T_flags;
		case 364: return DF_Type::caste_body_info__T_interactions;
		case 365: return DF_Type::caste_body_info__T_interactions__T_type;
		case 366: return DF_Type::caste_clothing_item;
		case 367: return DF_Type::caste_raw;
		case 368: return DF_Type::caste_raw__T_anon_1;
		case 369: return DF_Type::caste_raw__T_attributes;
		case 370: return DF_Type::caste_raw__T_bp_appearance;
		case 371: return DF_Type::caste_raw__T_caste_profession_name;
		case 372: return DF_Type::caste_raw__T_extracts;
		case 373: return DF_Type::caste_raw__T_lair_hunter_speech;
		case 374: return DF_Type::caste_raw__T_misc;
		case 375: return DF_Type::caste_raw__T_personality;
		case 376: return DF_Type::caste_raw__T_secretion;
		case 377: return DF_Type::caste_raw__T_shearable_tissue_layer;
		case 378: return DF_Type::caste_raw__T_sound;
		case 379: return DF_Type::caste_raw__T_unk29;
		case 380: return DF_Type::caste_raw__T_unknown2;
		case 381: return DF_Type::caste_raw_flags;
		case 382: return DF_Type::cave_column;
		case 383: return DF_Type::cave_column_link;
		case 384: return DF_Type::cave_column_rectangle;
		case 385: return DF_Type::cie_add_tag_mask1;
		case 386: return DF_Type::cie_add_tag_mask2;
		case 387: return DF_Type::civzone_type;
		case 388: return DF_Type::coin_batch;
		case 389: return DF_Type::coin_batch__T_image_back;
		case 390: return DF_Type::coin_batch__T_image_front;
		case 391: return DF_Type::color_modifier_raw;
		case 392: return DF_Type::combat_report_event_type;
		case 393: return DF_Type::conflict_level;
		case 394: return DF_Type::construction;
		case 395: return DF_Type::construction_flags;
		case 396: return DF_Type::construction_type;
		case 397: return DF_Type::conversation;
		case 398: return DF_Type::conversation__T_speech;
		case 399: return DF_Type::conversation__T_state;
		case 400: return DF_Type::conversation_menu;
		case 401: return DF_Type::coord;
		case 402: return DF_Type::coord2d;
		case 403: return DF_Type::coord2d_path;
		case 404: return DF_Type::coord_path;
		case 405: return DF_Type::coord_rect;
		case 406: return DF_Type::corpse_material_type;
		case 407: return DF_Type::craft_material_class;
		case 408: return DF_Type::creation_zone_pwg_alteration_campst;
		case 409: return DF_Type::creation_zone_pwg_alteration_location_deathst;
		case 410: return DF_Type::creation_zone_pwg_alteration_location_deathst__T_unk_1;
		case 411: return DF_Type::creation_zone_pwg_alteration_location_deathst__T_unk_1__T_anon_1;
		case 412: return DF_Type::creation_zone_pwg_alteration_srb_ruinedst;
		case 413: return DF_Type::creation_zone_pwg_alteration_srp_ruinedst;
		case 414: return DF_Type::creation_zone_pwg_alteration_type;
		case 415: return DF_Type::creation_zone_pwg_alterationst;
		case 416: return DF_Type::creature_graphics_appointment;
		case 417: return DF_Type::creature_graphics_role;
		case 418: return DF_Type::creature_handler;
		case 419: return DF_Type::creature_interaction;
		case 420: return DF_Type::creature_interaction__T_flags;
		case 421: return DF_Type::creature_interaction_effect;
		case 422: return DF_Type::creature_interaction_effect__T_counter_trigger;
		case 423: return DF_Type::creature_interaction_effect_add_simple_flagst;
		case 424: return DF_Type::creature_interaction_effect_bleedingst;
		case 425: return DF_Type::creature_interaction_effect_blistersst;
		case 426: return DF_Type::creature_interaction_effect_body_appearance_modifierst;
		case 427: return DF_Type::creature_interaction_effect_body_mat_interactionst;
		case 428: return DF_Type::creature_interaction_effect_body_transformationst;
		case 429: return DF_Type::creature_interaction_effect_bp_appearance_modifierst;
		case 430: return DF_Type::creature_interaction_effect_bruisingst;
		case 431: return DF_Type::creature_interaction_effect_can_do_interactionst;
		case 432: return DF_Type::creature_interaction_effect_change_personalityst;
		case 433: return DF_Type::creature_interaction_effect_close_open_woundsst;
		case 434: return DF_Type::creature_interaction_effect_cough_bloodst;
		case 435: return DF_Type::creature_interaction_effect_cure_infectionsst;
		case 436: return DF_Type::creature_interaction_effect_cure_infectionst;
		case 437: return DF_Type::creature_interaction_effect_display_namest;
		case 438: return DF_Type::creature_interaction_effect_display_symbolst;
		case 439: return DF_Type::creature_interaction_effect_dizzinessst;
		case 440: return DF_Type::creature_interaction_effect_drowsinessst;
		case 441: return DF_Type::creature_interaction_effect_erratic_behaviorst;
		case 442: return DF_Type::creature_interaction_effect_feel_emotionst;
		case 443: return DF_Type::creature_interaction_effect_feverst;
		case 444: return DF_Type::creature_interaction_effect_flags;
		case 445: return DF_Type::creature_interaction_effect_flash_symbolst;
		case 446: return DF_Type::creature_interaction_effect_heal_nervesst;
		case 447: return DF_Type::creature_interaction_effect_heal_tissuesst;
		case 448: return DF_Type::creature_interaction_effect_impair_functionst;
		case 449: return DF_Type::creature_interaction_effect_material_force_adjustst;
		case 450: return DF_Type::creature_interaction_effect_ment_att_changest;
		case 451: return DF_Type::creature_interaction_effect_nauseast;
		case 452: return DF_Type::creature_interaction_effect_necrosisst;
		case 453: return DF_Type::creature_interaction_effect_numbnessst;
		case 454: return DF_Type::creature_interaction_effect_oozingst;
		case 455: return DF_Type::creature_interaction_effect_painst;
		case 456: return DF_Type::creature_interaction_effect_paralysisst;
		case 457: return DF_Type::creature_interaction_effect_phys_att_changest;
		case 458: return DF_Type::creature_interaction_effect_reduce_dizzinessst;
		case 459: return DF_Type::creature_interaction_effect_reduce_feverst;
		case 460: return DF_Type::creature_interaction_effect_reduce_nauseast;
		case 461: return DF_Type::creature_interaction_effect_reduce_painst;
		case 462: return DF_Type::creature_interaction_effect_reduce_paralysisst;
		case 463: return DF_Type::creature_interaction_effect_reduce_swellingst;
		case 464: return DF_Type::creature_interaction_effect_regrow_partsst;
		case 465: return DF_Type::creature_interaction_effect_remove_simple_flagst;
		case 466: return DF_Type::creature_interaction_effect_sense_creature_classst;
		case 467: return DF_Type::creature_interaction_effect_skill_roll_adjustst;
		case 468: return DF_Type::creature_interaction_effect_special_attack_interactionst;
		case 469: return DF_Type::creature_interaction_effect_speed_changest;
		case 470: return DF_Type::creature_interaction_effect_stop_bleedingst;
		case 471: return DF_Type::creature_interaction_effect_swellingst;
		case 472: return DF_Type::creature_interaction_effect_target;
		case 473: return DF_Type::creature_interaction_effect_target_mode;
		case 474: return DF_Type::creature_interaction_effect_type;
		case 475: return DF_Type::creature_interaction_effect_unconsciousnessst;
		case 476: return DF_Type::creature_interaction_effect_vomit_bloodst;
		case 477: return DF_Type::creature_interaction_target_flags;
		case 478: return DF_Type::creature_raw;
		case 479: return DF_Type::creature_raw__T_graphics;
		case 480: return DF_Type::creature_raw__T_hive_product;
		case 481: return DF_Type::creature_raw__T_profession_name;
		case 482: return DF_Type::creature_raw_flags;
		case 483: return DF_Type::creature_variation;
		case 484: return DF_Type::creature_variation_convert_tag;
		case 485: return DF_Type::crime;
		case 486: return DF_Type::crime__T_counterintelligence;
		case 487: return DF_Type::crime__T_flags;
		case 488: return DF_Type::crime__T_mode;
		case 489: return DF_Type::crime__T_punishment;
		case 490: return DF_Type::crime__T_reports;
		case 491: return DF_Type::crime_type;
		case 492: return DF_Type::cultural_identity;
		case 493: return DF_Type::cultural_identity__T_anon_1;
		case 494: return DF_Type::cultural_identity__T_anon_2;
		case 495: return DF_Type::cultural_identity__T_group_log;
		case 496: return DF_Type::cultural_identity__T_group_log__T_join_type;
		case 497: return DF_Type::cumulus_type;
		case 498: return DF_Type::curse_attr_change;
		case 499: return DF_Type::d_init;
		case 500: return DF_Type::d_init__T_store_dist;
		case 501: return DF_Type::d_init__T_wound_color;
		case 502: return DF_Type::d_init_embark_confirm;
		case 503: return DF_Type::d_init_flags1;
		case 504: return DF_Type::d_init_flags2;
		case 505: return DF_Type::d_init_flags3;
		case 506: return DF_Type::d_init_flags4;
		case 507: return DF_Type::d_init_idlers;
		case 508: return DF_Type::d_init_nickname;
		case 509: return DF_Type::d_init_tunnel;
		case 510: return DF_Type::d_init_z_view;
		case 511: return DF_Type::dance_form;
		case 512: return DF_Type::dance_form_sub1;
		case 513: return DF_Type::dance_form_sub2;
		case 514: return DF_Type::death_condition_type;
		case 515: return DF_Type::death_type;
		case 516: return DF_Type::deep_vein_hollow;
		case 517: return DF_Type::descriptor_color;
		case 518: return DF_Type::descriptor_pattern;
		case 519: return DF_Type::descriptor_shape;
		case 520: return DF_Type::descriptor_shape__T_gems_use;
		case 521: return DF_Type::dfhack_knowledge_scholar_flag;
		case 522: return DF_Type::dfhack_material_category;
		case 523: return DF_Type::dfhack_room_quality_level;
		case 524: return DF_Type::dipscript_info;
		case 525: return DF_Type::dipscript_popup;
		case 526: return DF_Type::dipscript_popup__T_flags;
		case 527: return DF_Type::divination_set;
		case 528: return DF_Type::divination_set_roll;
		case 529: return DF_Type::door_flags;
		case 530: return DF_Type::dye_info;
		case 531: return DF_Type::effect_info;
		case 532: return DF_Type::embark_feature;
		case 533: return DF_Type::embark_finder_option;
		case 534: return DF_Type::embark_item_choice;
		case 535: return DF_Type::embark_item_choice__T_list;
		case 536: return DF_Type::embark_location;
		case 537: return DF_Type::embark_note;
		case 538: return DF_Type::embark_profile;
		case 539: return DF_Type::emotion_type;
		case 540: return DF_Type::enabler;
		case 541: return DF_Type::enabler__T_async_frombox;
		case 542: return DF_Type::enabler__T_async_frombox__T_queue;
		case 543: return DF_Type::enabler__T_async_frombox__T_queue___union0;
		case 544: return DF_Type::enabler__T_async_frombox__T_queue___union0___struct1;
		case 545: return DF_Type::enabler__T_async_frombox__T_queue__T_msg;
		case 546: return DF_Type::enabler__T_async_tobox;
		case 547: return DF_Type::enabler__T_async_tobox__T_queue;
		case 548: return DF_Type::enabler__T_async_tobox__T_queue__T_cmd;
		case 549: return DF_Type::enabler__T_async_zoom;
		case 550: return DF_Type::enabler__T_flag;
		case 551: return DF_Type::enabler__T_gputicks;
		case 552: return DF_Type::enabler__T_overridden_grid_sizes;
		case 553: return DF_Type::enabler__T_simticks;
		case 554: return DF_Type::enabler__T_text_system;
		case 555: return DF_Type::enabler__T_text_system__T_file_info;
		case 556: return DF_Type::enabler__T_textures;
		case 557: return DF_Type::engraving;
		case 558: return DF_Type::engraving_flags;
		case 559: return DF_Type::entity_action_type;
		case 560: return DF_Type::entity_activity_statistics;
		case 561: return DF_Type::entity_activity_statistics__T_food;
		case 562: return DF_Type::entity_activity_statistics__T_found_misc;
		case 563: return DF_Type::entity_activity_statistics__T_wealth;
		case 564: return DF_Type::entity_animal_raw;
		case 565: return DF_Type::entity_animal_raw__T_flags;
		case 566: return DF_Type::entity_buy_prices;
		case 567: return DF_Type::entity_buy_requests;
		case 568: return DF_Type::entity_claim_mask;
		case 569: return DF_Type::entity_claim_mask__T_map;
		case 570: return DF_Type::entity_entity_link;
		case 571: return DF_Type::entity_entity_link_type;
		case 572: return DF_Type::entity_event;
		case 573: return DF_Type::entity_event__T_data;
		case 574: return DF_Type::entity_event__T_data__T_abandon;
		case 575: return DF_Type::entity_event__T_data__T_abduction;
		case 576: return DF_Type::entity_event__T_data__T_accept_peace_offer;
		case 577: return DF_Type::entity_event__T_data__T_accept_tribute_demand;
		case 578: return DF_Type::entity_event__T_data__T_accept_tribute_offer;
		case 579: return DF_Type::entity_event__T_data__T_artifact_destroyed;
		case 580: return DF_Type::entity_event__T_data__T_artifact_in_feature_layer;
		case 581: return DF_Type::entity_event__T_data__T_artifact_in_inventory;
		case 582: return DF_Type::entity_event__T_data__T_artifact_in_site;
		case 583: return DF_Type::entity_event__T_data__T_artifact_in_subregion;
		case 584: return DF_Type::entity_event__T_data__T_artifact_not_in_feature_layer;
		case 585: return DF_Type::entity_event__T_data__T_artifact_not_in_inventory;
		case 586: return DF_Type::entity_event__T_data__T_artifact_not_in_site;
		case 587: return DF_Type::entity_event__T_data__T_artifact_not_in_subregion;
		case 588: return DF_Type::entity_event__T_data__T_beast;
		case 589: return DF_Type::entity_event__T_data__T_cease_tribute_offer;
		case 590: return DF_Type::entity_event__T_data__T_claim;
		case 591: return DF_Type::entity_event__T_data__T_flee;
		case 592: return DF_Type::entity_event__T_data__T_founded;
		case 593: return DF_Type::entity_event__T_data__T_founding;
		case 594: return DF_Type::entity_event__T_data__T_group;
		case 595: return DF_Type::entity_event__T_data__T_harass;
		case 596: return DF_Type::entity_event__T_data__T_incident;
		case 597: return DF_Type::entity_event__T_data__T_insurrection;
		case 598: return DF_Type::entity_event__T_data__T_insurrection_end;
		case 599: return DF_Type::entity_event__T_data__T_insurrection_end__T_result;
		case 600: return DF_Type::entity_event__T_data__T_invasion;
		case 601: return DF_Type::entity_event__T_data__T_leave;
		case 602: return DF_Type::entity_event__T_data__T_occupation;
		case 603: return DF_Type::entity_event__T_data__T_reclaimed;
		case 604: return DF_Type::entity_event__T_data__T_reclaiming;
		case 605: return DF_Type::entity_event__T_data__T_refuse_peace_offer;
		case 606: return DF_Type::entity_event__T_data__T_refuse_tribute_demand;
		case 607: return DF_Type::entity_event__T_data__T_refuse_tribute_offer;
		case 608: return DF_Type::entity_event__T_data__T_succession;
		case 609: return DF_Type::entity_event_type;
		case 610: return DF_Type::entity_material_category;
		case 611: return DF_Type::entity_name_type;
		case 612: return DF_Type::entity_occasion;
		case 613: return DF_Type::entity_occasion_info;
		case 614: return DF_Type::entity_occasion_schedule;
		case 615: return DF_Type::entity_occasion_schedule_feature;
		case 616: return DF_Type::entity_population;
		case 617: return DF_Type::entity_population_unk4;
		case 618: return DF_Type::entity_population_unk4__T_anon_1;
		case 619: return DF_Type::entity_population_unk4__T_anon_2;
		case 620: return DF_Type::entity_population_unk4__T_anon_3;
		case 621: return DF_Type::entity_position;
		case 622: return DF_Type::entity_position_assignment;
		case 623: return DF_Type::entity_position_flags;
		case 624: return DF_Type::entity_position_raw;
		case 625: return DF_Type::entity_position_raw_flags;
		case 626: return DF_Type::entity_position_responsibility;
		case 627: return DF_Type::entity_raw;
		case 628: return DF_Type::entity_raw__T_equipment;
		case 629: return DF_Type::entity_raw__T_jobs;
		case 630: return DF_Type::entity_raw__T_land_holder_trigger;
		case 631: return DF_Type::entity_raw__T_progress_trigger;
		case 632: return DF_Type::entity_raw__T_scholar;
		case 633: return DF_Type::entity_raw__T_symbols;
		case 634: return DF_Type::entity_raw__T_tissue_styles;
		case 635: return DF_Type::entity_raw__T_workshops;
		case 636: return DF_Type::entity_raw_flags;
		case 637: return DF_Type::entity_recipe;
		case 638: return DF_Type::entity_sell_category;
		case 639: return DF_Type::entity_sell_prices;
		case 640: return DF_Type::entity_sell_requests;
		case 641: return DF_Type::entity_site_link;
		case 642: return DF_Type::entity_site_link__T_unk_7;
		case 643: return DF_Type::entity_site_link_flags;
		case 644: return DF_Type::entity_site_link_status_flags;
		case 645: return DF_Type::entity_site_link_type;
		case 646: return DF_Type::entity_tissue_style;
		case 647: return DF_Type::entity_uniform;
		case 648: return DF_Type::entity_uniform_item;
		case 649: return DF_Type::entity_unk_v47_1;
		case 650: return DF_Type::environment_type;
		case 651: return DF_Type::era_type;
		case 652: return DF_Type::ethic_response;
		case 653: return DF_Type::ethic_type;
		case 654: return DF_Type::export_map_type;
		case 655: return DF_Type::feature;
		case 656: return DF_Type::feature_alteration;
		case 657: return DF_Type::feature_alteration_new_lava_fill_zst;
		case 658: return DF_Type::feature_alteration_new_pop_maxst;
		case 659: return DF_Type::feature_alteration_type;
		case 660: return DF_Type::feature_cavest;
		case 661: return DF_Type::feature_deep_special_tubest;
		case 662: return DF_Type::feature_deep_surface_portalst;
		case 663: return DF_Type::feature_init;
		case 664: return DF_Type::feature_init_cavest;
		case 665: return DF_Type::feature_init_deep_special_tubest;
		case 666: return DF_Type::feature_init_deep_surface_portalst;
		case 667: return DF_Type::feature_init_flags;
		case 668: return DF_Type::feature_init_magma_core_from_layerst;
		case 669: return DF_Type::feature_init_magma_poolst;
		case 670: return DF_Type::feature_init_outdoor_riverst;
		case 671: return DF_Type::feature_init_pitst;
		case 672: return DF_Type::feature_init_subterranean_from_layerst;
		case 673: return DF_Type::feature_init_underworld_from_layerst;
		case 674: return DF_Type::feature_init_volcanost;
		case 675: return DF_Type::feature_magma_core_from_layerst;
		case 676: return DF_Type::feature_magma_poolst;
		case 677: return DF_Type::feature_outdoor_riverst;
		case 678: return DF_Type::feature_pitst;
		case 679: return DF_Type::feature_subterranean_from_layerst;
		case 680: return DF_Type::feature_type;
		case 681: return DF_Type::feature_underworld_from_layerst;
		case 682: return DF_Type::feature_volcanost;
		case 683: return DF_Type::file_compressorst;
		case 684: return DF_Type::fire;
		case 685: return DF_Type::flow_guide;
		case 686: return DF_Type::flow_guide_item_cloudst;
		case 687: return DF_Type::flow_guide_trailing_flowst;
		case 688: return DF_Type::flow_guide_type;
		case 689: return DF_Type::flow_info;
		case 690: return DF_Type::flow_reuse_pool;
		case 691: return DF_Type::flow_reuse_pool__T_flags;
		case 692: return DF_Type::flow_type;
		case 693: return DF_Type::fog_type;
		case 694: return DF_Type::fortress_type;
		case 695: return DF_Type::front_type;
		case 696: return DF_Type::furnace_type;
		case 697: return DF_Type::furniture_type;
		case 698: return DF_Type::gait_info;
		case 699: return DF_Type::gait_info__T_flags;
		case 700: return DF_Type::gait_type;
		case 701: return DF_Type::game_mode;
		case 702: return DF_Type::game_type;
		case 703: return DF_Type::gate_flags;
		case 704: return DF_Type::general_ref;
		case 705: return DF_Type::general_ref_abstract_buildingst;
		case 706: return DF_Type::general_ref_activity_eventst;
		case 707: return DF_Type::general_ref_artifact;
		case 708: return DF_Type::general_ref_building;
		case 709: return DF_Type::general_ref_building_cagedst;
		case 710: return DF_Type::general_ref_building_chainst;
		case 711: return DF_Type::general_ref_building_civzone_assignedst;
		case 712: return DF_Type::general_ref_building_destinationst;
		case 713: return DF_Type::general_ref_building_display_furniturest;
		case 714: return DF_Type::general_ref_building_holderst;
		case 715: return DF_Type::general_ref_building_nest_boxst;
		case 716: return DF_Type::general_ref_building_triggerst;
		case 717: return DF_Type::general_ref_building_triggertargetst;
		case 718: return DF_Type::general_ref_building_use_target_1st;
		case 719: return DF_Type::general_ref_building_use_target_2st;
		case 720: return DF_Type::general_ref_building_well_tag;
		case 721: return DF_Type::general_ref_coinbatch;
		case 722: return DF_Type::general_ref_contained_in_itemst;
		case 723: return DF_Type::general_ref_contains_itemst;
		case 724: return DF_Type::general_ref_contains_unitst;
		case 725: return DF_Type::general_ref_creaturest;
		case 726: return DF_Type::general_ref_creaturest__T_flags;
		case 727: return DF_Type::general_ref_dance_formst;
		case 728: return DF_Type::general_ref_entity;
		case 729: return DF_Type::general_ref_entity_art_image;
		case 730: return DF_Type::general_ref_entity_itemownerst;
		case 731: return DF_Type::general_ref_entity_offeredst;
		case 732: return DF_Type::general_ref_entity_popst;
		case 733: return DF_Type::general_ref_entity_popst__T_flags;
		case 734: return DF_Type::general_ref_entity_stolenst;
		case 735: return DF_Type::general_ref_feature_layerst;
		case 736: return DF_Type::general_ref_historical_eventst;
		case 737: return DF_Type::general_ref_historical_figurest;
		case 738: return DF_Type::general_ref_interactionst;
		case 739: return DF_Type::general_ref_is_artifactst;
		case 740: return DF_Type::general_ref_is_nemesisst;
		case 741: return DF_Type::general_ref_item;
		case 742: return DF_Type::general_ref_item_type;
		case 743: return DF_Type::general_ref_knowledge_scholar_flagst;
		case 744: return DF_Type::general_ref_languagest;
		case 745: return DF_Type::general_ref_locationst;
		case 746: return DF_Type::general_ref_mapsquare;
		case 747: return DF_Type::general_ref_musical_formst;
		case 748: return DF_Type::general_ref_nemesis;
		case 749: return DF_Type::general_ref_poetic_formst;
		case 750: return DF_Type::general_ref_projectile;
		case 751: return DF_Type::general_ref_sitest;
		case 752: return DF_Type::general_ref_spherest;
		case 753: return DF_Type::general_ref_subregionst;
		case 754: return DF_Type::general_ref_type;
		case 755: return DF_Type::general_ref_unit;
		case 756: return DF_Type::general_ref_unit_beateest;
		case 757: return DF_Type::general_ref_unit_cageest;
		case 758: return DF_Type::general_ref_unit_climberst;
		case 759: return DF_Type::general_ref_unit_foodreceiverst;
		case 760: return DF_Type::general_ref_unit_geldeest;
		case 761: return DF_Type::general_ref_unit_holderst;
		case 762: return DF_Type::general_ref_unit_infantst;
		case 763: return DF_Type::general_ref_unit_interrogateest;
		case 764: return DF_Type::general_ref_unit_itemownerst;
		case 765: return DF_Type::general_ref_unit_itemownerst__T_flags;
		case 766: return DF_Type::general_ref_unit_kidnapeest;
		case 767: return DF_Type::general_ref_unit_milkeest;
		case 768: return DF_Type::general_ref_unit_patientst;
		case 769: return DF_Type::general_ref_unit_reporteest;
		case 770: return DF_Type::general_ref_unit_riderst;
		case 771: return DF_Type::general_ref_unit_sheareest;
		case 772: return DF_Type::general_ref_unit_slaughtereest;
		case 773: return DF_Type::general_ref_unit_suckeest;
		case 774: return DF_Type::general_ref_unit_tradebringerst;
		case 775: return DF_Type::general_ref_unit_traineest;
		case 776: return DF_Type::general_ref_unit_workerst;
		case 777: return DF_Type::general_ref_value_levelst;
		case 778: return DF_Type::general_ref_written_contentst;
		case 779: return DF_Type::geo_layer_type;
		case 780: return DF_Type::ghost_goal;
		case 781: return DF_Type::ghost_type;
		case 782: return DF_Type::gloves_flags;
		case 783: return DF_Type::glowing_barrier;
		case 784: return DF_Type::goal_type;
		case 785: return DF_Type::graphic;
		case 786: return DF_Type::guild_id;
		case 787: return DF_Type::hauler_type;
		case 788: return DF_Type::hauling_route;
		case 789: return DF_Type::hauling_stop;
		case 790: return DF_Type::health_view_bits1;
		case 791: return DF_Type::health_view_bits2;
		case 792: return DF_Type::health_view_bits3;
		case 793: return DF_Type::helm_flags;
		case 794: return DF_Type::hillock_house_type;
		case 795: return DF_Type::histfig_body_state;
		case 796: return DF_Type::histfig_entity_link;
		case 797: return DF_Type::histfig_entity_link_criminalst;
		case 798: return DF_Type::histfig_entity_link_enemyst;
		case 799: return DF_Type::histfig_entity_link_former_memberst;
		case 800: return DF_Type::histfig_entity_link_former_mercenaryst;
		case 801: return DF_Type::histfig_entity_link_former_occupationst;
		case 802: return DF_Type::histfig_entity_link_former_positionst;
		case 803: return DF_Type::histfig_entity_link_former_prisonerst;
		case 804: return DF_Type::histfig_entity_link_former_slavest;
		case 805: return DF_Type::histfig_entity_link_former_squadst;
		case 806: return DF_Type::histfig_entity_link_memberst;
		case 807: return DF_Type::histfig_entity_link_mercenaryst;
		case 808: return DF_Type::histfig_entity_link_occupationst;
		case 809: return DF_Type::histfig_entity_link_position_claimst;
		case 810: return DF_Type::histfig_entity_link_positionst;
		case 811: return DF_Type::histfig_entity_link_prisonerst;
		case 812: return DF_Type::histfig_entity_link_slavest;
		case 813: return DF_Type::histfig_entity_link_squadst;
		case 814: return DF_Type::histfig_entity_link_type;
		case 815: return DF_Type::histfig_flags;
		case 816: return DF_Type::histfig_hf_link;
		case 817: return DF_Type::histfig_hf_link_apprenticest;
		case 818: return DF_Type::histfig_hf_link_childst;
		case 819: return DF_Type::histfig_hf_link_companionst;
		case 820: return DF_Type::histfig_hf_link_deceased_spousest;
		case 821: return DF_Type::histfig_hf_link_deityst;
		case 822: return DF_Type::histfig_hf_link_fatherst;
		case 823: return DF_Type::histfig_hf_link_former_apprenticest;
		case 824: return DF_Type::histfig_hf_link_former_masterst;
		case 825: return DF_Type::histfig_hf_link_former_spousest;
		case 826: return DF_Type::histfig_hf_link_imprisonerst;
		case 827: return DF_Type::histfig_hf_link_loverst;
		case 828: return DF_Type::histfig_hf_link_masterst;
		case 829: return DF_Type::histfig_hf_link_motherst;
		case 830: return DF_Type::histfig_hf_link_pet_ownerst;
		case 831: return DF_Type::histfig_hf_link_prisonerst;
		case 832: return DF_Type::histfig_hf_link_spousest;
		case 833: return DF_Type::histfig_hf_link_type;
		case 834: return DF_Type::histfig_relationship_type;
		case 835: return DF_Type::histfig_site_link;
		case 836: return DF_Type::histfig_site_link_hangoutst;
		case 837: return DF_Type::histfig_site_link_home_site_abstract_buildingst;
		case 838: return DF_Type::histfig_site_link_home_site_realization_buildingst;
		case 839: return DF_Type::histfig_site_link_home_site_realization_sulst;
		case 840: return DF_Type::histfig_site_link_home_site_saved_civzonest;
		case 841: return DF_Type::histfig_site_link_lairst;
		case 842: return DF_Type::histfig_site_link_occupationst;
		case 843: return DF_Type::histfig_site_link_prison_abstract_buildingst;
		case 844: return DF_Type::histfig_site_link_prison_site_building_profilest;
		case 845: return DF_Type::histfig_site_link_seat_of_powerst;
		case 846: return DF_Type::histfig_site_link_type;
		case 847: return DF_Type::historical_entity;
		case 848: return DF_Type::historical_entity__T_claims;
		case 849: return DF_Type::historical_entity__T_derived_resources;
		case 850: return DF_Type::historical_entity__T_flags;
		case 851: return DF_Type::historical_entity__T_guild_professions;
		case 852: return DF_Type::historical_entity__T_positions;
		case 853: return DF_Type::historical_entity__T_relations;
		case 854: return DF_Type::historical_entity__T_relations__T_constructions;
		case 855: return DF_Type::historical_entity__T_relations__T_diplomacy;
		case 856: return DF_Type::historical_entity__T_resources;
		case 857: return DF_Type::historical_entity__T_resources__T_animals;
		case 858: return DF_Type::historical_entity__T_resources__T_metal;
		case 859: return DF_Type::historical_entity__T_resources__T_misc_mat;
		case 860: return DF_Type::historical_entity__T_resources__T_organic;
		case 861: return DF_Type::historical_entity__T_resources__T_refuse;
		case 862: return DF_Type::historical_entity__T_resources__T_unk13;
		case 863: return DF_Type::historical_entity__T_resources__T_wood_products;
		case 864: return DF_Type::historical_entity__T_tissue_styles;
		case 865: return DF_Type::historical_entity__T_training_knowledge;
		case 866: return DF_Type::historical_entity__T_unk_v47_1;
		case 867: return DF_Type::historical_entity__T_unknown1d;
		case 868: return DF_Type::historical_entity__T_unknown1e;
		case 869: return DF_Type::historical_entity__T_unknown2;
		case 870: return DF_Type::historical_entity_type;
		case 871: return DF_Type::historical_figure;
		case 872: return DF_Type::historical_figure__T_unk_fc;
		case 873: return DF_Type::historical_figure__T_vague_relationships;
		case 874: return DF_Type::historical_figure_info;
		case 875: return DF_Type::historical_figure_info__T_books;
		case 876: return DF_Type::historical_figure_info__T_books__T_flags;
		case 877: return DF_Type::historical_figure_info__T_curse;
		case 878: return DF_Type::historical_figure_info__T_curse__T_anon_1;
		case 879: return DF_Type::historical_figure_info__T_curse__T_experiments;
		case 880: return DF_Type::historical_figure_info__T_known_info;
		case 881: return DF_Type::historical_figure_info__T_known_info__T_anon_1;
		case 882: return DF_Type::historical_figure_info__T_known_info__T_anon_6;
		case 883: return DF_Type::historical_figure_info__T_known_info__T_knowledge;
		case 884: return DF_Type::historical_figure_info__T_known_info__T_knowledge__T_knowledge_goal;
		case 885: return DF_Type::historical_figure_info__T_known_info__T_unk_a8;
		case 886: return DF_Type::historical_figure_info__T_masterpieces;
		case 887: return DF_Type::historical_figure_info__T_personality;
		case 888: return DF_Type::historical_figure_info__T_relationships;
		case 889: return DF_Type::historical_figure_info__T_relationships__T_anon_1;
		case 890: return DF_Type::historical_figure_info__T_relationships__T_artifact_claims;
		case 891: return DF_Type::historical_figure_info__T_relationships__T_hf_historical;
		case 892: return DF_Type::historical_figure_info__T_relationships__T_hf_visual;
		case 893: return DF_Type::historical_figure_info__T_relationships__T_intrigues;
		case 894: return DF_Type::historical_figure_info__T_relationships__T_intrigues__T_intrigue;
		case 895: return DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots;
		case 896: return DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data;
		case 897: return DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data__T_Infiltrate_Society;
		case 898: return DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data__T_Sabotage_Actor;
		case 899: return DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_type;
		case 900: return DF_Type::historical_figure_info__T_reputation;
		case 901: return DF_Type::historical_figure_info__T_reputation__T_anon_1;
		case 902: return DF_Type::historical_figure_info__T_reputation__T_unk_2c;
		case 903: return DF_Type::historical_figure_info__T_reputation__T_unk_2c__T_anon_12;
		case 904: return DF_Type::historical_figure_info__T_reputation__T_wanted;
		case 905: return DF_Type::historical_figure_info__T_reputation__T_wanted__T_unk;
		case 906: return DF_Type::historical_figure_info__T_skills;
		case 907: return DF_Type::historical_figure_info__T_skills__T_employment_held;
		case 908: return DF_Type::historical_figure_info__T_skills__T_employment_held__T_employment;
		case 909: return DF_Type::historical_figure_info__T_whereabouts;
		case 910: return DF_Type::historical_figure_info__T_wounds;
		case 911: return DF_Type::historical_kills;
		case 912: return DF_Type::historical_kills__T_killed_undead;
		case 913: return DF_Type::history_era;
		case 914: return DF_Type::history_era__T_details;
		case 915: return DF_Type::history_era__T_title;
		case 916: return DF_Type::history_event;
		case 917: return DF_Type::history_event_add_entity_site_profile_flagst;
		case 918: return DF_Type::history_event_add_hf_entity_honorst;
		case 919: return DF_Type::history_event_add_hf_entity_linkst;
		case 920: return DF_Type::history_event_add_hf_hf_linkst;
		case 921: return DF_Type::history_event_add_hf_site_linkst;
		case 922: return DF_Type::history_event_agreement_concludedst;
		case 923: return DF_Type::history_event_agreement_formedst;
		case 924: return DF_Type::history_event_agreements_voidedst;
		case 925: return DF_Type::history_event_artifact_claim_formedst;
		case 926: return DF_Type::history_event_artifact_copiedst;
		case 927: return DF_Type::history_event_artifact_copiedst__T_flags2;
		case 928: return DF_Type::history_event_artifact_createdst;
		case 929: return DF_Type::history_event_artifact_createdst__T_flags2;
		case 930: return DF_Type::history_event_artifact_destroyedst;
		case 931: return DF_Type::history_event_artifact_droppedst;
		case 932: return DF_Type::history_event_artifact_foundst;
		case 933: return DF_Type::history_event_artifact_givenst;
		case 934: return DF_Type::history_event_artifact_hiddenst;
		case 935: return DF_Type::history_event_artifact_lostst;
		case 936: return DF_Type::history_event_artifact_possessedst;
		case 937: return DF_Type::history_event_artifact_recoveredst;
		case 938: return DF_Type::history_event_artifact_storedst;
		case 939: return DF_Type::history_event_artifact_transformedst;
		case 940: return DF_Type::history_event_assume_identityst;
		case 941: return DF_Type::history_event_body_abusedst;
		case 942: return DF_Type::history_event_body_abusedst__T_abuse_data;
		case 943: return DF_Type::history_event_body_abusedst__T_abuse_data__T_Animated;
		case 944: return DF_Type::history_event_body_abusedst__T_abuse_data__T_Flayed;
		case 945: return DF_Type::history_event_body_abusedst__T_abuse_data__T_Hung;
		case 946: return DF_Type::history_event_body_abusedst__T_abuse_data__T_Impaled;
		case 947: return DF_Type::history_event_body_abusedst__T_abuse_data__T_Piled;
		case 948: return DF_Type::history_event_body_abusedst__T_abuse_data__T_Piled__T_pile_type;
		case 949: return DF_Type::history_event_body_abusedst__T_abuse_type;
		case 950: return DF_Type::history_event_building_profile_acquiredst;
		case 951: return DF_Type::history_event_ceremonyst;
		case 952: return DF_Type::history_event_change_creature_typest;
		case 953: return DF_Type::history_event_change_hf_body_statest;
		case 954: return DF_Type::history_event_change_hf_jobst;
		case 955: return DF_Type::history_event_change_hf_moodst;
		case 956: return DF_Type::history_event_change_hf_statest;
		case 957: return DF_Type::history_event_change_hf_statest__T_state;
		case 958: return DF_Type::history_event_circumstance_info;
		case 959: return DF_Type::history_event_circumstance_info__T_data;
		case 960: return DF_Type::history_event_collection;
		case 961: return DF_Type::history_event_collection_abductionst;
		case 962: return DF_Type::history_event_collection_battlest;
		case 963: return DF_Type::history_event_collection_beast_attackst;
		case 964: return DF_Type::history_event_collection_ceremonyst;
		case 965: return DF_Type::history_event_collection_competitionst;
		case 966: return DF_Type::history_event_collection_duelst;
		case 967: return DF_Type::history_event_collection_entity_overthrownst;
		case 968: return DF_Type::history_event_collection_insurrectionst;
		case 969: return DF_Type::history_event_collection_journeyst;
		case 970: return DF_Type::history_event_collection_occasionst;
		case 971: return DF_Type::history_event_collection_performancest;
		case 972: return DF_Type::history_event_collection_persecutionst;
		case 973: return DF_Type::history_event_collection_processionst;
		case 974: return DF_Type::history_event_collection_purgest;
		case 975: return DF_Type::history_event_collection_raidst;
		case 976: return DF_Type::history_event_collection_site_conqueredst;
		case 977: return DF_Type::history_event_collection_theftst;
		case 978: return DF_Type::history_event_collection_type;
		case 979: return DF_Type::history_event_collection_warst;
		case 980: return DF_Type::history_event_collection_warst__T_unk;
		case 981: return DF_Type::history_event_competitionst;
		case 982: return DF_Type::history_event_context;
		case 983: return DF_Type::history_event_context__T_unk_10;
		case 984: return DF_Type::history_event_create_entity_positionst;
		case 985: return DF_Type::history_event_created_buildingst;
		case 986: return DF_Type::history_event_created_sitest;
		case 987: return DF_Type::history_event_created_world_constructionst;
		case 988: return DF_Type::history_event_creature_devouredst;
		case 989: return DF_Type::history_event_dance_form_createdst;
		case 990: return DF_Type::history_event_diplomat_lostst;
		case 991: return DF_Type::history_event_entity_actionst;
		case 992: return DF_Type::history_event_entity_alliance_formedst;
		case 993: return DF_Type::history_event_entity_breach_feature_layerst;
		case 994: return DF_Type::history_event_entity_createdst;
		case 995: return DF_Type::history_event_entity_dissolvedst;
		case 996: return DF_Type::history_event_entity_equipment_purchasest;
		case 997: return DF_Type::history_event_entity_expels_hfst;
		case 998: return DF_Type::history_event_entity_fled_sitest;
		case 999: return DF_Type::history_event_entity_incorporatedst;
		case 1000: return DF_Type::history_event_entity_lawst;
		case 1001: return DF_Type::history_event_entity_lawst__T_add_flags;
		case 1002: return DF_Type::history_event_entity_lawst__T_remove_flags;
		case 1003: return DF_Type::history_event_entity_overthrownst;
		case 1004: return DF_Type::history_event_entity_persecutedst;
		case 1005: return DF_Type::history_event_entity_rampaged_in_sitest;
		case 1006: return DF_Type::history_event_entity_razed_buildingst;
		case 1007: return DF_Type::history_event_entity_searched_sitest;
		case 1008: return DF_Type::history_event_failed_frame_attemptst;
		case 1009: return DF_Type::history_event_failed_intrigue_corruptionst;
		case 1010: return DF_Type::history_event_first_contact_failedst;
		case 1011: return DF_Type::history_event_first_contactst;
		case 1012: return DF_Type::history_event_flags;
		case 1013: return DF_Type::history_event_gamblest;
		case 1014: return DF_Type::history_event_hf_act_on_artifactst;
		case 1015: return DF_Type::history_event_hf_act_on_artifactst__T_action;
		case 1016: return DF_Type::history_event_hf_act_on_buildingst;
		case 1017: return DF_Type::history_event_hf_act_on_buildingst__T_action;
		case 1018: return DF_Type::history_event_hf_attacked_sitest;
		case 1019: return DF_Type::history_event_hf_confrontedst;
		case 1020: return DF_Type::history_event_hf_convictedst;
		case 1021: return DF_Type::history_event_hf_convictedst__T_plot_flags;
		case 1022: return DF_Type::history_event_hf_convictedst__T_punishment_flags;
		case 1023: return DF_Type::history_event_hf_destroyed_sitest;
		case 1024: return DF_Type::history_event_hf_does_interactionst;
		case 1025: return DF_Type::history_event_hf_enslavedst;
		case 1026: return DF_Type::history_event_hf_freedst;
		case 1027: return DF_Type::history_event_hf_gains_secret_goalst;
		case 1028: return DF_Type::history_event_hf_interrogatedst;
		case 1029: return DF_Type::history_event_hf_interrogatedst__T_interrogation_flags;
		case 1030: return DF_Type::history_event_hf_learns_secretst;
		case 1031: return DF_Type::history_event_hf_preachst;
		case 1032: return DF_Type::history_event_hf_ransomedst;
		case 1033: return DF_Type::history_event_hf_razed_buildingst;
		case 1034: return DF_Type::history_event_hf_recruited_unit_type_for_entityst;
		case 1035: return DF_Type::history_event_hf_relationship_deniedst;
		case 1036: return DF_Type::history_event_hfs_formed_intrigue_relationshipst;
		case 1037: return DF_Type::history_event_hfs_formed_reputation_relationshipst;
		case 1038: return DF_Type::history_event_hist_figure_abductedst;
		case 1039: return DF_Type::history_event_hist_figure_diedst;
		case 1040: return DF_Type::history_event_hist_figure_new_petst;
		case 1041: return DF_Type::history_event_hist_figure_reach_summitst;
		case 1042: return DF_Type::history_event_hist_figure_reunionst;
		case 1043: return DF_Type::history_event_hist_figure_revivedst;
		case 1044: return DF_Type::history_event_hist_figure_revivedst__T_flags2;
		case 1045: return DF_Type::history_event_hist_figure_simple_actionst;
		case 1046: return DF_Type::history_event_hist_figure_simple_battle_eventst;
		case 1047: return DF_Type::history_event_hist_figure_travelst;
		case 1048: return DF_Type::history_event_hist_figure_travelst__T_reason;
		case 1049: return DF_Type::history_event_hist_figure_woundedst;
		case 1050: return DF_Type::history_event_hist_figure_woundedst__T_flags2;
		case 1051: return DF_Type::history_event_hist_figure_woundedst__T_injury_type;
		case 1052: return DF_Type::history_event_insurrection_endedst;
		case 1053: return DF_Type::history_event_insurrection_startedst;
		case 1054: return DF_Type::history_event_item_stolenst;
		case 1055: return DF_Type::history_event_knowledge_discoveredst;
		case 1056: return DF_Type::history_event_masterpiece_created_arch_constructst;
		case 1057: return DF_Type::history_event_masterpiece_created_arch_designst;
		case 1058: return DF_Type::history_event_masterpiece_created_dye_itemst;
		case 1059: return DF_Type::history_event_masterpiece_created_engravingst;
		case 1060: return DF_Type::history_event_masterpiece_created_foodst;
		case 1061: return DF_Type::history_event_masterpiece_created_item_improvementst;
		case 1062: return DF_Type::history_event_masterpiece_created_itemst;
		case 1063: return DF_Type::history_event_masterpiece_createdst;
		case 1064: return DF_Type::history_event_masterpiece_lostst;
		case 1065: return DF_Type::history_event_merchantst;
		case 1066: return DF_Type::history_event_modified_buildingst;
		case 1067: return DF_Type::history_event_modified_buildingst__T_modification;
		case 1068: return DF_Type::history_event_musical_form_createdst;
		case 1069: return DF_Type::history_event_performancest;
		case 1070: return DF_Type::history_event_poetic_form_createdst;
		case 1071: return DF_Type::history_event_processionst;
		case 1072: return DF_Type::history_event_reason;
		case 1073: return DF_Type::history_event_reason_info;
		case 1074: return DF_Type::history_event_reason_info__T_data;
		case 1075: return DF_Type::history_event_reclaim_sitest;
		case 1076: return DF_Type::history_event_reclaim_sitest__T_flags2;
		case 1077: return DF_Type::history_event_regionpop_incorporated_into_entityst;
		case 1078: return DF_Type::history_event_remove_hf_entity_linkst;
		case 1079: return DF_Type::history_event_remove_hf_hf_linkst;
		case 1080: return DF_Type::history_event_remove_hf_site_linkst;
		case 1081: return DF_Type::history_event_replaced_buildingst;
		case 1082: return DF_Type::history_event_sabotagest;
		case 1083: return DF_Type::history_event_simple_battle_subtype;
		case 1084: return DF_Type::history_event_site_diedst;
		case 1085: return DF_Type::history_event_site_diedst__T_flags2;
		case 1086: return DF_Type::history_event_site_disputest;
		case 1087: return DF_Type::history_event_site_retiredst;
		case 1088: return DF_Type::history_event_site_retiredst__T_flags2;
		case 1089: return DF_Type::history_event_site_surrenderedst;
		case 1090: return DF_Type::history_event_sneak_into_sitest;
		case 1091: return DF_Type::history_event_spotted_leaving_sitest;
		case 1092: return DF_Type::history_event_squad_vs_squadst;
		case 1093: return DF_Type::history_event_tactical_situationst;
		case 1094: return DF_Type::history_event_tactical_situationst__T_tactics_flags;
		case 1095: return DF_Type::history_event_topicagreement_concludedst;
		case 1096: return DF_Type::history_event_topicagreement_madest;
		case 1097: return DF_Type::history_event_topicagreement_rejectedst;
		case 1098: return DF_Type::history_event_tradest;
		case 1099: return DF_Type::history_event_type;
		case 1100: return DF_Type::history_event_war_attacked_sitest;
		case 1101: return DF_Type::history_event_war_destroyed_sitest;
		case 1102: return DF_Type::history_event_war_field_battlest;
		case 1103: return DF_Type::history_event_war_peace_acceptedst;
		case 1104: return DF_Type::history_event_war_peace_rejectedst;
		case 1105: return DF_Type::history_event_war_plundered_sitest;
		case 1106: return DF_Type::history_event_war_site_new_leaderst;
		case 1107: return DF_Type::history_event_war_site_taken_overst;
		case 1108: return DF_Type::history_event_war_site_tribute_forcedst;
		case 1109: return DF_Type::history_event_war_site_tribute_forcedst__T_tribute_flags;
		case 1110: return DF_Type::history_event_written_content_composedst;
		case 1111: return DF_Type::history_hit_item;
		case 1112: return DF_Type::hive_flags;
		case 1113: return DF_Type::honors_type;
		case 1114: return DF_Type::honors_type__T_flags;
		case 1115: return DF_Type::honors_type__T_required_skill_type;
		case 1116: return DF_Type::hospital_supplies;
		case 1117: return DF_Type::hospital_supplies__T_supplies_needed;
		case 1118: return DF_Type::identity;
		case 1119: return DF_Type::identity_unk_94;
		case 1120: return DF_Type::improvement_type;
		case 1121: return DF_Type::incident;
		case 1122: return DF_Type::incident__T_data;
		case 1123: return DF_Type::incident__T_flags;
		case 1124: return DF_Type::incident__T_type;
		case 1125: return DF_Type::incident_hfid;
		case 1126: return DF_Type::incident_sub10;
		case 1127: return DF_Type::incident_sub6_performance;
		case 1128: return DF_Type::incident_sub6_performance__T_participants;
		case 1129: return DF_Type::incident_sub7;
		case 1130: return DF_Type::incident_sub8;
		case 1131: return DF_Type::incident_sub9;
		case 1132: return DF_Type::inclusion_type;
		case 1133: return DF_Type::init;
		case 1134: return DF_Type::init_display;
		case 1135: return DF_Type::init_display__T_windowed;
		case 1136: return DF_Type::init_display_flags;
		case 1137: return DF_Type::init_font;
		case 1138: return DF_Type::init_font__T_use_ttf;
		case 1139: return DF_Type::init_input;
		case 1140: return DF_Type::init_input_flags;
		case 1141: return DF_Type::init_media;
		case 1142: return DF_Type::init_media_flags;
		case 1143: return DF_Type::init_window;
		case 1144: return DF_Type::init_window_flags;
		case 1145: return DF_Type::inorganic_flags;
		case 1146: return DF_Type::inorganic_raw;
		case 1147: return DF_Type::inorganic_raw__T_environment;
		case 1148: return DF_Type::inorganic_raw__T_environment_spec;
		case 1149: return DF_Type::inorganic_raw__T_metal_ore;
		case 1150: return DF_Type::inorganic_raw__T_thread_metal;
		case 1151: return DF_Type::instrument_flags;
		case 1152: return DF_Type::instrument_piece;
		case 1153: return DF_Type::instrument_piece__T_flags;
		case 1154: return DF_Type::instrument_register;
		case 1155: return DF_Type::insurrection_outcome;
		case 1156: return DF_Type::interaction;
		case 1157: return DF_Type::interaction_effect;
		case 1158: return DF_Type::interaction_effect__T_flags;
		case 1159: return DF_Type::interaction_effect_add_syndromest;
		case 1160: return DF_Type::interaction_effect_animatest;
		case 1161: return DF_Type::interaction_effect_change_item_qualityst;
		case 1162: return DF_Type::interaction_effect_change_weatherst;
		case 1163: return DF_Type::interaction_effect_cleanst;
		case 1164: return DF_Type::interaction_effect_contactst;
		case 1165: return DF_Type::interaction_effect_create_itemst;
		case 1166: return DF_Type::interaction_effect_hidest;
		case 1167: return DF_Type::interaction_effect_location_hint;
		case 1168: return DF_Type::interaction_effect_material_emissionst;
		case 1169: return DF_Type::interaction_effect_propel_unitst;
		case 1170: return DF_Type::interaction_effect_resurrectst;
		case 1171: return DF_Type::interaction_effect_summon_unitst;
		case 1172: return DF_Type::interaction_effect_type;
		case 1173: return DF_Type::interaction_flags;
		case 1174: return DF_Type::interaction_instance;
		case 1175: return DF_Type::interaction_source;
		case 1176: return DF_Type::interaction_source_attackst;
		case 1177: return DF_Type::interaction_source_creature_actionst;
		case 1178: return DF_Type::interaction_source_deityst;
		case 1179: return DF_Type::interaction_source_disturbancest;
		case 1180: return DF_Type::interaction_source_experimentst;
		case 1181: return DF_Type::interaction_source_ingestionst;
		case 1182: return DF_Type::interaction_source_regionst;
		case 1183: return DF_Type::interaction_source_regionst__T_region_flags;
		case 1184: return DF_Type::interaction_source_secretst;
		case 1185: return DF_Type::interaction_source_secretst__T_learn_flags;
		case 1186: return DF_Type::interaction_source_type;
		case 1187: return DF_Type::interaction_source_underground_specialst;
		case 1188: return DF_Type::interaction_source_usage_hint;
		case 1189: return DF_Type::interaction_target;
		case 1190: return DF_Type::interaction_target_corpsest;
		case 1191: return DF_Type::interaction_target_creaturest;
		case 1192: return DF_Type::interaction_target_info;
		case 1193: return DF_Type::interaction_target_info__T_restrictions;
		case 1194: return DF_Type::interaction_target_location_type;
		case 1195: return DF_Type::interaction_target_locationst;
		case 1196: return DF_Type::interaction_target_materialst;
		case 1197: return DF_Type::interaction_target_materialst__T_restrictions;
		case 1198: return DF_Type::interaction_target_type;
		case 1199: return DF_Type::interface_breakdown_types;
		case 1200: return DF_Type::interface_button;
		case 1201: return DF_Type::interface_button_building_category_selectorst;
		case 1202: return DF_Type::interface_button_building_custom_category_selectorst;
		case 1203: return DF_Type::interface_button_building_material_selectorst;
		case 1204: return DF_Type::interface_button_building_new_jobst;
		case 1205: return DF_Type::interface_button_buildingst;
		case 1206: return DF_Type::interface_button_construction_building_selectorst;
		case 1207: return DF_Type::interface_button_construction_category_selectorst;
		case 1208: return DF_Type::interface_button_construction_category_selectorst__T_category_id;
		case 1209: return DF_Type::interface_button_construction_donest;
		case 1210: return DF_Type::interface_button_constructionst;
		case 1211: return DF_Type::interface_key;
		case 1212: return DF_Type::interfacest;
		case 1213: return DF_Type::invasion_info;
		case 1214: return DF_Type::invasion_info__T_flags;
		case 1215: return DF_Type::item;
		case 1216: return DF_Type::item_actual;
		case 1217: return DF_Type::item_ammost;
		case 1218: return DF_Type::item_amuletst;
		case 1219: return DF_Type::item_animaltrapst;
		case 1220: return DF_Type::item_anvilst;
		case 1221: return DF_Type::item_armorst;
		case 1222: return DF_Type::item_armorstandst;
		case 1223: return DF_Type::item_backpackst;
		case 1224: return DF_Type::item_ballistaarrowheadst;
		case 1225: return DF_Type::item_ballistapartsst;
		case 1226: return DF_Type::item_barrelst;
		case 1227: return DF_Type::item_barst;
		case 1228: return DF_Type::item_bedst;
		case 1229: return DF_Type::item_binst;
		case 1230: return DF_Type::item_blocksst;
		case 1231: return DF_Type::item_body_component;
		case 1232: return DF_Type::item_body_component__T_appearance;
		case 1233: return DF_Type::item_body_component__T_body;
		case 1234: return DF_Type::item_body_component__T_bone1;
		case 1235: return DF_Type::item_body_component__T_bone2;
		case 1236: return DF_Type::item_body_component__T_corpse_flags;
		case 1237: return DF_Type::item_bookst;
		case 1238: return DF_Type::item_boulderst;
		case 1239: return DF_Type::item_boxst;
		case 1240: return DF_Type::item_braceletst;
		case 1241: return DF_Type::item_branchst;
		case 1242: return DF_Type::item_bucketst;
		case 1243: return DF_Type::item_cabinetst;
		case 1244: return DF_Type::item_cagest;
		case 1245: return DF_Type::item_catapultpartsst;
		case 1246: return DF_Type::item_chainst;
		case 1247: return DF_Type::item_chairst;
		case 1248: return DF_Type::item_cheesest;
		case 1249: return DF_Type::item_clothst;
		case 1250: return DF_Type::item_coffinst;
		case 1251: return DF_Type::item_coinst;
		case 1252: return DF_Type::item_constructed;
		case 1253: return DF_Type::item_corpsepiecest;
		case 1254: return DF_Type::item_corpsest;
		case 1255: return DF_Type::item_crafted;
		case 1256: return DF_Type::item_critter;
		case 1257: return DF_Type::item_crownst;
		case 1258: return DF_Type::item_crutchst;
		case 1259: return DF_Type::item_doorst;
		case 1260: return DF_Type::item_drinkst;
		case 1261: return DF_Type::item_earringst;
		case 1262: return DF_Type::item_eggst;
		case 1263: return DF_Type::item_eggst__T_egg_flags;
		case 1264: return DF_Type::item_figurinest;
		case 1265: return DF_Type::item_filter_spec;
		case 1266: return DF_Type::item_fish_rawst;
		case 1267: return DF_Type::item_fishst;
		case 1268: return DF_Type::item_flags;
		case 1269: return DF_Type::item_flags2;
		case 1270: return DF_Type::item_flaskst;
		case 1271: return DF_Type::item_floodgatest;
		case 1272: return DF_Type::item_foodst;
		case 1273: return DF_Type::item_foodst__T_ingredients;
		case 1274: return DF_Type::item_gemst;
		case 1275: return DF_Type::item_globst;
		case 1276: return DF_Type::item_glovesst;
		case 1277: return DF_Type::item_gobletst;
		case 1278: return DF_Type::item_gratest;
		case 1279: return DF_Type::item_hatch_coverst;
		case 1280: return DF_Type::item_helmst;
		case 1281: return DF_Type::item_history_info;
		case 1282: return DF_Type::item_instrumentst;
		case 1283: return DF_Type::item_kill_info;
		case 1284: return DF_Type::item_liquid;
		case 1285: return DF_Type::item_liquid_miscst;
		case 1286: return DF_Type::item_liquipowder;
		case 1287: return DF_Type::item_magicness;
		case 1288: return DF_Type::item_magicness_type;
		case 1289: return DF_Type::item_matstate;
		case 1290: return DF_Type::item_meatst;
		case 1291: return DF_Type::item_millstonest;
		case 1292: return DF_Type::item_orthopedic_castst;
		case 1293: return DF_Type::item_pantsst;
		case 1294: return DF_Type::item_petst;
		case 1295: return DF_Type::item_petst__T_pet_flags;
		case 1296: return DF_Type::item_pipe_sectionst;
		case 1297: return DF_Type::item_plant_growthst;
		case 1298: return DF_Type::item_plantst;
		case 1299: return DF_Type::item_powder;
		case 1300: return DF_Type::item_powder_miscst;
		case 1301: return DF_Type::item_quality;
		case 1302: return DF_Type::item_quernst;
		case 1303: return DF_Type::item_quiverst;
		case 1304: return DF_Type::item_remainsst;
		case 1305: return DF_Type::item_ringst;
		case 1306: return DF_Type::item_rockst;
		case 1307: return DF_Type::item_roughst;
		case 1308: return DF_Type::item_scepterst;
		case 1309: return DF_Type::item_seedsst;
		case 1310: return DF_Type::item_sheetst;
		case 1311: return DF_Type::item_shieldst;
		case 1312: return DF_Type::item_shoesst;
		case 1313: return DF_Type::item_siegeammost;
		case 1314: return DF_Type::item_skin_tannedst;
		case 1315: return DF_Type::item_slabst;
		case 1316: return DF_Type::item_smallgemst;
		case 1317: return DF_Type::item_splintst;
		case 1318: return DF_Type::item_statuest;
		case 1319: return DF_Type::item_stockpile_ref;
		case 1320: return DF_Type::item_tablest;
		case 1321: return DF_Type::item_threadst;
		case 1322: return DF_Type::item_toolst;
		case 1323: return DF_Type::item_totemst;
		case 1324: return DF_Type::item_toyst;
		case 1325: return DF_Type::item_traction_benchst;
		case 1326: return DF_Type::item_trapcompst;
		case 1327: return DF_Type::item_trappartsst;
		case 1328: return DF_Type::item_type;
		case 1329: return DF_Type::item_verminst;
		case 1330: return DF_Type::item_weaponrackst;
		case 1331: return DF_Type::item_weaponst;
		case 1332: return DF_Type::item_windowst;
		case 1333: return DF_Type::item_woodst;
		case 1334: return DF_Type::itemdef;
		case 1335: return DF_Type::itemdef_ammost;
		case 1336: return DF_Type::itemdef_armorst;
		case 1337: return DF_Type::itemdef_foodst;
		case 1338: return DF_Type::itemdef_glovesst;
		case 1339: return DF_Type::itemdef_helmst;
		case 1340: return DF_Type::itemdef_instrumentst;
		case 1341: return DF_Type::itemdef_pantsst;
		case 1342: return DF_Type::itemdef_shieldst;
		case 1343: return DF_Type::itemdef_shoesst;
		case 1344: return DF_Type::itemdef_siegeammost;
		case 1345: return DF_Type::itemdef_toolst;
		case 1346: return DF_Type::itemdef_toolst__T_default_improvements;
		case 1347: return DF_Type::itemdef_toyst;
		case 1348: return DF_Type::itemdef_trapcompst;
		case 1349: return DF_Type::itemdef_weaponst;
		case 1350: return DF_Type::itemimprovement;
		case 1351: return DF_Type::itemimprovement_art_imagest;
		case 1352: return DF_Type::itemimprovement_bandsst;
		case 1353: return DF_Type::itemimprovement_clothst;
		case 1354: return DF_Type::itemimprovement_coveredst;
		case 1355: return DF_Type::itemimprovement_coveredst__T_cover_flags;
		case 1356: return DF_Type::itemimprovement_illustrationst;
		case 1357: return DF_Type::itemimprovement_instrument_piecest;
		case 1358: return DF_Type::itemimprovement_itemspecificst;
		case 1359: return DF_Type::itemimprovement_pagesst;
		case 1360: return DF_Type::itemimprovement_rings_hangingst;
		case 1361: return DF_Type::itemimprovement_sewn_imagest;
		case 1362: return DF_Type::itemimprovement_sewn_imagest__T_cloth;
		case 1363: return DF_Type::itemimprovement_specific_type;
		case 1364: return DF_Type::itemimprovement_spikesst;
		case 1365: return DF_Type::itemimprovement_threadst;
		case 1366: return DF_Type::itemimprovement_writingst;
		case 1367: return DF_Type::items_other_id;
		case 1368: return DF_Type::job;
		case 1369: return DF_Type::job_art_specification;
		case 1370: return DF_Type::job_art_specification__T_type;
		case 1371: return DF_Type::job_flags;
		case 1372: return DF_Type::job_handler;
		case 1373: return DF_Type::job_handler__T_anon_1;
		case 1374: return DF_Type::job_handler__T_postings;
		case 1375: return DF_Type::job_handler__T_postings__T_flags;
		case 1376: return DF_Type::job_item;
		case 1377: return DF_Type::job_item_filter;
		case 1378: return DF_Type::job_item_flags1;
		case 1379: return DF_Type::job_item_flags2;
		case 1380: return DF_Type::job_item_flags3;
		case 1381: return DF_Type::job_item_ref;
		case 1382: return DF_Type::job_item_ref__T_role;
		case 1383: return DF_Type::job_item_vector_id;
		case 1384: return DF_Type::job_list_link;
		case 1385: return DF_Type::job_material_category;
		case 1386: return DF_Type::job_skill;
		case 1387: return DF_Type::job_skill_class;
		case 1388: return DF_Type::job_subtype_surgery;
		case 1389: return DF_Type::job_type;
		case 1390: return DF_Type::job_type_class;
		case 1391: return DF_Type::KeybindingScreen;
		case 1392: return DF_Type::KeybindingScreen__T_mode;
		case 1393: return DF_Type::kitchen_exc_type;
		case 1394: return DF_Type::kitchen_pref_flag;
		case 1395: return DF_Type::knowledge_scholar_category_flag;
		case 1396: return DF_Type::knowledge_scholar_category_flag__T_flag_data;
		case 1397: return DF_Type::knowledge_scholar_category_flag__T_flag_type;
		case 1398: return DF_Type::knowledge_scholar_flags_0;
		case 1399: return DF_Type::knowledge_scholar_flags_1;
		case 1400: return DF_Type::knowledge_scholar_flags_10;
		case 1401: return DF_Type::knowledge_scholar_flags_11;
		case 1402: return DF_Type::knowledge_scholar_flags_12;
		case 1403: return DF_Type::knowledge_scholar_flags_13;
		case 1404: return DF_Type::knowledge_scholar_flags_2;
		case 1405: return DF_Type::knowledge_scholar_flags_3;
		case 1406: return DF_Type::knowledge_scholar_flags_4;
		case 1407: return DF_Type::knowledge_scholar_flags_5;
		case 1408: return DF_Type::knowledge_scholar_flags_6;
		case 1409: return DF_Type::knowledge_scholar_flags_7;
		case 1410: return DF_Type::knowledge_scholar_flags_8;
		case 1411: return DF_Type::knowledge_scholar_flags_9;
		case 1412: return DF_Type::lair_type;
		case 1413: return DF_Type::language_name;
		case 1414: return DF_Type::language_name_category;
		case 1415: return DF_Type::language_symbol;
		case 1416: return DF_Type::language_translation;
		case 1417: return DF_Type::language_word;
		case 1418: return DF_Type::language_word_flags;
		case 1419: return DF_Type::language_word_table;
		case 1420: return DF_Type::large_integer;
		case 1421: return DF_Type::large_integer___struct0;
		case 1422: return DF_Type::large_integer__T_u;
		case 1423: return DF_Type::layer_object;
		case 1424: return DF_Type::layer_object_buttonst;
		case 1425: return DF_Type::layer_object_listst;
		case 1426: return DF_Type::layer_type;
		case 1427: return DF_Type::lever_target_type;
		case 1428: return DF_Type::loadgame_save_info;
		case 1429: return DF_Type::local_population;
		case 1430: return DF_Type::local_population___union3;
		case 1431: return DF_Type::local_population__T_flags;
		case 1432: return DF_Type::location_scribe_jobs;
		case 1433: return DF_Type::machine;
		case 1434: return DF_Type::machine__T_components;
		case 1435: return DF_Type::machine__T_flags;
		case 1436: return DF_Type::machine_conn_modes;
		case 1437: return DF_Type::machine_handler;
		case 1438: return DF_Type::machine_info;
		case 1439: return DF_Type::machine_info__T_flags;
		case 1440: return DF_Type::machine_standardst;
		case 1441: return DF_Type::machine_tile_set;
		case 1442: return DF_Type::machine_type;
		case 1443: return DF_Type::MacroScreenLoad;
		case 1444: return DF_Type::MacroScreenSave;
		case 1445: return DF_Type::manager_order;
		case 1446: return DF_Type::manager_order__T_frequency;
		case 1447: return DF_Type::manager_order_condition_item;
		case 1448: return DF_Type::manager_order_condition_item__T_compare_type;
		case 1449: return DF_Type::manager_order_condition_order;
		case 1450: return DF_Type::manager_order_condition_order__T_condition;
		case 1451: return DF_Type::manager_order_status;
		case 1452: return DF_Type::manager_order_template;
		case 1453: return DF_Type::mandate;
		case 1454: return DF_Type::mandate__T_mode;
		case 1455: return DF_Type::mandate__T_punishment;
		case 1456: return DF_Type::map_block;
		case 1457: return DF_Type::map_block_column;
		case 1458: return DF_Type::map_block_column__T_unmined_glyphs;
		case 1459: return DF_Type::map_renderer;
		case 1460: return DF_Type::map_renderer__T_anon_4;
		case 1461: return DF_Type::map_viewport;
		case 1462: return DF_Type::masterpiece_loss_type;
		case 1463: return DF_Type::material;
		case 1464: return DF_Type::material_common;
		case 1465: return DF_Type::material_common__T_hardens_with_water;
		case 1466: return DF_Type::material_common__T_heat;
		case 1467: return DF_Type::material_common__T_reaction_product;
		case 1468: return DF_Type::material_common__T_strength;
		case 1469: return DF_Type::material_flags;
		case 1470: return DF_Type::material_template;
		case 1471: return DF_Type::material_vec_ref;
		case 1472: return DF_Type::matgloss_list;
		case 1473: return DF_Type::matgloss_list__T_unk_0;
		case 1474: return DF_Type::matter_state;
		case 1475: return DF_Type::meeting_context;
		case 1476: return DF_Type::meeting_diplomat_info;
		case 1477: return DF_Type::meeting_diplomat_info__T_flags;
		case 1478: return DF_Type::meeting_event;
		case 1479: return DF_Type::meeting_event_type;
		case 1480: return DF_Type::meeting_topic;
		case 1481: return DF_Type::meeting_variable;
		case 1482: return DF_Type::mental_attribute_type;
		case 1483: return DF_Type::mental_picture;
		case 1484: return DF_Type::mental_picture__T_unk;
		case 1485: return DF_Type::mental_picture_element_hfst;
		case 1486: return DF_Type::mental_picture_element_regionst;
		case 1487: return DF_Type::mental_picture_element_sitest;
		case 1488: return DF_Type::mental_picture_element_type;
		case 1489: return DF_Type::mental_picture_elementst;
		case 1490: return DF_Type::mental_picture_property_actionst;
		case 1491: return DF_Type::mental_picture_property_adjectivest;
		case 1492: return DF_Type::mental_picture_property_color_patternst;
		case 1493: return DF_Type::mental_picture_property_datest;
		case 1494: return DF_Type::mental_picture_property_emotionst;
		case 1495: return DF_Type::mental_picture_property_positionst;
		case 1496: return DF_Type::mental_picture_property_shapest;
		case 1497: return DF_Type::mental_picture_property_timest;
		case 1498: return DF_Type::mental_picture_property_toolst;
		case 1499: return DF_Type::mental_picture_property_type;
		case 1500: return DF_Type::mental_picture_propertyst;
		case 1501: return DF_Type::misc_trait_type;
		case 1502: return DF_Type::mission;
		case 1503: return DF_Type::mission__T_details;
		case 1504: return DF_Type::mission__T_details__T_raid;
		case 1505: return DF_Type::mission__T_details__T_raid__T_raid_flags;
		case 1506: return DF_Type::mission__T_details__T_raid__T_raid_type;
		case 1507: return DF_Type::mission__T_details__T_recovery;
		case 1508: return DF_Type::mission__T_details__T_request;
		case 1509: return DF_Type::mission__T_details__T_rescue;
		case 1510: return DF_Type::mission__T_type;
		case 1511: return DF_Type::mission_campaign_report;
		case 1512: return DF_Type::mission_report;
		case 1513: return DF_Type::monument_type;
		case 1514: return DF_Type::mood_type;
		case 1515: return DF_Type::mountain_peak_flags;
		case 1516: return DF_Type::moving_party;
		case 1517: return DF_Type::moving_party__T_members;
		case 1518: return DF_Type::musical_form;
		case 1519: return DF_Type::musical_form__T_flags;
		case 1520: return DF_Type::musical_form_feature;
		case 1521: return DF_Type::musical_form_instruments;
		case 1522: return DF_Type::musical_form_instruments__T_substitutions;
		case 1523: return DF_Type::musical_form_interval;
		case 1524: return DF_Type::musical_form_interval__T_flags;
		case 1525: return DF_Type::musical_form_melodies;
		case 1526: return DF_Type::musical_form_pitch_style;
		case 1527: return DF_Type::musical_form_purpose;
		case 1528: return DF_Type::musical_form_style;
		case 1529: return DF_Type::musical_form_sub4;
		case 1530: return DF_Type::musical_form_vocals;
		case 1531: return DF_Type::need_type;
		case 1532: return DF_Type::nemesis_flags;
		case 1533: return DF_Type::nemesis_offload;
		case 1534: return DF_Type::nemesis_record;
		case 1535: return DF_Type::next_global_id;
		case 1536: return DF_Type::occasion_schedule_feature;
		case 1537: return DF_Type::occasion_schedule_type;
		case 1538: return DF_Type::occupation;
		case 1539: return DF_Type::occupation_sub1;
		case 1540: return DF_Type::occupation_type;
		case 1541: return DF_Type::ocean_wave;
		case 1542: return DF_Type::organic_mat_category;
		case 1543: return DF_Type::orientation_flags;
		case 1544: return DF_Type::pants_flags;
		case 1545: return DF_Type::part_of_speech;
		case 1546: return DF_Type::party_info;
		case 1547: return DF_Type::pattern_type;
		case 1548: return DF_Type::performance_event_type;
		case 1549: return DF_Type::performance_participant_type;
		case 1550: return DF_Type::performance_play_orderst;
		case 1551: return DF_Type::performance_play_orderst__T_anon_4;
		case 1552: return DF_Type::personality_facet_type;
		case 1553: return DF_Type::physical_attribute_type;
		case 1554: return DF_Type::pitch_choice_type;
		case 1555: return DF_Type::plant;
		case 1556: return DF_Type::plant__T_damage_flags;
		case 1557: return DF_Type::plant_flags;
		case 1558: return DF_Type::plant_growth;
		case 1559: return DF_Type::plant_growth__T_behavior;
		case 1560: return DF_Type::plant_growth__T_locations;
		case 1561: return DF_Type::plant_growth_print;
		case 1562: return DF_Type::plant_raw;
		case 1563: return DF_Type::plant_raw__T_colors;
		case 1564: return DF_Type::plant_raw__T_material_defs;
		case 1565: return DF_Type::plant_raw__T_stockpile_growth_flags;
		case 1566: return DF_Type::plant_raw__T_tiles;
		case 1567: return DF_Type::plant_raw_flags;
		case 1568: return DF_Type::plant_tree_info;
		case 1569: return DF_Type::plant_tree_tile;
		case 1570: return DF_Type::plot_agreement;
		case 1571: return DF_Type::plot_role_type;
		case 1572: return DF_Type::plot_strategy_type;
		case 1573: return DF_Type::poetic_form;
		case 1574: return DF_Type::poetic_form__T_flags;
		case 1575: return DF_Type::poetic_form_action;
		case 1576: return DF_Type::poetic_form_additional_feature;
		case 1577: return DF_Type::poetic_form_caesura_position;
		case 1578: return DF_Type::poetic_form_feature;
		case 1579: return DF_Type::poetic_form_mood;
		case 1580: return DF_Type::poetic_form_part;
		case 1581: return DF_Type::poetic_form_part__T_flags;
		case 1582: return DF_Type::poetic_form_pattern;
		case 1583: return DF_Type::poetic_form_perspective;
		case 1584: return DF_Type::poetic_form_perspective__T_type;
		case 1585: return DF_Type::poetic_form_subject;
		case 1586: return DF_Type::poetic_form_subject_target;
		case 1587: return DF_Type::poetic_form_subject_target__T_Concept;
		case 1588: return DF_Type::poetic_form_subject_target__T_Histfig;
		case 1589: return DF_Type::popup_message;
		case 1590: return DF_Type::power_info;
		case 1591: return DF_Type::pressure_plate_info;
		case 1592: return DF_Type::pressure_plate_info__T_flags;
		case 1593: return DF_Type::profession;
		case 1594: return DF_Type::proj_itemst;
		case 1595: return DF_Type::proj_list_link;
		case 1596: return DF_Type::proj_magicst;
		case 1597: return DF_Type::proj_unitst;
		case 1598: return DF_Type::projectile;
		case 1599: return DF_Type::projectile_flags;
		case 1600: return DF_Type::projectile_type;
		case 1601: return DF_Type::property_ownership;
		case 1602: return DF_Type::punishment;
		case 1603: return DF_Type::reaction;
		case 1604: return DF_Type::reaction__T_building;
		case 1605: return DF_Type::reaction_category;
		case 1606: return DF_Type::reaction_description;
		case 1607: return DF_Type::reaction_flags;
		case 1608: return DF_Type::reaction_product;
		case 1609: return DF_Type::reaction_product_improvement_flags;
		case 1610: return DF_Type::reaction_product_item_flags;
		case 1611: return DF_Type::reaction_product_item_improvementst;
		case 1612: return DF_Type::reaction_product_item_improvementst__T_get_material;
		case 1613: return DF_Type::reaction_product_itemst;
		case 1614: return DF_Type::reaction_product_itemst__T_get_material;
		case 1615: return DF_Type::reaction_product_type;
		case 1616: return DF_Type::reaction_reagent;
		case 1617: return DF_Type::reaction_reagent_flags;
		case 1618: return DF_Type::reaction_reagent_itemst;
		case 1619: return DF_Type::reaction_reagent_type;
		case 1620: return DF_Type::region_block_event_sphere_fieldst;
		case 1621: return DF_Type::region_block_event_type;
		case 1622: return DF_Type::region_block_eventst;
		case 1623: return DF_Type::region_map_entry;
		case 1624: return DF_Type::region_map_entry__T_clouds;
		case 1625: return DF_Type::region_map_entry__T_wind;
		case 1626: return DF_Type::region_map_entry_flags;
		case 1627: return DF_Type::relationship_event;
		case 1628: return DF_Type::relationship_event_supplement;
		case 1629: return DF_Type::renderer;
		case 1630: return DF_Type::report;
		case 1631: return DF_Type::report__T_flags;
		case 1632: return DF_Type::reputation_type;
		case 1633: return DF_Type::resource_allotment_data;
		case 1634: return DF_Type::resource_allotment_data__T_unk_654;
		case 1635: return DF_Type::resource_allotment_specifier;
		case 1636: return DF_Type::resource_allotment_specifier_ammost;
		case 1637: return DF_Type::resource_allotment_specifier_anvilst;
		case 1638: return DF_Type::resource_allotment_specifier_armor_bodyst;
		case 1639: return DF_Type::resource_allotment_specifier_armor_bootsst;
		case 1640: return DF_Type::resource_allotment_specifier_armor_glovesst;
		case 1641: return DF_Type::resource_allotment_specifier_armor_helmst;
		case 1642: return DF_Type::resource_allotment_specifier_armor_pantsst;
		case 1643: return DF_Type::resource_allotment_specifier_backpackst;
		case 1644: return DF_Type::resource_allotment_specifier_bagst;
		case 1645: return DF_Type::resource_allotment_specifier_bedst;
		case 1646: return DF_Type::resource_allotment_specifier_bonest;
		case 1647: return DF_Type::resource_allotment_specifier_boxst;
		case 1648: return DF_Type::resource_allotment_specifier_cabinetst;
		case 1649: return DF_Type::resource_allotment_specifier_chairst;
		case 1650: return DF_Type::resource_allotment_specifier_cheesest;
		case 1651: return DF_Type::resource_allotment_specifier_clothing_bodyst;
		case 1652: return DF_Type::resource_allotment_specifier_clothing_bootsst;
		case 1653: return DF_Type::resource_allotment_specifier_clothing_glovesst;
		case 1654: return DF_Type::resource_allotment_specifier_clothing_helmst;
		case 1655: return DF_Type::resource_allotment_specifier_clothing_pantsst;
		case 1656: return DF_Type::resource_allotment_specifier_clothst;
		case 1657: return DF_Type::resource_allotment_specifier_craftsst;
		case 1658: return DF_Type::resource_allotment_specifier_cropst;
		case 1659: return DF_Type::resource_allotment_specifier_extractst;
		case 1660: return DF_Type::resource_allotment_specifier_flaskst;
		case 1661: return DF_Type::resource_allotment_specifier_gemsst;
		case 1662: return DF_Type::resource_allotment_specifier_hornst;
		case 1663: return DF_Type::resource_allotment_specifier_leatherst;
		case 1664: return DF_Type::resource_allotment_specifier_meatst;
		case 1665: return DF_Type::resource_allotment_specifier_metalst;
		case 1666: return DF_Type::resource_allotment_specifier_pearlst;
		case 1667: return DF_Type::resource_allotment_specifier_powderst;
		case 1668: return DF_Type::resource_allotment_specifier_quiverst;
		case 1669: return DF_Type::resource_allotment_specifier_shellst;
		case 1670: return DF_Type::resource_allotment_specifier_skinst;
		case 1671: return DF_Type::resource_allotment_specifier_soapst;
		case 1672: return DF_Type::resource_allotment_specifier_stonest;
		case 1673: return DF_Type::resource_allotment_specifier_tablest;
		case 1674: return DF_Type::resource_allotment_specifier_tallowst;
		case 1675: return DF_Type::resource_allotment_specifier_threadst;
		case 1676: return DF_Type::resource_allotment_specifier_toothst;
		case 1677: return DF_Type::resource_allotment_specifier_type;
		case 1678: return DF_Type::resource_allotment_specifier_weapon_meleest;
		case 1679: return DF_Type::resource_allotment_specifier_weapon_rangedst;
		case 1680: return DF_Type::resource_allotment_specifier_woodst;
		case 1681: return DF_Type::rhythm;
		case 1682: return DF_Type::rhythm_sub1;
		case 1683: return DF_Type::rhythm_sub1__T_anon_1;
		case 1684: return DF_Type::rhythm_sub2;
		case 1685: return DF_Type::room_rent_info;
		case 1686: return DF_Type::room_rent_info__T_flags;
		case 1687: return DF_Type::route_stockpile_link;
		case 1688: return DF_Type::route_stockpile_link__T_mode;
		case 1689: return DF_Type::scale;
		case 1690: return DF_Type::scale__T_unk1;
		case 1691: return DF_Type::scale_sub1;
		case 1692: return DF_Type::scale_sub2;
		case 1693: return DF_Type::schedule_info;
		case 1694: return DF_Type::schedule_slot;
		case 1695: return DF_Type::screw_pump_direction;
		case 1696: return DF_Type::scribejob;
		case 1697: return DF_Type::script_step_conditionalst;
		case 1698: return DF_Type::script_step_conditionalst__T_condition;
		case 1699: return DF_Type::script_step_constructtopiclistst;
		case 1700: return DF_Type::script_step_dipeventst;
		case 1701: return DF_Type::script_step_diphistoryst;
		case 1702: return DF_Type::script_step_discussst;
		case 1703: return DF_Type::script_step_eventst;
		case 1704: return DF_Type::script_step_invasionst;
		case 1705: return DF_Type::script_step_setvarst;
		case 1706: return DF_Type::script_step_simpleactionst;
		case 1707: return DF_Type::script_step_textviewerst;
		case 1708: return DF_Type::script_step_topicdiscussionst;
		case 1709: return DF_Type::script_stepst;
		case 1710: return DF_Type::script_var_longst;
		case 1711: return DF_Type::script_var_unitst;
		case 1712: return DF_Type::script_varst;
		case 1713: return DF_Type::setup_character_info;
		case 1714: return DF_Type::setup_character_info__T_available_embark_items;
		case 1715: return DF_Type::setup_character_info__T_page;
		case 1716: return DF_Type::setup_character_info__T_sel_trait_column;
		case 1717: return DF_Type::setup_character_info__T_status;
		case 1718: return DF_Type::shoes_flags;
		case 1719: return DF_Type::shop_type;
		case 1720: return DF_Type::siegeengine_type;
		case 1721: return DF_Type::site_building_item;
		case 1722: return DF_Type::site_dispute_type;
		case 1723: return DF_Type::site_realization_building;
		case 1724: return DF_Type::site_realization_building__T_unk_4c;
		case 1725: return DF_Type::site_realization_building_info_castle_courtyardst;
		case 1726: return DF_Type::site_realization_building_info_castle_towerst;
		case 1727: return DF_Type::site_realization_building_info_castle_wallst;
		case 1728: return DF_Type::site_realization_building_info_hillock_housest;
		case 1729: return DF_Type::site_realization_building_info_market_squarest;
		case 1730: return DF_Type::site_realization_building_info_shop_housest;
		case 1731: return DF_Type::site_realization_building_info_tree_housest;
		case 1732: return DF_Type::site_realization_building_info_trenchesst;
		case 1733: return DF_Type::site_realization_building_info_trenchesst__T_spokes;
		case 1734: return DF_Type::site_realization_building_infost;
		case 1735: return DF_Type::site_realization_building_type;
		case 1736: return DF_Type::site_realization_crossroads;
		case 1737: return DF_Type::site_reputation_info;
		case 1738: return DF_Type::site_reputation_report;
		case 1739: return DF_Type::site_shop_type;
		case 1740: return DF_Type::site_type;
		case 1741: return DF_Type::skill_rating;
		case 1742: return DF_Type::slab_engraving_type;
		case 1743: return DF_Type::sound_production_type;
		case 1744: return DF_Type::spatter;
		case 1745: return DF_Type::spatter__T_flags;
		case 1746: return DF_Type::spatter_common;
		case 1747: return DF_Type::spatter_common__T_base_flags;
		case 1748: return DF_Type::special_mat_table;
		case 1749: return DF_Type::specific_ref;
		case 1750: return DF_Type::specific_ref__T_data;
		case 1751: return DF_Type::specific_ref__T_data__T_UNIT_ITEM_WRESTLE;
		case 1752: return DF_Type::specific_ref_type;
		case 1753: return DF_Type::sphere_type;
		case 1754: return DF_Type::spoils_report;
		case 1755: return DF_Type::squad;
		case 1756: return DF_Type::squad__T_rooms;
		case 1757: return DF_Type::squad_ammo_spec;
		case 1758: return DF_Type::squad_ammo_spec__T_flags;
		case 1759: return DF_Type::squad_event_type;
		case 1760: return DF_Type::squad_order;
		case 1761: return DF_Type::squad_order_cannot_reason;
		case 1762: return DF_Type::squad_order_cause_trouble_for_entityst;
		case 1763: return DF_Type::squad_order_defend_burrowsst;
		case 1764: return DF_Type::squad_order_drive_armies_from_sitest;
		case 1765: return DF_Type::squad_order_drive_entity_off_sitest;
		case 1766: return DF_Type::squad_order_kill_hfst;
		case 1767: return DF_Type::squad_order_kill_listst;
		case 1768: return DF_Type::squad_order_movest;
		case 1769: return DF_Type::squad_order_patrol_routest;
		case 1770: return DF_Type::squad_order_raid_sitest;
		case 1771: return DF_Type::squad_order_rescue_hfst;
		case 1772: return DF_Type::squad_order_retrieve_artifactst;
		case 1773: return DF_Type::squad_order_trainst;
		case 1774: return DF_Type::squad_order_type;
		case 1775: return DF_Type::squad_position;
		case 1776: return DF_Type::squad_schedule_entry;
		case 1777: return DF_Type::squad_schedule_order;
		case 1778: return DF_Type::squad_uniform_spec;
		case 1779: return DF_Type::squad_use_flags;
		case 1780: return DF_Type::stockpile_category;
		case 1781: return DF_Type::stockpile_group_set;
		case 1782: return DF_Type::stockpile_links;
		case 1783: return DF_Type::stockpile_list;
		case 1784: return DF_Type::stockpile_settings;
		case 1785: return DF_Type::stockpile_settings__T_ammo;
		case 1786: return DF_Type::stockpile_settings__T_animals;
		case 1787: return DF_Type::stockpile_settings__T_armor;
		case 1788: return DF_Type::stockpile_settings__T_bars_blocks;
		case 1789: return DF_Type::stockpile_settings__T_cloth;
		case 1790: return DF_Type::stockpile_settings__T_coins;
		case 1791: return DF_Type::stockpile_settings__T_finished_goods;
		case 1792: return DF_Type::stockpile_settings__T_food;
		case 1793: return DF_Type::stockpile_settings__T_furniture;
		case 1794: return DF_Type::stockpile_settings__T_gems;
		case 1795: return DF_Type::stockpile_settings__T_leather;
		case 1796: return DF_Type::stockpile_settings__T_ore;
		case 1797: return DF_Type::stockpile_settings__T_refuse;
		case 1798: return DF_Type::stockpile_settings__T_sheet;
		case 1799: return DF_Type::stockpile_settings__T_stone;
		case 1800: return DF_Type::stockpile_settings__T_weapons;
		case 1801: return DF_Type::stockpile_settings__T_wood;
		case 1802: return DF_Type::stop_depart_condition;
		case 1803: return DF_Type::stop_depart_condition__T_direction;
		case 1804: return DF_Type::stop_depart_condition__T_flags;
		case 1805: return DF_Type::stop_depart_condition__T_mode;
		case 1806: return DF_Type::strain_type;
		case 1807: return DF_Type::stratus_type;
		case 1808: return DF_Type::syndrome;
		case 1809: return DF_Type::syndrome_flags;
		case 1810: return DF_Type::T_cursor;
		case 1811: return DF_Type::T_selection_rect;
		case 1812: return DF_Type::tactical_situation;
		case 1813: return DF_Type::talk_choice;
		case 1814: return DF_Type::talk_choice__T_unk;
		case 1815: return DF_Type::talk_choice_type;
		case 1816: return DF_Type::temperaturest;
		case 1817: return DF_Type::temple_deity_data;
		case 1818: return DF_Type::temple_deity_type;
		case 1819: return DF_Type::text_info_element_longst;
		case 1820: return DF_Type::text_info_element_stringst;
		case 1821: return DF_Type::text_info_elementst;
		case 1822: return DF_Type::texture_handler;
		case 1823: return DF_Type::tile_bitmask;
		case 1824: return DF_Type::tile_building_occ;
		case 1825: return DF_Type::tile_designation;
		case 1826: return DF_Type::tile_dig_designation;
		case 1827: return DF_Type::tile_liquid;
		case 1828: return DF_Type::tile_liquid_flow;
		case 1829: return DF_Type::tile_liquid_flow_dir;
		case 1830: return DF_Type::tile_occupancy;
		case 1831: return DF_Type::tile_page;
		case 1832: return DF_Type::tile_traffic;
		case 1833: return DF_Type::tiletype;
		case 1834: return DF_Type::tiletype_material;
		case 1835: return DF_Type::tiletype_shape;
		case 1836: return DF_Type::tiletype_shape_basic;
		case 1837: return DF_Type::tiletype_special;
		case 1838: return DF_Type::tiletype_variant;
		case 1839: return DF_Type::timbre_type;
		case 1840: return DF_Type::timed_event;
		case 1841: return DF_Type::timed_event_type;
		case 1842: return DF_Type::tissue;
		case 1843: return DF_Type::tissue_flags;
		case 1844: return DF_Type::tissue_style_raw;
		case 1845: return DF_Type::tissue_style_type;
		case 1846: return DF_Type::tissue_template;
		case 1847: return DF_Type::tool_flags;
		case 1848: return DF_Type::tool_uses;
		case 1849: return DF_Type::tower_shape;
		case 1850: return DF_Type::toy_flags;
		case 1851: return DF_Type::training_assignment;
		case 1852: return DF_Type::training_assignment__T_flags;
		case 1853: return DF_Type::training_knowledge_level;
		case 1854: return DF_Type::trap_type;
		case 1855: return DF_Type::trapcomp_flags;
		case 1856: return DF_Type::tree_house_type;
		case 1857: return DF_Type::tuning_type;
		case 1858: return DF_Type::ui;
		case 1859: return DF_Type::ui__T_alerts;
		case 1860: return DF_Type::ui__T_alerts__T_list;
		case 1861: return DF_Type::ui__T_becoming_capital;
		case 1862: return DF_Type::ui__T_burrows;
		case 1863: return DF_Type::ui__T_economy_prices;
		case 1864: return DF_Type::ui__T_economy_prices__T_price_adjustment;
		case 1865: return DF_Type::ui__T_economy_prices__T_price_setter;
		case 1866: return DF_Type::ui__T_equipment;
		case 1867: return DF_Type::ui__T_equipment__T_update;
		case 1868: return DF_Type::ui__T_hauling;
		case 1869: return DF_Type::ui__T_invasions;
		case 1870: return DF_Type::ui__T_kitchen;
		case 1871: return DF_Type::ui__T_main;
		case 1872: return DF_Type::ui__T_main__T_dead_citizens;
		case 1873: return DF_Type::ui__T_map_edge;
		case 1874: return DF_Type::ui__T_squads;
		case 1875: return DF_Type::ui__T_stockpile;
		case 1876: return DF_Type::ui__T_tax_collection;
		case 1877: return DF_Type::ui__T_unk23c8_flags;
		case 1878: return DF_Type::ui__T_unk2a8c;
		case 1879: return DF_Type::ui__T_waypoints;
		case 1880: return DF_Type::ui__T_waypoints__T_points;
		case 1881: return DF_Type::ui__T_waypoints__T_routes;
		case 1882: return DF_Type::ui_advmode;
		case 1883: return DF_Type::ui_advmode__T_assume_identity;
		case 1884: return DF_Type::ui_advmode__T_companions;
		case 1885: return DF_Type::ui_advmode__T_conversation;
		case 1886: return DF_Type::ui_advmode__T_conversation__T_choices;
		case 1887: return DF_Type::ui_advmode__T_conversation__T_targets;
		case 1888: return DF_Type::ui_advmode__T_conversation__T_targets__T_type;
		case 1889: return DF_Type::ui_advmode__T_interactions;
		case 1890: return DF_Type::ui_advmode__T_show_menu;
		case 1891: return DF_Type::ui_advmode__T_travel_right_map;
		case 1892: return DF_Type::ui_advmode__T_unk_3124;
		case 1893: return DF_Type::ui_advmode__T_unk_3170;
		case 1894: return DF_Type::ui_advmode__T_unk_3170__T_unk_2;
		case 1895: return DF_Type::ui_advmode__T_unk_v40_1;
		case 1896: return DF_Type::ui_advmode__T_unk_v40_2;
		case 1897: return DF_Type::ui_advmode__T_unk_v40_3;
		case 1898: return DF_Type::ui_advmode__T_unk_v40_4;
		case 1899: return DF_Type::ui_advmode__T_unk_v40_4__T_unk_v40_4a;
		case 1900: return DF_Type::ui_advmode__T_unk_v40_5;
		case 1901: return DF_Type::ui_advmode__T_unk_v42_1;
		case 1902: return DF_Type::ui_advmode_menu;
		case 1903: return DF_Type::ui_build_item_req;
		case 1904: return DF_Type::ui_build_selector;
		case 1905: return DF_Type::ui_hotkey;
		case 1906: return DF_Type::ui_hotkey___union1;
		case 1907: return DF_Type::ui_hotkey__T_cmd;
		case 1908: return DF_Type::ui_look_list;
		case 1909: return DF_Type::ui_look_list__T_items;
		case 1910: return DF_Type::ui_look_list__T_items__T_data;
		case 1911: return DF_Type::ui_look_list__T_items__T_data__T_Magma;
		case 1912: return DF_Type::ui_look_list__T_items__T_data__T_Spatter;
		case 1913: return DF_Type::ui_look_list__T_items__T_data__T_Water;
		case 1914: return DF_Type::ui_look_list__T_items__T_type;
		case 1915: return DF_Type::ui_sidebar_menus;
		case 1916: return DF_Type::ui_sidebar_menus__T_barracks;
		case 1917: return DF_Type::ui_sidebar_menus__T_building;
		case 1918: return DF_Type::ui_sidebar_menus__T_command_line;
		case 1919: return DF_Type::ui_sidebar_menus__T_designation;
		case 1920: return DF_Type::ui_sidebar_menus__T_designation__T_mine_mode;
		case 1921: return DF_Type::ui_sidebar_menus__T_hospital;
		case 1922: return DF_Type::ui_sidebar_menus__T_job_details;
		case 1923: return DF_Type::ui_sidebar_menus__T_location;
		case 1924: return DF_Type::ui_sidebar_menus__T_minimap;
		case 1925: return DF_Type::ui_sidebar_menus__T_unit;
		case 1926: return DF_Type::ui_sidebar_menus__T_unit__T_expel_error;
		case 1927: return DF_Type::ui_sidebar_menus__T_unit_cursor;
		case 1928: return DF_Type::ui_sidebar_menus__T_unit_skills;
		case 1929: return DF_Type::ui_sidebar_menus__T_workshop_job;
		case 1930: return DF_Type::ui_sidebar_menus__T_zone;
		case 1931: return DF_Type::ui_sidebar_menus__T_zone__T_mode;
		case 1932: return DF_Type::ui_sidebar_mode;
		case 1933: return DF_Type::ui_unit_view_mode;
		case 1934: return DF_Type::ui_unit_view_mode__T_value;
		case 1935: return DF_Type::uniform_category;
		case 1936: return DF_Type::uniform_flags;
		case 1937: return DF_Type::uniform_indiv_choice;
		case 1938: return DF_Type::unit;
		case 1939: return DF_Type::unit__T_animal;
		case 1940: return DF_Type::unit__T_appearance;
		case 1941: return DF_Type::unit__T_body;
		case 1942: return DF_Type::unit__T_counters;
		case 1943: return DF_Type::unit__T_counters2;
		case 1944: return DF_Type::unit__T_counters__T_soldier_mood;
		case 1945: return DF_Type::unit__T_curse;
		case 1946: return DF_Type::unit__T_enemy;
		case 1947: return DF_Type::unit__T_enemy__T_undead;
		case 1948: return DF_Type::unit__T_enemy__T_unk_448;
		case 1949: return DF_Type::unit__T_enemy__T_unk_448__T_unk;
		case 1950: return DF_Type::unit__T_enemy__T_unk_44c;
		case 1951: return DF_Type::unit__T_enemy__T_unk_v40_sub3;
		case 1952: return DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_2;
		case 1953: return DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_6;
		case 1954: return DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_7;
		case 1955: return DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_7__T_unk_sub1;
		case 1956: return DF_Type::unit__T_enemy__T_witness_reports;
		case 1957: return DF_Type::unit__T_job;
		case 1958: return DF_Type::unit__T_meeting;
		case 1959: return DF_Type::unit__T_meeting__T_state;
		case 1960: return DF_Type::unit__T_military;
		case 1961: return DF_Type::unit__T_military__T_pickup_flags;
		case 1962: return DF_Type::unit__T_opponent;
		case 1963: return DF_Type::unit__T_path;
		case 1964: return DF_Type::unit__T_reports;
		case 1965: return DF_Type::unit__T_status;
		case 1966: return DF_Type::unit__T_status2;
		case 1967: return DF_Type::unit__T_status__T_eat_history;
		case 1968: return DF_Type::unit__T_status__T_eat_history__T_drink;
		case 1969: return DF_Type::unit__T_status__T_eat_history__T_food;
		case 1970: return DF_Type::unit__T_syndromes;
		case 1971: return DF_Type::unit__T_unknown7;
		case 1972: return DF_Type::unit_action;
		case 1973: return DF_Type::unit_action__T_data;
		case 1974: return DF_Type::unit_action_data_attack;
		case 1975: return DF_Type::unit_action_data_attack__T_flags;
		case 1976: return DF_Type::unit_action_data_attack__T_unk_4;
		case 1977: return DF_Type::unit_action_data_attack__T_unk_4__T_wrestle_type;
		case 1978: return DF_Type::unit_action_data_block;
		case 1979: return DF_Type::unit_action_data_climb;
		case 1980: return DF_Type::unit_action_data_dodge;
		case 1981: return DF_Type::unit_action_data_hold_item;
		case 1982: return DF_Type::unit_action_data_hold_terrain;
		case 1983: return DF_Type::unit_action_data_job;
		case 1984: return DF_Type::unit_action_data_job2;
		case 1985: return DF_Type::unit_action_data_jump;
		case 1986: return DF_Type::unit_action_data_lie_down;
		case 1987: return DF_Type::unit_action_data_move;
		case 1988: return DF_Type::unit_action_data_move__T_flags;
		case 1989: return DF_Type::unit_action_data_parry;
		case 1990: return DF_Type::unit_action_data_push_object;
		case 1991: return DF_Type::unit_action_data_recover;
		case 1992: return DF_Type::unit_action_data_release_item;
		case 1993: return DF_Type::unit_action_data_release_terrain;
		case 1994: return DF_Type::unit_action_data_stand_up;
		case 1995: return DF_Type::unit_action_data_suck_blood;
		case 1996: return DF_Type::unit_action_data_talk;
		case 1997: return DF_Type::unit_action_data_unsteady;
		case 1998: return DF_Type::unit_action_type;
		case 1999: return DF_Type::unit_appearance;
		case 2000: return DF_Type::unit_attribute;
		case 2001: return DF_Type::unit_bp_health_flags;
		case 2002: return DF_Type::unit_chunk;
		case 2003: return DF_Type::unit_chunk__T_units;
		case 2004: return DF_Type::unit_coin_debt;
		case 2005: return DF_Type::unit_complaint;
		case 2006: return DF_Type::unit_complaint__T_type;
		case 2007: return DF_Type::unit_dance_skill;
		case 2008: return DF_Type::unit_demand;
		case 2009: return DF_Type::unit_demand__T_place;
		case 2010: return DF_Type::unit_emotion_memory;
		case 2011: return DF_Type::unit_flags1;
		case 2012: return DF_Type::unit_flags2;
		case 2013: return DF_Type::unit_flags3;
		case 2014: return DF_Type::unit_flags4;
		case 2015: return DF_Type::unit_genes;
		case 2016: return DF_Type::unit_ghost_info;
		case 2017: return DF_Type::unit_ghost_info__T_flags;
		case 2018: return DF_Type::unit_ghost_info__T_target;
		case 2019: return DF_Type::unit_health_flags;
		case 2020: return DF_Type::unit_health_info;
		case 2021: return DF_Type::unit_health_info__T_op_history;
		case 2022: return DF_Type::unit_health_info__T_op_history__T_info;
		case 2023: return DF_Type::unit_health_info__T_op_history__T_info__T_bandage;
		case 2024: return DF_Type::unit_health_info__T_op_history__T_info__T_crutch;
		case 2025: return DF_Type::unit_instrument_skill;
		case 2026: return DF_Type::unit_inventory_item;
		case 2027: return DF_Type::unit_inventory_item__T_mode;
		case 2028: return DF_Type::unit_item_use;
		case 2029: return DF_Type::unit_item_wrestle;
		case 2030: return DF_Type::unit_labor;
		case 2031: return DF_Type::unit_labor_category;
		case 2032: return DF_Type::unit_misc_trait;
		case 2033: return DF_Type::unit_musical_skill;
		case 2034: return DF_Type::unit_path_goal;
		case 2035: return DF_Type::unit_personality;
		case 2036: return DF_Type::unit_personality__T_dreams;
		case 2037: return DF_Type::unit_personality__T_emotions;
		case 2038: return DF_Type::unit_personality__T_emotions__T_flags;
		case 2039: return DF_Type::unit_personality__T_flags;
		case 2040: return DF_Type::unit_personality__T_memories;
		case 2041: return DF_Type::unit_personality__T_memories__T_reflected_on;
		case 2042: return DF_Type::unit_personality__T_needs;
		case 2043: return DF_Type::unit_personality__T_unk5;
		case 2044: return DF_Type::unit_personality__T_unk_v40_2;
		case 2045: return DF_Type::unit_personality__T_unk_v40_6;
		case 2046: return DF_Type::unit_personality__T_values;
		case 2047: return DF_Type::unit_poetic_skill;
		case 2048: return DF_Type::unit_preference;
		case 2049: return DF_Type::unit_preference___union2;
		case 2050: return DF_Type::unit_preference__T_type;
		case 2051: return DF_Type::unit_relationship_type;
		case 2052: return DF_Type::unit_report_type;
		case 2053: return DF_Type::unit_request;
		case 2054: return DF_Type::unit_request__T_type;
		case 2055: return DF_Type::unit_skill;
		case 2056: return DF_Type::unit_soul;
		case 2057: return DF_Type::unit_soul__T_performance_skills;
		case 2058: return DF_Type::unit_station_type;
		case 2059: return DF_Type::unit_storage_status;
		case 2060: return DF_Type::unit_syndrome;
		case 2061: return DF_Type::unit_syndrome__T_flags;
		case 2062: return DF_Type::unit_syndrome__T_symptoms;
		case 2063: return DF_Type::unit_syndrome__T_symptoms__T_flags;
		case 2064: return DF_Type::unit_thought_type;
		case 2065: return DF_Type::unit_unk_138;
		case 2066: return DF_Type::unit_wound;
		case 2067: return DF_Type::unit_wound__T_flags;
		case 2068: return DF_Type::unit_wound__T_parts;
		case 2069: return DF_Type::units_other_id;
		case 2070: return DF_Type::vague_relationship_type;
		case 2071: return DF_Type::value_type;
		case 2072: return DF_Type::vehicle;
		case 2073: return DF_Type::vermin;
		case 2074: return DF_Type::vermin_flags;
		case 2075: return DF_Type::viewscreen;
		case 2076: return DF_Type::viewscreen_adopt_regionst;
		case 2077: return DF_Type::viewscreen_adventure_logst;
		case 2078: return DF_Type::viewscreen_adventure_logst__T_info_mode;
		case 2079: return DF_Type::viewscreen_adventure_logst__T_mode;
		case 2080: return DF_Type::viewscreen_adventure_logst__T_unk_68;
		case 2081: return DF_Type::viewscreen_announcelistst;
		case 2082: return DF_Type::viewscreen_assign_display_itemst;
		case 2083: return DF_Type::viewscreen_assign_display_itemst__T_sel_column;
		case 2084: return DF_Type::viewscreen_barterst;
		case 2085: return DF_Type::viewscreen_buildinglistst;
		case 2086: return DF_Type::viewscreen_buildingst;
		case 2087: return DF_Type::viewscreen_choose_start_sitest;
		case 2088: return DF_Type::viewscreen_choose_start_sitest__T_finder;
		case 2089: return DF_Type::viewscreen_choose_start_sitest__T_finder__T_finder_state;
		case 2090: return DF_Type::viewscreen_choose_start_sitest__T_page;
		case 2091: return DF_Type::viewscreen_civlistst;
		case 2092: return DF_Type::viewscreen_civlistst__T_artifact_details;
		case 2093: return DF_Type::viewscreen_civlistst__T_page;
		case 2094: return DF_Type::viewscreen_civlistst__T_rumors;
		case 2095: return DF_Type::viewscreen_civlistst__T_rumors__T_type;
		case 2096: return DF_Type::viewscreen_civlistst__T_unk_cache;
		case 2097: return DF_Type::viewscreen_civlistst__T_unk_cache__T_tmp1;
		case 2098: return DF_Type::viewscreen_civlistst__T_unk_cache__T_tmp2;
		case 2099: return DF_Type::viewscreen_counterintelligencest;
		case 2100: return DF_Type::viewscreen_createquotast;
		case 2101: return DF_Type::viewscreen_customize_unitst;
		case 2102: return DF_Type::viewscreen_dungeon_monsterstatusst;
		case 2103: return DF_Type::viewscreen_dungeon_wrestlest;
		case 2104: return DF_Type::viewscreen_dungeon_wrestlest__T_unk1;
		case 2105: return DF_Type::viewscreen_dungeonmodest;
		case 2106: return DF_Type::viewscreen_dwarfmodest;
		case 2107: return DF_Type::viewscreen_entityst;
		case 2108: return DF_Type::viewscreen_export_graphical_mapst;
		case 2109: return DF_Type::viewscreen_export_graphical_mapst__T_rgb_buffer;
		case 2110: return DF_Type::viewscreen_export_regionst;
		case 2111: return DF_Type::viewscreen_export_regionst__T_unk1;
		case 2112: return DF_Type::viewscreen_game_cleanerst;
		case 2113: return DF_Type::viewscreen_game_cleanerst__T_state;
		case 2114: return DF_Type::viewscreen_image_creator_mode;
		case 2115: return DF_Type::viewscreen_image_creatorst;
		case 2116: return DF_Type::viewscreen_image_creatorst__T_artifacts;
		case 2117: return DF_Type::viewscreen_image_creatorst__T_entities;
		case 2118: return DF_Type::viewscreen_image_creatorst__T_histfigs;
		case 2119: return DF_Type::viewscreen_image_creatorst__T_objects;
		case 2120: return DF_Type::viewscreen_image_creatorst__T_plants;
		case 2121: return DF_Type::viewscreen_image_creatorst__T_relationships;
		case 2122: return DF_Type::viewscreen_image_creatorst__T_shapes;
		case 2123: return DF_Type::viewscreen_image_creatorst__T_sites;
		case 2124: return DF_Type::viewscreen_image_creatorst__T_trees;
		case 2125: return DF_Type::viewscreen_itemst;
		case 2126: return DF_Type::viewscreen_joblistst;
		case 2127: return DF_Type::viewscreen_jobmanagementst;
		case 2128: return DF_Type::viewscreen_jobst;
		case 2129: return DF_Type::viewscreen_justicest;
		case 2130: return DF_Type::viewscreen_justicest__T_cur_column;
		case 2131: return DF_Type::viewscreen_justicest__T_interrogate_status;
		case 2132: return DF_Type::viewscreen_kitchenpref_page;
		case 2133: return DF_Type::viewscreen_kitchenprefst;
		case 2134: return DF_Type::viewscreen_layer;
		case 2135: return DF_Type::viewscreen_layer_arena_creaturest;
		case 2136: return DF_Type::viewscreen_layer_assigntradest;
		case 2137: return DF_Type::viewscreen_layer_choose_language_namest;
		case 2138: return DF_Type::viewscreen_layer_choose_language_namest__T_current_component;
		case 2139: return DF_Type::viewscreen_layer_currencyst;
		case 2140: return DF_Type::viewscreen_layer_export_play_mapst;
		case 2141: return DF_Type::viewscreen_layer_militaryst;
		case 2142: return DF_Type::viewscreen_layer_militaryst__T_ammo;
		case 2143: return DF_Type::viewscreen_layer_militaryst__T_ammo__T_add_item;
		case 2144: return DF_Type::viewscreen_layer_militaryst__T_ammo__T_material;
		case 2145: return DF_Type::viewscreen_layer_militaryst__T_equip;
		case 2146: return DF_Type::viewscreen_layer_militaryst__T_equip__T_add_item;
		case 2147: return DF_Type::viewscreen_layer_militaryst__T_equip__T_assigned;
		case 2148: return DF_Type::viewscreen_layer_militaryst__T_equip__T_color;
		case 2149: return DF_Type::viewscreen_layer_militaryst__T_equip__T_edit_mode;
		case 2150: return DF_Type::viewscreen_layer_militaryst__T_equip__T_material;
		case 2151: return DF_Type::viewscreen_layer_militaryst__T_equip__T_mode;
		case 2152: return DF_Type::viewscreen_layer_militaryst__T_equip__T_uniform;
		case 2153: return DF_Type::viewscreen_layer_militaryst__T_page;
		case 2154: return DF_Type::viewscreen_layer_militaryst__T_positions;
		case 2155: return DF_Type::viewscreen_layer_militaryst__T_squad_members;
		case 2156: return DF_Type::viewscreen_layer_militaryst__T_squads;
		case 2157: return DF_Type::viewscreen_layer_musicsoundst;
		case 2158: return DF_Type::viewscreen_layer_noblelistst;
		case 2159: return DF_Type::viewscreen_layer_noblelistst__T_candidates;
		case 2160: return DF_Type::viewscreen_layer_noblelistst__T_info;
		case 2161: return DF_Type::viewscreen_layer_noblelistst__T_mode;
		case 2162: return DF_Type::viewscreen_layer_overall_healthst;
		case 2163: return DF_Type::viewscreen_layer_reactionst;
		case 2164: return DF_Type::viewscreen_layer_squad_schedulest;
		case 2165: return DF_Type::viewscreen_layer_stockpilest;
		case 2166: return DF_Type::viewscreen_layer_stone_restrictionst;
		case 2167: return DF_Type::viewscreen_layer_unit_actionst;
		case 2168: return DF_Type::viewscreen_layer_unit_healthst;
		case 2169: return DF_Type::viewscreen_layer_unit_relationshipst;
		case 2170: return DF_Type::viewscreen_layer_world_gen_param_presetst;
		case 2171: return DF_Type::viewscreen_layer_world_gen_paramst;
		case 2172: return DF_Type::viewscreen_layer_world_gen_paramst__T_unk1;
		case 2173: return DF_Type::viewscreen_legendsst;
		case 2174: return DF_Type::viewscreen_legendsst__T_anon_7;
		case 2175: return DF_Type::viewscreen_legendsst__T_anon_7__T_anon_3;
		case 2176: return DF_Type::viewscreen_legendsst__T_cur_page;
		case 2177: return DF_Type::viewscreen_loadgamest;
		case 2178: return DF_Type::viewscreen_loadgamest__T_cur_step;
		case 2179: return DF_Type::viewscreen_locationsst;
		case 2180: return DF_Type::viewscreen_locationsst__T_in_edit;
		case 2181: return DF_Type::viewscreen_locationsst__T_menu;
		case 2182: return DF_Type::viewscreen_meetingst;
		case 2183: return DF_Type::viewscreen_movieplayerst;
		case 2184: return DF_Type::viewscreen_new_regionst;
		case 2185: return DF_Type::viewscreen_new_regionst__T_worldgen_presets;
		case 2186: return DF_Type::viewscreen_noblest;
		case 2187: return DF_Type::viewscreen_optionst;
		case 2188: return DF_Type::viewscreen_optionst__T_options;
		case 2189: return DF_Type::viewscreen_overallstatusst;
		case 2190: return DF_Type::viewscreen_overallstatusst__T_visible_pages;
		case 2191: return DF_Type::viewscreen_petitionsst;
		case 2192: return DF_Type::viewscreen_petst;
		case 2193: return DF_Type::viewscreen_petst__T_animal;
		case 2194: return DF_Type::viewscreen_petst__T_mode;
		case 2195: return DF_Type::viewscreen_petst__T_trainer_mode;
		case 2196: return DF_Type::viewscreen_pricest;
		case 2197: return DF_Type::viewscreen_reportlistst;
		case 2198: return DF_Type::viewscreen_requestagreementst;
		case 2199: return DF_Type::viewscreen_savegamest;
		case 2200: return DF_Type::viewscreen_selectitemst;
		case 2201: return DF_Type::viewscreen_setupadventurest;
		case 2202: return DF_Type::viewscreen_setupadventurest__T_page;
		case 2203: return DF_Type::viewscreen_setupadventurest__T_races_info;
		case 2204: return DF_Type::viewscreen_setupadventurest__T_status;
		case 2205: return DF_Type::viewscreen_setupdwarfgamest;
		case 2206: return DF_Type::viewscreen_setupdwarfgamest__T_animals;
		case 2207: return DF_Type::viewscreen_setupdwarfgamest__T_choice_types;
		case 2208: return DF_Type::viewscreen_setupdwarfgamest__T_mode;
		case 2209: return DF_Type::viewscreen_setupdwarfgamest__T_unk_v43;
		case 2210: return DF_Type::viewscreen_setupdwarfgamest__T_unk_v43__T_unk_v43_sub9;
		case 2211: return DF_Type::viewscreen_storesst;
		case 2212: return DF_Type::viewscreen_textviewerst;
		case 2213: return DF_Type::viewscreen_textviewerst__T_formatted_text;
		case 2214: return DF_Type::viewscreen_textviewerst__T_formatted_text__T_flags;
		case 2215: return DF_Type::viewscreen_titlest;
		case 2216: return DF_Type::viewscreen_titlest__T_menu_line_id;
		case 2217: return DF_Type::viewscreen_titlest__T_sel_subpage;
		case 2218: return DF_Type::viewscreen_titlest__T_start_savegames;
		case 2219: return DF_Type::viewscreen_topicmeeting_fill_land_holder_positionsst;
		case 2220: return DF_Type::viewscreen_topicmeeting_takerequestsst;
		case 2221: return DF_Type::viewscreen_topicmeetingst;
		case 2222: return DF_Type::viewscreen_tradeagreementst;
		case 2223: return DF_Type::viewscreen_tradegoodsst;
		case 2224: return DF_Type::viewscreen_tradelistst;
		case 2225: return DF_Type::viewscreen_treasurelistst;
		case 2226: return DF_Type::viewscreen_unitlist_page;
		case 2227: return DF_Type::viewscreen_unitlistst;
		case 2228: return DF_Type::viewscreen_unitst;
		case 2229: return DF_Type::viewscreen_update_regionst;
		case 2230: return DF_Type::viewscreen_wagesst;
		case 2231: return DF_Type::viewscreen_workquota_conditionst;
		case 2232: return DF_Type::viewscreen_workquota_conditionst__T_mode;
		case 2233: return DF_Type::viewscreen_workquota_conditionst__T_traits;
		case 2234: return DF_Type::viewscreen_workquota_conditionst__T_traits__T_flags;
		case 2235: return DF_Type::viewscreen_workquota_detailsst;
		case 2236: return DF_Type::viewscreen_workshop_profilest;
		case 2237: return DF_Type::viewscreen_workshop_profilest__T_tab;
		case 2238: return DF_Type::weapon_attack;
		case 2239: return DF_Type::weapon_attack__T_flags;
		case 2240: return DF_Type::weapon_flags;
		case 2241: return DF_Type::weather_type;
		case 2242: return DF_Type::web_cluster;
		case 2243: return DF_Type::whereabouts_type;
		case 2244: return DF_Type::widget_menu;
		case 2245: return DF_Type::widget_textbox;
		case 2246: return DF_Type::workshop_profile;
		case 2247: return DF_Type::workshop_type;
		case 2248: return DF_Type::world;
		case 2249: return DF_Type::world__T_activities;
		case 2250: return DF_Type::world__T_agreements;
		case 2251: return DF_Type::world__T_area_grasses;
		case 2252: return DF_Type::world__T_area_grasses__T_layer_grasses;
		case 2253: return DF_Type::world__T_arena_settings;
		case 2254: return DF_Type::world__T_arena_spawn;
		case 2255: return DF_Type::world__T_arena_spawn__T_equipment;
		case 2256: return DF_Type::world__T_arena_spawn__T_item_types;
		case 2257: return DF_Type::world__T_arena_spawn__T_tame;
		case 2258: return DF_Type::world__T_armies;
		case 2259: return DF_Type::world__T_army_controllers;
		case 2260: return DF_Type::world__T_army_tracking_info;
		case 2261: return DF_Type::world__T_artifacts;
		case 2262: return DF_Type::world__T_belief_systems;
		case 2263: return DF_Type::world__T_crimes;
		case 2264: return DF_Type::world__T_cultural_identities;
		case 2265: return DF_Type::world__T_cur_savegame;
		case 2266: return DF_Type::world__T_dance_forms;
		case 2267: return DF_Type::world__T_divination_sets;
		case 2268: return DF_Type::world__T_enemy_status_cache;
		case 2269: return DF_Type::world__T_entities;
		case 2270: return DF_Type::world__T_features;
		case 2271: return DF_Type::world__T_flow_engine;
		case 2272: return DF_Type::world__T_flow_guides;
		case 2273: return DF_Type::world__T_formations;
		case 2274: return DF_Type::world__T_identities;
		case 2275: return DF_Type::world__T_image_sets;
		case 2276: return DF_Type::world__T_image_sets__T_all;
		case 2277: return DF_Type::world__T_image_sets__T_all__T_anon_3;
		case 2278: return DF_Type::world__T_incidents;
		case 2279: return DF_Type::world__T_interaction_instances;
		case 2280: return DF_Type::world__T_items;
		case 2281: return DF_Type::world__T_languages;
		case 2282: return DF_Type::world__T_map;
		case 2283: return DF_Type::world__T_map_extras;
		case 2284: return DF_Type::world__T_math;
		case 2285: return DF_Type::world__T_math__T_approx;
		case 2286: return DF_Type::world__T_musical_forms;
		case 2287: return DF_Type::world__T_nemesis;
		case 2288: return DF_Type::world__T_occupations;
		case 2289: return DF_Type::world__T_pathfinder;
		case 2290: return DF_Type::world__T_pathfinder__T_boundary_heap;
		case 2291: return DF_Type::world__T_plants;
		case 2292: return DF_Type::world__T_poetic_forms;
		case 2293: return DF_Type::world__T_profession_skills;
		case 2294: return DF_Type::world__T_rhythms;
		case 2295: return DF_Type::world__T_scales;
		case 2296: return DF_Type::world__T_schedules;
		case 2297: return DF_Type::world__T_squads;
		case 2298: return DF_Type::world__T_status;
		case 2299: return DF_Type::world__T_status__T_flags;
		case 2300: return DF_Type::world__T_status__T_slots;
		case 2301: return DF_Type::world__T_status__T_slots__T_flags;
		case 2302: return DF_Type::world__T_stockpile;
		case 2303: return DF_Type::world__T_stockpile__T_simple1;
		case 2304: return DF_Type::world__T_stockpile__T_simple2;
		case 2305: return DF_Type::world__T_stockpile__T_simple3;
		case 2306: return DF_Type::world__T_units;
		case 2307: return DF_Type::world__T_unk_131ec0;
		case 2308: return DF_Type::world__T_unk_131ef0;
		case 2309: return DF_Type::world__T_unk_131ef0__T_claims;
		case 2310: return DF_Type::world__T_unk_19325c;
		case 2311: return DF_Type::world__T_unk_19325c__T_anon_1;
		case 2312: return DF_Type::world__T_unk_19325c__T_anon_2;
		case 2313: return DF_Type::world__T_unk_19325c__T_anon_3;
		case 2314: return DF_Type::world__T_unk_26c678;
		case 2315: return DF_Type::world__T_unk_v40_6;
		case 2316: return DF_Type::world__T_vehicles;
		case 2317: return DF_Type::world__T_vermin;
		case 2318: return DF_Type::world__T_worldgen;
		case 2319: return DF_Type::world__T_worldgen__T_worldgen_parms;
		case 2320: return DF_Type::world__T_worldgen_coord_buf;
		case 2321: return DF_Type::world__T_worldgen_status;
		case 2322: return DF_Type::world__T_written_contents;
		case 2323: return DF_Type::world_construction;
		case 2324: return DF_Type::world_construction_bridgest;
		case 2325: return DF_Type::world_construction_roadst;
		case 2326: return DF_Type::world_construction_square;
		case 2327: return DF_Type::world_construction_square_bridgest;
		case 2328: return DF_Type::world_construction_square_roadst;
		case 2329: return DF_Type::world_construction_square_tunnelst;
		case 2330: return DF_Type::world_construction_square_wallst;
		case 2331: return DF_Type::world_construction_tunnelst;
		case 2332: return DF_Type::world_construction_type;
		case 2333: return DF_Type::world_construction_wallst;
		case 2334: return DF_Type::world_dat_summary;
		case 2335: return DF_Type::world_data;
		case 2336: return DF_Type::world_data__T_constructions;
		case 2337: return DF_Type::world_data__T_feature_map;
		case 2338: return DF_Type::world_data__T_feature_map__T_features;
		case 2339: return DF_Type::world_data__T_field_battles;
		case 2340: return DF_Type::world_data__T_field_battles__T_sapient_deaths;
		case 2341: return DF_Type::world_data__T_flip_latitude;
		case 2342: return DF_Type::world_data__T_freakish_weather;
		case 2343: return DF_Type::world_data__T_mountain_peaks;
		case 2344: return DF_Type::world_data__T_unk_150;
		case 2345: return DF_Type::world_data__T_unk_150__T_unk_18;
		case 2346: return DF_Type::world_data__T_unk_150__T_unk_28;
		case 2347: return DF_Type::world_data__T_unk_150__T_unk_8;
		case 2348: return DF_Type::world_data__T_unk_274;
		case 2349: return DF_Type::world_data__T_unk_274__T_unk_10;
		case 2350: return DF_Type::world_data__T_unk_482f8;
		case 2351: return DF_Type::world_data__T_unk_b4;
		case 2352: return DF_Type::world_gen_param_basest;
		case 2353: return DF_Type::world_gen_param_charst;
		case 2354: return DF_Type::world_gen_param_memberst;
		case 2355: return DF_Type::world_gen_param_seedst;
		case 2356: return DF_Type::world_gen_param_valuest;
		case 2357: return DF_Type::world_geo_biome;
		case 2358: return DF_Type::world_geo_layer;
		case 2359: return DF_Type::world_history;
		case 2360: return DF_Type::world_history__T_event_collections;
		case 2361: return DF_Type::world_history__T_intrigues;
		case 2362: return DF_Type::world_history__T_intrigues__T_anon_1;
		case 2363: return DF_Type::world_landmass;
		case 2364: return DF_Type::world_object_data;
		case 2365: return DF_Type::world_object_data__T_offloaded_buildings;
		case 2366: return DF_Type::world_object_data__T_offloaded_items;
		case 2367: return DF_Type::world_object_data__T_unk_94;
		case 2368: return DF_Type::world_population;
		case 2369: return DF_Type::world_population___union4;
		case 2370: return DF_Type::world_population_ref;
		case 2371: return DF_Type::world_population_type;
		case 2372: return DF_Type::world_raws;
		case 2373: return DF_Type::world_raws__T_bodyglosses;
		case 2374: return DF_Type::world_raws__T_buildings;
		case 2375: return DF_Type::world_raws__T_descriptors;
		case 2376: return DF_Type::world_raws__T_effects;
		case 2377: return DF_Type::world_raws__T_itemdefs;
		case 2378: return DF_Type::world_raws__T_language;
		case 2379: return DF_Type::world_raws__T_plants;
		case 2380: return DF_Type::world_raws__T_reactions;
		case 2381: return DF_Type::world_raws__T_syndromes;
		case 2382: return DF_Type::world_region;
		case 2383: return DF_Type::world_region_details;
		case 2384: return DF_Type::world_region_details__T_edges;
		case 2385: return DF_Type::world_region_details__T_other_features;
		case 2386: return DF_Type::world_region_details__T_rivers_horizontal;
		case 2387: return DF_Type::world_region_details__T_rivers_vertical;
		case 2388: return DF_Type::world_region_feature;
		case 2389: return DF_Type::world_region_type;
		case 2390: return DF_Type::world_river;
		case 2391: return DF_Type::world_site;
		case 2392: return DF_Type::world_site__T_subtype_info;
		case 2393: return DF_Type::world_site__T_unk_1;
		case 2394: return DF_Type::world_site__T_unk_118;
		case 2395: return DF_Type::world_site__T_unk_13c;
		case 2396: return DF_Type::world_site__T_unk_188;
		case 2397: return DF_Type::world_site__T_unk_188__T_unk1;
		case 2398: return DF_Type::world_site__T_unk_1__T_units;
		case 2399: return DF_Type::world_site__T_unk_21c;
		case 2400: return DF_Type::world_site__T_unk_v40_2;
		case 2401: return DF_Type::world_site__T_unk_v40_4a;
		case 2402: return DF_Type::world_site__T_unk_v40_4b;
		case 2403: return DF_Type::world_site__T_unk_v40_4c;
		case 2404: return DF_Type::world_site__T_unk_v40_4d;
		case 2405: return DF_Type::world_site__T_unk_v40_4d__T_anon_1;
		case 2406: return DF_Type::world_site__T_unk_v43_2;
		case 2407: return DF_Type::world_site__T_unk_v47_1;
		case 2408: return DF_Type::world_site__T_unk_v47_1__T_unk_1;
		case 2409: return DF_Type::world_site_flags;
		case 2410: return DF_Type::world_site_inhabitant;
		case 2411: return DF_Type::world_site_realization;
		case 2412: return DF_Type::world_site_realization__T_areas;
		case 2413: return DF_Type::world_site_realization__T_areas__T_type;
		case 2414: return DF_Type::world_site_realization__T_building_map;
		case 2415: return DF_Type::world_site_realization__T_river_map;
		case 2416: return DF_Type::world_site_realization__T_unk_193bc;
		case 2417: return DF_Type::world_site_realization__T_unk_193bc__T_unk_8;
		case 2418: return DF_Type::world_site_realization__T_unk_55e8;
		case 2419: return DF_Type::world_site_realization__T_unk_55e8__T_unk_v40_2;
		case 2420: return DF_Type::world_site_type;
		case 2421: return DF_Type::world_site_unk130;
		case 2422: return DF_Type::world_site_unk130__T_unk_4;
		case 2423: return DF_Type::world_underground_region;
		case 2424: return DF_Type::world_underground_region__T_type;
		case 2425: return DF_Type::world_unk26c678_unk38;
		case 2426: return DF_Type::world_unk_20;
		case 2427: return DF_Type::world_unk_20__T_anon_7;
		case 2428: return DF_Type::world_unk_6c;
		case 2429: return DF_Type::world_unk_a8;
		case 2430: return DF_Type::world_unk_b4;
		case 2431: return DF_Type::world_unk_c0;
		case 2432: return DF_Type::world_unk_c0__T_anon_7;
		case 2433: return DF_Type::worldgen_range_type;
		case 2434: return DF_Type::worldgen_region_type;
		case 2435: return DF_Type::wound_curse_info;
		case 2436: return DF_Type::wound_damage_flags1;
		case 2437: return DF_Type::wound_damage_flags2;
		case 2438: return DF_Type::wound_effect_type;
		case 2439: return DF_Type::written_content;
		case 2440: return DF_Type::written_content_style;
		case 2441: return DF_Type::written_content_type;
		case 2442: return DF_Type::z_level_flags;
		case 2443: return DF_Type::zoom_commands;
	}
	return DF_Type::None;
}
} // namespace rdf