#include "../cefau3.h"

#include "include/capi/cef_context_menu_handler_capi.h"

/* CefRunContextMenuCallback
--------------------------------------------------*/

CEFAU3API void CefRunContextMenuCallback_Continue(struct _cef_run_context_menu_callback_t* self,
	int command_id,
	int event_flags)
{
	self->cont(self, command_id, event_flags);
}

CEFAU3API void CefRunContextMenuCallback_Cancel(struct _cef_run_context_menu_callback_t* self)
{
	self->cancel(self);
}

/* CefContextMenuHandler
--------------------------------------------------*/

typedef struct CefContextMenuHandler {
	cef_context_menu_handler_t self;
	const char *OBCM;
	const char *RCM;
	const char *OCMC;
	const char *OCMD;
} CefContextMenuHandler;

CefHandlerCreate(CefContextMenuHandler);

CefHandlerFunc(CefContextMenuHandler, on_before_context_menu, OBCM);
CefHandlerFunc(CefContextMenuHandler, run_context_menu, RCM);
CefHandlerFunc(CefContextMenuHandler, on_context_menu_command, OCMC);
CefHandlerFunc(CefContextMenuHandler, on_context_menu_dismissed, OCMD);

/* CefContextMenuParams
--------------------------------------------------*/

CEFAU3API int CefContextMenuParams_GetXCoord(struct _cef_context_menu_params_t* self)
{
	return self->get_xcoord(self);
}

CEFAU3API int CefContextMenuParams_GetYCoord(struct _cef_context_menu_params_t* self)
{
	return self->get_ycoord(self);
}

CEFAU3API cef_context_menu_type_flags_t CefContextMenuParams_GetTypeFlags(
	struct _cef_context_menu_params_t* self)
{
	return self->get_type_flags(self);
}

CEFAU3API const wchar_t* CefContextMenuParams_GetLinkUrl(
	struct _cef_context_menu_params_t* self)
{
	return self->get_link_url(self)->str;
}

CEFAU3API const wchar_t* CefContextMenuParams_GetUnfilteredLinkUrl(
	struct _cef_context_menu_params_t* self)
{
	return self->get_unfiltered_link_url(self)->str;
}

CEFAU3API const wchar_t* CefContextMenuParams_GetSourceUrl(
	struct _cef_context_menu_params_t* self)
{
	return self->get_source_url(self)->str;
}

CEFAU3API int CefContextMenuParams_HasImageContents(
	struct _cef_context_menu_params_t* self)
{
	return self->has_image_contents(self);
}

CEFAU3API const wchar_t* CefContextMenuParams_GetTitleText(
	struct _cef_context_menu_params_t* self)
{
	return self->get_title_text(self)->str;
}

CEFAU3API const wchar_t* CefContextMenuParams_GetPageUrl(
	struct _cef_context_menu_params_t* self)
{
	return self->get_page_url(self)->str;
}

CEFAU3API const wchar_t* CefContextMenuParams_GetFrameUrl(
	struct _cef_context_menu_params_t* self)
{
	return self->get_frame_url(self)->str;
}

CEFAU3API const wchar_t* CefContextMenuParams_GetFrameCharset(
	struct _cef_context_menu_params_t* self)
{
	return self->get_frame_charset(self)->str;
}

CEFAU3API cef_context_menu_media_type_t CefContextMenuParams_GetMediaType(
	struct _cef_context_menu_params_t* self)
{
	return self->get_media_type(self);
}

CEFAU3API cef_context_menu_media_state_flags_t CefContextMenuParams_GetMediaStateFlags(
	struct _cef_context_menu_params_t* self)
{
	return self->get_media_state_flags(self);
}

CEFAU3API const wchar_t* CefContextMenuParams_GetSelectionText(
	struct _cef_context_menu_params_t* self)
{
	return self->get_selection_text(self)->str;
}

CEFAU3API const wchar_t* CefContextMenuParams_GetMisspelledWord(
	struct _cef_context_menu_params_t* self)
{
	return self->get_misspelled_word(self)->str;
}

CEFAU3API int CefContextMenuParams_GetDictionarySuggestions(
	struct _cef_context_menu_params_t* self,
	cef_string_list_t suggestions)
{
	return self->get_dictionary_suggestions(self, suggestions);
}

CEFAU3API int CefContextMenuParams_IsEditable(struct _cef_context_menu_params_t* self)
{
	return self->is_editable(self);
}

CEFAU3API int CefContextMenuParams_IsSpellCheckEnabled(
	struct _cef_context_menu_params_t* self)
{
	return self->is_spell_check_enabled(self);
}

CEFAU3API cef_context_menu_edit_state_flags_t CefContextMenuParams_GetEditStateFlags(
	struct _cef_context_menu_params_t* self)
{
	return self->get_edit_state_flags(self);
}

CEFAU3API int CefContextMenuParams_IsCustomMenu(struct _cef_context_menu_params_t* self)
{
	return self->is_custom_menu(self);
}

CEFAU3API int CefContextMenuParams_IsPepperMenu(struct _cef_context_menu_params_t* self)
{
	return self->is_pepper_menu(self);
}