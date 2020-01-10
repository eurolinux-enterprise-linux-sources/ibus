/* pango.c generated by valac 0.38.2, the Vala compiler
 * generated from pango.vala, do not modify */

/* vim:set et sts=4 sw=4:
 *
 * ibus - The Input Bus
 *
 * Copyright(c) 2011 Peng Huang <shawn.p.huang@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
 * USA
 */

#include <glib.h>
#include <glib-object.h>
#include <ibus.h>
#include <pango/pango.h>
#include <stdlib.h>
#include <string.h>

#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _pango_attribute_destroy0(var) ((var == NULL) ? NULL : (var = (pango_attribute_destroy (var), NULL)))
#define _pango_attr_list_unref0(var) ((var == NULL) ? NULL : (var = (pango_attr_list_unref (var), NULL)))



PangoAttrList* get_pango_attr_list_from_ibus_text (IBusText* text);


static gint string_index_of_nth_char (const gchar* self, glong c) {
	gint result = 0;
	glong _tmp0_;
	gchar* _tmp1_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = c;
	_tmp1_ = g_utf8_offset_to_pointer (self, _tmp0_);
	result = (gint) (_tmp1_ - ((gchar*) self));
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


PangoAttrList* get_pango_attr_list_from_ibus_text (IBusText* text) {
	PangoAttrList* result = NULL;
	PangoAttrList* pango_attrs = NULL;
	PangoAttrList* _tmp0_;
	IBusAttrList* attrs = NULL;
	IBusText* _tmp1_;
	IBusAttrList* _tmp2_;
	IBusAttrList* _tmp3_;
	const gchar* str = NULL;
	IBusText* _tmp4_;
	const gchar* _tmp5_;
	glong nchars = 0L;
	const gchar* _tmp6_;
	gint _tmp7_;
	glong* offsets = NULL;
	glong _tmp8_;
	glong* _tmp9_;
	gint offsets_length1;
	gint _offsets_size_;
	IBusAttribute* attr = NULL;
	gint i = 0;
	g_return_val_if_fail (text != NULL, NULL);
	_tmp0_ = pango_attr_list_new ();
	pango_attrs = _tmp0_;
	_tmp1_ = text;
	_tmp2_ = ibus_text_get_attributes (_tmp1_);
	attrs = _tmp2_;
	_tmp3_ = attrs;
	if (_tmp3_ == NULL) {
		result = pango_attrs;
		return result;
	}
	_tmp4_ = text;
	_tmp5_ = ibus_text_get_text (_tmp4_);
	str = _tmp5_;
	_tmp6_ = str;
	_tmp7_ = g_utf8_strlen (_tmp6_, (gssize) -1);
	nchars = (glong) _tmp7_;
	_tmp8_ = nchars;
	_tmp9_ = g_new0 (glong, _tmp8_ + 1);
	offsets = _tmp9_;
	offsets_length1 = _tmp8_ + 1;
	_offsets_size_ = offsets_length1;
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp10_ = FALSE;
			_tmp10_ = TRUE;
			while (TRUE) {
				gint _tmp12_;
				glong _tmp13_;
				glong* _tmp14_;
				gint _tmp14__length1;
				gint _tmp15_;
				const gchar* _tmp16_;
				gint _tmp17_;
				gint _tmp18_;
				glong _tmp19_;
				if (!_tmp10_) {
					gint _tmp11_;
					_tmp11_ = i;
					i = _tmp11_ + 1;
				}
				_tmp10_ = FALSE;
				_tmp12_ = i;
				_tmp13_ = nchars;
				if (!(((glong) _tmp12_) <= _tmp13_)) {
					break;
				}
				_tmp14_ = offsets;
				_tmp14__length1 = offsets_length1;
				_tmp15_ = i;
				_tmp16_ = str;
				_tmp17_ = i;
				_tmp18_ = string_index_of_nth_char (_tmp16_, (glong) _tmp17_);
				_tmp14_[_tmp15_] = (glong) _tmp18_;
				_tmp19_ = _tmp14_[_tmp15_];
			}
		}
	}
	i = 0;
	while (TRUE) {
		IBusAttrList* _tmp20_;
		gint _tmp21_;
		IBusAttribute* _tmp22_;
		IBusAttribute* _tmp23_;
		IBusAttribute* _tmp24_;
		glong start_index = 0L;
		IBusAttribute* _tmp25_;
		guint _tmp26_;
		glong _tmp27_;
		glong _tmp28_ = 0L;
		glong _tmp29_;
		glong _tmp30_;
		glong end_index = 0L;
		IBusAttribute* _tmp36_;
		guint _tmp37_;
		glong _tmp38_;
		glong _tmp39_ = 0L;
		glong _tmp40_;
		glong _tmp41_;
		PangoAttribute* pango_attr = NULL;
		IBusAttribute* _tmp47_;
		guint _tmp48_;
		PangoAttribute* _tmp72_;
		glong _tmp73_;
		PangoAttribute* _tmp74_;
		glong _tmp75_;
		PangoAttrList* _tmp76_;
		PangoAttribute* _tmp77_;
		_tmp20_ = attrs;
		_tmp21_ = i;
		i = _tmp21_ + 1;
		_tmp22_ = ibus_attr_list_get (_tmp20_, (guint) _tmp21_);
		_tmp23_ = _g_object_ref0 (_tmp22_);
		_g_object_unref0 (attr);
		attr = _tmp23_;
		_tmp24_ = attr;
		if (_tmp24_ == NULL) {
			break;
		}
		_tmp25_ = attr;
		_tmp26_ = _tmp25_->start_index;
		start_index = (glong) _tmp26_;
		_tmp27_ = start_index;
		if (_tmp27_ <= ((glong) 0)) {
			start_index = (glong) 0;
		}
		_tmp29_ = start_index;
		_tmp30_ = nchars;
		if (_tmp29_ <= _tmp30_) {
			glong* _tmp31_;
			gint _tmp31__length1;
			glong _tmp32_;
			glong _tmp33_;
			_tmp31_ = offsets;
			_tmp31__length1 = offsets_length1;
			_tmp32_ = start_index;
			_tmp33_ = _tmp31_[_tmp32_];
			_tmp28_ = _tmp33_;
		} else {
			glong* _tmp34_;
			gint _tmp34__length1;
			glong _tmp35_;
			_tmp34_ = offsets;
			_tmp34__length1 = offsets_length1;
			_tmp35_ = _tmp34_[-1];
			_tmp28_ = _tmp35_;
		}
		start_index = _tmp28_;
		_tmp36_ = attr;
		_tmp37_ = _tmp36_->end_index;
		end_index = (glong) _tmp37_;
		_tmp38_ = end_index;
		if (_tmp38_ <= ((glong) 0)) {
			end_index = (glong) 0;
		}
		_tmp40_ = end_index;
		_tmp41_ = nchars;
		if (_tmp40_ <= _tmp41_) {
			glong* _tmp42_;
			gint _tmp42__length1;
			glong _tmp43_;
			glong _tmp44_;
			_tmp42_ = offsets;
			_tmp42__length1 = offsets_length1;
			_tmp43_ = end_index;
			_tmp44_ = _tmp42_[_tmp43_];
			_tmp39_ = _tmp44_;
		} else {
			glong* _tmp45_;
			gint _tmp45__length1;
			glong _tmp46_;
			_tmp45_ = offsets;
			_tmp45__length1 = offsets_length1;
			_tmp46_ = _tmp45_[-1];
			_tmp39_ = _tmp46_;
		}
		end_index = _tmp39_;
		pango_attr = NULL;
		_tmp47_ = attr;
		_tmp48_ = _tmp47_->type;
		switch (_tmp48_) {
			case IBUS_ATTR_TYPE_FOREGROUND:
			{
				{
					guint16 r = 0U;
					IBusAttribute* _tmp49_;
					guint _tmp50_;
					guint16 g = 0U;
					IBusAttribute* _tmp51_;
					guint _tmp52_;
					guint16 b = 0U;
					IBusAttribute* _tmp53_;
					guint _tmp54_;
					guint16 _tmp55_;
					guint16 _tmp56_;
					guint16 _tmp57_;
					PangoAttribute* _tmp58_;
					_tmp49_ = attr;
					_tmp50_ = _tmp49_->value;
					r = (guint16) ((_tmp50_ & 0x00ff0000) >> 8);
					_tmp51_ = attr;
					_tmp52_ = _tmp51_->value;
					g = (guint16) (_tmp52_ & 0x0000ff00);
					_tmp53_ = attr;
					_tmp54_ = _tmp53_->value;
					b = (guint16) ((_tmp54_ & 0x000000ff) << 8);
					_tmp55_ = r;
					_tmp56_ = g;
					_tmp57_ = b;
					_tmp58_ = pango_attr_foreground_new (_tmp55_, _tmp56_, _tmp57_);
					_pango_attribute_destroy0 (pango_attr);
					pango_attr = _tmp58_;
					break;
				}
			}
			case IBUS_ATTR_TYPE_BACKGROUND:
			{
				{
					guint16 r = 0U;
					IBusAttribute* _tmp59_;
					guint _tmp60_;
					guint16 g = 0U;
					IBusAttribute* _tmp61_;
					guint _tmp62_;
					guint16 b = 0U;
					IBusAttribute* _tmp63_;
					guint _tmp64_;
					guint16 _tmp65_;
					guint16 _tmp66_;
					guint16 _tmp67_;
					PangoAttribute* _tmp68_;
					_tmp59_ = attr;
					_tmp60_ = _tmp59_->value;
					r = (guint16) ((_tmp60_ & 0x00ff0000) >> 8);
					_tmp61_ = attr;
					_tmp62_ = _tmp61_->value;
					g = (guint16) (_tmp62_ & 0x0000ff00);
					_tmp63_ = attr;
					_tmp64_ = _tmp63_->value;
					b = (guint16) ((_tmp64_ & 0x000000ff) << 8);
					_tmp65_ = r;
					_tmp66_ = g;
					_tmp67_ = b;
					_tmp68_ = pango_attr_background_new (_tmp65_, _tmp66_, _tmp67_);
					_pango_attribute_destroy0 (pango_attr);
					pango_attr = _tmp68_;
					break;
				}
			}
			case IBUS_ATTR_TYPE_UNDERLINE:
			{
				{
					IBusAttribute* _tmp69_;
					guint _tmp70_;
					PangoAttribute* _tmp71_;
					_tmp69_ = attr;
					_tmp70_ = _tmp69_->value;
					_tmp71_ = pango_attr_underline_new ((PangoUnderline) _tmp70_);
					_pango_attribute_destroy0 (pango_attr);
					pango_attr = _tmp71_;
					break;
				}
			}
			default:
			{
				continue;
			}
		}
		_tmp72_ = pango_attr;
		_tmp73_ = start_index;
		_tmp72_->start_index = (guint) _tmp73_;
		_tmp74_ = pango_attr;
		_tmp75_ = end_index;
		_tmp74_->end_index = (guint) _tmp75_;
		_tmp76_ = pango_attrs;
		_tmp77_ = pango_attr;
		pango_attr = NULL;
		pango_attr_list_insert (_tmp76_, _tmp77_);
		_pango_attribute_destroy0 (pango_attr);
	}
	result = pango_attrs;
	_g_object_unref0 (attr);
	offsets = (g_free (offsets), NULL);
	return result;
}



