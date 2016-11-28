    if ( node.right == 2 && current_status.right == BlockType::FREE ) {
        ++node.right;
        node.direction = Direction::RIGHT;
        stack.push_back( node );
        ++X;
        return Direction::RIGHT;
    }

    if ( node.down == 2 && current_status.down == BlockType::FREE ) {
        ++node.down;
        node.direction = Direction::DOWN;
        stack.push_back( node );
        --Y;
        return Direction::DOWN;

    }

    if ( node.left == 2 && current_status.left == BlockType::FREE ) {
        ++node.left;
        node.direction = Direction::LEFT;
        stack.push_back( node );
        --X;
        return Direction::LEFT;
    }

    if ( node.up == 2 && current_status.up == BlockType::FREE ) {
        ++node.up;
        node.direction = Direction::UP;
        stack.push_back( node );
        ++Y;
        return Direction::UP;
    }
