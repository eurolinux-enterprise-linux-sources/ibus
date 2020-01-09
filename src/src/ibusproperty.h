/* vim:set et sts=4: */
/* IBus - The Input Bus
 * Copyright (C) 2008-2010 Peng Huang <shawn.p.huang@gmail.com>
 * Copyright (C) 2008-2010 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */
/**
 * SECTION: ibusproperty
 * @short_description: UI component for input method engine property.
 * @title: IBusProperty
 * @stability: Stable
 *
 * An IBusProperty is an UI component like a button or a menu item
 * which shows the status of corresponding input method engine property.
 * End user can operate and see the current status of IME through these components.
 * For example, ibus-chewing users change the English/Chinese input mode by
 * pressing ctrl-space or click on the Eng/Chi switch button.
 * And the IBusProperty shows the change correspondingly.
 *
 * @see_also: #IBusPropList, #IBusEngine
 */
#ifndef __IBUS_PROPERTY_H_
#define __IBUS_PROPERTY_H_

#include "ibusserializable.h"
#include "ibustext.h"

G_BEGIN_DECLS

/*
 * Type macros.
 */
/* define IBusProperty macros */
#define IBUS_TYPE_PROPERTY             \
    (ibus_property_get_type ())
#define IBUS_PROPERTY(obj)             \
    (G_TYPE_CHECK_INSTANCE_CAST ((obj), IBUS_TYPE_PROPERTY, IBusProperty))
#define IBUS_PROPERTY_CLASS(klass)     \
    (G_TYPE_CHECK_CLASS_CAST ((klass), IBUS_TYPE_PROPERTY, IBusPropertyClass))
#define IBUS_IS_PROPERTY(obj)          \
    (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IBUS_TYPE_PROPERTY))
#define IBUS_IS_PROPERTY_CLASS(klass)  \
    (G_TYPE_CHECK_CLASS_TYPE ((klass), IBUS_TYPE_PROPERTY))
#define IBUS_PROPERTY_GET_CLASS(obj)   \
    (G_TYPE_INSTANCE_GET_CLASS ((obj), IBUS_TYPE_PROPERTY, IBusPropertyClass))

/**
 * IBusPropType:
 * @PROP_TYPE_NORMAL: Property is shown as normal text.
 * @PROP_TYPE_TOGGLE: Property is shown as a toggle button.
 * @PROP_TYPE_RADIO: Property is shown as a radio selection option.
 * @PROP_TYPE_MENU: Property is shown as a menu, usually imply it has sub menu
 * items.
 * @PROP_TYPE_SEPARATOR: A separator for menu.
 *
 * Type enumeration of IBusProperty.
 */
typedef enum {
    PROP_TYPE_NORMAL = 0,
    PROP_TYPE_TOGGLE = 1,
    PROP_TYPE_RADIO = 2,
    PROP_TYPE_MENU = 3,
    PROP_TYPE_SEPARATOR = 4,
} IBusPropType;

/**
 * IBusPropState:
 * @PROP_STATE_UNCHECKED: Property option is unchecked.
 * @PROP_STATE_CHECKED: Property option is checked.
 * @PROP_STATE_INCONSISTENT: The state is inconsistent with the associated IME
 * property.
 *
 * State of IBusProperty. The actual effect depends on #IBusPropType of the
 * IBusProperty.
 *
 * <variablelist>
 *     <varlistentry>
 *         <term>PROP_TYPE_TOGGLE</term>
 *         <listitem><para>Emphasized if PROP_STATE_CHECKED, normal otherwise.</para></listitem>
 *     </varlistentry>
 *     <varlistentry>
 *         <term>PROP_TYPE_RADIO</term>
 *         <listitem><para>Option checked if PROP_STATE_CHECKED, unchecked otherwise.</para></listitem>
 *     </varlistentry>
 * </variablelist>
 * No effect on other types.
 */
typedef enum {
    PROP_STATE_UNCHECKED = 0,
    PROP_STATE_CHECKED = 1,
    PROP_STATE_INCONSISTENT = 2,
} IBusPropState;


typedef struct _IBusProperty IBusProperty;
typedef struct _IBusPropertyClass IBusPropertyClass;

#ifndef __PROPLIST_DEFINED
#define __PROPLIST_DEFINED
typedef struct _IBusPropList IBusPropList;
typedef struct _IBusPropListClass IBusPropListClass;
#endif

/**
 * IBusProperty:
 * @key: Unique Identity for the IBusProperty.
 * @icon: Icon file for the IBusProperty.
 * @label: Text shown in UI.
 * @tooltip: Message shown if mouse hovered the  IBusProperty.
 * @sensitive: Whether the IBusProperty is sensitive to keyboard and mouse event.
 * @visible: Whether the IBusProperty is visible.
 * @type: IBusPropType of IBusProperty.
 * @state: IBusPropState of IBusProperty.
 * @sub_props: IBusPropList that contains sub IBusProperties. These IBusProperties are usually
 * shown as sub menu item.
 *
 * UI component for input method engine property.
 */
struct _IBusProperty {
    IBusSerializable parent;

    /*< public >*/
    gchar    *key;
    gchar    *icon;
    IBusText *label;
    IBusText *tooltip;

    gboolean sensitive;
    gboolean visible;
    guint type;
    guint state;

    IBusPropList *sub_props;
};

struct _IBusPropertyClass {
    IBusSerializableClass parent;
};

GType            ibus_property_get_type     ();

/**
 * ibus_property_new:
 * @key: Unique Identity for the IBusProperty.
 * @type: IBusPropType of IBusProperty.
 * @label: Text shown in UI.
 * @icon: Icon file for the IBusProperty.
 * @tooltip: Message shown if mouse hovered the  IBusProperty.
 * @sensitive: Whether the IBusProperty is sensitive to keyboard and mouse event.
 * @visible: Whether the IBusProperty is visible.
 * @state: IBusPropState of IBusProperty.
 * @prop_list: IBusPropList that contains sub IBusProperties.
 * @returns: A newly allocated IBusProperty.
 *
 * New a IBusProperty.
 */
IBusProperty    *ibus_property_new          (const gchar    *key,
                                             IBusPropType    type,
                                             IBusText       *label,
                                             const gchar    *icon,
                                             IBusText       *tooltip,
                                             gboolean        sensitive,
                                             gboolean        visible,
                                             IBusPropState   state,
                                             IBusPropList   *prop_list);

/**
 * ibus_property_set_label:
 * @prop: An IBusProperty.
 * @label: Text shown in UI.
 *
 * Set the label of IBusProperty.
 */
void             ibus_property_set_label    (IBusProperty   *prop,
                                             IBusText       *label);

/**
 * ibus_property_set_icon:
 * @prop: An IBusProperty.
 * @icon: Icon shown in UI. It could be a full path of an icon file or an icon name.
 *
 * Set the icon of IBusProperty.
 */
void             ibus_property_set_icon     (IBusProperty   *prop,
                                             const gchar    *icon);

/**
 * ibus_property_set_tooltip:
 * @prop: An IBusProperty.
 * @tooltip: Text of the tooltip.
 *
 * Set the tooltip of IBusProperty.
 */
void             ibus_property_set_tooltip  (IBusProperty   *prop,
                                             IBusText       *tooltip);

/**
 * ibus_property_set_sensitive:
 * @prop: An IBusProperty.
 * @sensitive: Whether the IBusProperty is sensitive.
 *
 * Set whether the IBusProperty is sensitive.
 */
void             ibus_property_set_sensitive(IBusProperty   *prop,
                                             gboolean        sensitive);

/**
 * ibus_property_set_visible:
 * @prop: An IBusProperty.
 * @visible: Whether the IBusProperty is visible.
 *
 * Set whether the IBusProperty is visible.
 */
void             ibus_property_set_visible  (IBusProperty   *prop,
                                             gboolean        visible);

/**
 * ibus_property_set_state:
 * @prop: An IBusProperty.
 * @state: The state of the IBusProperty.
 *
 * Set the state of the IBusProperty.
 */
void             ibus_property_set_state    (IBusProperty   *prop,
                                             IBusPropState   state);


/**
 * ibus_property_set_sub_props:
 * @prop: An IBusProperty.
 * @prop_list: IBusPropList that contains sub IBusProperties.
 *
 * Set the sub IBusProperties.
 */
void             ibus_property_set_sub_props(IBusProperty   *prop,
                                             IBusPropList   *prop_list);

/**
 * ibus_property_update:
 * @prop: An IBusProperty.
 * @prop_update: IBusPropList that contains sub IBusProperties.
 * @returns: TRUE for update suceeded; FALSE otherwise.
 *
 * Update the content of an IBusProperty.
 * IBusProperty @prop_update can either be sub-property of @prop,
 * or holds new values for @prop.
 */

gboolean         ibus_property_update       (IBusProperty   *prop,
                                             IBusProperty   *prop_update);

G_END_DECLS
#endif
