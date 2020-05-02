#ifndef DF_TYPES_H
#define DF_TYPES_H

#include <string>
namespace rdf
{
	enum class DF_Type
	{
		None = 0,
		int64_t,
		uint64_t,
		int32_t,
		int16_t,
		uint32_t,
		uint16_t,
		uint8_t,
		int8_t,
		Void,
		Char,
		Long,
		Bool,
		Stl_string,
		Static_string,
		Ptr_string,
		Ptr_char,
		S_float,
		D_float,
		S_double,
		Padding,
Stl_fstream,
		abstract_building,
		abstract_building__T_inhabitants,
		abstract_building__T_unk1,
		abstract_building_contents,
		abstract_building_counting_housest,
		abstract_building_dark_towerst,
		abstract_building_dungeonst,
		abstract_building_dungeonst__T_dungeon_type,
		abstract_building_flags,
		abstract_building_guildhallst,
		abstract_building_inn_tavernst,
		abstract_building_inn_tavernst__T_room_info,
		abstract_building_keepst,
		abstract_building_libraryst,
		abstract_building_marketst,
		abstract_building_mead_hallst,
		abstract_building_templest,
		abstract_building_tombst,
		abstract_building_towerst,
		abstract_building_type,
		abstract_building_underworld_spirest,
		abstract_building_unk,
		abstract_building_unk__T_anon_1,
		active_script_var_longst,
		active_script_var_unitst,
		active_script_varst,
		activity_entry,
		activity_entry_type,
		activity_event,
		activity_event__T_flags,
		activity_event__T_unk_v42_1,
		activity_event__T_unk_v42_2,
		activity_event_combat_trainingst,
		activity_event_conflictst,
		activity_event_conflictst__T_sides,
		activity_event_conflictst__T_sides__T_enemies,
		activity_event_conversationst,
		activity_event_conversationst__T_anon_6,
		activity_event_conversationst__T_flags2,
		activity_event_conversationst__T_participants,
		activity_event_conversationst__T_turns,
		activity_event_conversationst__T_unk2,
		activity_event_conversationst__T_unk_b4,
		activity_event_copy_written_contentst,
		activity_event_copy_written_contentst__T_flagsmaybe,
		activity_event_discuss_topicst,
		activity_event_encounterst,
		activity_event_encounterst__T_anon_1,
		activity_event_encounterst__T_anon_2,
		activity_event_fill_service_orderst,
		activity_event_guardst,
		activity_event_harassmentst,
		activity_event_harassmentst__T_anon_2,
		activity_event_individual_skill_drillst,
		activity_event_make_believest,
		activity_event_participants,
		activity_event_performancest,
		activity_event_performancest__T_participant_actions,
		activity_event_play_with_toyst,
		activity_event_play_with_toyst__T_unk,
		activity_event_playst,
		activity_event_ponder_topicst,
		activity_event_prayerst,
		activity_event_ranged_practicest,
		activity_event_readst,
		activity_event_researchst,
		activity_event_reunionst,
		activity_event_skill_demonstrationst,
		activity_event_socializest,
		activity_event_sparringst,
		activity_event_sparringst__T_groups,
		activity_event_store_objectst,
		activity_event_teach_topicst,
		activity_event_training_sessionst,
		activity_event_type,
		activity_event_worshipst,
		activity_event_writest,
		activity_info,
		activity_info__T_flags,
		adventure_environment_ingest_from_containerst,
		adventure_environment_ingest_materialst,
		adventure_environment_optionst,
		adventure_environment_pickup_chop_treest,
		adventure_environment_pickup_ignite_vegst,
		adventure_environment_pickup_make_campfirest,
		adventure_environment_pickup_vermin_eventst,
		adventure_environment_place_in_bld_containerst,
		adventure_environment_place_in_it_containerst,
		adventure_environment_unit_suck_bloodst,
		adventure_item_interact_choicest,
		adventure_item_interact_fill_from_containerst,
		adventure_item_interact_fill_with_materialst,
		adventure_item_interact_give_namest,
		adventure_item_interact_heat_from_tilest,
		adventure_item_interact_pull_outst,
		adventure_item_interact_readst,
		adventure_item_interact_strugglest,
		adventure_log_item,
		adventure_movement_attack_creaturest,
		adventure_movement_building_interactst,
		adventure_movement_climbst,
		adventure_movement_hold_itemst,
		adventure_movement_hold_tilest,
		adventure_movement_item_interact_guidest,
		adventure_movement_item_interact_pushst,
		adventure_movement_item_interact_ridest,
		adventure_movement_item_interactst,
		adventure_movement_movest,
		adventure_movement_optionst,
		adventure_movement_release_hold_itemst,
		adventure_movement_release_hold_tilest,
		adventure_option_eat_item_contaminantst,
		adventure_option_eat_unit_contaminantst,
		adventure_option_view_contaminantst,
		adventure_optionst,
		adventurer_attribute_level,
		agreement,
		agreement__T_flags,
		agreement_details,
		agreement_details__T_data,
		agreement_details_data_citizenship,
		agreement_details_data_demonic_binding,
		agreement_details_data_join_party,
		agreement_details_data_location,
		agreement_details_data_parley,
		agreement_details_data_plot_abduct,
		agreement_details_data_plot_assassination,
		agreement_details_data_plot_conviction,
		agreement_details_data_plot_frame_treason,
		agreement_details_data_plot_induce_war,
		agreement_details_data_plot_infiltration_coup,
		agreement_details_data_plot_sabotage,
		agreement_details_data_plot_steal_artifact,
		agreement_details_data_position_corruption,
		agreement_details_data_promise_position,
		agreement_details_data_residency,
		agreement_details_type,
		agreement_party,
		agreement_party__T_anon_1,
		ammo_flags,
		animal_training_level,
		announcement_flags,
		announcement_type,
		announcements,
		appearance_modifier_growth_interval,
		appearance_modifier_type,
		architectural_element,
		armor_flags,
		armor_general_flags,
		armor_properties,
		army,
		army__T_members,
		army__T_unk_2c,
		army_controller,
		army_controller__T_type,
		army_controller__T_unk_64,
		army_controller_invasion,
		army_controller_invasion__T_anon_1,
		army_controller_sub1,
		army_controller_sub11,
		army_controller_sub11__T_anon_3,
		army_controller_sub12,
		army_controller_sub12__T_unk_4,
		army_controller_sub13,
		army_controller_sub13__T_anon_4,
		army_controller_sub14,
		army_controller_sub14__T_anon_4,
		army_controller_sub15,
		army_controller_sub15__T_anon_3,
		army_controller_sub16,
		army_controller_sub17,
		army_controller_sub18,
		army_controller_sub4,
		army_controller_sub4__T_unk_2,
		army_controller_sub5,
		army_controller_sub6,
		army_controller_sub7,
		army_controller_sub7__T_anon_3,
		army_controller_villain_visiting,
		army_flags,
		art_facet_type,
		art_image,
		art_image_chunk,
		art_image_element,
		art_image_element_creaturest,
		art_image_element_itemst,
		art_image_element_plantst,
		art_image_element_shapest,
		art_image_element_treest,
		art_image_element_type,
		art_image_property,
		art_image_property_intransitive_verbst,
		art_image_property_transitive_verbst,
		art_image_property_type,
		art_image_property_verb,
		art_image_ref,
		artifact_claim,
		artifact_claim_type,
		artifact_record,
		assign_trade_status,
		assign_trade_status__T_status,
		assume_identity_mode,
		barrack_preference_category,
		battlefield,
		battlefield__T_sapient_deaths,
		belief_system,
		biome_type,
		block_burrow,
		block_burrow_link,
		block_flags,
		block_square_event,
		block_square_event_designation_priorityst,
		block_square_event_frozen_liquidst,
		block_square_event_grassst,
		block_square_event_item_spatterst,
		block_square_event_material_spatterst,
		block_square_event_mineralst,
		block_square_event_mineralst__T_flags,
		block_square_event_spoorst,
		block_square_event_type,
		block_square_event_world_constructionst,
		body_appearance_modifier,
		body_component_info,
		body_detail_plan,
		body_layer_status,
		body_part_layer_flags,
		body_part_layer_raw,
		body_part_raw,
		body_part_raw_flags,
		body_part_status,
		body_part_template,
		body_part_template_contype,
		body_part_template_flags,
		body_size_info,
		body_template,
		bp_appearance_modifier,
		breath_attack_type,
		breed,
		breed__T_unk_18,
		breed__T_unk_28,
		breed__T_unk_8,
		build_req_choice_genst,
		build_req_choice_specst,
		build_req_choice_type,
		build_req_choicest,
		building,
		building__T_activities,
		building__T_job_claim_suppress,
		building_actual,
		building_actual__T_contained_items,
		building_animaltrapst,
		building_archerytargetst,
		building_archerytargetst__T_archery_direction,
		building_armorstandst,
		building_axle_horizontalst,
		building_axle_verticalst,
		building_bars_floorst,
		building_bars_verticalst,
		building_bedst,
		building_bedst__T_bed_flags,
		building_bookcasest,
		building_boxst,
		building_bridgest,
		building_bridgest__T_direction,
		building_cabinetst,
		building_cagest,
		building_cagest__T_cage_flags,
		building_chainst,
		building_chainst__T_chain_flags,
		building_chairst,
		building_civzonest,
		building_civzonest__T_gather_flags,
		building_civzonest__T_pit_flags,
		building_civzonest__T_zone_flags,
		building_coffinst,
		building_coffinst__T_burial_mode,
		building_constructionst,
		building_def,
		building_def_furnacest,
		building_def_item,
		building_def_workshopst,
		building_design,
		building_design__T_flags,
		building_display_furniturest,
		building_doorst,
		building_drawbuffer,
		building_extents,
		building_farmplotst,
		building_flags,
		building_floodgatest,
		building_furnacest,
		building_gear_assemblyst,
		building_gear_assemblyst__T_gear_flags,
		building_grate_floorst,
		building_grate_wallst,
		building_handler,
		building_hatchst,
		building_hivest,
		building_instrumentst,
		building_nest_boxst,
		building_nestst,
		building_offering_placest,
		building_road_dirtst,
		building_road_pavedst,
		building_roadst,
		building_rollersst,
		building_screw_pumpst,
		building_shopst,
		building_shopst__T_shop_flags,
		building_siegeenginest,
		building_siegeenginest__T_action,
		building_siegeenginest__T_facing,
		building_slabst,
		building_squad_use,
		building_statuest,
		building_stockpilest,
		building_supportst,
		building_supportst__T_support_flags,
		building_tablest,
		building_tablest__T_table_flags,
		building_traction_benchst,
		building_tradedepotst,
		building_tradedepotst__T_trade_flags,
		building_trapst,
		building_trapst__T_stop_flags,
		building_type,
		building_users,
		building_wagonst,
		building_water_wheelst,
		building_weaponrackst,
		building_weaponst,
		building_wellst,
		building_wellst__T_well_flags,
		building_windmillst,
		building_window_gemst,
		building_window_glassst,
		building_windowst,
		building_workshopst,
		buildings_other_id,
		builtin_mats,
		burrow,
		campfire,
		caravan_state,
		caravan_state__T_flags,
		caravan_state__T_trade_state,
		caste_attack,
		caste_attack__T_flags,
		caste_body_info,
		caste_body_info__T_extra_butcher_objects,
		caste_body_info__T_flags,
		caste_body_info__T_interactions,
		caste_body_info__T_interactions__T_type,
		caste_clothing_item,
		caste_raw,
		caste_raw__T_anon_1,
		caste_raw__T_attributes,
		caste_raw__T_bp_appearance,
		caste_raw__T_caste_profession_name,
		caste_raw__T_extracts,
		caste_raw__T_lair_hunter_speech,
		caste_raw__T_misc,
		caste_raw__T_personality,
		caste_raw__T_secretion,
		caste_raw__T_shearable_tissue_layer,
		caste_raw__T_sound,
		caste_raw__T_unk29,
		caste_raw__T_unknown2,
		caste_raw_flags,
		cave_column,
		cave_column_link,
		cave_column_rectangle,
		cie_add_tag_mask1,
		cie_add_tag_mask2,
		civzone_type,
		coin_batch,
		coin_batch__T_image_back,
		coin_batch__T_image_front,
		color_modifier_raw,
		combat_report_event_type,
		conflict_level,
		construction,
		construction_flags,
		construction_type,
		conversation,
		conversation__T_speech,
		conversation__T_state,
		conversation_menu,
		coord,
		coord2d,
		coord2d_path,
		coord_path,
		coord_rect,
		corpse_material_type,
		craft_material_class,
		creation_zone_pwg_alteration_campst,
		creation_zone_pwg_alteration_location_deathst,
		creation_zone_pwg_alteration_location_deathst__T_unk_1,
		creation_zone_pwg_alteration_location_deathst__T_unk_1__T_anon_1,
		creation_zone_pwg_alteration_srb_ruinedst,
		creation_zone_pwg_alteration_srp_ruinedst,
		creation_zone_pwg_alteration_type,
		creation_zone_pwg_alterationst,
		creature_graphics_appointment,
		creature_graphics_role,
		creature_handler,
		creature_interaction,
		creature_interaction__T_flags,
		creature_interaction_effect,
		creature_interaction_effect__T_counter_trigger,
		creature_interaction_effect_add_simple_flagst,
		creature_interaction_effect_bleedingst,
		creature_interaction_effect_blistersst,
		creature_interaction_effect_body_appearance_modifierst,
		creature_interaction_effect_body_mat_interactionst,
		creature_interaction_effect_body_transformationst,
		creature_interaction_effect_bp_appearance_modifierst,
		creature_interaction_effect_bruisingst,
		creature_interaction_effect_can_do_interactionst,
		creature_interaction_effect_change_personalityst,
		creature_interaction_effect_close_open_woundsst,
		creature_interaction_effect_cough_bloodst,
		creature_interaction_effect_cure_infectionsst,
		creature_interaction_effect_cure_infectionst,
		creature_interaction_effect_display_namest,
		creature_interaction_effect_display_symbolst,
		creature_interaction_effect_dizzinessst,
		creature_interaction_effect_drowsinessst,
		creature_interaction_effect_erratic_behaviorst,
		creature_interaction_effect_feel_emotionst,
		creature_interaction_effect_feverst,
		creature_interaction_effect_flags,
		creature_interaction_effect_flash_symbolst,
		creature_interaction_effect_heal_nervesst,
		creature_interaction_effect_heal_tissuesst,
		creature_interaction_effect_impair_functionst,
		creature_interaction_effect_material_force_adjustst,
		creature_interaction_effect_ment_att_changest,
		creature_interaction_effect_nauseast,
		creature_interaction_effect_necrosisst,
		creature_interaction_effect_numbnessst,
		creature_interaction_effect_oozingst,
		creature_interaction_effect_painst,
		creature_interaction_effect_paralysisst,
		creature_interaction_effect_phys_att_changest,
		creature_interaction_effect_reduce_dizzinessst,
		creature_interaction_effect_reduce_feverst,
		creature_interaction_effect_reduce_nauseast,
		creature_interaction_effect_reduce_painst,
		creature_interaction_effect_reduce_paralysisst,
		creature_interaction_effect_reduce_swellingst,
		creature_interaction_effect_regrow_partsst,
		creature_interaction_effect_remove_simple_flagst,
		creature_interaction_effect_sense_creature_classst,
		creature_interaction_effect_skill_roll_adjustst,
		creature_interaction_effect_special_attack_interactionst,
		creature_interaction_effect_speed_changest,
		creature_interaction_effect_stop_bleedingst,
		creature_interaction_effect_swellingst,
		creature_interaction_effect_target,
		creature_interaction_effect_target_mode,
		creature_interaction_effect_type,
		creature_interaction_effect_unconsciousnessst,
		creature_interaction_effect_vomit_bloodst,
		creature_interaction_target_flags,
		creature_raw,
		creature_raw__T_graphics,
		creature_raw__T_hive_product,
		creature_raw__T_profession_name,
		creature_raw_flags,
		creature_variation,
		creature_variation_convert_tag,
		crime,
		crime__T_convict_data,
		crime__T_counterintelligence,
		crime__T_flags,
		crime__T_mode,
		crime__T_punishment,
		crime__T_reports,
		crime__T_victim_data,
		crime_type,
		cultural_identity,
		cultural_identity__T_anon_1,
		cultural_identity__T_anon_2,
		cultural_identity__T_group_log,
		cultural_identity__T_group_log__T_join_type,
		cumulus_type,
		curse_attr_change,
		d_init,
		d_init__T_store_dist,
		d_init__T_wound_color,
		d_init_embark_confirm,
		d_init_flags1,
		d_init_flags2,
		d_init_flags3,
		d_init_flags4,
		d_init_idlers,
		d_init_nickname,
		d_init_tunnel,
		d_init_z_view,
		dance_form,
		dance_form_sub1,
		dance_form_sub2,
		death_condition_type,
		death_type,
		deep_vein_hollow,
		descriptor_color,
		descriptor_pattern,
		descriptor_shape,
		descriptor_shape__T_gems_use,
		dfhack_knowledge_scholar_flag,
		dfhack_material_category,
		dfhack_room_quality_level,
		dipscript_info,
		dipscript_popup,
		dipscript_popup__T_flags,
		divination_set,
		divination_set_roll,
		door_flags,
		dye_info,
		effect_info,
		embark_feature,
		embark_finder_option,
		embark_item_choice,
		embark_item_choice__T_list,
		embark_location,
		embark_note,
		embark_profile,
		emotion_type,
		enabler,
		enabler__T_async_frombox,
		enabler__T_async_frombox__T_queue,
		enabler__T_async_frombox__T_queue___union0,
		enabler__T_async_frombox__T_queue___union0___struct1,
		enabler__T_async_frombox__T_queue__T_msg,
		enabler__T_async_tobox,
		enabler__T_async_tobox__T_queue,
		enabler__T_async_tobox__T_queue__T_cmd,
		enabler__T_async_zoom,
		enabler__T_flag,
		enabler__T_gputicks,
		enabler__T_overridden_grid_sizes,
		enabler__T_simticks,
		enabler__T_text_system,
		enabler__T_text_system__T_file_info,
		enabler__T_textures,
		engraving,
		engraving_flags,
		entity_action_type,
		entity_activity_statistics,
		entity_activity_statistics__T_food,
		entity_activity_statistics__T_found_misc,
		entity_activity_statistics__T_wealth,
		entity_animal_raw,
		entity_animal_raw__T_flags,
		entity_buy_prices,
		entity_buy_requests,
		entity_claim_mask,
		entity_claim_mask__T_map,
		entity_entity_link,
		entity_entity_link_type,
		entity_event,
		entity_event__T_data,
		entity_event__T_data__T_abandon,
		entity_event__T_data__T_abduction,
		entity_event__T_data__T_accept_peace_offer,
		entity_event__T_data__T_accept_tribute_demand,
		entity_event__T_data__T_accept_tribute_offer,
		entity_event__T_data__T_artifact_destroyed,
		entity_event__T_data__T_artifact_in_feature_layer,
		entity_event__T_data__T_artifact_in_inventory,
		entity_event__T_data__T_artifact_in_site,
		entity_event__T_data__T_artifact_in_subregion,
		entity_event__T_data__T_artifact_not_in_feature_layer,
		entity_event__T_data__T_artifact_not_in_inventory,
		entity_event__T_data__T_artifact_not_in_site,
		entity_event__T_data__T_artifact_not_in_subregion,
		entity_event__T_data__T_beast,
		entity_event__T_data__T_cease_tribute_offer,
		entity_event__T_data__T_claim,
		entity_event__T_data__T_flee,
		entity_event__T_data__T_founded,
		entity_event__T_data__T_founding,
		entity_event__T_data__T_group,
		entity_event__T_data__T_harass,
		entity_event__T_data__T_incident,
		entity_event__T_data__T_insurrection,
		entity_event__T_data__T_insurrection_end,
		entity_event__T_data__T_insurrection_end__T_result,
		entity_event__T_data__T_invasion,
		entity_event__T_data__T_leave,
		entity_event__T_data__T_occupation,
		entity_event__T_data__T_reclaimed,
		entity_event__T_data__T_reclaiming,
		entity_event__T_data__T_refuse_peace_offer,
		entity_event__T_data__T_refuse_tribute_demand,
		entity_event__T_data__T_refuse_tribute_offer,
		entity_event__T_data__T_succession,
		entity_event_type,
		entity_material_category,
		entity_name_type,
		entity_occasion,
		entity_occasion_info,
		entity_occasion_schedule,
		entity_occasion_schedule_feature,
		entity_population,
		entity_population_unk4,
		entity_population_unk4__T_anon_1,
		entity_population_unk4__T_anon_2,
		entity_population_unk4__T_anon_3,
		entity_position,
		entity_position_assignment,
		entity_position_flags,
		entity_position_raw,
		entity_position_raw_flags,
		entity_position_responsibility,
		entity_raw,
		entity_raw__T_equipment,
		entity_raw__T_jobs,
		entity_raw__T_land_holder_trigger,
		entity_raw__T_progress_trigger,
		entity_raw__T_scholar,
		entity_raw__T_symbols,
		entity_raw__T_tissue_styles,
		entity_raw__T_workshops,
		entity_raw_flags,
		entity_recipe,
		entity_sell_category,
		entity_sell_prices,
		entity_sell_requests,
		entity_site_link,
		entity_site_link__T_unk_7,
		entity_site_link_flags,
		entity_site_link_status_flags,
		entity_site_link_type,
		entity_tissue_style,
		entity_uniform,
		entity_uniform_item,
		entity_unk_v47_1,
		environment_type,
		era_type,
		ethic_response,
		ethic_type,
		export_map_type,
		feature,
		feature_alteration,
		feature_alteration_new_lava_fill_zst,
		feature_alteration_new_pop_maxst,
		feature_alteration_type,
		feature_cavest,
		feature_deep_special_tubest,
		feature_deep_surface_portalst,
		feature_init,
		feature_init_cavest,
		feature_init_deep_special_tubest,
		feature_init_deep_surface_portalst,
		feature_init_flags,
		feature_init_magma_core_from_layerst,
		feature_init_magma_poolst,
		feature_init_outdoor_riverst,
		feature_init_pitst,
		feature_init_subterranean_from_layerst,
		feature_init_underworld_from_layerst,
		feature_init_volcanost,
		feature_magma_core_from_layerst,
		feature_magma_poolst,
		feature_outdoor_riverst,
		feature_pitst,
		feature_subterranean_from_layerst,
		feature_type,
		feature_underworld_from_layerst,
		feature_volcanost,
		file_compressorst,
		fire,
		flow_guide,
		flow_guide_item_cloudst,
		flow_guide_trailing_flowst,
		flow_guide_type,
		flow_info,
		flow_reuse_pool,
		flow_reuse_pool__T_flags,
		flow_type,
		fog_type,
		fortress_type,
		front_type,
		furnace_type,
		furniture_type,
		gait_info,
		gait_info__T_flags,
		gait_type,
		game_mode,
		game_type,
		gate_flags,
		general_ref,
		general_ref_abstract_buildingst,
		general_ref_activity_eventst,
		general_ref_artifact,
		general_ref_building,
		general_ref_building_cagedst,
		general_ref_building_chainst,
		general_ref_building_civzone_assignedst,
		general_ref_building_destinationst,
		general_ref_building_display_furniturest,
		general_ref_building_holderst,
		general_ref_building_nest_boxst,
		general_ref_building_triggerst,
		general_ref_building_triggertargetst,
		general_ref_building_use_target_1st,
		general_ref_building_use_target_2st,
		general_ref_building_well_tag,
		general_ref_coinbatch,
		general_ref_contained_in_itemst,
		general_ref_contains_itemst,
		general_ref_contains_unitst,
		general_ref_creaturest,
		general_ref_dance_formst,
		general_ref_entity,
		general_ref_entity_art_image,
		general_ref_entity_itemownerst,
		general_ref_entity_offeredst,
		general_ref_entity_popst,
		general_ref_entity_stolenst,
		general_ref_feature_layerst,
		general_ref_historical_eventst,
		general_ref_historical_figurest,
		general_ref_interactionst,
		general_ref_is_artifactst,
		general_ref_is_nemesisst,
		general_ref_item,
		general_ref_item_type,
		general_ref_knowledge_scholar_flagst,
		general_ref_languagest,
		general_ref_locationst,
		general_ref_mapsquare,
		general_ref_musical_formst,
		general_ref_nemesis,
		general_ref_poetic_formst,
		general_ref_projectile,
		general_ref_sitest,
		general_ref_spherest,
		general_ref_subregionst,
		general_ref_type,
		general_ref_unit,
		general_ref_unit_beateest,
		general_ref_unit_cageest,
		general_ref_unit_climberst,
		general_ref_unit_foodreceiverst,
		general_ref_unit_geldeest,
		general_ref_unit_holderst,
		general_ref_unit_infantst,
		general_ref_unit_interrogateest,
		general_ref_unit_itemownerst,
		general_ref_unit_itemownerst__T_flags,
		general_ref_unit_kidnapeest,
		general_ref_unit_milkeest,
		general_ref_unit_patientst,
		general_ref_unit_reporteest,
		general_ref_unit_riderst,
		general_ref_unit_sheareest,
		general_ref_unit_slaughtereest,
		general_ref_unit_suckeest,
		general_ref_unit_tradebringerst,
		general_ref_unit_traineest,
		general_ref_unit_workerst,
		general_ref_value_levelst,
		general_ref_written_contentst,
		geo_layer_type,
		ghost_goal,
		ghost_type,
		gloves_flags,
		glowing_barrier,
		goal_type,
		graphic,
		guild_id,
		hauler_type,
		hauling_route,
		hauling_stop,
		health_view_bits1,
		health_view_bits2,
		health_view_bits3,
		helm_flags,
		hillock_house_type,
		histfig_body_state,
		histfig_entity_link,
		histfig_entity_link_criminalst,
		histfig_entity_link_enemyst,
		histfig_entity_link_former_memberst,
		histfig_entity_link_former_mercenaryst,
		histfig_entity_link_former_occupationst,
		histfig_entity_link_former_positionst,
		histfig_entity_link_former_prisonerst,
		histfig_entity_link_former_slavest,
		histfig_entity_link_former_squadst,
		histfig_entity_link_memberst,
		histfig_entity_link_mercenaryst,
		histfig_entity_link_occupationst,
		histfig_entity_link_position_claimst,
		histfig_entity_link_positionst,
		histfig_entity_link_prisonerst,
		histfig_entity_link_slavest,
		histfig_entity_link_squadst,
		histfig_entity_link_type,
		histfig_flags,
		histfig_hf_link,
		histfig_hf_link_apprenticest,
		histfig_hf_link_childst,
		histfig_hf_link_companionst,
		histfig_hf_link_deceased_spousest,
		histfig_hf_link_deityst,
		histfig_hf_link_fatherst,
		histfig_hf_link_former_apprenticest,
		histfig_hf_link_former_masterst,
		histfig_hf_link_former_spousest,
		histfig_hf_link_imprisonerst,
		histfig_hf_link_loverst,
		histfig_hf_link_masterst,
		histfig_hf_link_motherst,
		histfig_hf_link_pet_ownerst,
		histfig_hf_link_prisonerst,
		histfig_hf_link_spousest,
		histfig_hf_link_type,
		histfig_relationship_type,
		histfig_site_link,
		histfig_site_link_hangoutst,
		histfig_site_link_home_site_abstract_buildingst,
		histfig_site_link_home_site_realization_buildingst,
		histfig_site_link_home_site_realization_sulst,
		histfig_site_link_home_site_saved_civzonest,
		histfig_site_link_lairst,
		histfig_site_link_occupationst,
		histfig_site_link_prison_abstract_buildingst,
		histfig_site_link_prison_site_building_profilest,
		histfig_site_link_seat_of_powerst,
		histfig_site_link_type,
		historical_entity,
		historical_entity__T_claims,
		historical_entity__T_derived_resources,
		historical_entity__T_flags,
		historical_entity__T_guild_professions,
		historical_entity__T_positions,
		historical_entity__T_relations,
		historical_entity__T_relations__T_constructions,
		historical_entity__T_relations__T_diplomacy,
		historical_entity__T_resources,
		historical_entity__T_resources__T_animals,
		historical_entity__T_resources__T_metal,
		historical_entity__T_resources__T_misc_mat,
		historical_entity__T_resources__T_organic,
		historical_entity__T_resources__T_refuse,
		historical_entity__T_resources__T_unk13,
		historical_entity__T_resources__T_wood_products,
		historical_entity__T_tissue_styles,
		historical_entity__T_training_knowledge,
		historical_entity__T_unk_v47_1,
		historical_entity__T_unknown1d,
		historical_entity__T_unknown1e,
		historical_entity__T_unknown2,
		historical_entity__T_unknown2__T_unk28,
		historical_entity__T_unknown2__T_unk29,
		historical_entity_type,
		historical_figure,
		historical_figure__T_unk_fc,
		historical_figure__T_unk_v47_2,
		historical_figure__T_vague_relationships,
		historical_figure_info,
		historical_figure_info__T_books,
		historical_figure_info__T_books__T_flags,
		historical_figure_info__T_curse,
		historical_figure_info__T_curse__T_anon_1,
		historical_figure_info__T_curse__T_experiments,
		historical_figure_info__T_known_info,
		historical_figure_info__T_known_info__T_anon_1,
		historical_figure_info__T_known_info__T_anon_6,
		historical_figure_info__T_known_info__T_knowledge,
		historical_figure_info__T_known_info__T_knowledge__T_knowledge_goal,
		historical_figure_info__T_known_info__T_unk_a8,
		historical_figure_info__T_masterpieces,
		historical_figure_info__T_personality,
		historical_figure_info__T_relationships,
		historical_figure_info__T_relationships__T_anon_1,
		historical_figure_info__T_relationships__T_artifact_claims,
		historical_figure_info__T_relationships__T_hf_historical,
		historical_figure_info__T_relationships__T_hf_visual,
		historical_figure_info__T_relationships__T_intrigues,
		historical_figure_info__T_relationships__T_intrigues__T_intrigue,
		historical_figure_info__T_relationships__T_intrigues__T_plots,
		historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data,
		historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data__T_Infiltrate_Society,
		historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_data__T_Sabotage_Actor,
		historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_type,
		historical_figure_info__T_reputation,
		historical_figure_info__T_reputation__T_anon_1,
		historical_figure_info__T_reputation__T_unk_2c,
		historical_figure_info__T_reputation__T_unk_2c__T_anon_12,
		historical_figure_info__T_reputation__T_wanted,
		historical_figure_info__T_reputation__T_wanted__T_unk,
		historical_figure_info__T_skills,
		historical_figure_info__T_skills__T_employment_held,
		historical_figure_info__T_skills__T_employment_held__T_employment,
		historical_figure_info__T_whereabouts,
		historical_figure_info__T_wounds,
		historical_kills,
		history_era,
		history_era__T_details,
		history_era__T_title,
		history_event,
		history_event_add_entity_site_profile_flagst,
		history_event_add_hf_entity_honorst,
		history_event_add_hf_entity_linkst,
		history_event_add_hf_hf_linkst,
		history_event_add_hf_site_linkst,
		history_event_agreement_concludedst,
		history_event_agreement_formedst,
		history_event_agreements_voidedst,
		history_event_artifact_claim_formedst,
		history_event_artifact_copiedst,
		history_event_artifact_copiedst__T_flags2,
		history_event_artifact_createdst,
		history_event_artifact_createdst__T_flags2,
		history_event_artifact_destroyedst,
		history_event_artifact_droppedst,
		history_event_artifact_foundst,
		history_event_artifact_givenst,
		history_event_artifact_hiddenst,
		history_event_artifact_lostst,
		history_event_artifact_possessedst,
		history_event_artifact_recoveredst,
		history_event_artifact_storedst,
		history_event_artifact_transformedst,
		history_event_assume_identityst,
		history_event_body_abusedst,
		history_event_body_abusedst__T_abuse_data,
		history_event_body_abusedst__T_abuse_data__T_Animated,
		history_event_body_abusedst__T_abuse_data__T_Flayed,
		history_event_body_abusedst__T_abuse_data__T_Hung,
		history_event_body_abusedst__T_abuse_data__T_Impaled,
		history_event_body_abusedst__T_abuse_data__T_Piled,
		history_event_body_abusedst__T_abuse_data__T_Piled__T_pile_type,
		history_event_body_abusedst__T_abuse_type,
		history_event_building_profile_acquiredst,
		history_event_ceremonyst,
		history_event_change_creature_typest,
		history_event_change_hf_body_statest,
		history_event_change_hf_jobst,
		history_event_change_hf_moodst,
		history_event_change_hf_statest,
		history_event_change_hf_statest__T_state,
		history_event_circumstance_info,
		history_event_circumstance_info__T_data,
		history_event_collection,
		history_event_collection_abductionst,
		history_event_collection_battlest,
		history_event_collection_battlest__T_attacker_merc_type,
		history_event_collection_beast_attackst,
		history_event_collection_ceremonyst,
		history_event_collection_competitionst,
		history_event_collection_duelst,
		history_event_collection_entity_overthrownst,
		history_event_collection_insurrectionst,
		history_event_collection_journeyst,
		history_event_collection_occasionst,
		history_event_collection_performancest,
		history_event_collection_persecutionst,
		history_event_collection_processionst,
		history_event_collection_purgest,
		history_event_collection_raidst,
		history_event_collection_site_conqueredst,
		history_event_collection_theftst,
		history_event_collection_type,
		history_event_collection_warst,
		history_event_collection_warst__T_unk,
		history_event_competitionst,
		history_event_context,
		history_event_context__T_unk_10,
		history_event_create_entity_positionst,
		history_event_created_buildingst,
		history_event_created_sitest,
		history_event_created_world_constructionst,
		history_event_creature_devouredst,
		history_event_dance_form_createdst,
		history_event_diplomat_lostst,
		history_event_entity_actionst,
		history_event_entity_alliance_formedst,
		history_event_entity_breach_feature_layerst,
		history_event_entity_createdst,
		history_event_entity_dissolvedst,
		history_event_entity_equipment_purchasest,
		history_event_entity_expels_hfst,
		history_event_entity_fled_sitest,
		history_event_entity_incorporatedst,
		history_event_entity_lawst,
		history_event_entity_lawst__T_add_flags,
		history_event_entity_lawst__T_remove_flags,
		history_event_entity_overthrownst,
		history_event_entity_persecutedst,
		history_event_entity_rampaged_in_sitest,
		history_event_entity_razed_buildingst,
		history_event_entity_searched_sitest,
		history_event_failed_frame_attemptst,
		history_event_failed_intrigue_corruptionst,
		history_event_first_contact_failedst,
		history_event_first_contactst,
		history_event_flags,
		history_event_gamblest,
		history_event_hf_act_on_artifactst,
		history_event_hf_act_on_artifactst__T_action,
		history_event_hf_act_on_buildingst,
		history_event_hf_act_on_buildingst__T_action,
		history_event_hf_attacked_sitest,
		history_event_hf_confrontedst,
		history_event_hf_convictedst,
		history_event_hf_convictedst__T_plot_flags,
		history_event_hf_convictedst__T_punishment_flags,
		history_event_hf_destroyed_sitest,
		history_event_hf_does_interactionst,
		history_event_hf_enslavedst,
		history_event_hf_freedst,
		history_event_hf_gains_secret_goalst,
		history_event_hf_interrogatedst,
		history_event_hf_interrogatedst__T_interrogation_flags,
		history_event_hf_learns_secretst,
		history_event_hf_preachst,
		history_event_hf_ransomedst,
		history_event_hf_razed_buildingst,
		history_event_hf_recruited_unit_type_for_entityst,
		history_event_hf_relationship_deniedst,
		history_event_hfs_formed_intrigue_relationshipst,
		history_event_hfs_formed_reputation_relationshipst,
		history_event_hist_figure_abductedst,
		history_event_hist_figure_diedst,
		history_event_hist_figure_new_petst,
		history_event_hist_figure_reach_summitst,
		history_event_hist_figure_reunionst,
		history_event_hist_figure_revivedst,
		history_event_hist_figure_revivedst__T_flags2,
		history_event_hist_figure_simple_actionst,
		history_event_hist_figure_simple_battle_eventst,
		history_event_hist_figure_travelst,
		history_event_hist_figure_travelst__T_reason,
		history_event_hist_figure_woundedst,
		history_event_hist_figure_woundedst__T_flags2,
		history_event_hist_figure_woundedst__T_injury_type,
		history_event_insurrection_endedst,
		history_event_insurrection_startedst,
		history_event_item_stolenst,
		history_event_knowledge_discoveredst,
		history_event_masterpiece_created_arch_constructst,
		history_event_masterpiece_created_arch_designst,
		history_event_masterpiece_created_dye_itemst,
		history_event_masterpiece_created_engravingst,
		history_event_masterpiece_created_foodst,
		history_event_masterpiece_created_item_improvementst,
		history_event_masterpiece_created_itemst,
		history_event_masterpiece_createdst,
		history_event_masterpiece_lostst,
		history_event_merchantst,
		history_event_modified_buildingst,
		history_event_modified_buildingst__T_modification,
		history_event_musical_form_createdst,
		history_event_performancest,
		history_event_poetic_form_createdst,
		history_event_processionst,
		history_event_reason,
		history_event_reason_info,
		history_event_reason_info__T_data,
		history_event_reclaim_sitest,
		history_event_reclaim_sitest__T_flags2,
		history_event_regionpop_incorporated_into_entityst,
		history_event_remove_hf_entity_linkst,
		history_event_remove_hf_hf_linkst,
		history_event_remove_hf_site_linkst,
		history_event_replaced_buildingst,
		history_event_sabotagest,
		history_event_simple_battle_subtype,
		history_event_site_diedst,
		history_event_site_diedst__T_flags2,
		history_event_site_disputest,
		history_event_site_retiredst,
		history_event_site_retiredst__T_flags2,
		history_event_site_surrenderedst,
		history_event_sneak_into_sitest,
		history_event_spotted_leaving_sitest,
		history_event_squad_vs_squadst,
		history_event_tactical_situationst,
		history_event_tactical_situationst__T_tactics_flags,
		history_event_topicagreement_concludedst,
		history_event_topicagreement_madest,
		history_event_topicagreement_rejectedst,
		history_event_tradest,
		history_event_type,
		history_event_war_attacked_sitest,
		history_event_war_attacked_sitest__T_unk_1,
		history_event_war_destroyed_sitest,
		history_event_war_field_battlest,
		history_event_war_peace_acceptedst,
		history_event_war_peace_rejectedst,
		history_event_war_plundered_sitest,
		history_event_war_site_new_leaderst,
		history_event_war_site_taken_overst,
		history_event_war_site_tribute_forcedst,
		history_event_war_site_tribute_forcedst__T_tribute_flags,
		history_event_written_content_composedst,
		history_hit_item,
		hive_flags,
		honors_type,
		honors_type__T_flags,
		honors_type__T_required_skill_type,
		hospital_supplies,
		hospital_supplies__T_supplies_needed,
		identity,
		identity___union1,
		identity_type,
		identity_unk_94,
		image_set,
		image_set__T_unk_vec1,
		improvement_type,
		incident,
		incident__T_data,
		incident__T_flags,
		incident__T_type,
		incident_hfid,
		incident_sub10,
		incident_sub6_performance,
		incident_sub6_performance__T_participants,
		incident_sub7,
		incident_sub8,
		incident_sub9,
		inclusion_type,
		init,
		init_display,
		init_display__T_windowed,
		init_display_flags,
		init_font,
		init_font__T_use_ttf,
		init_input,
		init_input_flags,
		init_media,
		init_media_flags,
		init_window,
		init_window_flags,
		inorganic_flags,
		inorganic_raw,
		inorganic_raw__T_environment,
		inorganic_raw__T_environment_spec,
		inorganic_raw__T_metal_ore,
		inorganic_raw__T_thread_metal,
		instrument_flags,
		instrument_piece,
		instrument_piece__T_flags,
		instrument_register,
		insurrection_outcome,
		interaction,
		interaction_effect,
		interaction_effect__T_flags,
		interaction_effect_add_syndromest,
		interaction_effect_animatest,
		interaction_effect_change_item_qualityst,
		interaction_effect_change_weatherst,
		interaction_effect_cleanst,
		interaction_effect_contactst,
		interaction_effect_create_itemst,
		interaction_effect_hidest,
		interaction_effect_location_hint,
		interaction_effect_material_emissionst,
		interaction_effect_propel_unitst,
		interaction_effect_resurrectst,
		interaction_effect_summon_unitst,
		interaction_effect_type,
		interaction_flags,
		interaction_instance,
		interaction_source,
		interaction_source_attackst,
		interaction_source_creature_actionst,
		interaction_source_deityst,
		interaction_source_disturbancest,
		interaction_source_experimentst,
		interaction_source_ingestionst,
		interaction_source_regionst,
		interaction_source_regionst__T_region_flags,
		interaction_source_secretst,
		interaction_source_secretst__T_learn_flags,
		interaction_source_type,
		interaction_source_underground_specialst,
		interaction_source_usage_hint,
		interaction_target,
		interaction_target_corpsest,
		interaction_target_creaturest,
		interaction_target_info,
		interaction_target_info__T_restrictions,
		interaction_target_location_type,
		interaction_target_locationst,
		interaction_target_materialst,
		interaction_target_materialst__T_restrictions,
		interaction_target_type,
		interface_breakdown_types,
		interface_button,
		interface_button_building_category_selectorst,
		interface_button_building_custom_category_selectorst,
		interface_button_building_material_selectorst,
		interface_button_building_new_jobst,
		interface_button_buildingst,
		interface_button_construction_building_selectorst,
		interface_button_construction_category_selectorst,
		interface_button_construction_category_selectorst__T_category_id,
		interface_button_construction_donest,
		interface_button_constructionst,
		interface_key,
		interfacest,
		interrogation_report,
		invasion_info,
		invasion_info__T_flags,
		item,
		item_actual,
		item_ammost,
		item_amuletst,
		item_animaltrapst,
		item_anvilst,
		item_armorst,
		item_armorstandst,
		item_backpackst,
		item_ballistaarrowheadst,
		item_ballistapartsst,
		item_barrelst,
		item_barst,
		item_bedst,
		item_binst,
		item_blocksst,
		item_body_component,
		item_body_component__T_appearance,
		item_body_component__T_body,
		item_body_component__T_bone1,
		item_body_component__T_bone2,
		item_body_component__T_corpse_flags,
		item_bookst,
		item_boulderst,
		item_boxst,
		item_braceletst,
		item_branchst,
		item_bucketst,
		item_cabinetst,
		item_cagest,
		item_catapultpartsst,
		item_chainst,
		item_chairst,
		item_cheesest,
		item_clothst,
		item_coffinst,
		item_coinst,
		item_constructed,
		item_corpsepiecest,
		item_corpsest,
		item_crafted,
		item_critter,
		item_crownst,
		item_crutchst,
		item_doorst,
		item_drinkst,
		item_earringst,
		item_eggst,
		item_eggst__T_egg_flags,
		item_figurinest,
		item_filter_spec,
		item_fish_rawst,
		item_fishst,
		item_flags,
		item_flags2,
		item_flaskst,
		item_floodgatest,
		item_foodst,
		item_foodst__T_ingredients,
		item_gemst,
		item_globst,
		item_glovesst,
		item_gobletst,
		item_gratest,
		item_hatch_coverst,
		item_helmst,
		item_history_info,
		item_instrumentst,
		item_kill_info,
		item_liquid,
		item_liquid_miscst,
		item_liquipowder,
		item_magicness,
		item_magicness_type,
		item_matstate,
		item_meatst,
		item_millstonest,
		item_orthopedic_castst,
		item_pantsst,
		item_petst,
		item_petst__T_pet_flags,
		item_pipe_sectionst,
		item_plant_growthst,
		item_plantst,
		item_powder,
		item_powder_miscst,
		item_quality,
		item_quernst,
		item_quiverst,
		item_remainsst,
		item_ringst,
		item_rockst,
		item_roughst,
		item_scepterst,
		item_seedsst,
		item_sheetst,
		item_shieldst,
		item_shoesst,
		item_siegeammost,
		item_skin_tannedst,
		item_slabst,
		item_smallgemst,
		item_splintst,
		item_statuest,
		item_stockpile_ref,
		item_tablest,
		item_threadst,
		item_toolst,
		item_totemst,
		item_toyst,
		item_traction_benchst,
		item_trapcompst,
		item_trappartsst,
		item_type,
		item_verminst,
		item_weaponrackst,
		item_weaponst,
		item_windowst,
		item_woodst,
		itemdef,
		itemdef_ammost,
		itemdef_armorst,
		itemdef_flags,
		itemdef_foodst,
		itemdef_glovesst,
		itemdef_helmst,
		itemdef_instrumentst,
		itemdef_pantsst,
		itemdef_shieldst,
		itemdef_shoesst,
		itemdef_siegeammost,
		itemdef_toolst,
		itemdef_toolst__T_default_improvements,
		itemdef_toyst,
		itemdef_trapcompst,
		itemdef_weaponst,
		itemimprovement,
		itemimprovement_art_imagest,
		itemimprovement_bandsst,
		itemimprovement_clothst,
		itemimprovement_coveredst,
		itemimprovement_coveredst__T_cover_flags,
		itemimprovement_illustrationst,
		itemimprovement_instrument_piecest,
		itemimprovement_itemspecificst,
		itemimprovement_pagesst,
		itemimprovement_rings_hangingst,
		itemimprovement_sewn_imagest,
		itemimprovement_sewn_imagest__T_cloth,
		itemimprovement_specific_type,
		itemimprovement_spikesst,
		itemimprovement_threadst,
		itemimprovement_writingst,
		items_other_id,
		job,
		job_art_specification,
		job_art_specification__T_type,
		job_flags,
		job_handler,
		job_handler__T_anon_1,
		job_handler__T_postings,
		job_handler__T_postings__T_flags,
		job_item,
		job_item_filter,
		job_item_flags1,
		job_item_flags2,
		job_item_flags3,
		job_item_ref,
		job_item_ref__T_role,
		job_item_vector_id,
		job_list_link,
		job_material_category,
		job_skill,
		job_skill_class,
		job_subtype_surgery,
		job_type,
		job_type_class,
		justification,
		KeybindingScreen,
		KeybindingScreen__T_mode,
		kitchen_exc_type,
		kitchen_pref_flag,
		knowledge_scholar_category_flag,
		knowledge_scholar_category_flag__T_flag_data,
		knowledge_scholar_category_flag__T_flag_type,
		knowledge_scholar_flags_0,
		knowledge_scholar_flags_1,
		knowledge_scholar_flags_10,
		knowledge_scholar_flags_11,
		knowledge_scholar_flags_12,
		knowledge_scholar_flags_13,
		knowledge_scholar_flags_2,
		knowledge_scholar_flags_3,
		knowledge_scholar_flags_4,
		knowledge_scholar_flags_5,
		knowledge_scholar_flags_6,
		knowledge_scholar_flags_7,
		knowledge_scholar_flags_8,
		knowledge_scholar_flags_9,
		lair_type,
		language_name,
		language_name_category,
		language_symbol,
		language_translation,
		language_word,
		language_word_flags,
		language_word_table,
		large_integer,
		large_integer___struct0,
		large_integer__T_u,
		layer_object,
		layer_object_buttonst,
		layer_object_listst,
		layer_type,
		lever_target_type,
		loadgame_save_info,
		local_population,
		local_population___union4,
		local_population__T_flags,
		location_scribe_jobs,
		machine,
		machine__T_components,
		machine__T_flags,
		machine_conn_modes,
		machine_handler,
		machine_info,
		machine_info__T_flags,
		machine_standardst,
		machine_tile_set,
		machine_type,
		MacroScreenLoad,
		MacroScreenSave,
		manager_order,
		manager_order__T_frequency,
		manager_order_condition_item,
		manager_order_condition_item__T_compare_type,
		manager_order_condition_order,
		manager_order_condition_order__T_condition,
		manager_order_status,
		manager_order_template,
		mandate,
		mandate__T_mode,
		mandate__T_punishment,
		map_block,
		map_block_column,
		map_block_column__T_unmined_glyphs,
		map_renderer,
		map_renderer__T_anon_4,
		map_viewport,
		masterpiece_loss_type,
		material,
		material_common,
		material_common__T_hardens_with_water,
		material_common__T_heat,
		material_common__T_reaction_product,
		material_common__T_strength,
		material_flags,
		material_template,
		material_vec_ref,
		matgloss_list,
		matgloss_list__T_unk_0,
		matter_state,
		meeting_context,
		meeting_diplomat_info,
		meeting_diplomat_info__T_flags,
		meeting_event,
		meeting_event_type,
		meeting_topic,
		meeting_variable,
		mental_attribute_type,
		mental_picture,
		mental_picture__T_unk,
		mental_picture_element_hfst,
		mental_picture_element_regionst,
		mental_picture_element_sitest,
		mental_picture_element_type,
		mental_picture_elementst,
		mental_picture_property_actionst,
		mental_picture_property_adjectivest,
		mental_picture_property_color_patternst,
		mental_picture_property_datest,
		mental_picture_property_emotionst,
		mental_picture_property_positionst,
		mental_picture_property_shapest,
		mental_picture_property_timest,
		mental_picture_property_toolst,
		mental_picture_property_type,
		mental_picture_propertyst,
		misc_trait_type,
		mission,
		mission__T_details,
		mission__T_details__T_raid,
		mission__T_details__T_raid__T_raid_flags,
		mission__T_details__T_raid__T_raid_type,
		mission__T_details__T_recovery,
		mission__T_details__T_request,
		mission__T_details__T_rescue,
		mission__T_type,
		mission_campaign_report,
		mission_report,
		monument_type,
		mood_type,
		mountain_peak_flags,
		moving_party,
		moving_party__T_members,
		musical_form,
		musical_form__T_flags,
		musical_form_feature,
		musical_form_instruments,
		musical_form_instruments__T_substitutions,
		musical_form_interval,
		musical_form_interval__T_flags,
		musical_form_melodies,
		musical_form_pitch_style,
		musical_form_purpose,
		musical_form_style,
		musical_form_sub4,
		musical_form_vocals,
		need_type,
		nemesis_flags,
		nemesis_offload,
		nemesis_record,
		next_global_id,
		occasion_schedule_feature,
		occasion_schedule_type,
		occupation,
		occupation_sub1,
		occupation_type,
		ocean_wave,
		organic_mat_category,
		orientation_flags,
		pants_flags,
		part_of_speech,
		party_info,
		pattern_type,
		performance_event_type,
		performance_participant_type,
		performance_play_orderst,
		performance_play_orderst__T_anon_4,
		personality_facet_type,
		physical_attribute_type,
		pitch_choice_type,
		plant,
		plant__T_damage_flags,
		plant_flags,
		plant_growth,
		plant_growth__T_behavior,
		plant_growth__T_locations,
		plant_growth_print,
		plant_raw,
		plant_raw__T_colors,
		plant_raw__T_material_defs,
		plant_raw__T_stockpile_growth_flags,
		plant_raw__T_tiles,
		plant_raw_flags,
		plant_tree_info,
		plant_tree_tile,
		plot_agreement,
		plot_role_type,
		plot_strategy_type,
		poetic_form,
		poetic_form__T_flags,
		poetic_form_action,
		poetic_form_additional_feature,
		poetic_form_caesura_position,
		poetic_form_feature,
		poetic_form_mood,
		poetic_form_part,
		poetic_form_part__T_flags,
		poetic_form_pattern,
		poetic_form_perspective,
		poetic_form_perspective__T_type,
		poetic_form_subject,
		poetic_form_subject_target,
		poetic_form_subject_target__T_Concept,
		poetic_form_subject_target__T_Histfig,
		popup_message,
		power_info,
		pressure_plate_info,
		pressure_plate_info__T_flags,
		profession,
		proj_itemst,
		proj_list_link,
		proj_magicst,
		proj_unitst,
		projectile,
		projectile_flags,
		projectile_type,
		property_ownership,
		punishment,
		reaction,
		reaction__T_building,
		reaction_category,
		reaction_description,
		reaction_flags,
		reaction_product,
		reaction_product_improvement_flags,
		reaction_product_item_flags,
		reaction_product_item_improvementst,
		reaction_product_item_improvementst__T_get_material,
		reaction_product_itemst,
		reaction_product_itemst__T_get_material,
		reaction_product_type,
		reaction_reagent,
		reaction_reagent_flags,
		reaction_reagent_itemst,
		reaction_reagent_type,
		region_block_event_sphere_fieldst,
		region_block_event_type,
		region_block_eventst,
		region_map_entry,
		region_map_entry__T_clouds,
		region_map_entry__T_wind,
		region_map_entry_flags,
		region_weather,
		relationship_event,
		relationship_event_supplement,
		renderer,
		report,
		report__T_flags,
		reputation_type,
		resource_allotment_data,
		resource_allotment_data__T_unk_654,
		resource_allotment_specifier,
		resource_allotment_specifier_ammost,
		resource_allotment_specifier_anvilst,
		resource_allotment_specifier_armor_bodyst,
		resource_allotment_specifier_armor_bootsst,
		resource_allotment_specifier_armor_glovesst,
		resource_allotment_specifier_armor_helmst,
		resource_allotment_specifier_armor_pantsst,
		resource_allotment_specifier_backpackst,
		resource_allotment_specifier_bagst,
		resource_allotment_specifier_bedst,
		resource_allotment_specifier_bonest,
		resource_allotment_specifier_boxst,
		resource_allotment_specifier_cabinetst,
		resource_allotment_specifier_chairst,
		resource_allotment_specifier_cheesest,
		resource_allotment_specifier_clothing_bodyst,
		resource_allotment_specifier_clothing_bootsst,
		resource_allotment_specifier_clothing_glovesst,
		resource_allotment_specifier_clothing_helmst,
		resource_allotment_specifier_clothing_pantsst,
		resource_allotment_specifier_clothst,
		resource_allotment_specifier_craftsst,
		resource_allotment_specifier_cropst,
		resource_allotment_specifier_extractst,
		resource_allotment_specifier_flaskst,
		resource_allotment_specifier_gemsst,
		resource_allotment_specifier_hornst,
		resource_allotment_specifier_leatherst,
		resource_allotment_specifier_meatst,
		resource_allotment_specifier_metalst,
		resource_allotment_specifier_pearlst,
		resource_allotment_specifier_powderst,
		resource_allotment_specifier_quiverst,
		resource_allotment_specifier_shellst,
		resource_allotment_specifier_skinst,
		resource_allotment_specifier_soapst,
		resource_allotment_specifier_stonest,
		resource_allotment_specifier_tablest,
		resource_allotment_specifier_tallowst,
		resource_allotment_specifier_threadst,
		resource_allotment_specifier_toothst,
		resource_allotment_specifier_type,
		resource_allotment_specifier_weapon_meleest,
		resource_allotment_specifier_weapon_rangedst,
		resource_allotment_specifier_woodst,
		rhythm,
		rhythm_sub1,
		rhythm_sub1__T_anon_1,
		rhythm_sub2,
		room_rent_info,
		room_rent_info__T_flags,
		route_stockpile_link,
		route_stockpile_link__T_mode,
		scale,
		scale__T_unk1,
		scale_sub1,
		scale_sub2,
		schedule_info,
		schedule_slot,
		screw_pump_direction,
		scribejob,
		script_step_conditionalst,
		script_step_conditionalst__T_condition,
		script_step_constructtopiclistst,
		script_step_dipeventst,
		script_step_diphistoryst,
		script_step_discussst,
		script_step_eventst,
		script_step_invasionst,
		script_step_setvarst,
		script_step_simpleactionst,
		script_step_textviewerst,
		script_step_topicdiscussionst,
		script_stepst,
		script_var_longst,
		script_var_unitst,
		script_varst,
		setup_character_info,
		setup_character_info__T_available_embark_items,
		setup_character_info__T_page,
		setup_character_info__T_sel_trait_column,
		setup_character_info__T_status,
		shoes_flags,
		shop_type,
		siegeengine_type,
		site_building_item,
		site_dispute_type,
		site_realization_building,
		site_realization_building__T_unk_4c,
		site_realization_building_info_castle_courtyardst,
		site_realization_building_info_castle_towerst,
		site_realization_building_info_castle_wallst,
		site_realization_building_info_hillock_housest,
		site_realization_building_info_market_squarest,
		site_realization_building_info_shop_housest,
		site_realization_building_info_tree_housest,
		site_realization_building_info_trenchesst,
		site_realization_building_info_trenchesst__T_spokes,
		site_realization_building_infost,
		site_realization_building_type,
		site_realization_crossroads,
		site_reputation_info,
		site_reputation_report,
		site_shop_type,
		site_type,
		skill_rating,
		slab_engraving_type,
		sound_production_type,
		spatter,
		spatter__T_flags,
		spatter_common,
		spatter_common__T_base_flags,
		special_mat_table,
		specific_ref,
		specific_ref__T_data,
		specific_ref__T_data__T_wrestle,
		specific_ref_type,
		sphere_type,
		spoils_report,
		squad,
		squad__T_rooms,
		squad_ammo_spec,
		squad_ammo_spec__T_flags,
		squad_event_type,
		squad_order,
		squad_order_cannot_reason,
		squad_order_cause_trouble_for_entityst,
		squad_order_defend_burrowsst,
		squad_order_drive_armies_from_sitest,
		squad_order_drive_entity_off_sitest,
		squad_order_kill_hfst,
		squad_order_kill_listst,
		squad_order_movest,
		squad_order_patrol_routest,
		squad_order_raid_sitest,
		squad_order_rescue_hfst,
		squad_order_retrieve_artifactst,
		squad_order_trainst,
		squad_order_type,
		squad_position,
		squad_schedule_entry,
		squad_schedule_order,
		squad_uniform_spec,
		squad_use_flags,
		stockpile_category,
		stockpile_group_set,
		stockpile_links,
		stockpile_list,
		stockpile_settings,
		stockpile_settings__T_ammo,
		stockpile_settings__T_animals,
		stockpile_settings__T_armor,
		stockpile_settings__T_bars_blocks,
		stockpile_settings__T_cloth,
		stockpile_settings__T_coins,
		stockpile_settings__T_finished_goods,
		stockpile_settings__T_food,
		stockpile_settings__T_furniture,
		stockpile_settings__T_gems,
		stockpile_settings__T_leather,
		stockpile_settings__T_ore,
		stockpile_settings__T_refuse,
		stockpile_settings__T_sheet,
		stockpile_settings__T_stone,
		stockpile_settings__T_weapons,
		stockpile_settings__T_wood,
		stop_depart_condition,
		stop_depart_condition__T_direction,
		stop_depart_condition__T_flags,
		stop_depart_condition__T_mode,
		strain_type,
		stratus_type,
		syndrome,
		syndrome_flags,
		T_cursor,
		T_selection_rect,
		tactical_situation,
		talk_choice,
		talk_choice__T_unk,
		talk_choice_type,
		temperaturest,
		temple_deity_data,
		temple_deity_type,
		text_info_element_longst,
		text_info_element_stringst,
		text_info_elementst,
		texture_handler,
		tile_bitmask,
		tile_building_occ,
		tile_designation,
		tile_dig_designation,
		tile_liquid,
		tile_liquid_flow,
		tile_liquid_flow_dir,
		tile_occupancy,
		tile_page,
		tile_traffic,
		tiletype,
		tiletype_material,
		tiletype_shape,
		tiletype_shape_basic,
		tiletype_special,
		tiletype_variant,
		timbre_type,
		timed_event,
		timed_event_type,
		tissue,
		tissue_flags,
		tissue_style_raw,
		tissue_style_type,
		tissue_template,
		tool_flags,
		tool_uses,
		tower_shape,
		toy_flags,
		training_assignment,
		training_assignment__T_flags,
		training_knowledge_level,
		trap_type,
		trapcomp_flags,
		tree_house_type,
		tuning_type,
		ui,
		ui__T_alerts,
		ui__T_alerts__T_list,
		ui__T_becoming_capital,
		ui__T_burrows,
		ui__T_economy_prices,
		ui__T_economy_prices__T_price_adjustment,
		ui__T_economy_prices__T_price_setter,
		ui__T_equipment,
		ui__T_equipment__T_update,
		ui__T_hauling,
		ui__T_invasions,
		ui__T_kitchen,
		ui__T_main,
		ui__T_main__T_dead_citizens,
		ui__T_map_edge,
		ui__T_squads,
		ui__T_stockpile,
		ui__T_tax_collection,
		ui__T_unk23c8_flags,
		ui__T_unk2a8c,
		ui__T_waypoints,
		ui__T_waypoints__T_points,
		ui__T_waypoints__T_routes,
		ui_advmode,
		ui_advmode__T_assume_identity,
		ui_advmode__T_companions,
		ui_advmode__T_conversation,
		ui_advmode__T_conversation__T_choices,
		ui_advmode__T_conversation__T_targets,
		ui_advmode__T_conversation__T_targets__T_type,
		ui_advmode__T_interactions,
		ui_advmode__T_show_menu,
		ui_advmode__T_travel_right_map,
		ui_advmode__T_unk_3124,
		ui_advmode__T_unk_3170,
		ui_advmode__T_unk_3170__T_unk_2,
		ui_advmode__T_unk_v40_1,
		ui_advmode__T_unk_v40_2,
		ui_advmode__T_unk_v40_3,
		ui_advmode__T_unk_v40_4,
		ui_advmode__T_unk_v40_4__T_unk_v40_4a,
		ui_advmode__T_unk_v40_5,
		ui_advmode__T_unk_v42_1,
		ui_advmode_menu,
		ui_build_item_req,
		ui_build_selector,
		ui_hotkey,
		ui_hotkey___union2,
		ui_hotkey__T_cmd,
		ui_look_list,
		ui_look_list__T_items,
		ui_look_list__T_items__T_data,
		ui_look_list__T_items__T_data__T_Magma,
		ui_look_list__T_items__T_data__T_Spatter,
		ui_look_list__T_items__T_data__T_Water,
		ui_look_list__T_items__T_type,
		ui_sidebar_menus,
		ui_sidebar_menus__T_barracks,
		ui_sidebar_menus__T_building,
		ui_sidebar_menus__T_command_line,
		ui_sidebar_menus__T_designation,
		ui_sidebar_menus__T_designation__T_mine_mode,
		ui_sidebar_menus__T_hospital,
		ui_sidebar_menus__T_job_details,
		ui_sidebar_menus__T_location,
		ui_sidebar_menus__T_minimap,
		ui_sidebar_menus__T_unit,
		ui_sidebar_menus__T_unit__T_expel_error,
		ui_sidebar_menus__T_unit_cursor,
		ui_sidebar_menus__T_unit_skills,
		ui_sidebar_menus__T_workshop_job,
		ui_sidebar_menus__T_zone,
		ui_sidebar_menus__T_zone__T_mode,
		ui_sidebar_mode,
		ui_unit_view_mode,
		ui_unit_view_mode__T_value,
		undead_flags,
		uniform_category,
		uniform_flags,
		uniform_indiv_choice,
		unit,
		unit__T_animal,
		unit__T_appearance,
		unit__T_body,
		unit__T_counters,
		unit__T_counters2,
		unit__T_counters__T_soldier_mood,
		unit__T_curse,
		unit__T_enemy,
		unit__T_enemy__T_undead,
		unit__T_enemy__T_unk_448,
		unit__T_enemy__T_unk_448__T_unk,
		unit__T_enemy__T_unk_44c,
		unit__T_enemy__T_unk_v40_sub3,
		unit__T_enemy__T_unk_v40_sub3__T_unk_2,
		unit__T_enemy__T_unk_v40_sub3__T_unk_6,
		unit__T_enemy__T_unk_v40_sub3__T_unk_7,
		unit__T_enemy__T_unk_v40_sub3__T_unk_7__T_unk_sub1,
		unit__T_enemy__T_witness_reports,
		unit__T_job,
		unit__T_meeting,
		unit__T_meeting__T_state,
		unit__T_military,
		unit__T_military__T_pickup_flags,
		unit__T_opponent,
		unit__T_path,
		unit__T_reports,
		unit__T_status,
		unit__T_status2,
		unit__T_status__T_eat_history,
		unit__T_status__T_eat_history__T_drink,
		unit__T_status__T_eat_history__T_food,
		unit__T_syndromes,
		unit__T_unknown7,
		unit_action,
		unit_action__T_data,
		unit_action_data_attack,
		unit_action_data_attack__T_flags,
		unit_action_data_attack__T_unk_4,
		unit_action_data_attack__T_unk_4__T_wrestle_type,
		unit_action_data_block,
		unit_action_data_climb,
		unit_action_data_dodge,
		unit_action_data_hold_item,
		unit_action_data_hold_terrain,
		unit_action_data_job,
		unit_action_data_job2,
		unit_action_data_jump,
		unit_action_data_lie_down,
		unit_action_data_move,
		unit_action_data_move__T_flags,
		unit_action_data_parry,
		unit_action_data_push_object,
		unit_action_data_recover,
		unit_action_data_release_item,
		unit_action_data_release_terrain,
		unit_action_data_stand_up,
		unit_action_data_suck_blood,
		unit_action_data_talk,
		unit_action_data_unsteady,
		unit_action_type,
		unit_appearance,
		unit_attribute,
		unit_bp_health_flags,
		unit_chunk,
		unit_chunk__T_units,
		unit_coin_debt,
		unit_complaint,
		unit_complaint__T_type,
		unit_dance_skill,
		unit_demand,
		unit_demand__T_place,
		unit_emotion_memory,
		unit_flags1,
		unit_flags2,
		unit_flags3,
		unit_flags4,
		unit_genes,
		unit_ghost_info,
		unit_ghost_info__T_flags,
		unit_ghost_info__T_target,
		unit_health_flags,
		unit_health_info,
		unit_health_info__T_op_history,
		unit_health_info__T_op_history__T_info,
		unit_health_info__T_op_history__T_info__T_bandage,
		unit_health_info__T_op_history__T_info__T_crutch,
		unit_instrument_skill,
		unit_inventory_item,
		unit_inventory_item__T_mode,
		unit_item_use,
		unit_item_wrestle,
		unit_labor,
		unit_labor_category,
		unit_misc_trait,
		unit_musical_skill,
		unit_path_goal,
		unit_personality,
		unit_personality__T_dreams,
		unit_personality__T_emotions,
		unit_personality__T_emotions__T_flags,
		unit_personality__T_flags,
		unit_personality__T_memories,
		unit_personality__T_memories__T_reflected_on,
		unit_personality__T_needs,
		unit_personality__T_unk5,
		unit_personality__T_unk_v40_2,
		unit_personality__T_unk_v40_6,
		unit_personality__T_values,
		unit_poetic_skill,
		unit_preference,
		unit_preference___union3,
		unit_preference__T_type,
		unit_relationship_type,
		unit_report_type,
		unit_request,
		unit_request__T_type,
		unit_skill,
		unit_soul,
		unit_soul__T_performance_skills,
		unit_station_type,
		unit_storage_status,
		unit_syndrome,
		unit_syndrome__T_flags,
		unit_syndrome__T_symptoms,
		unit_syndrome__T_symptoms__T_flags,
		unit_thought_type,
		unit_unk_138,
		unit_wound,
		unit_wound__T_flags,
		unit_wound__T_parts,
		units_other_id,
		unk_scale_enum_type,
		vague_relationship_type,
		value_type,
		vehicle,
		vermin,
		vermin_flags,
		viewscreen,
		viewscreen_adopt_regionst,
		viewscreen_adventure_logst,
		viewscreen_adventure_logst__T_info_mode,
		viewscreen_adventure_logst__T_mode,
		viewscreen_adventure_logst__T_unk_68,
		viewscreen_announcelistst,
		viewscreen_assign_display_itemst,
		viewscreen_assign_display_itemst__T_sel_column,
		viewscreen_barterst,
		viewscreen_buildinglistst,
		viewscreen_buildingst,
		viewscreen_choose_start_sitest,
		viewscreen_choose_start_sitest__T_finder,
		viewscreen_choose_start_sitest__T_finder__T_finder_state,
		viewscreen_choose_start_sitest__T_page,
		viewscreen_civlistst,
		viewscreen_civlistst__T_artifact_details,
		viewscreen_civlistst__T_page,
		viewscreen_civlistst__T_rumors,
		viewscreen_civlistst__T_rumors__T_type,
		viewscreen_civlistst__T_unk_cache,
		viewscreen_civlistst__T_unk_cache__T_tmp1,
		viewscreen_civlistst__T_unk_cache__T_tmp2,
		viewscreen_counterintelligencest,
		viewscreen_createquotast,
		viewscreen_customize_unitst,
		viewscreen_dungeon_monsterstatusst,
		viewscreen_dungeon_wrestlest,
		viewscreen_dungeon_wrestlest__T_unk1,
		viewscreen_dungeonmodest,
		viewscreen_dwarfmodest,
		viewscreen_entityst,
		viewscreen_export_graphical_mapst,
		viewscreen_export_graphical_mapst__T_rgb_buffer,
		viewscreen_export_regionst,
		viewscreen_export_regionst__T_unk1,
		viewscreen_game_cleanerst,
		viewscreen_game_cleanerst__T_state,
		viewscreen_image_creator_mode,
		viewscreen_image_creatorst,
		viewscreen_image_creatorst__T_artifacts,
		viewscreen_image_creatorst__T_entities,
		viewscreen_image_creatorst__T_histfigs,
		viewscreen_image_creatorst__T_objects,
		viewscreen_image_creatorst__T_plants,
		viewscreen_image_creatorst__T_relationships,
		viewscreen_image_creatorst__T_shapes,
		viewscreen_image_creatorst__T_sites,
		viewscreen_image_creatorst__T_trees,
		viewscreen_itemst,
		viewscreen_joblistst,
		viewscreen_jobmanagementst,
		viewscreen_jobst,
		viewscreen_justicest,
		viewscreen_justicest__T_cur_column,
		viewscreen_justicest__T_interrogate_status,
		viewscreen_kitchenpref_page,
		viewscreen_kitchenprefst,
		viewscreen_layer,
		viewscreen_layer_arena_creaturest,
		viewscreen_layer_assigntradest,
		viewscreen_layer_choose_language_namest,
		viewscreen_layer_choose_language_namest__T_current_component,
		viewscreen_layer_currencyst,
		viewscreen_layer_export_play_mapst,
		viewscreen_layer_militaryst,
		viewscreen_layer_militaryst__T_ammo,
		viewscreen_layer_militaryst__T_ammo__T_add_item,
		viewscreen_layer_militaryst__T_ammo__T_material,
		viewscreen_layer_militaryst__T_equip,
		viewscreen_layer_militaryst__T_equip__T_add_item,
		viewscreen_layer_militaryst__T_equip__T_assigned,
		viewscreen_layer_militaryst__T_equip__T_color,
		viewscreen_layer_militaryst__T_equip__T_edit_mode,
		viewscreen_layer_militaryst__T_equip__T_material,
		viewscreen_layer_militaryst__T_equip__T_mode,
		viewscreen_layer_militaryst__T_equip__T_uniform,
		viewscreen_layer_militaryst__T_page,
		viewscreen_layer_militaryst__T_positions,
		viewscreen_layer_militaryst__T_squad_members,
		viewscreen_layer_militaryst__T_squads,
		viewscreen_layer_musicsoundst,
		viewscreen_layer_noblelistst,
		viewscreen_layer_noblelistst__T_candidates,
		viewscreen_layer_noblelistst__T_info,
		viewscreen_layer_noblelistst__T_mode,
		viewscreen_layer_overall_healthst,
		viewscreen_layer_reactionst,
		viewscreen_layer_squad_schedulest,
		viewscreen_layer_stockpilest,
		viewscreen_layer_stone_restrictionst,
		viewscreen_layer_unit_actionst,
		viewscreen_layer_unit_healthst,
		viewscreen_layer_unit_relationshipst,
		viewscreen_layer_world_gen_param_presetst,
		viewscreen_layer_world_gen_paramst,
		viewscreen_layer_world_gen_paramst__T_unk1,
		viewscreen_legendsst,
		viewscreen_legendsst__T_anon_7,
		viewscreen_legendsst__T_anon_7__T_anon_3,
		viewscreen_legendsst__T_cur_page,
		viewscreen_loadgamest,
		viewscreen_loadgamest__T_cur_step,
		viewscreen_locationsst,
		viewscreen_locationsst__T_in_edit,
		viewscreen_locationsst__T_menu,
		viewscreen_meetingst,
		viewscreen_movieplayerst,
		viewscreen_new_regionst,
		viewscreen_new_regionst__T_worldgen_presets,
		viewscreen_noblest,
		viewscreen_optionst,
		viewscreen_optionst__T_options,
		viewscreen_overallstatusst,
		viewscreen_overallstatusst__T_visible_pages,
		viewscreen_petitionsst,
		viewscreen_petst,
		viewscreen_petst__T_animal,
		viewscreen_petst__T_mode,
		viewscreen_petst__T_trainer_mode,
		viewscreen_pricest,
		viewscreen_reportlistst,
		viewscreen_requestagreementst,
		viewscreen_savegamest,
		viewscreen_selectitemst,
		viewscreen_setupadventurest,
		viewscreen_setupadventurest__T_page,
		viewscreen_setupadventurest__T_races_info,
		viewscreen_setupadventurest__T_status,
		viewscreen_setupdwarfgamest,
		viewscreen_setupdwarfgamest__T_animals,
		viewscreen_setupdwarfgamest__T_choice_types,
		viewscreen_setupdwarfgamest__T_mode,
		viewscreen_setupdwarfgamest__T_unk_v43,
		viewscreen_setupdwarfgamest__T_unk_v43__T_unk_v43_sub9,
		viewscreen_storesst,
		viewscreen_textviewerst,
		viewscreen_textviewerst__T_formatted_text,
		viewscreen_textviewerst__T_formatted_text__T_flags,
		viewscreen_titlest,
		viewscreen_titlest__T_menu_line_id,
		viewscreen_titlest__T_sel_subpage,
		viewscreen_titlest__T_start_savegames,
		viewscreen_topicmeeting_fill_land_holder_positionsst,
		viewscreen_topicmeeting_takerequestsst,
		viewscreen_topicmeetingst,
		viewscreen_tradeagreementst,
		viewscreen_tradegoodsst,
		viewscreen_tradelistst,
		viewscreen_treasurelistst,
		viewscreen_unitlist_page,
		viewscreen_unitlistst,
		viewscreen_unitst,
		viewscreen_update_regionst,
		viewscreen_wagesst,
		viewscreen_workquota_conditionst,
		viewscreen_workquota_conditionst__T_mode,
		viewscreen_workquota_conditionst__T_traits,
		viewscreen_workquota_conditionst__T_traits__T_flags,
		viewscreen_workquota_detailsst,
		viewscreen_workshop_profilest,
		viewscreen_workshop_profilest__T_tab,
		weapon_attack,
		weapon_attack__T_flags,
		weapon_flags,
		weather_type,
		web_cluster,
		whereabouts_type,
		widget_menu,
		widget_textbox,
		workshop_profile,
		workshop_type,
		world,
		world__T_activities,
		world__T_agreements,
		world__T_area_grasses,
		world__T_area_grasses__T_layer_grasses,
		world__T_arena_settings,
		world__T_arena_spawn,
		world__T_arena_spawn__T_equipment,
		world__T_arena_spawn__T_item_types,
		world__T_arena_spawn__T_tame,
		world__T_armies,
		world__T_army_controllers,
		world__T_army_tracking_info,
		world__T_artifacts,
		world__T_belief_systems,
		world__T_crimes,
		world__T_cultural_identities,
		world__T_cur_savegame,
		world__T_dance_forms,
		world__T_divination_sets,
		world__T_enemy_status_cache,
		world__T_entities,
		world__T_features,
		world__T_flow_engine,
		world__T_flow_guides,
		world__T_formations,
		world__T_identities,
		world__T_image_sets,
		world__T_incidents,
		world__T_interaction_instances,
		world__T_items,
		world__T_languages,
		world__T_map,
		world__T_map_extras,
		world__T_math,
		world__T_math__T_approx,
		world__T_musical_forms,
		world__T_nemesis,
		world__T_occupations,
		world__T_pathfinder,
		world__T_pathfinder__T_boundary_heap,
		world__T_plants,
		world__T_poetic_forms,
		world__T_profession_skills,
		world__T_rhythms,
		world__T_scales,
		world__T_schedules,
		world__T_squads,
		world__T_status,
		world__T_status__T_flags,
		world__T_status__T_slots,
		world__T_status__T_slots__T_flags,
		world__T_stockpile,
		world__T_stockpile__T_simple1,
		world__T_stockpile__T_simple2,
		world__T_stockpile__T_simple3,
		world__T_units,
		world__T_unk_131ec0,
		world__T_unk_131ef0,
		world__T_unk_131ef0__T_claims,
		world__T_unk_19325c,
		world__T_unk_19325c__T_anon_1,
		world__T_unk_19325c__T_anon_2,
		world__T_unk_19325c__T_anon_3,
		world__T_unk_26c678,
		world__T_unk_v40_6,
		world__T_vehicles,
		world__T_vermin,
		world__T_worldgen,
		world__T_worldgen__T_worldgen_parms,
		world__T_worldgen_coord_buf,
		world__T_worldgen_status,
		world__T_written_contents,
		world_construction,
		world_construction_bridgest,
		world_construction_roadst,
		world_construction_square,
		world_construction_square_bridgest,
		world_construction_square_roadst,
		world_construction_square_tunnelst,
		world_construction_square_wallst,
		world_construction_tunnelst,
		world_construction_type,
		world_construction_wallst,
		world_dat_summary,
		world_data,
		world_data__T_constructions,
		world_data__T_feature_map,
		world_data__T_feature_map__T_features,
		world_data__T_flip_latitude,
		world_data__T_mountain_peaks,
		world_data__T_unk_274,
		world_data__T_unk_274__T_unk_10,
		world_data__T_unk_482f8,
		world_data__T_unk_b4,
		world_gen_param_basest,
		world_gen_param_charst,
		world_gen_param_memberst,
		world_gen_param_seedst,
		world_gen_param_valuest,
		world_geo_biome,
		world_geo_layer,
		world_history,
		world_history__T_event_collections,
		world_history__T_intrigues,
		world_history__T_intrigues__T_anon_1,
		world_landmass,
		world_object_data,
		world_object_data__T_offloaded_buildings,
		world_object_data__T_offloaded_items,
		world_object_data__T_unk_94,
		world_population,
		world_population___union5,
		world_population_ref,
		world_population_type,
		world_raws,
		world_raws__T_bodyglosses,
		world_raws__T_buildings,
		world_raws__T_descriptors,
		world_raws__T_effects,
		world_raws__T_itemdefs,
		world_raws__T_language,
		world_raws__T_plants,
		world_raws__T_reactions,
		world_raws__T_syndromes,
		world_region,
		world_region_details,
		world_region_details__T_edges,
		world_region_details__T_other_features,
		world_region_details__T_rivers_horizontal,
		world_region_details__T_rivers_vertical,
		world_region_feature,
		world_region_type,
		world_river,
		world_site,
		world_site__T_subtype_info,
		world_site__T_unk_1,
		world_site__T_unk_118,
		world_site__T_unk_13c,
		world_site__T_unk_188,
		world_site__T_unk_188__T_unk1,
		world_site__T_unk_1__T_units,
		world_site__T_unk_21c,
		world_site__T_unk_v40_2,
		world_site__T_unk_v40_4a,
		world_site__T_unk_v40_4b,
		world_site__T_unk_v40_4c,
		world_site__T_unk_v40_4d,
		world_site__T_unk_v40_4d__T_anon_1,
		world_site__T_unk_v43_2,
		world_site__T_unk_v47_1,
		world_site__T_unk_v47_1__T_unk_1,
		world_site_flags,
		world_site_inhabitant,
		world_site_realization,
		world_site_realization__T_areas,
		world_site_realization__T_areas__T_type,
		world_site_realization__T_building_map,
		world_site_realization__T_river_map,
		world_site_realization__T_unk_193bc,
		world_site_realization__T_unk_193bc__T_unk_8,
		world_site_realization__T_unk_55e8,
		world_site_realization__T_unk_55e8__T_unk_v40_2,
		world_site_type,
		world_site_unk130,
		world_site_unk130__T_unk_4,
		world_underground_region,
		world_underground_region__T_type,
		world_unk26c678_unk38,
		world_unk_20,
		world_unk_20__T_anon_7,
		world_unk_6c,
		world_unk_a8,
		world_unk_b4,
		world_unk_c0,
		world_unk_c0__T_anon_7,
		worldgen_range_type,
		worldgen_region_type,
		wound_curse_info,
		wound_curse_info__T_timing,
		wound_damage_flags1,
		wound_damage_flags2,
		wound_effect_type,
		written_content,
		written_content_style,
		written_content_type,
		z_level_flags,
		zoom_commands
	};

	std::string DF_Type_to_string(DF_Type p_type);
	DF_Type DF_Type_from_string(std::string& p_string);
	DF_Type DF_Type_from_string(const char* p_char);
	int32_t DF_Type_to_int(DF_Type p_df_type);
	DF_Type int_to_DF_Type(int p_value);
	std::size_t size_of_DF_Type(DF_Type p_type);
}
#endif // DF_TYPES_H