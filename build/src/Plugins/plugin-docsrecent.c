/* plugin-docsrecent.c generated by valac 0.36.6, the Vala compiler
 * generated from plugin-docsrecent.vala, do not modify */

/* Copyright 2017 Juan Pablo Lozano
*
* This file is part of GCleaner.
*
* GCleaner is free software: you can redistribute it
* and/or modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation, either version 3 of the
* License, or (at your option) any later version.
*
* GCleaner is distributed in the hope that it will be
* useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
* Public License for more details.
*
* You should have received a copy of the GNU General Public License along
* with GCleaner. If not, see http://www.gnu.org/licenses/.
*/
/*Importing libraries GTK+ and GLib*/

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gio/gio.h>
#include <stdio.h>

#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))


extern gchar* path_docrecent;
gchar* path_docrecent = NULL;

void msg_docsrecent_pathNotFound (GtkWindow* win);
gchar* get_docrecent_params (void);
void docsrecent_clean (void);


void msg_docsrecent_pathNotFound (GtkWindow* win) {
	gchar* home = NULL;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	GtkMessageDialog* docsrecentNotFound = NULL;
	GtkWindow* _tmp2_;
	GtkMessageDialog* _tmp3_;
#line 26 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	g_return_if_fail (win != NULL);
#line 28 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	_tmp0_ = g_getenv ("HOME");
#line 28 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	_tmp1_ = g_strdup (_tmp0_);
#line 28 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	home = _tmp1_;
#line 29 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	_tmp2_ = win;
#line 29 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	_tmp3_ = (GtkMessageDialog*) gtk_message_dialog_new (_tmp2_, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_WARNING, GTK_BUTTONS_OK, "¡No se pudo analizar los Documentos Recientes! Verifique el acceso al " \
"archivo\n" \
" %s/.local/share/recently-used.xbel", home);
#line 29 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	g_object_ref_sink (_tmp3_);
#line 29 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	docsrecentNotFound = _tmp3_;
#line 30 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	gtk_window_set_title ((GtkWindow*) docsrecentNotFound, "Advertencia... Documentos Recientes");
#line 31 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	gtk_dialog_run ((GtkDialog*) docsrecentNotFound);
#line 32 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	gtk_widget_destroy ((GtkWidget*) docsrecentNotFound);
#line 26 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	_g_object_unref0 (docsrecentNotFound);
#line 26 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	_g_free0 (home);
#line 78 "plugin-docsrecent.c"
}


gchar* get_docrecent_params (void) {
	gchar* result = NULL;
	gchar* home = NULL;
	const gchar* _tmp0_;
	gchar* _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	GFile* file = NULL;
	const gchar* _tmp4_;
	GFile* _tmp5_;
	GFile* _tmp6_;
	gboolean _tmp7_;
	GError * _inner_error_ = NULL;
#line 37 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	_tmp0_ = g_getenv ("HOME");
#line 37 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	_tmp1_ = g_strdup (_tmp0_);
#line 37 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	home = _tmp1_;
#line 38 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	_tmp2_ = home;
#line 38 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	_tmp3_ = g_strconcat (_tmp2_, "/.local/share/recently-used.xbel", NULL);
#line 38 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	_g_free0 (path_docrecent);
#line 38 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	path_docrecent = _tmp3_;
#line 39 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	_tmp4_ = path_docrecent;
#line 39 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	_tmp5_ = g_file_new_for_path (_tmp4_);
#line 39 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	file = _tmp5_;
#line 41 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	_tmp6_ = file;
#line 41 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	_tmp7_ = g_file_query_exists (_tmp6_, NULL);
#line 41 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	if (_tmp7_) {
#line 121 "plugin-docsrecent.c"
		const gchar* _tmp8_;
		gchar* _tmp9_;
#line 43 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_tmp8_ = path_docrecent;
#line 43 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_tmp9_ = g_strdup (_tmp8_);
#line 43 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		result = _tmp9_;
#line 43 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_g_object_unref0 (file);
#line 43 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_g_free0 (home);
#line 43 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		return result;
#line 136 "plugin-docsrecent.c"
	} else {
		{
			const gchar* _tmp10_;
			gchar* _tmp11_;
			gchar* _tmp12_;
			gchar* _tmp13_;
			gchar* _tmp14_;
			const gchar* _tmp15_;
			gchar* _tmp16_;
#line 47 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			_tmp10_ = path_docrecent;
#line 47 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			_tmp11_ = g_strconcat ("bash -c \"echo > ", _tmp10_, NULL);
#line 47 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			_tmp12_ = _tmp11_;
#line 47 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			_tmp13_ = g_strconcat (_tmp12_, "\"", NULL);
#line 47 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			_tmp14_ = _tmp13_;
#line 47 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			g_spawn_command_line_sync (_tmp14_, NULL, NULL, NULL, &_inner_error_);
#line 47 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			_g_free0 (_tmp14_);
#line 47 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			_g_free0 (_tmp12_);
#line 47 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 47 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
				if (_inner_error_->domain == G_SPAWN_ERROR) {
#line 166 "plugin-docsrecent.c"
					goto __catch18_g_spawn_error;
				}
#line 47 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
				_g_object_unref0 (file);
#line 47 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
				_g_free0 (home);
#line 47 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
#line 47 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
				g_clear_error (&_inner_error_);
#line 47 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
				return NULL;
#line 179 "plugin-docsrecent.c"
			}
#line 48 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			_tmp15_ = path_docrecent;
#line 48 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			_tmp16_ = g_strdup (_tmp15_);
#line 48 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			result = _tmp16_;
#line 48 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			_g_object_unref0 (file);
#line 48 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			_g_free0 (home);
#line 48 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			return result;
#line 193 "plugin-docsrecent.c"
		}
		goto __finally18;
		__catch18_g_spawn_error:
		{
			GError* e = NULL;
			FILE* _tmp17_;
			GError* _tmp18_;
			const gchar* _tmp19_;
			gchar* _tmp20_;
#line 45 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			e = _inner_error_;
#line 45 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			_inner_error_ = NULL;
#line 51 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			_tmp17_ = stdout;
#line 51 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			_tmp18_ = e;
#line 51 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			_tmp19_ = _tmp18_->message;
#line 51 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			fprintf (_tmp17_, "COM.GCLEANER.PLUGIN-DOCSRECENT-S: [COMMAND-ERROR: %s]", _tmp19_);
#line 52 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			_tmp20_ = g_strdup ("error");
#line 52 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			result = _tmp20_;
#line 52 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			_g_error_free0 (e);
#line 52 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			_g_object_unref0 (file);
#line 52 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			_g_free0 (home);
#line 52 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			return result;
#line 227 "plugin-docsrecent.c"
		}
		__finally18:
#line 45 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_g_object_unref0 (file);
#line 45 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_g_free0 (home);
#line 45 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
#line 45 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		g_clear_error (&_inner_error_);
#line 45 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		return NULL;
#line 240 "plugin-docsrecent.c"
	}
#line 35 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	_g_object_unref0 (file);
#line 35 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	_g_free0 (home);
#line 246 "plugin-docsrecent.c"
}


void docsrecent_clean (void) {
	gchar* _error_ = NULL;
	gint status = 0;
	GError * _inner_error_ = NULL;
	{
		const gchar* _tmp0_;
		gchar* _tmp1_;
		gchar* _tmp2_;
		gchar* _tmp3_;
		gchar* _tmp4_;
		gchar* _tmp5_ = NULL;
		gint _tmp6_ = 0;
#line 64 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_tmp0_ = path_docrecent;
#line 64 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_tmp1_ = g_strconcat ("bash -c \"echo > ", _tmp0_, NULL);
#line 64 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_tmp2_ = _tmp1_;
#line 64 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_tmp3_ = g_strconcat (_tmp2_, "\"", NULL);
#line 64 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_tmp4_ = _tmp3_;
#line 64 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		g_spawn_command_line_sync (_tmp4_, NULL, &_tmp5_, &_tmp6_, &_inner_error_);
#line 64 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_g_free0 (_error_);
#line 64 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_error_ = _tmp5_;
#line 64 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		status = _tmp6_;
#line 64 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_g_free0 (_tmp4_);
#line 64 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_g_free0 (_tmp2_);
#line 64 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 64 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			if (_inner_error_->domain == G_SPAWN_ERROR) {
#line 288 "plugin-docsrecent.c"
				goto __catch19_g_spawn_error;
			}
#line 64 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			_g_free0 (_error_);
#line 64 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
#line 64 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			g_clear_error (&_inner_error_);
#line 64 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
			return;
#line 299 "plugin-docsrecent.c"
		}
	}
	goto __finally19;
	__catch19_g_spawn_error:
	{
		GError* e = NULL;
		FILE* _tmp7_;
		GError* _tmp8_;
		const gchar* _tmp9_;
		FILE* _tmp10_;
		FILE* _tmp11_;
		gchar* _tmp12_;
		gchar* _tmp13_;
#line 62 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		e = _inner_error_;
#line 62 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_inner_error_ = NULL;
#line 67 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_tmp7_ = stdout;
#line 67 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_tmp8_ = e;
#line 67 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_tmp9_ = _tmp8_->message;
#line 67 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		fprintf (_tmp7_, "COM.GCLEANER.PLUGIN-DOCSRECENT-C: [COMMAND-ERROR: %s]", _tmp9_);
#line 68 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_tmp10_ = stdout;
#line 68 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		fprintf (_tmp10_, "COM.GCLEANER.PLUGIN-DOCSRECENT-C: [ERROR: %s]\n", _error_);
#line 69 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_tmp11_ = stdout;
#line 69 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_tmp12_ = g_strdup_printf ("%i", status);
#line 69 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_tmp13_ = _tmp12_;
#line 69 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		fprintf (_tmp11_, "COM.GCLEANER.PLUGIN-DOCSRECENT-C: [STATUS: %s]\n", _tmp13_);
#line 69 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_g_free0 (_tmp13_);
#line 62 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_g_error_free0 (e);
#line 341 "plugin-docsrecent.c"
	}
	__finally19:
#line 62 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 62 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		_g_free0 (_error_);
#line 62 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
#line 62 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		g_clear_error (&_inner_error_);
#line 62 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
		return;
#line 354 "plugin-docsrecent.c"
	}
#line 57 "/home/jeremy/Documents/gcleaner/src/Plugins/plugin-docsrecent.vala"
	_g_free0 (_error_);
#line 358 "plugin-docsrecent.c"
}



