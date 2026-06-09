#ifndef PDFTRON_H_CPPContentTree
#define PDFTRON_H_CPPContentTree

#include <C/Layout/TRN_ContentElement.h>
#include <C/Layout/TRN_ContentNode.h>
#include <C/Layout/TRN_Paragraph.h>
#include <C/Layout/TRN_Table.h>
#include <C/Layout/TRN_TableRow.h>
#include <C/Layout/TRN_TableCell.h>
#include <C/Layout/TRN_TextRun.h>
#include <C/Layout/TRN_TextStyledElement.h>
#include <C/Layout/TRN_List.h>
#include <C/Layout/TRN_ListItem.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>

namespace pdftron { namespace Layout {

class Paragraph;
class ContentNode;
class TextRun;
class Table;
class TableRow;
class TableCell;
class ContentGroup;
class FlowDocument;
class List;
class ListItem;

/**
 * An ElementRef is a reference to a specific type of Layout::ContentElement, for example,
 * Layout::TextRun. An instance of ElementRef is largely equivalent to an instance of tElement
 * in terms of capability, the only difference being that the ElementRef can be invalid.
 * As such, ElementRefs are used in cases where a method can return a ContentElement,
 * but may also return an empty result, like ContentElement::AsTextRun.
 */
template <typename T>
class ElementRef
{
	friend class ContentElement;

	/**
	 * Create a new ElementRef object, internal use only.
	 */
	template <typename TImpl>
	ElementRef(TImpl impl);

public:
	/**
	 * Create an invalid ElementRef object.
	 */
	ElementRef();

	/**
	 * Retrieves the underlying object of type T. 
	 *
	 * @return The underlying object of type T.
	 * @note Throws an exception if the ElementRef is invalid 
	 *       or if the underlying object is not of type T.
	 */
	T& GetElement();

	/**
	 * Checks if the reference can be dereferenced, i.e., points to an actual object.
	 *
	 * @return True if the ElementRef points to an actual object, false otherwise.
	 */
	bool IsValid();

	/**
	 * Implements the Safe Bool Idiom so the reference can be checked for validity.
	 */
	operator void*();

	/**
	 * Overloaded arrow operator to access the members of the object of type T.
	 *
	 * @return Pointer to the underlying object of type T.
	 * @note Throws an exception if the ElementRef is invalid.
	 */
	T* operator->();

	/**
	 * Dereference operator to get the underlying object of type T.
	 *
	 * @return Reference to the underlying object of type T.
	 * @note Throws an exception if the ElementRef is invalid.
	 */
	T& operator*();

private:
	T m_element;
};

/**
 * A TextStyledElement provides access to the text style properties of a
 * ContentElement.
 */
class TextStyledElement
{
	friend class ContentNode;
	friend class TextRun;
	friend class List;
	friend class ContentElement;

	/**
	 * Create a new TextStyledElement object, internal use only.
	 */
	TextStyledElement(TRN_TextStyledElement impl);

public:

	/**
	 * Set the font face name to be used for the style
	 *
	 * @param font_name The font face name to use for the style
	 */
	void SetFontFace(const UString& font_name);

	/**
	 * Get the font face name used for the style
	 *
	 * @return the font face name used for the style
	 */
	UString GetFontFace();

	/**
	 * Set font size of the style
	 *
	 * @param font_size The font size to use for the style
	 */
	void SetFontSize(double font_size);
	
	/**
	 * Get the font size of the style
	 *
	 * @return The font size of the style
	 */
	double GetFontSize();

	/**
	 * Set or unset the style as 'italic'
	 *
	 * @param val use true to set the style as 'Italic'
	 */
	void SetItalic(bool val);

	/**
	 * Get the italic setting of the style
	 *
	 * @return true if the style is set as 'Italic'
	 */
	bool IsItalic();
	
	/**
	 * Set or unset the style as 'Bold'
	 *
	 * @param val use true to set the style as 'Bold'
	 */
	void SetBold(bool val);

	/**
	 * Get the bold setting of the style
	 *
	 * @return true if the style is set as 'Bold'
	 */
	bool IsBold();

	/**
	 * Set text color for the style
	 *
	 * @param red The red component of the text color
	 * @param green The green component of the text color
	 * @param blue The blue component of the text color
	 */
	void SetTextColor(UInt8 red, UInt8 green, UInt8 blue);

	/**
	 * Set the background color for the style
	 *
	 * @param red The red component of the text color
	 * @param green The green component of the text color
	 * @param blue The blue component of the text color
	 */
	void SetBackgroundColor(UInt8 red, UInt8 green, UInt8 blue);

#ifndef SWIGHIDDEN
	TRN_TextStyledElement m_impl;
#endif
};

/**
 * Base class for all content elements in the document content tree. It contains
 * methods to retrieve instances of derived classes via the AsDerivedClass() methods.
 * The pattern is to retrieve a ElementRef<DerivedClass> object and then check if it is valid
 * via the IsValid() method or casting to void*. If it is valid, the actual
 * derived instance can be accessed through the ElementRef<DerivedClass> object.
 */
class ContentElement
{
protected:
	/**
	 * Create a new ContentElement object, internal use only.
	 */
	ContentElement(TRN_ContentElement impl);

public:
	~ContentElement();
	void Destroy();

	/**
	 * Retrieve the ElementRef<List> object for this content element which
	 * can be used to validate if this element is a list and, if so, to
	 * retrieve an associated List object.
	 *
	 * @return The ElementRef<List> object
	 */
	ElementRef<List> AsList() const;

	/**
	 * Retrieve the ElementRef<List> object for this content element which
	 * can be used to validate if this element is a list item and, if so, to
	 * retrieve an associated ListItem object.
	 *
	 * @return The ElementRef<ListItem> object
	 */
	ElementRef<ListItem> AsListItem() const;

	/**
	 * Retrieve the ElementRef<ContentNode> object for this content element which
	 * can be used to validate if this element is a content node and, if so, to
	 * retrieve an associated ContentNode object.
	 *
	 * @return The ElementRef<ContentNode> object
	 */
	ElementRef<ContentNode> AsContentNode() const;

	/**
	 * Retrieve the ElementRef<TextRun> object for this content element. This
	 * can be used to check if this element is a text run and, if so, to
	 * access the associated TextRun object.
	 *
	 * @return The ElementRef<TextRun> object
	 */
	ElementRef<TextRun> AsTextRun() const;

	/**
	 * Retrieve the ElementRef<Paragraph> object for this content element. This
	 * can be used to check if this element is a paragraph and, if so, to
	 * access the associated Paragraph object.
	 *
	 * @return The ElementRef<Paragraph> object
	 */
	ElementRef<Paragraph> AsParagraph() const;

	/**
	 * Retrieve the ElementRef<Table> object for this content element. This
	 * can be used to check if this element is a table and, if so, to
	 * access the associated Table object.
	 *
	 * @return The ElementRef<Table> object
	 */
	ElementRef<Table> AsTable() const;

	/**
	 * Retrieve the ElementRef<TableRow> object for this content element. This
	 * can be used to check if this element is a table row and, if so, to
	 * access the associated TableRow object.
	 *
	 * @return The ElementRef<TableRow> object
	 */
	ElementRef<TableRow> AsTableRow() const;

	/**
	 * Retrieve the ElementRef<TableCell> object for this content element. This
	 * can be used to check if this element is a table cell and, if so, to
	 * access the associated TableCell object.
	 *
	 * @return The ElementRef<TableCell> object
	 */
	ElementRef<TableCell> AsTableCell() const;

	/**
	 * Retrieve the TextStyledElement object for manipulating the text
	 * style of this content element.
	 *
	 * @return The TextStyledElement object
	 */
	TextStyledElement GetTextStyledElement();

#ifndef SWIGHIDDEN
	TRN_ContentElement m_impl;
#endif
};

/**
 * A TextRun is a content element that represents a single run of text. A
 * paragraph can contain multiple TextRun objects.
 */
class TextRun : public ContentElement
{
	friend class Paragraph;
	friend class ElementRef<TextRun>;

	/**
	 * Create a new TextRun object, internal use only.
	 */
	TextRun(TRN_TextRun impl);

public:
	~TextRun();
	void Destroy();

	/**
	 * Set the text content of the TextRun object
	 *
	 * @param text The text content to set
	 */
	void SetText(const UString& text);

	/**
	 * Get the text content of the TextRun object
	 *
	 * @return The text content
	 */
	UString GetText();
};

/**
 * ContentNodeIterator is an iterator type that can be used to traverse a list of
 * Content Elements in a ContentNode.
 */
typedef Common::Iterator<ContentElement> ContentNodeIterator;

/**
 * Base class for all elements in the document content tree that can contain
 * other content elements.
 */
class ContentNode : public ContentElement
{
	friend class FlowDocument;
	friend class ElementRef<TableCell>;
	friend class ElementRef<ContentNode>;

protected:
	/**
	 * Create a new ContentNode object, internal use only.
	 */
	ContentNode(TRN_ContentNode impl);

public:
	~ContentNode();
	void Destroy();

	/**
	 * Retrieve a ContentNodeIterator object from the content node
	 *
	 * <p>
	 * The ContentNodeIterator object can be used to traverse the children
	 * of the content node.
	 *
	 * @return The ContentNodeIterator object
	 */
	ContentNodeIterator GetContentNodeIterator();
};

/**
 * A Paragraph is a content node that contains a list of TextRun objects.
 */
class Paragraph : public ContentNode
{
	friend class FlowDocument;
	friend class ListItem;
	friend class ElementRef<Paragraph>;
	friend class TableCell;

	Paragraph(TRN_Paragraph impl);

public:
	enum TextJustification
	{
		/**
		 * Text justification is invalid
		 */
		e_text_justification_invalid = 0,
		/**
		 * Text is left justified
		 */
		e_text_justify_left = 1,
		/**
		 * Text is right justified
		 */
		e_text_justify_right = 2,
		/**
		 * Text is justified centered
		 */
		e_text_justify_center = 3
	};

	~Paragraph();
	void Destroy();

	/**
	 * Add another text run to the paragraph
	 *
	 * @param text The text to add
	 * @return The newly created TextRun object
	 */
	TextRun AddText(const UString& text);

	/**
	 * Set the "space before" value for the paragraph style
	 *
	 * @param val The "space before" value to set
	 */
	void SetSpaceBefore(double val);

	/**
	 * Get the "space before" value for the paragraph style
	 *
	 * @return "space before" value for paragraph style
	 */
	double GetSpaceBefore();

	/**
	 * Set the "space after" value for paragraph style
	 *
	 * @param val The "space after" value to set
	 */
	void SetSpaceAfter(double val);

	/**
	 * Get the "space after" value for the paragraph style
	 *
	 * @return "space after" value for paragraph style
	 */
	double GetSpaceAfter();

	/**
	 * Set justification mode for paragraph style
	 *
	 * @param val The justification mode to set
	 */
	void SetJustificationMode(TextJustification val);

	/**
	 * Get justification mode for the paragraph
	 *
	 * @return Justification mode for paragraph style
	 */
	TextJustification GetJustificationMode();

	/**
	 * Sets the start indent for the paragraph style.
	 *
	 * @param val The start indent value to set.
	 */
	void SetStartIndent(double val);

	/**
	 * Gets the start indent for the paragraph style.
	 *
	 * @return The start indent value for the paragraph style.
	 */
	double GetStartIndent();

	/**
	 * Sets the end indent for the paragraph style.
	 *
	 * @param val The end indent value to set.
	 */
	void SetEndIndent(double val);

	/**
	 * Gets the end indent for the paragraph style.
	 *
	 * @return The end indent value for the paragraph style.
	 */
	double GetEndIndent();

	/**
	 * Sets the text indent for the paragraph style.
	 *
	 * @param val The text indent value to set.
	 */
	void SetTextIndent(double val);

	/**
	 * Gets the text indent for the paragraph style.
	 *
	 * @return The text indent value for the paragraph style.
	 */
	double GetTextIndent();

	/**
	 * Sets the border for the paragraph style.
	 *
	 * @param thickness The border thickness.
	 * @param red The red component of the border color.
	 * @param green The green component of the border color.
	 * @param blue The blue component of the border color.
	 */
	void SetBorder(double thickness, UInt8 red, UInt8 green, UInt8 blue);

	/**
	 * Gets the border thickness for the paragraph style.
	 *
	 * @return The border thickness for the paragraph style.
	 */
	double GetBorderThickness();

	/**
	 * Adds a tab stop to the paragraph style.
	 *
	 * @param val The position of the tab stop to add.
	 */
	void AddTabStop(double val);

	/**
	 * Gets the next tab stop position for the paragraph style, given a starting position.
	 *
	 * @param val The starting position.
	 * @return The position of the next tab stop.
	 */
	double GetNextTabStop(double val);

	/**
	 * Sets the default tab stop position for the paragraph style.
	 *
	 * @param val The default tab stop position to set.
	 */
	void SetDefaultTabStop(double val);

	/**
	 * Gets the default tab stop position for the paragraph style.
	 *
	 * @return The default tab stop position for the paragraph style.
	 */
	double GetDefaultTabStop();

	/**
	 * Sets the number of spaces per tab for the paragraph style.
	 *
	 * @param val The number of spaces per tab to set.
	 */
	void SetSpacesPerTab(UInt32 val);

	/**
	 * Gets the number of spaces per tab for the paragraph style.
	 *
	 * @return The number of spaces per tab for the paragraph style.
	 */
	UInt32 GetSpacesPerTab();

	/**
	 * Sets the right-to-left (RTL) property for the paragraph style.
	 *
	 * @param val The value to set. True if RTL, false if not.
	 */
	void SetDisplayRtl(bool val);

	/**
	 * Checks if the paragraph style has the right-to-left (RTL) property set.
	 *
	 * @return True if the display is RTL, false otherwise.
	 */
	bool IsDisplayRtl();
};


/**
 * A class representing a table cell, which can be used during document creation.
 */
class TableCell : public ContentNode
{
	friend class Table;
	friend class TableRow;
	friend class ElementRef<TableCell>;

	/**
	 * Create a new TableCell object, internal use only.
	 */
	TableCell(TRN_TableCell impl);

public:
	enum CellAlignmentVertical
	{
		/**
		 * Cell content is top-aligned
		 */
		e_alignment_top = 1,
		/**
		 * Cell content is vertically centered
		 */
		e_alignment_center = 2,
		/**
		 * Cell content is bottom-aligned
		 */
		e_alignment_bottom = 3,
	};

	enum CellAlignmentHorizontal
	{
		/**
		 * Cell content is left-aligned
		 */
		e_alignment_left = 1,
		/**
		 * Cell content is horizontally centered
		 */
		e_alignment_middle = 2,
		/**
		 * Cell content is right-aligned
		 */
		e_alignment_right = 3,
	};

	~TableCell();
	void Destroy();

	/**
	 * Add an empty paragraph to the cell
	 * 
	 * @return The paragraph that was added
	 */
	Paragraph AddParagraph();

	/**
	 * Add a paragraph with text to the cell
	 *
	 * @return The paragraph that was added
	 */
	Paragraph AddParagraph(const UString& text);

	/**
	 * Add a nested table to the cell
	 *
	 * @return The table that was added
	 */
	Table AddTable();

	/**
	 * Merge the cell with the specified number of cells to the right
	 *
	 * @return The merged cell
	 */
	TableCell MergeCellsRight(UInt32 num);

	/**
	 * Merge the cell with the specified number of cells downwards
	 *
	 * @return The merged cell
	 */
	TableCell MergeCellsDown(UInt32 num);

	/**
	 * Set the background color of the cell
	 *
	 * @param red The red component of the border color
	 * @param green The green component of the border color
	 * @param blue The blue component of the border color
	 */
	void SetBackgroundColor(UInt8 red, UInt8 green, UInt8 blue);
	
	/**
	 * Set the cell's border thickness and color
	 *
	 * @param thickness The thickness of the border
	 * @param red The red component of the border color
	 * @param green The green component of the border color
	 * @param blue The blue component of the border color
	 */
	void SetBorder(double thickness, UInt8 red, UInt8 green, UInt8 blue);

	/**
	 * Get the border thickness of the table cell
	 *
	 * @return border thickness
	 */
	double GetBorderThickness();

	/**
	 * Set the vertical alignment of the cell
	 *
	 * @param val The vertical alignment of the cell
	 */
	void SetVerticalAlignment(CellAlignmentVertical val);
	
	/**
	 * Get the vertical alignment of the cell
	 *
	 * @return the vertical alignment of the cell
	 */
	CellAlignmentVertical GetVerticalAlignment(); 

	/**
	 * Set horizontal alignment of the cell
	 *
	 * @param val The horizontal alignment of the cell
	 */
	void SetHorizontalAlignment(CellAlignmentHorizontal val);
	
	/**
	 * Get the horizontal alignment of the cell
	 *
	 * @return the horizontal Alignment of the cell
	 */
	CellAlignmentHorizontal GetHorizontalAlignment(); 

	/**
	 * Set the height of the cell
	 *
	 * @param val The height of the cell
	 */
	void SetHeight(double val);

	/**
	 * Get the height of the cell
	 *
	 * @return the height of the cell
	 */
	double GetHeight();

	/**
	 * Set the width of the cell
	 *
	 * @param val The width of the cell
	 */
	void SetWidth(double val);

	/**
	 * Get the width of the cell
	 *
	 * @return the width of the cell
	 */
	double GetWidth();
};

/**
 * A class representing a table row, which can be used during document creation.
 */
class TableRow : public ContentNode
{
	friend class Table;
	friend class ElementRef<TableRow>;

	/**
	 * Create a new TableRow object, internal use only.
	 */
	TableRow(TRN_TableRow impl);

public:
	~TableRow();
	void Destroy();

	/**
	 * Add a new cell to the row
	 *
	 * @return The newly created cell
	 */
	TableCell AddTableCell();

	/**
	 * Set row height
	 *
	 * @param val The row height
	 */
	void SetRowHeight(double val);

	/**
	 * Get number of columns in the row
	 *
	 * <p>Because of cell merging different rows may have different numbers of
	 * columns.</p>
	 *
	 * @return number of columns in the row
	 */
	UInt32 GetNumColumns();
};

/**
 * A Table is a content node that contains a grid of cells.
 */
class Table : public ContentNode
{
	friend class FlowDocument;
	friend class ElementRef<Table>;
	friend class TableCell;

	/**
	 * Create a new Table object, internal use only.
	 */
	Table(TRN_Table impl);

public:
	~Table();
	void Destroy();

	/**
	 * Add a new row to the table
	 *
	 * @return The newly created row
	 */
	TableRow AddTableRow();

	/**
	 * Get a cell from the table
	 *
	 * @param column The column index of the cell to retrieve
	 * @param row The row index of the cell to retrieve
	 * 
	 * @return the TableCell at the specified column and row
	 */
	TableCell GetTableCell(UInt32 column, UInt32 row);

	/**
	 * Set default column weight of the table
	 *
	 * @param val The default column weight
	 */
	void SetDefaultColumnWidth(double val);

	/**
	 * Get default row height of the table
	 *
	 * @return Default row height of the table
	 */
	double GetDefaultRowHeight();

	/**
	 * Set default row height of the table
	 *
	 * @param val The default row height
	 */
	void SetDefaultRowHeight(double val);

	/**
	 * Set the cell's border thickness and color
	 *
	 * @param thickness The thickness of the border in points
	 * @param red The red component of the border color
	 * @param green The green component of the border color
	 * @param blue The blue component of the border color
	 */
	void SetBorder(double thickness, UInt8 red, UInt8 green, UInt8 blue);

	/**
	 * Get the border thickness of the table
	 *
	 * @return border thickness in points
	 */
	double GetBorderThickness();

	/**
	 * Get the number of rows in the table
	 *
	 * @return number of rows in the table
	 */
	UInt32 GetNumRows();

	/**
	 * Get the number of rows in the table
	 *
	 * @return number of rows in the table
	 */
	UInt32 GetNumColumns();
};

/**
 * A class representing a list in the document content tree.
 */
class List : public ContentNode
{
	friend class FlowDocument;
	friend class TableCell;
	friend class ListItem;
	friend class ElementRef<List>;

	List(TRN_List impl);
	void Destroy();
	void UpdateLastItemRef(TRN_ContentElement last_item);

public:
	enum NumberFormat
	{
		e_none = 0,
		e_decimal,
		e_lower_roman,
		e_upper_roman,
		e_lower_letter,
		e_upper_letter,
		e_ordinal,
		e_ordinal_text,
		e_chinese_counting,
		e_chinese_counting_thousand,
		e_cardinal_text,
		e_decimal_zero,
	};

	~List();

	/**
	 * Set the number format of the list.
	 *
	 * @param format The number format to set for the list.
	 */
	void SetNumberFormat(const NumberFormat format);

	/**
	 * Set the number format of the list with a custom suffix and cascade flag.
	 *
	 * @param format The number format to set for the list.
	 * @param suffix The suffix to append to the list item number.
	 * @param cascade If true, the number format will be applied to nested lists as well.
	 */
	void SetNumberFormat(const NumberFormat format, const UString& suffix, bool cascade);

	/**
	 * Get the text style element for the list item labels.
	 *
	 * @return The TextStyledElement representing the label style.
	 */
	TextStyledElement GetLabelStyle();

	/**
	 * Set the start index for the list items.
	 *
	 * @param idx The start index value.
	 */
	void SetStartIndex(int idx);

	/**
	 * Add a new list item to the list.
	 *
	 * @return The ListItem object representing the newly added item.
	 */
	ListItem AddItem();

	/**
	 * Continues the logical continuation of a particular list, even if other non-list content items
	 * have been created since the last call to AddItem(). This method is useful when splitting a sublist
	 * and wanting to continue the new items as part of the original sublist hierarchy.
	 *
	 * Note: Without calling ContinueList(), new list items created after a split (e.g., a split paragraph)
	 * would be added to the main list structure (above the split) based on their natural positions in the
	 * list/sublist hierarchy.
	 *
	 * Example usage: To continue a root-level list after a split, call ContinueList() on the root-level list.
	 */
	void ContinueList();

	/**
	 * Get the indentation level of the list.
	 *
	 * @return The indentation level.
	 */
	int GetIndentationLevel();

	/**
	 * Get the identifier of the list.
	 *
	 * @return The list identifier.
	 */
	int GetListIdentifier();

#ifndef SWIGHIDDEN
	TRN_List m_impl;
#endif
};

/**
 * A class representing an item in a list in the document content tree.
 */
class ListItem : public ContentNode
{
	friend class List;
	friend class ElementRef<ListItem>;

	ListItem(TRN_ListItem impl);
	void Destroy();
	void UpdateLastItemRef(TRN_ContentElement last_item);

public:
	~ListItem();

	/**
	 * Add a new paragraph to the list item.
	 *
	 * @return The Paragraph object representing the newly added paragraph.
	 */
	Paragraph AddParagraph();

	/**
	 * Add a new paragraph with the specified text to the list item.
	 *
	 * @param text The text content of the paragraph.
	 * @return The Paragraph object representing the newly added paragraph.
	 */
	Paragraph AddParagraph(const UString& text);

	/**
	 * Add a nested list to the list item.
	 *
	 * @return The List object representing the nested list.
	 */
	List AddList();

	/**
	 * Get the indentation level of the list item.
	 *
	 * @return The indentation level.
	 */
	int GetIndentationLevel();

	/**
	 * Get the identifier of the list.
	 *
	 * @return The list identifier.
	 */
	int GetListIdentifier();

	/**
	 * Get the index of the list item within the parent list.
	 *
	 * @return The index of the list item.
	 */
	int GetItemIndex();

#ifndef SWIGHIDDEN
	TRN_ListItem m_impl;
#endif
};

#include <Impl/ContentElement.inl>
#include <Impl/ContentNode.inl>
#include <Impl/ElementRef.inl>
#include <Impl/Paragraph.inl>
#include <Impl/TextRun.inl>
#include <Impl/TextStyledElement.inl>
#include <Impl/TableCell.inl>
#include <Impl/TableRow.inl>
#include <Impl/Table.inl>
#include <Impl/ListItem.inl>
#include <Impl/List.inl>

} //end pdftron
} //end Layout

#endif // PDFTRON_H_CPPContentTree
