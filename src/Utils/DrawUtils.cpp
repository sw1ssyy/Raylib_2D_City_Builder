//
// Created by johnc on 28/08/2026.
//

#include "DrawUtils.h"

void DrawUtils::DrawCell(const GridCell& cell)
{
    if (cell.IsCellClicked())
    {
        DrawRectangleRec(cell.GetCellRect(), cell.GetClickedCellColor());
    }
    else
    {
        DrawRectangleLines(cell.GetCellRect().x, cell.GetCellRect().y, cell.GetCellRect().width, cell.GetCellRect().height, cell.GetBaseCellColor());
    }
}
