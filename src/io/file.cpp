
#include "file.h"

using namespace io;

file::file(string filename) {
	this->filename = filename;
	this->s_status = stat(filename.c_str(), &this->s_stat);
	if(this->s_status != 0) {
		char * ptr_error = strerror(errno);
		ostringstream oss;
		oss << "Cannot stat " << this->filename << ": " << ptr_error << endl;
		this->message_exception = oss.str();
		cerr << oss.str();
	}
	
	char path_buff[PATH_MAX];
	memset(path_buff, 0x00, sizeof(path_buff));
	if(realpath(this->filename.c_str(), path_buff) != NULL) {
		this->absolute_path = string(path_buff);
	} else {
		char * ptr_error = strerror(errno);
		cerr << "Cannot realpath " << this->filename << ": " << ptr_error << endl;
	}
	
	if(this->is_link()) {
		memset(path_buff, 0x00, sizeof(path_buff));
		if(readlink(this->filename.c_str(), path_buff, sizeof(path_buff)) != -1) {
			this->absolute_link_path = string(path_buff);
		} else {
			char * ptr_error = strerror(errno);
			cerr << "Cannot readlink " << this->filename << ": " << ptr_error << endl;
		}
	}
}

bool file::exists() {
	return this->s_status == 0;
}

void file::throw_stat_exception() {
	throw file_exception(this->message_exception);
}

string file::get_absolute_path() {
	if(this->s_status == 0) {
		return this->absolute_path;
	} else {
		throw_stat_exception();
		return "";
	}
}

string file::get_absolute_link_path() {
	if(this->s_status == 0) {
		if(! this->absolute_link_path.empty()) {
			return this->absolute_link_path;
		} else {
			return this->absolute_path;
		}
	} else {
		throw_stat_exception();
		return "";
	}
}

bool file::is_file() {
	if(this->s_status == 0) {
		return S_ISREG(this->s_stat.st_mode);
	} else {
		throw_stat_exception();
		return false;
	}
}

bool file::is_directory() {
	if(this->s_status == 0) {
		return S_ISDIR(this->s_stat.st_mode);
	} else {
		throw_stat_exception();
		return false;
	}
}

bool file::is_link() {
	if(this->s_status == 0) {
		return S_ISLNK(this->s_stat.st_mode);
	} else {
		throw_stat_exception();
		return false;
	}
}

bool file::is_character_device() {
	if(this->s_status == 0) {
		return S_ISCHR(this->s_stat.st_mode);
	} else {
		throw_stat_exception();
		return false;
	}
}

bool file::is_block_device() {
	if(this->s_status == 0) {
		return S_ISBLK(this->s_stat.st_mode);
	} else {
		throw_stat_exception();
		return false;
	}
}

bool file::is_fifo() {
	if(this->s_status == 0) {
		return S_ISFIFO(this->s_stat.st_mode);
	} else {
		throw_stat_exception();
		return false;
	}
}

bool file::is_socket() {
	if(this->s_status == 0) {
		return S_ISSOCK(this->s_stat.st_mode);
	} else {
		throw_stat_exception();
		return false;
	}
}

off_t file::get_size() {
	if(this->s_status == 0) {
		return this->s_stat.st_size;
	} else {
		throw_stat_exception();
		return (long int)(0);
	}
}

blksize_t file::get_blksize() {
	if(this->s_status == 0) {
		return this->s_stat.st_blksize;
	} else {
		throw_stat_exception();
		return (long int)(0);
	}
}

struct timespec file::get_time_access() {
	if(this->s_status == 0) {
		return this->s_stat.st_atim;
	} else {
		throw_stat_exception();
		return {0, 0};
	}
}

struct timespec file::get_time_modification() {
	if(this->s_status == 0) {
		return this->s_stat.st_mtim;
	} else {
		throw_stat_exception();
		return {0, 0};
	}
}

struct timespec file::get_time_creation() {
	if(this->s_status == 0) {
		return this->s_stat.st_ctim;
	} else {
		throw_stat_exception();
		return {0, 0};
	}
}

dev_t file::get_device() {
	if(this->s_status == 0) {
		return this->s_stat.st_dev;
	} else {
		throw_stat_exception();
		return (unsigned long int)(0);
	}
}

ino_t file::get_inode() {
	if(this->s_status == 0) {
		return this->s_stat.st_ino;
	} else {
		throw_stat_exception();
		return (unsigned long int)(0);
	}
}

mode_t file::get_mode() {
	if(this->s_status == 0) {
		return this->s_stat.st_mode;
	} else {
		throw_stat_exception();
		return (unsigned int)(0);
	}
}

nlink_t file::get_number_physical_links() {
	if(this->s_status == 0) {
		return this->s_stat.st_nlink;
	} else {
		throw_stat_exception();
		return (unsigned long int)(0);
	}
}

uid_t file::get_uid() {
	if(this->s_status == 0) {
		return this->s_stat.st_uid;
	} else {
		throw_stat_exception();
		return (unsigned int)(0);
	}
}

gid_t file::get_gid() {
	if(this->s_status == 0) {
		return this->s_stat.st_gid;
	} else {
		throw_stat_exception();
		return (unsigned int)(0);
	}
}

dev_t file::get_device_type() {
	if(this->s_status == 0) {
		return this->s_stat.st_rdev;
	} else {
		throw_stat_exception();
		return (unsigned long int)(0);
	}
}

bool file::check_permissions(mode_t mask) {
	if(this->s_status == 0) {
		return this->s_stat.st_mode & mask;
	} else {
		throw_stat_exception();
		return (unsigned int)(0);
	}
}

bool file::is_user_read() {
	if(this->s_status == 0) {
		return this->s_stat.st_mode & S_IRUSR;
	} else {
		throw_stat_exception();
		return false;
	}
}

bool file::is_user_write() {
	if(this->s_status == 0) {
		return this->s_stat.st_mode & S_IWUSR;
	} else {
		throw_stat_exception();
		return false;
	}
}

bool file::is_user_exec() {
	if(this->s_status == 0) {
		return this->s_stat.st_mode & S_IXUSR;
	} else {
		throw_stat_exception();
		return false;
	}
}

bool file::is_group_read() {
	if(this->s_status == 0) {
		return this->s_stat.st_mode & S_IRGRP;
	} else {
		throw_stat_exception();
		return false;
	}
}

bool file::is_group_write() {
	if(this->s_status == 0) {
		return this->s_stat.st_mode & S_IWGRP;
	} else {
		throw_stat_exception();
		return false;
	}
}

bool file::is_group_exec() {
	if(this->s_status == 0) {
		return this->s_stat.st_mode & S_IXGRP;
	} else {
		throw_stat_exception();
		return false;
	}
}

bool file::is_others_read() {
	if(this->s_status == 0) {
		return this->s_stat.st_mode & S_IROTH;
	} else {
		throw_stat_exception();
		return false;
	}
}

bool file::is_others_write() {
	if(this->s_status == 0) {
		return this->s_stat.st_mode & S_IWOTH;
	} else {
		throw_stat_exception();
		return false;
	}
}

bool file::is_others_exec() {
	if(this->s_status == 0) {
		return this->s_stat.st_mode & S_IXOTH;
	} else {
		throw_stat_exception();
		return false;
	}
}

string file::get_permissions() {
	if(this->s_status == 0) {
		ostringstream oss;
		if(this->is_user_read()) {
			oss << "r";
		} else {
			oss << "-";
		}
		if(this->is_user_write()) {
			oss << "w";
		} else {
			oss << "-";
		}
		if(this->is_user_exec()) {
			oss << "x";
		} else {
			oss << "-";
		}
		
		if(this->is_group_read()) {
			oss << "r";
		} else {
			oss << "-";
		}
		if(this->is_group_write()) {
			oss << "w";
		} else {
			oss << "-";
		}
		if(this->is_group_exec()) {
			oss << "x";
		} else {
			oss << "-";
		}
		
		if(this->is_group_read()) {
			oss << "r";
		} else {
			oss << "-";
		}
		if(this->is_group_write()) {
			oss << "w";
		} else {
			oss << "-";
		}
		if(this->is_group_exec()) {
			oss << "x";
		} else {
			oss << "-";
		}
		
		return oss.str();
	} else {
		throw_stat_exception();
		return "";
	}
}
