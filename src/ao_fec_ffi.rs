/* automatically generated by rust-bindgen 0.69.4 */

extern "C" {
    pub fn ao_fec_check_crc(bytes: *const u8, len: usize) -> ::std::os::raw::c_int;
}
extern "C" {
    pub fn ao_fec_encode(in_: *const u8, len: usize, out: *mut u8) -> usize;
}
extern "C" {
    pub fn ao_fec_decode(
        in_: *const u8,
        in_len: usize,
        out: *mut u8,
        out_len: usize,
    ) -> ::std::os::raw::c_int;
}
