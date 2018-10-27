
#include <iostream>
#include "file.h"
#include "file_exception.h"

using namespace io;
using namespace std;

int main() {
	
	struct timespec s_ts;
	
	try {
		file f_etc_fstat("/etc/fstab");

		cout << "Absoulte path: " << f_etc_fstat.get_absolute_path() << endl;
		cout << "Is file? : " << f_etc_fstat.is_file() << endl;
		cout << "Is directory? : " << f_etc_fstat.is_directory() << endl;
		cout << "Is link? : " << f_etc_fstat.is_link() << endl;
		cout << "Is character device? : " << f_etc_fstat.is_character_device() << endl;
		cout << "Is block device? : " << f_etc_fstat.is_character_device() << endl;
		cout << "Is fifo? : " << f_etc_fstat.is_fifo() << endl;
		cout << "Is socket? : " << f_etc_fstat.is_socket() << endl;
		cout << "Mode : " << f_etc_fstat.get_mode() << endl;
		cout << "Size : " << f_etc_fstat.get_size() << endl;
		cout << "Block size : " << f_etc_fstat.get_blksize() << endl;
		cout << "iNode : " << f_etc_fstat.get_inode() << endl;
		cout << "Number of physical links? : " << f_etc_fstat.get_number_physical_links() << endl;
		cout << "Device : " << f_etc_fstat.get_device() << endl;
		cout << "Device type : " << f_etc_fstat.get_device_type() << endl;
		cout << "UID : " << f_etc_fstat.get_uid() << endl;
		cout << "GID : " << f_etc_fstat.get_gid() << endl;
		s_ts = f_etc_fstat.get_time_creation();
		cout << "Creation : " << s_ts.tv_sec << " sec, " << s_ts.tv_nsec << " usec" << endl;
		s_ts = f_etc_fstat.get_time_access();
		cout << "Access : " << s_ts.tv_sec << " sec, " << s_ts.tv_nsec << " usec" << endl;
		s_ts = f_etc_fstat.get_time_creation();
		cout << "Creation : " << s_ts.tv_sec << " sec, " << s_ts.tv_nsec << " usec" << endl;
		cout << endl;
		
	} catch (file_exception & ex) {
		cerr << ex.what() << endl;
	}
	
	try {
		file f_etc_fstat("./input/test_file_001.txt");

		cout << "Absoulte path: " << f_etc_fstat.get_absolute_path() << endl;
		cout << "Is file? : " << f_etc_fstat.is_file() << endl;
		cout << "Is directory? : " << f_etc_fstat.is_directory() << endl;
		cout << "Is link? : " << f_etc_fstat.is_link() << endl;
		cout << "Is character device? : " << f_etc_fstat.is_character_device() << endl;
		cout << "Is block device? : " << f_etc_fstat.is_character_device() << endl;
		cout << "Is fifo? : " << f_etc_fstat.is_fifo() << endl;
		cout << "Is socket? : " << f_etc_fstat.is_socket() << endl;
		cout << "Mode : " << f_etc_fstat.get_mode() << endl;
		cout << "Size : " << f_etc_fstat.get_size() << endl;
		cout << "Block size : " << f_etc_fstat.get_blksize() << endl;
		cout << "iNode : " << f_etc_fstat.get_inode() << endl;
		cout << "Number of physical links? : " << f_etc_fstat.get_number_physical_links() << endl;
		cout << "Device : " << f_etc_fstat.get_device() << endl;
		cout << "Device type : " << f_etc_fstat.get_device_type() << endl;
		cout << "UID : " << f_etc_fstat.get_uid() << endl;
		cout << "GID : " << f_etc_fstat.get_gid() << endl;
		s_ts = f_etc_fstat.get_time_creation();
		cout << "Creation : " << s_ts.tv_sec << " sec, " << s_ts.tv_nsec << " usec" << endl;
		s_ts = f_etc_fstat.get_time_access();
		cout << "Access : " << s_ts.tv_sec << " sec, " << s_ts.tv_nsec << " usec" << endl;
		s_ts = f_etc_fstat.get_time_creation();
		cout << "Creation : " << s_ts.tv_sec << " sec, " << s_ts.tv_nsec << " usec" << endl;
		cout << endl;
		
	} catch (file_exception & ex) {
		cerr << ex.what() << endl;
	}
	
	try {
		file f_etc_fstat("/bin/systemd");

		cout << "Absoulte path: " << f_etc_fstat.get_absolute_path() << endl;
		cout << "Is file? : " << f_etc_fstat.is_file() << endl;
		cout << "Is directory? : " << f_etc_fstat.is_directory() << endl;
		cout << "Is link? : " << f_etc_fstat.is_link() << endl;
		cout << "Is character device? : " << f_etc_fstat.is_character_device() << endl;
		cout << "Is block device? : " << f_etc_fstat.is_character_device() << endl;
		cout << "Is fifo? : " << f_etc_fstat.is_fifo() << endl;
		cout << "Is socket? : " << f_etc_fstat.is_socket() << endl;
		cout << "Mode : " << f_etc_fstat.get_mode() << endl;
		cout << "Size : " << f_etc_fstat.get_size() << endl;
		cout << "Block size : " << f_etc_fstat.get_blksize() << endl;
		cout << "iNode : " << f_etc_fstat.get_inode() << endl;
		cout << "Number of physical links? : " << f_etc_fstat.get_number_physical_links() << endl;
		cout << "Device : " << f_etc_fstat.get_device() << endl;
		cout << "Device type : " << f_etc_fstat.get_device_type() << endl;
		cout << "UID : " << f_etc_fstat.get_uid() << endl;
		cout << "GID : " << f_etc_fstat.get_gid() << endl;
		s_ts = f_etc_fstat.get_time_creation();
		cout << "Creation : " << s_ts.tv_sec << " sec, " << s_ts.tv_nsec << " usec" << endl;
		s_ts = f_etc_fstat.get_time_access();
		cout << "Access : " << s_ts.tv_sec << " sec, " << s_ts.tv_nsec << " usec" << endl;
		s_ts = f_etc_fstat.get_time_creation();
		cout << "Creation : " << s_ts.tv_sec << " sec, " << s_ts.tv_nsec << " usec" << endl;
		cout << endl;
		
	} catch (file_exception & ex) {
		cerr << ex.what() << endl;
	}
	
	try {
		file f_etc_fstab("~/this_file_does_not_exists.txt");
	
	} catch (file_exception & ex) {
		cerr << ex.what() << endl;
	}
	
	
	cout << "Done" << endl;

	return 0;
}
