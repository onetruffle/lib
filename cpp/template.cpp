// #include "template.cpp"
#include "root.cpp"

fn solve() -> void;
fn main() -> int {
    C_UNSYNC;
    IO_UNSYNC;
    int T; cin >> T;
    LOOPI(tc, 1, T, 1) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
}

fn solve() -> void {
    end:;
    cout << flush;
}