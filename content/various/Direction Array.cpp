/**
 * Author:
 * Date: 2025-11-20
 * License: CC0
 * Description: Direction vectors for grid and knight moves.
 *  - 4/8 directions $(dx[i], dy[i])$, $i=0..7$:
 *      $(+1, 0)=\text{Down}$, $(-1, 0)=\text{Up}$, $(0, +1)=\text{Right}$, $(0, -1)=\text{Left}$,
 *      $(+1, +1)=\text{Down-Right}$, $(+1, -1)=\text{Down-Left}$, $(-1, +1)=\text{Up-Right}$, $(-1, -1)=\text{Up-Left}$
 *  - Knight moves $(kdx[i], kdy[i])$, $i=0..7$
 * Time: O(1)
 * Status: Tested
 */
#pragma once

// (dx, dy for grid-based problems) 4 directions and 4 diagonal moves
const ll dx[] = {1, -1, 0, 0, 1, 1, -1, -1};  
const ll dy[] = {0, 0, 1, -1, 1, -1, 1, -1};  

// Knight's Move
ll kdx[] = {-2, -2, -1, -1,  1,  1,  2,  2};
ll kdy[] = {-1,  1, -2,  2, -2,  2, -1,  1};

