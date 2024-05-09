#ifndef SIMPLEBOARD_H
#define SIMPLEBOARD_H

//------------------------------
#include <utility>
#include <exception>
#include <stdexcept>

#include "board.h"

//==============================
//--------------------------------------------
template<std::size_t N>
class SimpleBoard : public IBoard
{
    public:
        SimpleBoard() = default;
        ~SimpleBoard() = default;

        virtual std::pair<PositionType, PositionType> dimention() const override
        {
            return std::make_pair(PositionType{}, m_size);
        }

        virtual Mark mark(const PositionType& pos) const override
        {
            if( pos.x < m_size.x && pos.y < m_size.y )
                return m_marks[pos.x][pos.y];

            throw std::invalid_argument("Invalid position");
            return MARK_UNKNOWN;
        }

        virtual bool setMark(const PositionType& pos, const Mark& mark) override
        {
            if( pos.x < m_size.x && pos.y < m_size.y ){
                m_marks[pos.x][pos.y] = mark;
                return true;
            }
            return false;
        }

    private:
        PositionType m_size = {N,N};
        Mark m_marks[N][N] = {IBoard::MARK_EMPTY};
};

#endif // SIMPLEBOARD_H
