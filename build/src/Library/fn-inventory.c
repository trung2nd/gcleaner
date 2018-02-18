/* fn-inventory.c generated by valac 0.36.6, the Vala compiler
 * generated from fn-inventory.vala, do not modify */

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


#define GCLEANER_TOOLS_TYPE_INVENTORY_PATHS (gcleaner_tools_inventory_paths_get_type ())
#define GCLEANER_TOOLS_INVENTORY_PATHS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GCLEANER_TOOLS_TYPE_INVENTORY_PATHS, GCleanerToolsInventoryPaths))
#define GCLEANER_TOOLS_INVENTORY_PATHS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GCLEANER_TOOLS_TYPE_INVENTORY_PATHS, GCleanerToolsInventoryPathsClass))
#define GCLEANER_TOOLS_IS_INVENTORY_PATHS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GCLEANER_TOOLS_TYPE_INVENTORY_PATHS))
#define GCLEANER_TOOLS_IS_INVENTORY_PATHS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GCLEANER_TOOLS_TYPE_INVENTORY_PATHS))
#define GCLEANER_TOOLS_INVENTORY_PATHS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GCLEANER_TOOLS_TYPE_INVENTORY_PATHS, GCleanerToolsInventoryPathsClass))

typedef struct _GCleanerToolsInventoryPaths GCleanerToolsInventoryPaths;
typedef struct _GCleanerToolsInventoryPathsClass GCleanerToolsInventoryPathsClass;
typedef struct _GCleanerToolsInventoryPathsPrivate GCleanerToolsInventoryPathsPrivate;
#define _g_array_unref0(var) ((var == NULL) ? NULL : (var = (g_array_unref (var), NULL)))

struct _GCleanerToolsInventoryPaths {
	GObject parent_instance;
	GCleanerToolsInventoryPathsPrivate * priv;
	GArray* paths;
};

struct _GCleanerToolsInventoryPathsClass {
	GObjectClass parent_class;
};


static gpointer gcleaner_tools_inventory_paths_parent_class = NULL;

GType gcleaner_tools_inventory_paths_get_type (void) G_GNUC_CONST;
enum  {
	GCLEANER_TOOLS_INVENTORY_PATHS_DUMMY_PROPERTY
};
GCleanerToolsInventoryPaths* gcleaner_tools_inventory_paths_new (void);
GCleanerToolsInventoryPaths* gcleaner_tools_inventory_paths_construct (GType object_type);
void gcleaner_tools_inventory_paths_add (GCleanerToolsInventoryPaths* self, const gchar* file_path);
static void gcleaner_tools_inventory_paths_finalize (GObject * obj);


GCleanerToolsInventoryPaths* gcleaner_tools_inventory_paths_construct (GType object_type) {
	GCleanerToolsInventoryPaths * self = NULL;
	GArray* _tmp0_;
#line 32 "/home/jeremy/Documents/gcleaner/src/Library/fn-inventory.vala"
	self = (GCleanerToolsInventoryPaths*) g_object_new (object_type, NULL);
#line 34 "/home/jeremy/Documents/gcleaner/src/Library/fn-inventory.vala"
	_tmp0_ = g_array_new (TRUE, TRUE, sizeof (gchar*));
#line 34 "/home/jeremy/Documents/gcleaner/src/Library/fn-inventory.vala"
	_g_array_unref0 (self->paths);
#line 34 "/home/jeremy/Documents/gcleaner/src/Library/fn-inventory.vala"
	self->paths = _tmp0_;
#line 32 "/home/jeremy/Documents/gcleaner/src/Library/fn-inventory.vala"
	return self;
#line 78 "fn-inventory.c"
}


GCleanerToolsInventoryPaths* gcleaner_tools_inventory_paths_new (void) {
#line 32 "/home/jeremy/Documents/gcleaner/src/Library/fn-inventory.vala"
	return gcleaner_tools_inventory_paths_construct (GCLEANER_TOOLS_TYPE_INVENTORY_PATHS);
#line 85 "fn-inventory.c"
}


void gcleaner_tools_inventory_paths_add (GCleanerToolsInventoryPaths* self, const gchar* file_path) {
	GArray* _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_;
#line 41 "/home/jeremy/Documents/gcleaner/src/Library/fn-inventory.vala"
	g_return_if_fail (self != NULL);
#line 41 "/home/jeremy/Documents/gcleaner/src/Library/fn-inventory.vala"
	g_return_if_fail (file_path != NULL);
#line 42 "/home/jeremy/Documents/gcleaner/src/Library/fn-inventory.vala"
	_tmp0_ = self->paths;
#line 42 "/home/jeremy/Documents/gcleaner/src/Library/fn-inventory.vala"
	_tmp1_ = file_path;
#line 42 "/home/jeremy/Documents/gcleaner/src/Library/fn-inventory.vala"
	_tmp2_ = g_strdup (_tmp1_);
#line 42 "/home/jeremy/Documents/gcleaner/src/Library/fn-inventory.vala"
	g_array_append_val (_tmp0_, _tmp2_);
#line 105 "fn-inventory.c"
}


static void gcleaner_tools_inventory_paths_class_init (GCleanerToolsInventoryPathsClass * klass) {
#line 25 "/home/jeremy/Documents/gcleaner/src/Library/fn-inventory.vala"
	gcleaner_tools_inventory_paths_parent_class = g_type_class_peek_parent (klass);
#line 25 "/home/jeremy/Documents/gcleaner/src/Library/fn-inventory.vala"
	G_OBJECT_CLASS (klass)->finalize = gcleaner_tools_inventory_paths_finalize;
#line 114 "fn-inventory.c"
}


static void gcleaner_tools_inventory_paths_instance_init (GCleanerToolsInventoryPaths * self) {
}


static void gcleaner_tools_inventory_paths_finalize (GObject * obj) {
	GCleanerToolsInventoryPaths * self;
#line 25 "/home/jeremy/Documents/gcleaner/src/Library/fn-inventory.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, GCLEANER_TOOLS_TYPE_INVENTORY_PATHS, GCleanerToolsInventoryPaths);
#line 30 "/home/jeremy/Documents/gcleaner/src/Library/fn-inventory.vala"
	_g_array_unref0 (self->paths);
#line 25 "/home/jeremy/Documents/gcleaner/src/Library/fn-inventory.vala"
	G_OBJECT_CLASS (gcleaner_tools_inventory_paths_parent_class)->finalize (obj);
#line 130 "fn-inventory.c"
}


GType gcleaner_tools_inventory_paths_get_type (void) {
	static volatile gsize gcleaner_tools_inventory_paths_type_id__volatile = 0;
	if (g_once_init_enter (&gcleaner_tools_inventory_paths_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (GCleanerToolsInventoryPathsClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gcleaner_tools_inventory_paths_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (GCleanerToolsInventoryPaths), 0, (GInstanceInitFunc) gcleaner_tools_inventory_paths_instance_init, NULL };
		GType gcleaner_tools_inventory_paths_type_id;
		gcleaner_tools_inventory_paths_type_id = g_type_register_static (G_TYPE_OBJECT, "GCleanerToolsInventoryPaths", &g_define_type_info, 0);
		g_once_init_leave (&gcleaner_tools_inventory_paths_type_id__volatile, gcleaner_tools_inventory_paths_type_id);
	}
	return gcleaner_tools_inventory_paths_type_id__volatile;
}


