
#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <sstream>
#include <string>

#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

#include "file_exception.h"

using namespace std;

namespace io {
		
	class file {
	private:
		string filename;
		string absolute_path;
		string absolute_link_path;
		struct stat s_stat;
		int s_status;
		string message_exception;
		
		bool check_permissions(mode_t mask);
		void throw_stat_exception();
		
	public:
		file(string filename);
		
		string get_absolute_path();
		string get_absolute_link_path();
		
		bool exists();
		bool is_file();
		bool is_directory();
		bool is_link();
		bool is_character_device();
		bool is_block_device();
		bool is_fifo();
		bool is_socket();
		
		off_t get_size();
		blksize_t get_blksize();
		
		struct timespec get_time_access();
		struct timespec get_time_modification();
		struct timespec get_time_creation();
		
		dev_t get_device();
		ino_t get_inode();
		mode_t get_mode();
		nlink_t get_number_physical_links();
		
		uid_t get_uid();
		gid_t get_gid();
		dev_t get_device_type();
		
		bool is_user_read();
		bool is_user_write();
		bool is_user_exec();
		
		bool is_group_read();
		bool is_group_write();
		bool is_group_exec();
		
		bool is_others_read();
		bool is_others_write();
		bool is_others_exec();
		
		string get_permissions();
	};
}

#endif
